#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/* betty style doc for function main goes there */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf("Last digit of %d is ", n);

  int last_digit = n % 10;

  if (last_digit > 5) 
  {
    printf("and is greater than 5\n");
  } else if (last_digit == 0)
  {
    printf("and is 0\n");
  } else 
  {
    printf("and is less than 6 and not 0\n");
  }

  return (0);
}
