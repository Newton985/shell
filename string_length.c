#include "shell.h"


int string_length(const char *str)
{
    int length = 0;

    if (!str)
        return 0;

    while (str[length] != '\0')
        length++;

    return length;
}


int string_compare(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }

    if (*str1 == *str2)
        return 0;
    else
        return (*str1 < *str2 ? -1 : 1);
}


char *starts_with(const char *haystack, const char *needle)
{
    while (*needle)
    {
        if (*needle != *haystack)
            return NULL;
        needle++;
        haystack++;
    }

    return (char *)haystack;
}


char *string_concatenate(char *dest, const char *src)
{
    char *result = dest;

    while (*dest)
        dest++;

    while (*src)
        *dest++ = *src++;

    *dest = '\0';

    return result;
}