#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

char    *read_file(int  fd);

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strjoin_modified(char const *s1, char const *s2);

int c_to_c_count(char const *s, char c);

char	*ft_strchr(const char *s, int	c);

void	*ft_memset(void	*s, int	c, size_t	n);

#endif