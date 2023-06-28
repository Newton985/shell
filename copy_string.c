#include "shell.h"


char *string_copy(char *dest, const char *src)
{
    int i = 0;

    if (dest == src || src == NULL)
        return dest;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}


char *string_duplicate(const char *str)
{
    int length = 0;
    char *ret;

    if (str == NULL)
        return NULL;

    while (str[length] != '\0')
        length++;

    ret = malloc(sizeof(char) * (length + 1));

    if (!ret)
        return NULL;

    for (int i = 0; i <= length; i++)
        ret[i] = str[i];

    return ret;
}


void print_string(const char *str)
{
    if (str == NULL)
        return;

    int i = 0;

    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
}


int write_character(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;

    return 1;
}