#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * display_elf_magic - prints the ELF magic numbers
 * @e_ident: Pointer to array containing ELF magic numbers
 */
void display_elf_magic(unsigned char *e_ident)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * display_elf_class - prints the ELF class
 * @elf_class: ELF class byte
 */
void display_elf_class(unsigned char elf_class)
{
	printf("Class:                             ");
	switch (elf_class)
	{
	case ELFCLASSNONE:
		printf("Invalid class\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Unknown\n");
	}
}

/**
 * display_data_encoding - prints the data encoding of the ELF file
 * @data_encoding: Data encoding byte
 */
void display_data_encoding(unsigned char data_encoding)
{
	printf("Data:                              ");
	switch (data_encoding)
	{
	case ELFDATANONE:
		printf("Invalid data encoding\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Unknown\n");
	}
}

/**
 * display_version - prints the version of the ELF file
 * @version: Version byte
 */
void display_version(unsigned char version)
{
	printf("Version:                           ");
	if (version == EV_CURRENT)
	{
		printf("1 (current)\n");
	}
	else
	{
		printf("Invalid version\n");
	}
}

/**
 * validate_elf_file - checks if the file is a valid ELF file
 * @header: Pointer to the ELF header structure
 * @fd: File descriptor of the ELF file
 * Return: 0 if valid, or 1 if invalid
 */
int validate_elf_file(Elf64_Ehdr *header, int fd)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
		header->e_ident[EI_MAG1] != ELFMAG1 ||
		header->e_ident[EI_MAG2] != ELFMAG2 ||
		header->e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file\n");
		close(fd);
		return (1);
	}
	return (0);
}

/**
 * main - Entry point, opens an ELF file and prints info from its header
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, or 1 on failure
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		close(fd);
		return (1);
	}

	if (validate_elf_file(&header, fd))
	{
		return (1);
	}

	display_elf_magic(header.e_ident);
	display_elf_class(header.e_ident[EI_CLASS]);
	display_data_encoding(header.e_ident[EI_DATA]);
	display_version(header.e_ident[EI_VERSION]);

	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (1);
	}

	return (0);
}

