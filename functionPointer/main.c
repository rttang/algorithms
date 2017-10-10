#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpy_like(char *dst,const char *src);
typedef char *(*strcpy_funcptr)(char *,const char *);
strcpy_funcptr get_strcpy_ptr(void);

void do_strcpy(strcpy_funcptr some_strcpy,char *dst,const char *src)
{
    (*some_strcpy)(dst,src);
}

#define str_length 18
int main()
{
    char src[str_length] = "this is a string";
    char dst[str_length];

    strcpy_funcptr  strcpy_ptr;
    strcpy_ptr = get_strcpy_ptr();
    do_strcpy(strcpy_ptr,dst,src);
    printf("dst=%s\n",dst);
    return 0;
}
strcpy_funcptr get_strcpy_ptr(void)
{

    return &strcpy_like;
}
char *strcpy_like(char *dst,const char *src){
    return strcpy(dst,src);
}
