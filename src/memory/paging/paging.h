#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>
#include <stddef.h>

#define PAGING_CATCHE_BIT_DISABLED 0b00010000
#define PAGING_WRITE_THROUGH       0b00001000
#define PAGING_ACCESS_FROM_ALL     0b00000100
#define PAGING_IS_WRITABLE         0b00000010
#define PAGING_IS_PRESENT          0b00000001

#define PAGING_TOTAL_ENTRYS_PER_TABLE 1024
#define PAGING_PAGE_SIZE 4096

struct paging_4gb_chunk
{
    uint32_t* directory_entry;
};

uint32_t* paging_4gb_chunk_get_directory(struct paging_4gb_chunk* chunk);
struct paging_4gb_chunk* paging_new_4gb(uint8_t flags);
void paging_switch(uint32_t* directory);
void enable_paging();


#endif