/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:36:08 by yotsubo           #+#    #+#             */
/*   Updated: 2022/06/26 12:36:08 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

#define NUM_OF_FD 256
//hanger[fd]にfdのcursorを入れていく。

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
        printf("prestore: %s\n", store);
        line = strcjoin(line, store, '\n');
        if (!line)
            return (NULL);
    }
    read_size = BUFFER_SIZE;
    while ((read_size == BUFFER_SIZE) && !ft_strchr(line, '\n'))
    {
        read_size = read(fd, tmp, BUFFER_SIZE);
        tmp[read_size] = '\0';
        printf("tmp : %s\n", tmp);
        line = strcjoin(line, tmp, '\n');
        printf("line : %s\n", line);
        if (!line)
            return (NULL);
    }
    printf("tmp[0] : %c\n", tmp[0]);
    if (read_size < BUFFER_SIZE && !ft_strchr(line, '\n'))
        store = NULL;
    else if (tmp[0] && ft_strchr(tmp, '\n'))
    {
        printf("hello\n");
        store = ft_strdup(ft_strchr(tmp, '\n') + 1);
    }
    else if (read_size > 0)
    {
        printf("store : %s\n", store);
        store = ft_strdup(ft_strchr(store, '\n') + 1);
    }
    printf("store : %s\n", store);
    if (!store && !line)
        return (NULL);
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