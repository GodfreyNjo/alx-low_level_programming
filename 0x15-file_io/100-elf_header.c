#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

/**
 * print_elf_info - Display information from the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_info(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("\tMagic:\t\t");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("\tClass:\t\t%s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("\tData:\t\t%s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("\tVersion:\t%d (current)\n", header->e_ident[EI_VERSION]);
	printf("\tOS/ABI:\t%s\n", get_osabi(header->e_ident[EI_OSABI]));
	printf("\tABI Version:\t%d\n", header->e_ident[EI_ABIVERSION]);
	printf("\tType:\t\t%d (%s)\n", header->e_type, get_type(header->e_type));
	printf("\tEntry point address:\t0x%lx\n", header->e_entry);
}

const char *get_osabi(unsigned char osabi)
{
	switch (osabi)
	{
		case 0: return "UNIX - System V";
		case 1: return "HP-UX";
		case 2: return "NetBSD";
		case 3: return "Linux";
		case 6: return "Solaris";
		default: return "Unknown";
	}
}

const char *get_type(uint16_t type)
{
	switch (type)
	{
		case ET_NONE: return "None";
		case ET_REL: return "Relocatable file";
		case ET_EXEC: return "Executable file";
		case ET_DYN: return "Shared object file";
		case ET_CORE: return "Core file";
		default: return "Unknown";
	}
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 98;
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header) ||
			memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Not an ELF file.\n");
		close(fd);
		return 98;
	}

	print_elf_info(&header);

	close(fd);
	return 0;
}

