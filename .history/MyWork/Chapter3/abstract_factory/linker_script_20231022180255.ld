/* Simple GNU Linker Script */

OUTPUT_FORMAT("elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)

ENTRY(main)

SECTIONS
{
    /* Read-only sections */
    . = 0x00400000;
    
    .text :
    {
        *(.text)
    }
    
    .rodata :
    {
        *(.rodata)
    }
    
    /* Read-write sections */
    .data :
    {
        *(.data)
    }
    
    .bss :
    {
        *(.bss)
    }
}
