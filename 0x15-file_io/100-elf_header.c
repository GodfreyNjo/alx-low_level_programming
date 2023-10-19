#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_elf_id_data - Outputs the ELF identification bytes.
 * @id_data: Pointer referencing the array with ELF identification bytes.
 */
void print_elf_id_data(unsigned char *id_data)
{
	int counter;

	printf("ELF ID Bytes:	");
	for (counter = 0; counter < EI_NIDENT; counter++)
	{
		printf("%02x ", id_data[counter]);
	}
	printf("\n");
}

/**
 * print_elf_format - Outputs the format of the ELF file.
 * @format_indicator: Byte indicating the ELF format.
 */
void print_elf_format(unsigned char format_indicator)
{
	printf("Format:				");
	switch (format_indicator)
	{
	case ELFCLASSNONE:
		printf("Undefined format\n");
		break;
	case ELFCLASS32:
		printf("32-bit format\n");
		break;
	case ELFCLASS64:
		printf("64-bit format\n");
		break;
	default:
		printf("Unrecognized format\n");
	}
}

/**
 * print_byte_order - Outputs the byte ordering used in the ELF file.
 * @order_type: Byte representing the data encoding.
 */
void print_byte_order(unsigned char order_type)
{
	printf("Byte Order:			");
	switch (order_type)
	{
	case ELFDATANONE:
		printf("Invalid encoding\n");
		break;
	case ELFDATA2LSB:
		printf("Little-endian\n");
		break;
	case ELFDATA2MSB:
		printf("Big-endian\n");
		break;
	default:
		printf("Unrecognized encoding\n");
	}
}

/**
 * print_file_version - Outputs the version of the ELF specification used.
 * @spec_version: Byte representing the version.
 */
void print_file_version(unsigned char spec_version)
{
	printf("Spec Version:			");
	if (spec_version == EV_CURRENT)
	{
		printf("Current standard version\n");
	}
	else
	{
		printf("Non-standard or outdated version\n");
	}
}

/**
 * verify_elf_status - Confirms if the file follows the ELF specification.
 * @header_info: Pointer to the ELF header structure.
 * @file_descriptor: File descriptor for the ELF file.
 * Return: 0 if specifications are met, 1 if they are not.
 */
int verify_elf_status(Elf64_Ehdr *header_info, int file_descriptor)
{
	if (header_info->e_ident[EI_MAG0] != ELFMAG0 ||
		header_info->e_ident[EI_MAG1] != ELFMAG1 ||
		header_info->e_ident[EI_MAG2] != ELFMAG2 ||
		header_info->e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "File does not conform to ELF specifications.\n");
		close(file_descriptor);
		return (1);
	}
	return (0);
}

/**
 * main - Primary function, reads an ELF file and outputs its header information.
 * @argc: Number of command line arguments.
 * @argv: Array containing the command line arguments.
 * Return: 0 upon successful execution, 1 upon failure.
 */
int main(int argc, char **argv)
{
	int file_descriptor;
	Elf64_Ehdr header_info;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_file_path\n", argv[0]);
		return (1);
	}

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		perror("Unable to access file");
		return (1);
	}

	if (read(file_descriptor, &header_info, sizeof(header_info)) != sizeof(header_info))
	{
		perror("Could not retrieve ELF header information");
		close(file_descriptor);
		return (1);
	}

	if (verify_elf_status(&header_info, file_descriptor))
	{
		return (1);
	}

	print_elf_id_data(header_info.e_ident);
	print_elf_format(header_info.e_ident[EI_CLASS]);
	print_byte_order(header_info.e_ident[EI_DATA]);
	print_file_version(header_info.e_ident[EI_VERSION]);

	if (close(file_descriptor) == -1)
	{
		perror("Error encountered while closing the file");
		return (1);
	}

	return (0);
}

