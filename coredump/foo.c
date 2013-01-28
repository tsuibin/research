#include <stdio.h>
static void sub(void);
int main(void)
{
     sub();
     return 0;
}
static void sub(void)
{
     int *p = NULL;
     /* derefernce a null pointer, expect core dump. */
     printf("%d", *p);
}
