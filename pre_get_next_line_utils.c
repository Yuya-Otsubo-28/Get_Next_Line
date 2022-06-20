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

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s12 = (char *)malloc(sizeof (char) * total_size);
	if (s1)  
    {
        while (*s1 != '\0')
	    {
		    s12[i] = *s1;
		    s1++;
		    i++;
	    }
    }
	while (*s2 != '\0')
	{
	    s12[i] = *s2;
	    s2++;
	    i++;
    }
	s12[i] = '\0';
	return (s12);
}

int count_c(char const *s, char c)
{
    int count;
    char    *tmp;

    count = 0;
    tmp = (char *)s;
    while (*tmp)
    {
        if (*(tmp++) == c)
            count++;
    }
    return (count);
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

char    *c_to_c_modified(char const *s, char c)
{
    static char *cursor;
    char    *part;
    int index;

    index = 0;
    if (!(part = (char *)malloc(sizeof(char) * c_to_c_count(s, c) + 2)))
        return (NULL);
    if (!cursor)
        cursor = (char *)s;
    while (*cursor != c && *cursor != '\0')
    {
        part[index] = *cursor;
        index++;
        cursor++;
    }
    part[index++] = c;
	part[index] = '\0';
    if (*cursor == c)
        cursor++;
    return (part);
}

char	*ft_strchr(const char *s, int	c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}