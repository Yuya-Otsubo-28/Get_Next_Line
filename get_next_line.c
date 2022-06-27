/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:36:08 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/27 13:12:40 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

#define NUM_OF_FD 256
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

void    free_all(char *line, char *store)
{
    if (!store)
        free(store);
    if (!line)
        free(line);
}

char    *read_and_store(int fd)
{
    char    *line;
    static char    *store;
    char    tmp[BUFFER_SIZE + 1];
    ssize_t read_size;

    line = NULL;
    ft_memset(tmp, '\0', BUFFER_SIZE);
    if (store != NULL)
    {
        line = strcjoin(line, store, '\n');
		free(store);
        if (!line)
        {
            free_all(line, store);
            return (NULL);
        }
    }
    read_size = BUFFER_SIZE;
    while ((read_size == BUFFER_SIZE) && !ft_strchr(line, '\n'))
    {
        read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free_all(line, store);
			return (NULL);
		}
		if (read_size == 0 && !line)
			return (NULL);
        tmp[read_size] = '\0';
        line = strcjoin(line, tmp, '\n');
        if (!line)
        {
            free_all(line, store);
            return (NULL);
        }
    }
    if (read_size < BUFFER_SIZE && !ft_strchr(line, '\n'))
        store = NULL;
    else if (tmp[0] && ft_strchr(tmp, '\n'))
    {
        store = ft_strdup(ft_strchr(tmp, '\n') + 1);
    }
    else if (read_size > 0)
    {
        store = ft_strdup(ft_strchr(store, '\n') + 1);
    }
    if (!store && !line)
    {
        free_all(line, store);
        return (NULL);
    }
    return (line);
}

char *get_next_line(int fd)
{
    char    *res;

    if (fd < 0 || fd > NUM_OF_FD || BUFFER_SIZE <= 0)
        return (NULL);
    res = read_and_store(fd);
    if (!res)
        return (NULL);
    return (res);
}
/*
int main(void)
{
    char    *res;
    ssize_t fd;

    fd = open("test.txt", O_RDONLY);
    res = get_next_line(fd);
    printf("res1 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res2 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res3 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res4 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res5 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res6 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res7 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res8 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res9 : %s\n", res);
    printf("--------------------\n");
    res = get_next_line(fd);
    printf("res10 : %s\n", res);
    printf("--------------------\n");
    return (0);
}
*/
