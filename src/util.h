#ifndef FS_UTIL
#define FS_UTIL

#include "fs.h"
#include "memory.h"

void append_block_sequence_lists(LList* parent, LList sublist);
double inode_addr_to_disk_block_addr(Disk disk, int inode_addr);
bool compare_block_sequence(void* el_1, void* el_2);

uint32_t round_up_nearest_multiple(uint32_t, uint32_t);
int div_round_up(int a, int b);
bool block_seq_is_empty(BlockSequence seq);

void util_print_block_seq_list(LList list);

int util_string_to_heap(char*, HeapData*);

int compare_superblock(Superblock, Superblock);
int compare_inode(Inode, Inode);

int util_write_uint16(HeapData*, int, uint16_t);
int util_write_uint32(HeapData*, int, uint32_t);
int util_write_uint64(HeapData*, int, uint64_t);

uint16_t util_read_uint16(HeapData, int, int*);
uint32_t util_read_uint32(HeapData, int, int*);
uint64_t util_read_uint64(HeapData, int, int*);
// Free callbacks 
void free_element_standard(void* element);
void free_element_bl_debug(void* element);

#endif
