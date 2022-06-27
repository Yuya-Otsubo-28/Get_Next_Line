#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

char	*ft_strdup(const char *s1);

size_t	strclen(const char *str, char c);

char	*strcjoin(char *s1, char const *s2, char c);

char	*ft_strchr(const char *s, int	c);

void	*ft_memset(void	*s, int	c, size_t	n);

char    *read_and_store(int fd);

char *get_next_line(int fd);

#endif
