#include "paging.h"
#include "memory/heap/kheap.h"

void paging_load_directory(uint32_t* directory);

static uint32_t* current_directory = 0;
struct paging_4gb_chunk* paging_new_4gb(uint8_t flags)
{
    uint32_t* directory = kzalloc(sizeof(uint32_t) * PAGING_TOTAL_ENTRYS_PER_TABLE);
    int offset = 0;
    for (int i = 0; i < PAGING_TOTAL_ENTRYS_PER_TABLE; i++) {
        // Creating a page table for each entry in the directory
        uint32_t* entry = kzalloc(sizeof(uint32_t) * PAGING_TOTAL_ENTRYS_PER_TABLE);
        for (int b = 0; b < PAGING_TOTAL_ENTRYS_PER_TABLE; b++) {
            entry[b] = (offset + (b * PAGING_PAGE_SIZE)) | flags;
        }
        offset += (PAGING_TOTAL_ENTRYS_PER_TABLE * PAGING_PAGE_SIZE);
        directory[i] = (uint32_t)entry | flags | PAGING_IS_WRITABLE;
    }
    struct paging_4gb_chunk* chunk4gb = kzalloc(sizeof(struct paging_4gb_chunk));
    chunk4gb->directory_entry = directory;
    return chunk4gb;
}

void paging_switch(uint32_t* directory)
{
    paging_load_directory(directory);
    current_directory = directory;
}

uint32_t* paging_4gb_chunk_get_directory(struct paging_4gb_chunk* chunk)
{
    return chunk->directory_entry;
}