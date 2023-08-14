#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/resource.h>
# include <stdio.h>
# include <fcntl.h>
#include <string.h>

char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
void read_file(int fd, char **line_fd);
int found_char(char *str, char c);

#endif