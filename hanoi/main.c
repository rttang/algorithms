#include <stdio.h>
#include <stdlib.h>
int Count = 0;
void move(){
    Count++;
}
int hanoi(int num){
    if(num == 1){
        move();
    }
    else{
        hanoi(num-1);

        hanoi(num-1);
        move();
    }
}
int main()
{
    int num = 0;
    printf("input hanoi sum\n");
    scanf("%d",&num);
    hanoi(num);
    printf("result:%d",Count);
    return 0;
}
