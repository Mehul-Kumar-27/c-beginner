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

Error safe_strncpy(char *dest, const char *src, size_t max_len) {
    Error error = {0, ""}; // Initialize the struct to avoid undefined behavior

    if (max_len == 0) {
        error.status = 1;
        strncpy(error.message, "error: no space for copy", sizeof(error.message) - 1);
        error.message[sizeof(error.message) - 1] = '\0'; // Ensure null termination
        return error;
    }

    size_t src_len = strlen(src);
    size_t copy_len = (src_len < max_len - 1) ? src_len : max_len - 1;
    strncpy(dest, src, copy_len);
    dest[copy_len] = '\0'; // Ensure null termination

    return error; // Returns success (error.status == 0)
}

/// @brief handleNumberInput would take in the number value in the string format and then assign it to destination
/// @param args An array of arguments:
///             args[0] = input (string form of the number)
///             args[1] = destination (pointer to int where the result will be stored)
///             args[2] = min (optional, minimum value)
///             args[3] = max (optional, maximum value)
/// @return Error type error status is 0 if copy process is successful
Error handleNumberInput(void *args[])
{
    Error error;

    // Extract arguments from the array
    char *input = (char *)args[0];
    int *destination = (int *)args[1];
    int min = (args[2] != NULL) ? *((int *)args[2]) : INT_MIN; // Default to INT_MIN if not provided
    int max = (args[3] != NULL) ? *((int *)args[3]) : INT_MAX; // Default to INT_MAX if not provided

    // Checking if the input is empty
    if (input == NULL)
    {
        safe_strncpy(error.message, "error: input provided is NULL!", sizeof(error.message) - 1);
        error.status = 1;
        return error;
    }

    int value;
    if (sscanf(input, "%d", &value) != 1)
    {
        safe_strncpy(error.message, "error: invalid number provided!", sizeof(error.message) - 1);
        error.status = 1;
        return error;
    }

    // Skip bounds check if min and max are set to INT_MIN and INT_MAX respectively
    if ((min != INT_MIN && value < min) || (max != INT_MAX && value > max))
    {
        safe_strncpy(error.message, "error: out of bound value provided", sizeof(error.message) - 1);
        error.status = 1;
        return error;
    }

    *destination = value;
    safe_strncpy(error.message, "success", sizeof(error.message) - 1);
    error.status = 0;
    return error;
}
