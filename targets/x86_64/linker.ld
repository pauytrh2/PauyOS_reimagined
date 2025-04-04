/* linker.ld */

ENTRY(start)

SECTIONS
{
	. = 0x100000;

	.boot :
	{
		KEEP(*(.multiboot2_header))
	}

	.text :
	{
		*(.text)
	}
}