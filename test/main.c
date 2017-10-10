#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strcpy_like(char *dst,const char *src);
char *(*strcpy_ptr)(char *dst,const char *src);
#define str_length 18
int main()
{

    char src[str_length] = "this is a string";
    char dst[str_length];

    strcpy_ptr=strcpy_like;
    strcpy_ptr =&strcpy_like;

    //(*strcpy_ptr)(dst,src);
    char *(*strcpies[3])(char*,const char*)={strcpy,strcpy,strcpy};
    strcpies[0](dst,src);
    printf("dst=%s\n",dst);
    return 0;
}
char *strcpy_like(char *dst,const char *src)
{

    return strcpy(dst,src);
}
