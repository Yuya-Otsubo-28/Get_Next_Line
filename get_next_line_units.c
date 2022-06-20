#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
    if (!str)
    {
        return (0);
    }
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin_modified(char const *s1, char const *s2)
{
	char	*s12;
	size_t	total_size;
	int	i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s12 = (char *)malloc(sizeof (char) * total_size);
	if (!s12)
        return (NULL);
	if (s1)  
    {
        while (*s1 != '\0')
		    s12[i++] = *(s1++);
    }
    if (s2)
    {
	    while (*s2 != '\0')
	        s12[i++] = *(s2++);
    }
	s12[i] = '\0';
	return (s12);
}

char	*ft_strchr(const char *s, int	c)
{
	char	*p;

    if (s == NULL)
        return (NULL);
	p = (char *)s;
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}

int c_to_c_count(char const *s, char c)
{
    int count;

    count = 0;
    while (*s != c && *s != '\0')
    {
        s++;
        count++;
    }
    return (count);
}

void	*ft_memset(void	*s, int	c, size_t	n)
{
	unsigned char	*a;

    if (!s)
        return (NULL);
	a = (unsigned char *)s;
	while (n > 0)
	{
		*a = (unsigned char)c;
		a++;
		n--;
	}
	return (s);
}