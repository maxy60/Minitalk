#include <stdio.h>

int main()
{
	char	bytes;
	int		i;
    char    c;

	i = 7;
    c = 'L';
    bytes = 0;
	while (i >= 0)
	{
        if (1 & (c >> i))
			bytes |= (1 << i--);
		else
			bytes |= (0 << i--);
	}
    printf("bytes = %c\n", bytes);
}
