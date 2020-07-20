#include <stdio.h>

char **ft_split(char *str, char *charset);

int		main()
{
	char str[500] = "+a+b+c--qwe+++d";
	char charset[500] = "+-";
	char **result = ft_split(str, charset);
	printf("%s\n%s\n----------------\n", str, charset);
	for (int i = 0; result[i]; i++)
		printf("%s\n", result[i]);

	return (0);
}
