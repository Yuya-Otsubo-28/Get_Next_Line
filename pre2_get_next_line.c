#include"get_next_line.h"

#define BUFFER_SIZE 50

char    *read_file(int  fd)
{
    static char    *cursor;
    char    *tmp;
    char    *line;
    int read_size;
    int end_of_line;

    line = NULL;
    printf("line : %s\ncursor : %s\n", line, cursor);
    line = ft_strjoin_modified(line, cursor);
    printf("first line : %s\n", line);
//    printf("before : %s\n", line);
    if (cursor)
        free(cursor);
    printf("after free cursor : %s\n", cursor);
//    printf("line : %s\n", line);
    read_size = BUFFER_SIZE;
    if (!(tmp = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    while ((read_size == BUFFER_SIZE) && !(ft_strchr(line, '\n')))
    {
//        printf("a\n");
        read_size = read(fd, tmp, BUFFER_SIZE);
        tmp[read_size] = '\0';
        line = ft_strjoin_modified(line, tmp);
    }
//    printf("after : %s\n", line);
    if (!*line)
    {
//        printf("Hello\n");
        return (NULL);
    }
    end_of_line = c_to_c_count(line, '\n');
    line[end_of_line] = '\0';
    printf("line[end_of_line + 1] : %s\n", &line[end_of_line + 1]);
    cursor = ft_strjoin_modified(cursor, &line[end_of_line + 1]);
    printf("last cursor : %s\n", cursor);
    return (line);
}

char    *get_next_line(int fd)
{
    char    *line;
    int end_of_line;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    line = read_file(fd);
    if (!line)
        return (NULL);
    end_of_line = ft_strlen(line);
    line[end_of_line++] = '\n';
    line[end_of_line] = '\0';
    return (line);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
        printf("\nans : %s\n", line);
/*    line = get_next_line(fd);
    printf("\nans : %s\n", line);
    line = get_next_line(fd);
    printf("\nans : %s\n", line);
    line = get_next_line(fd);
    printf("\nans : %s\n", line);
    line = get_next_line(fd);
    printf("\nans : %s\n", line);*/
    close(fd);
    return (0);
}