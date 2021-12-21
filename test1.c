#include <stdio.h>

int main()
{
	char	*bytes;
	int		i;
    char    c;

	i = 7;
    c = '1';
    *bytes = 0;
	while (i >= 0)
	{
        if (1 & (c >> i))
        {
            printf("in if\n");
			*bytes = 1 & (*bytes >> i);
        }
		else
        {
            printf("in else\n");
			*bytes = 0 & (*bytes >> i);
        }
		i--;
	}
    printf("bytes %c\n", *bytes);
}
https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/