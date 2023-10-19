#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * checkElf - Checks if the file is a valid ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Exits with status code 98 if the file is not a valid ELF file.
 */
void checkElf(unsigned char *e_ident)
{
	for (int index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 && e_ident[index] != 'E' &&
			e_ident[index] != 'L' && e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagic - Prints the magic numbers from the ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void printMagic(unsigned char *e_ident)
{
	printf(" Magic:");
	for (int index = 0; index < EI_NIDENT; index++)
	{
		printf(" %02x", e_ident[index]);
	}
	printf("\n");
}

/**
 * printClass - Prints the ELF class from the ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printClass(unsigned char *e_ident)
{
	printf(" Class:");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf(" none\n");
			break;
		case ELFCLASS32:
			printf(" ELF32\n");
			break;
		case ELFCLASS64:
			printf(" ELF64\n");
			break;
		default:
			printf(" <unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printData - Prints the data format from the ELF header.
 * @e_ident: A pointer to an array containing the data format.
 */
void printData(unsigned char *e_ident)
{
	printf(" Data:");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf(" none\n");
			break;
		case ELFDATA2LSB:
			printf(" 2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf(" 2's complement, big endian\n");
			break;
		default:
			printf(" <unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * printVersion - Prints the ELF version from the ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void printVersion(unsigned char *e_ident)
{
	printf(" Version: %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * printAbi - Prints the OS/ABI from the ELF header.
 * @e_ident: A pointer to an array containing the OS/ABI.
 */
void printAbi(unsigned char *e_ident)
{
	printf(" OS/ABI:");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf(" UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf(" UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf(" UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf(" UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf(" UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf(" UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf(" UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf(" UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf(" ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf(" Standalone App\n");
			break;
		default:
			printf(" <unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printType - Prints the ELF type from the ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printType(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type:");
	switch (e_type)
	{
		case ET_NONE:
			printf(" NONE (None)\n");
			break;
		case ET_REL:
			printf(" REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf(" EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf(" DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf(" CORE (Core file)\n");
			break;
		default:
			printf(" <unknown: %x>\n", e_type);
	}
}

/**
 * printEntry - Prints the entry point address from the ELF header.
 * @e_entry: The entry point address.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printEntry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0x00FF00FF);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("0x%x\n", (unsigned int)e_entry);
	else
		printf("0x%lx\n", e_entry);
}

/**
 * closeElf - Closes the ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: Exits with status code 98 if the file cannot be closed.
 */
void closeElf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		exit(98);
	}
}

/**
 * main - Displays information from the ELF header of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with status code 98 on error or if the file is not an ELF file.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr elfHeader;
	unsigned char *elfIdent = elfHeader.e_ident;
	int fileDescriptor, readResult;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	readResult = read(fileDescriptor, &elfHeader, sizeof(Elf64_Ehdr));
	if (readResult == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	checkElf(elfIdent);
	printf("ELF Header:\n");
	printMagic(elfIdent);
	printClass(elfIdent);
	printData(elfIdent);
	printVersion(elfIdent);
	printAbi(elfIdent);
	printType(elfHeader.e_type, elfIdent);
	printEntry(elfHeader.e_entry, elfIdent);
	closeElf(fileDescriptor);

	return (0);
}

