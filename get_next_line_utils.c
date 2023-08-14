#include "get_next_line.h"

int found_char(char *str, char c)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

size_t ft_strlen(char *tmp)
{
    size_t i = 0;

    if (!tmp)
        return (0);
    while (tmp[i] != '\0')
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i = 0;
    int j = 0;

    str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
    if (!str)
    {
        return NULL;
    }
    if (!s1)
    {
        s1 = malloc(sizeof(char) * ft_strlen(s2) + 1);
        strcpy(s1, s2);
        return s1;
    }
    if (!s1 || !s2)
    {
        s1 = NULL;
        return NULL;
    }
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
        str[i++] = s2[j++];
    str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    return (str);
}