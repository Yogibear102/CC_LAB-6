#include <stdio.h>
#include <unistd.h>

int main()
{
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));
    printf("Served by backend: %s\n", hostname);
    return 0;
}