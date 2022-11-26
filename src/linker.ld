ENTRY(_START)
OUTPUT_FORMAT(binary)
SECTIONS
{
    . = 1M; /* Kernel will be loaded 1 megabyte into memory - at address 0x100000 */
    .text : ALIGN(4096)
    {
        *(.text)
    }
    .rodata : ALIGN(4096)
    {
        *(.rodata)
    }
    .data : ALIGN(4096)
    {
        *(.data)
    }
    .bss : ALIGN(4096)
    {
        *(COMMON)
        *(.bss)
    }

    .asm : ALIGN(4096)
    {
        *(.asm)
    }
}