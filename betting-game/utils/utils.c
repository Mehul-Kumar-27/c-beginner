#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include "utils.h"

void removeNewLine(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

Error safe_strncpy(char *dest, const char *src, size_t max_len)
{
    Error error;
    if (max_len == 0)
    {
        error.status = 1;
        strcpy(error.message, "error: no space for copy");
        return error;
    }

    size_t src_len = strlen(src);
    size_t copy_len = (src_len < max_len) ? src_len : max_len -1;
    strncpy(dest, src, copy_len);
    dest[copy_len] = '\0';

    return error;
}
