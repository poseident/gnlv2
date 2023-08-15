/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <bschweit@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:48:34 by bschweit          #+#    #+#             */
/*   Updated: 2023/08/15 20:54:48 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
//# include "get_next_line_utils.c"

char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(int fd, char *line_fd);
int		found_char(char *str, char c);
char	*clean_line_buf(char *line_buf);
char	*real_line(char *line_buf);

#endif