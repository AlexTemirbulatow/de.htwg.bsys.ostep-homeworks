#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Expected arguments: <Memory in MB> <Time in seconds>\n");
        exit(EXIT_FAILURE);
    }

    int bytes = atoi(argv[1]) * 1048576; // from megabytes to bytes
    int *arr = malloc(bytes);
    int length = bytes / sizeof(int);

    int secondsArg = atoi(argv[2]);
    time_t secondsBegin = time(NULL);
    time_t secondsEnd;

    bool finish = false;
    while (1)
    {
        int n = 0;
        for (int i = 0; i < length; i++)
        {

            secondsEnd = time(NULL);
            if ((secondsEnd - secondsBegin) >= secondsArg)
            {
                finish = true;
                break;
            }

            n += 1;
            arr[i] = n;
            printf("%p: %d\n", &arr[i], arr[i]);
        }

        if (finish)
        {
            break;
        }
    }

    printf("\nallocated memory: %d bytes / %s megabytes\n", bytes, argv[1]);
    printf("runtime: %d seconds\n", secondsArg);
    free(arr);
    return 0;
}


/*

-----------------------
|    FREE(1) FLAGS    |
-----------------------

-b, --bytes
        Display the amount of memory in bytes.

-k, --kibi
        Display the amount of memory in kibibytes.  This is the
        default.

-m, --mebi
        Display the amount of memory in mebibytes.

-g, --gibi
        Display the amount of memory in gibibytes.

--tebi Display the amount of memory in tebibytes.

--pebi Display the amount of memory in pebibytes.

--kilo Display the amount of memory in kilobytes. Implies --si.

--mega Display the amount of memory in megabytes. Implies --si.

--giga Display the amount of memory in gigabytes. Implies --si.

--tera Display the amount of memory in terabytes. Implies --si.

--peta Display the amount of memory in petabytes. Implies --si.

-h, --human
        Show all output fields automatically scaled to shortest
        three digit unit and display the units of print out.
        Following units are used.

        B = bytes
        Ki = kibibyte
        Mi = mebibyte
        Gi = gibibyte
        Ti = tebibyte
        Pi = pebibyte

        If unit is missing, and you have exbibyte of RAM or swap,
        the number is in tebibytes and columns might not be
        aligned with header.

-w, --wide
        Switch to the wide mode. The wide mode produces lines
        longer than 80 characters. In this mode buffers and cache
        are reported in two separate columns.

-c, --count count
        Display the result count times.  Requires the -s option.

-l, --lohi
        Show detailed low and high memory statistics.

-s, --seconds delay
        Continuously display the result delay  seconds apart.  You
        may actually specify any floating point number for delay
        using either . or , for decimal point.  usleep(3) is used
        for microsecond resolution delay times.

--si   Use kilo, mega, giga etc (power of 1000) instead of kibi,
        mebi, gibi (power of 1024).

-t, --total
        Display a line showing the column totals.

-v, --committed
        Display a line showing the memory commit limit and amount
        of committed/uncommitted memory. The total column on this
        line will display the memory commit limit.   This line is
        relevant if memory overcommit is disabled.

--help Print help.

-V, --version
        Display version information.
*/
