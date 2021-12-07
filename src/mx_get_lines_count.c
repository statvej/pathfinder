#include "libmx.h"
#include "patfinder.h"
#include <stdio.h>
int mx_get_lines_count(char **text)
{
    if (!text)
    {
        return 0;
    }
    int count = 0;
    for (; text[count] != NULL; count++)
    {
    }
    return count;
}
