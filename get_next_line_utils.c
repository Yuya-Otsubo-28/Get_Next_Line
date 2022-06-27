/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_units.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:09:31 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/26 13:09:31 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	s1_size;
	size_t	i;

	s1_size = strclen(s1, '\0') + 1;
	cpy = (char *)malloc(sizeof (char) * s1_size);
	if (cpy == NULL)
		return (0);
	i = 0;
	while (*s1 != '\0')
		cpy[i++] = *(s1++);
	cpy[i] = '\0';
	return (cpy);
}

size_t	strclen(const char *str, char c)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] != c && str[size] != '\0')
		size++;
	if (c != '\0' && str[size] == c)
		size++;
	return (size);
}

char	*strcjoin(char const *s1, char const *s2, char c)
{
	char	*s12;
	size_t	total_size;
	int	i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	total_size = strclen(s1, '\n') + strclen(s2, c) + 1;
	s12 = (char *)malloc(sizeof (char) * total_size);
	if (!s12)
        return (NULL);
    while (s1 && *s1 != '\0')
	    s12[i++] = *(s1++);
    while (s2 && *s2 != '\0')
	{
		s12[i++] = *s2;
		if (*s2 == c)
			break;
		s2++;
	}
	s12[i] = '\0';
	return (s12);
}

char	*ft_strchr(const char *s, int	c)
{
	char	*p;

    if (s == NULL)
	{
        return (NULL);
	}
	p = (char *)s;
	while (*p)
	{
		if (*p == c)
		{
			return (p);
		}
		p++;
	}
	return (NULL);
}

void	*ft_memset(void	*s, int	c, size_t	n)
{
	unsigned char	*a;

    if (!s)
	{
        return (NULL);
	}
	a = (unsigned char *)s;
	while (n > 0)
	{
		*a = (unsigned char)c;
		a++;
		n--;
	}
	return (s);
}