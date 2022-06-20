#include"get_next_line.h"

#define BUFFER_SIZE
//hanger[fd]にfdのcursorを入れていく。

void    read_and_store(int fd, char **hanger)
{
    size_t read_size;
    int end_of_line;
    char *tmp;
    char *line;

    line = NULL;
    line = ft_strjoin
    read_size = BUFFER_SIZE;
    tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!tmp)
        return (NULL);
    while ((read_size == BUFFER_SIZE) && !ft_strchr(line, '\n'))
    {
        read_size = read(fd, tmp, BUFFER_SIZE);
        tmp[BUFFER_SIZE] = '\0';
        line = ft_strjoin_modified(line, tmp);
    }
    if (!line)
        return (NULL);
    end_of_line = c_to_c_count(line, '\n');
    line[end_of_line] = '\0';
    hanger[fd] = ft_strjoin_modified(hanger[fd], tmp);
    return (line);
}

char *get_next_line(int fd)
{
    static char **hanger;
    char    *res;
    int num_of_fd;

    if (fd < 0 || fd > num_of_fd || BUFFER_SIZE < 0)
        return (NULL);
    hanger = (char **)malloc(sizeof(char *) * num_of_fd);
    if (!hanger)
        return (NULL);
    res = read_and_store(fd, hanger);
    if (!res)
        return (NULL);
    res[ft_strlen(res) + 1] = '\0';
    res[ft_strlen(res) - 1] = '\n';
    return (res);
}