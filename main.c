#include "ft_printf.h"
#include <stdio.h>
#define TST "%*.*s  %% %15c yujk %% %18p %% |%018.x|%%%%%%%% %18.15X  %% |%012d| hgjgh %% %-32u  %% |%015.*i|\n",8,5,NULL, 'j', NULL, 0,45, -1,22554478,-2,INT32_MIN

int	main()
{
	printf("|%d|\n", ft_printf(TST));
	printf("|%d|\n", printf(TST));

	return (0);
}
