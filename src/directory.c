#include "directory.h"

int dir_add_entry(Directory* directory, DirectoryEntry entry) {
	if (entry.name.size > 0xFF) return ERR_INODE_NAME_TOO_LARGE;
	const int entry_size = entry.name.size + 5;
	int ret = 0;

	if (!directory->valid) {
		ret = mem_alloc(directory, entry_size);
	}
	else {
		ret = mem_realloc(directory, entry_size + directory->size);
	}
	if (ret != SUCCESS) return ret;

	const int INCREMENT_8 = 1;
	const int INCREMENT_16 = 2;
	const int INCREMENT_32 = 4;

	int current_location = directory->size - entry_size;

	ret = util_write_uint32(directory, current_location, entry.inode_number);
	if (ret != SUCCESS) return ret;
	current_location += INCREMENT_32;

	ret = mem_write(directory, current_location, entry.name.size);
	if (ret != SUCCESS) return ret;
	current_location += INCREMENT_8;

	ret = mem_write_section(directory, current_location, entry.name);
	if (ret != SUCCESS) return ret;

	return SUCCESS;
}

int dir_get_inode_number(Directory directory, HeapData name, uint32_t* inode_number) {
	if (!directory.valid) return ERR_INVALID_MEMORY_ACCESS;
	if (!name.valid) return ERR_INVALID_MEMORY_ACCESS;

	// Always referes to the *start* of each directory entry
	int current_location = 0;

	while (current_location < directory.size) {
		int name_start = current_location + 5;
		int error = 0;
		if (name_start + name.size > directory.size) return ERR_INODE_NOT_FOUND;

		uint32_t inode_num = util_read_uint32(directory, current_location, &error);
		if (error != SUCCESS) return error;

		uint8_t name_size = mem_read(directory, current_location + 4, &error);
		if (error != SUCCESS) return error;

		if (name_size != name.size) {
			current_location += 5 + name_size;
			continue;
		}

		if (memcmp(&directory.data[current_location + 5], name.data, name.size) == 0) {
			*inode_number = inode_num;
			return SUCCESS;
		}

		current_location += 5 + name_size;
	}

	return ERR_INODE_NOT_FOUND;
}