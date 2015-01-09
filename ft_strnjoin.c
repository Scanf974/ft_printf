#include "ft_printf.h"

static char	*ft_strncat_p(char *s1, const char *s2, int len, int len_all)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}

static char	*ft_strncpy_p(char *dst, const char *src, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strnjoin(char const *s1, char const *s2, int len)
{
	int		len_src;
	char	*dst;

	if (s1 && s2)
	{
		len_src = len - ft_strlen(s2);
		if (ft_strlen(s2) == 0)
			len_src--;
		dst = ft_memalloc(len + 1);
		if (dst)
		{
			dst = ft_strncpy_p(dst, s1, len_src);
			dst = ft_strncat_p(dst, s2, len_src, len);
			return (dst);
		}
	}
	return (NULL);
}
