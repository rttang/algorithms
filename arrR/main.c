#include <stdio.h>
#include <stdlib.h>
int list[6] = {1,2,3,4,5,6};
void invert_array(int j)
{
    if(j<6){
        invert_array(j+1);
        printf("[%d]",list[j]);
    }
}
int main()
{
    int i;

    printf("��������:\n");
    for(i=0;i<6;i++)
        printf("[%d]",list[i]);
    printf("\n");
    printf("�ݹ������������:\n");
    invert_array(0);
    printf("\n");
    return 0;
}
