
MEMORY
{
    flash (rx) : ORIGIN = 0x08000000, LENGTH = 128K
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}

ENTRY(Reset_Handler)

SECTIONS {
  .isr_vector : { LONG(ORIGIN(ram) + LENGTH(ram)) KEEP(*(.isr_vector)) }  > flash
  .text : {*(.text) *(.text.*) } > flash
  .bss : { *(.bss) *(.bss.*) } > ram
  .data : { *(.data) *(.data.*) } > ram AT > flash
  .rodata : { *(.rodata) *(.rodata.*) } > flash

  .shstrtab : { *(.shstrtab) }
  /DISCARD/ : {*(.ARM.exidx)}
}

bss_start = ADDR(.bss);
bss_end = bss_start + SIZEOF(.bss);

data_rom_start = LOADADDR(.data);
data_start = ADDR(.data);
data_end = data_start + SIZEOF(.data);

rom_data_start = LOADADDR(.data);

stack = ORIGIN(ram) + LENGTH(ram);

_start = ADDR(.text);