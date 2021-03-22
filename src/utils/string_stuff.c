/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-mydefender-florian.gibault
** File description:
** string_stuff
*/

#include "my_defender.h"

char *str_add(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *str_result = malloc(sizeof(char) * (len1 + len2 + 1));
    int i = 0;

    for (; i < len1; i++) {
        str_result[i] = str1[i];
    }
    for (int j = 0; j < len2; i++, j++) {
        str_result[i] = str2[j];
    }
    str_result[i] = 0;
    return str_result;
}

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (s2[i] - s1[i]);
        }
    }
    return 0;
}

char *str_truncate(char *str, int nbr)
{
    char *temp = str;
    if (my_strlen(temp) < nbr) {
        return temp;
    } else {
        temp[32] = '.';
        temp[33] = '.';
        temp[34] = '.';
        temp[35] = '\0';
    }
    return temp;
}

char *my_strdup(char *src)
{
    char *str = malloc((my_strlen(src) + 1) * sizeof(char));
    int k;

    for (k = 0; src[k] != '\0'; ++k)
        str[k] = src[k];
    str[k] = '\0';
    return (str);
}

char *char_to_str(char c)
{
    char *res = malloc(sizeof(char) * 2);

    res[0] = c;
    res[1] = 0;
    return (res);
}