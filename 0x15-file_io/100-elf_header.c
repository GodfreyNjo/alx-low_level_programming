#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * checkElfFile - Checks if the file is an ELF file.
 * @eIdent: Pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exit with status code 98.
 */
void checkElfFile(unsigned char *eIdent);

/**
 * printMagicNumbers - Prints ELF header magic numbers.
 * @eIdent: Pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printMagicNumbers(unsigned char *eIdent);

/**
 * printElfClass - Prints ELF header class.
 * @eIdent: Pointer to an array containing the ELF class.
 */
void printElfClass(unsigned char *eIdent);

/**
 * printElfData - Prints ELF header data.
 * @eIdent: Pointer to an array containing the ELF class.
 */
void printElfData(unsigned char *eIdent);

/**
 * printElfVersion - Prints ELF header version.
 * @eIdent: Pointer to an array containing the ELF version.
 */
void printElfVersion(unsigned char *eIdent);

/**
 * printElfOsAbi - Prints ELF header OS/ABI.
 * @eIdent: Pointer to an array containing the ELF version.
 */
void printElfOsAbi(unsigned char *eIdent);

/**
 * printElfAbi - Prints ELF header ABI version.
 * @eIdent: Pointer to an array containing the ELF ABI version.
 */
void printElfAbi(unsigned char *eIdent);

/**
 * printElfType - Prints ELF header type.
 * @eType: The ELF type.
 * @eIdent: Pointer to an array containing the ELF class.
 */
void printElfType(unsigned int eType, unsigned char *eIdent);

/**
 * printElfEntry - Prints ELF header entry pointer.
 * @eEntry: The address of the ELF entry point.
 * @eIdent: Pointer to an array containing the ELF class.
 */
void printElfEntry(unsigned long int eEntry, unsigned char *eIdent);

/**
 * closeElfFile - Closes an ELF file.
 * @elf: The ELF file descriptor.
 *
 * Description: If the file cannot be closed, exit with status code 98.
 */
void closeElfFile(int elf);

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: Number of arguments.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0.
 *
 * Description: If the file is not an ELF File or
 *              the function fails, exit with status code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDescriptor, bytesRead;

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr);
	if (header == NULL)
	{
		closeElfFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Memory allocation failure\n");
		exit(98);
	}

	bytesRead = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (bytesRead == -1)
	{
		free(header);
		closeElfFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkElfFile(header->eIdent);
	printf("ELF Header:\n");
	printMagicNumbers(header->eIdent);
	printElfClass(header->eIdent);
	printElfData(header->eIdent);
	printElfVersion(header->eIdent);
	printElfOsAbi(header->eIdent);
	printElfAbi(header->eIdent);
	printElfType(header->eType, header->eIdent);
	printElfEntry(header->eEntry, header->eIdent);

	free(header);
	closeElfFile(fileDescriptor);

	return (0);
}

