#include <stdio.h>

int main()
{
	int i;
	char c = '1';

	i = 7;
	while (i >= 0)
	{
		if (1 & (c >> i))
			printf("yo %d\n", i);
		else
			printf("hello %d\n", i);
		i--;
	}
}