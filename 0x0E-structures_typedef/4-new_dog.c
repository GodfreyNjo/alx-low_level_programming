#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog and stores copies of name and owner.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: A pointer to the new dog, or NULL on failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;
	char *nameCopy, *ownerCopy;

	if (name == NULL || owner == NULL)
		return (0);

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
		return (0);

	nameCopy = strdup(name);
	ownerCopy = strdup(owner);

	if (nameCopy == NULL || ownerCopy == NULL)
	{
		free(newDog);
		free(nameCopy);
		free(ownerCopy);
		return (0);
	}

	newDog->name = nameCopy;
	newDog->age = age;
	newDog->owner = ownerCopy;

	return (newDog);
}

