#ifndef FS_CONSTANTS
#define FS_CONSTANTS

// All disk sizes are in bytes (uint8_t)

#define KILO 1024
#define MEGA 1024 * KILO
#define GIGA 1024 * MEGA

#define DISK_SIZE MEGA
#define BLOCK_SIZE 512
#define INODE_SIZE 128
#define INDIRECT_NUM_BLOCK_SEQUENCE BLOCK_SIZE / 8
#define DIRECT_BLOCK_NUM 6

#define SUCCESS 0
#define ERR_MALLOC_FAILED 1
#define ERR_INVALID_MEMORY_ACCESS 2
#define ERR_DISK_NOT_MOUNTED 3
#define ERR_INVALID_MEM_ALLOC 4
#define ERR_INVALID_FILE_PATH 5
#define ERR_FILE_ACCESS_FAILED 6
#define ERR_PARTIAL_FILE_WRITE 7
#define ERR_NULL_STRING 8
#define ERR_EMPTY_STRING 9
#define ERR_INODE_NAME_TOO_LARGE 10
#define ERR_INODE_NOT_FOUND 11
#define ERR_NO_BITMAP_RUN_FOUND 12
#define ERR_INVALID_BITMAP 13

#define SUPERBLOCK_MAGIC_1 0xA1B2C3D4
#define SUPERBLOCK_MAGIC_2 0xAD34FB5E
#define INODE_MAGIC 0x98765432
#define CURRENT_FS_VERSION 0x0001
#define INODE_FLAG_IS_DIR 0x1

#endif
