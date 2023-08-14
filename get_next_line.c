#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#define BUFFER_SIZE 42
#include "get_next_line.h"

int main(int argc, char **argv)
{
    char *line = "";
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);
    int fd3 = open(argv[3], O_RDONLY);
    line = get_next_line(fd1);
    printf("fd1: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd3);
    printf("fd3: [%s\n", line);
    line = get_next_line(fd1);
    printf("fd1: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd3);
    printf("fd3: [%s\n", line);
    line = get_next_line(fd1);
    printf("fd1: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd3);
    printf("fd3: [%s\n", line);
    line = get_next_line(fd1);
    printf("fd1: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd3);
    printf("fd3: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
    line = get_next_line(fd2);
    printf("fd2: [%s\n", line);
}

char *real_line(char *line, char *line_buf)
{
    int i = 0;
    char *str;

    if (!line_buf)
        return NULL;
    while (line_buf[i] != '\0' && line_buf[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 2));
    if (!line)
        return NULL;
    i = 0;
    while (line_buf[i] != '\0' && line_buf[i] != '\n')
    {
        line[i] = line_buf[i];
        i++;
    }
    if (line_buf[i] == '\n')
    {
        line[i] = line_buf[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

void read_file(int fd, char **line_fd)
{
    int readed = 1;
    char *str;
    char *buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));

    if (!buf)
        return ;
    while (!found_char(*line_fd, '\n') && readed != 0)
    {
        readed = read(fd, buf, BUFFER_SIZE);
        if (readed == -1)
        {
            free(buf);
            return ;
        }
        buf[readed] = '\0';
        str = ft_strjoin(*line_fd, buf);
        free(*line_fd);
        *line_fd = str;
    }
    free(buf);
    return;
}

void clean_line_buf(char **line_buf)
{
    int i = 0;
    int j = 0;
    char *str;

    while (line_buf[0][i] != '\0' && line_buf[0][i] != '\n')
        i++;
    if (line_buf[0][i] == '\0')
    {
        line_buf[0] = NULL;
        return ;
    }
    str = malloc(sizeof(char) * (ft_strlen(line_buf[0]) - i + 1));
    if (!str)
        return ;
    i++;
    while (line_buf[0][i] != '\0')
    {
        str[j] = line_buf[0][i];
        j++;
        i++;
    }
    str[j] = '\0';
    free(line_buf[0]);
    line_buf[0] = str;
    return;
}

char *get_next_line(int fd)
{
    static char *line_buf[10240];
    char *line;

    read_file(fd, &(line_buf[fd]));
    if (!line_buf[fd])
        return (NULL);
    line = real_line(line, line_buf[fd]);
    clean_line_buf(&(line_buf[fd]));
    return (line);
}