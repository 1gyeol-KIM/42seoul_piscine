#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max);

int		main()
{
	int		min = 0;
	int 	max = 0;
	int *result;
	int range = ft_ultimate_range(&result, min, max);
	printf("%d\n", range);
	for (int i=0; i < max - min; i++)
		printf("%d ", result[i]);
	printf("\n");
	return 0;
}
