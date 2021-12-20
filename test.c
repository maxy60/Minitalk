#include <stdio.h>

int main()
{
	int i;
	char c = '1';

	i = 0;
	while (i < 8)
	{
		if (c & (2 << i++))
			printf("test   %d  \n", i);
		printf("je suis rentre   %d  \n", i);
	}
}
http://www.bien-programmer.fr/bits.htm