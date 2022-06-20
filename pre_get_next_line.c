#include"get_next_line.h"

#define BUFFER_SIZE 20

void    free_all(char   **hanger, int   lines)
{
    int i;

    i = 0;
    while (i <= lines)
        free(hanger[i++]);
    free(hanger);
}

char    *get_all(char *all, int  fd)
{
    int read_size;
    int total_size;
    char    *tmp;

    total_size = 0;
    all = NULL;
    read_size = BUFFER_SIZE;
    if (!(tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (NULL);
    while(read_size == BUFFER_SIZE)
    {
        read_size = read(fd, tmp, BUFFER_SIZE);
        tmp[BUFFER_SIZE] = '\0';
        all = ft_strjoin_modified(all, tmp);
        total_size += read_size;
    }
    all[total_size] = '\0';
    return (all);
}

char    *get_next_line(int  fd)
{
    static  int index;
    static  char    **hanger;
    static  int lines = 1;
    char    *all;
    int i;

    i = 0;
    all = NULL;
    if (fd < 0 || BUFFER_SIZE < 0 || index + 1 > lines)
    {
        free_all(hanger, lines);
        free(all);
        return (NULL);
    }
    if (!hanger)
    {
        all = get_all(all, fd);
        lines = count_c(all, '\n') + 1;
        if (!(hanger = (char**)malloc(sizeof(char*) * (lines + 1))))
            return (NULL);
        while (i < lines)
            hanger[i++] = c_to_c_modified(all, '\n');
        hanger[i] = '\0';
    }
    return (hanger[index++]);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while (line = get_next_line(fd))
        printf("%s", line);
    close(fd);
    return (0);
}