#include "main.h"                                                                                                                  
#include <unistd.h>                                                                                                                     
                                                                                                                                        
/**                                                                                                                                     
 * _putchar - will write the character c to stdout                                                                                          
 * @c: The character to print                                                                                                           
 *                                                                                                                                      
 * Return: (succes)s 1.                                                                                                                
 * On error, -1 is returned.errno is set appropriately.                                                                            
 */                                                                                                                                     
int _putchar(char c)                                                                                                                    
{                                                                                                                                       
        return (write(1, &c, 1));                                                                                                       
}

