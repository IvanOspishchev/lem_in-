#include "libft.h"

int				cnt_char(const char *s, char c)
{
	int			i;
	int			l;
	
	i = 0;
	l = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			l++;
		i++;
	}
	return (l);
}
