#include "libft.h"
#include <stdlib.h>

static int	itobase_helper(char **result, int len, int negative)
{
	*result = malloc(len + negative + 1);
	if (!*result)
		return (0);
	(*result)[len + negative] = '\0';
	if (negative)
		**result = '-';
	return (1);
}

char	*ft_itobase(int64_t n, int base)
{
	int		negative;
	int		len;
	char	*result;

	if (base < 2)
		return ((char *)0);
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	len = ft_baselen(n, base);
	if (!itobase_helper(&result, len, negative))
		return ((char *)0);
	while (len-- > 0)
	{
		if (n % base > 9)
			result[len + negative] = n % base - 9 + 'a';
		else
			result[len + negative] = n % base + '0';
		n /= base;
	}
	return (result);
}
