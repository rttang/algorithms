#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int swap(void *x,void *y,int size)
{
    void *tmp;
    if((tmp = malloc(size))==NULL)
        return -1;
    memcpy(tmp,x,size);
    memcpy(x,y,size);
    memcpy(y,tmp,size);
    free(tmp);

    return 0;
}
int main()
{
    int a=10,b=11,size;
    size= sizeof(a);
    swap(&a,&b,size);
    printf("%d\n",a);
    printf("%d\n",b);
    printf("Hello world!\n");
    return 0;
}
