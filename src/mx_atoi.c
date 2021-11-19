#include <stdbool.h>
#include "../libmx/inc/libmx.h"
#include "../inc/patfinder.h"

int mx_atoi(const char *str)
{
    if (!str)
        return 0;

    char *temp = mx_unconstchar(str);
    int res = 0;
    int count = mx_strlen(temp);
    for (int i = 0; i <= count && mx_isdigit(str[i]); i++)
    {
        res = res*10 +(str[i] - 48);
        
    }

    return res;
}

