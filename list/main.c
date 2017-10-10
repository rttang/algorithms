#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    List L,P;
    int num,i,cnt;
    L= (PtrToNode)malloc(sizeof(struct Node));
    P=(PtrToNode)malloc(sizeof(struct Node));
    L->Next=(PtrToNode)malloc(sizeof(struct Node));
    L->PosNum=0;
    P=L->Next;
    for(i=0; i<6; i++)
    {
        printf("ÇëÊäÈë±àºÅ==>");
        scanf("%d",&P->num);
        printf("ÇëÊäÈë±àºÅ(%d)ÐÕÃû==>",P->num);
        scanf("%s",P->name);
        P->Next=(PtrToNode)malloc(sizeof(struct Node));
        if(!P->Next)
        {
            printf("ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
            exit(1);
        }
        P->Next->Next=NULL;
        P=P->Next;
    }
    printf("ÓÊ¼ÄÊý¾Ý£º\n");
    P=L->Next;
    for(i=0; i<6; i++)
    {

        printf("±àºÅ:%d\n",P->num);
        printf("ÐÕÃû£º%s\n",P->name);
        P=P->Next;
    }
  L = InvertList(L);
    P=L->Next;
    for(i=0; i<6; i++)
    {

        printf("±àºÅ:%d\n",P->num);
        printf("ÐÕÃû£º%s\n",P->name);
        P=P->Next;
    }
    //cnt=6;
    /* while(1)
    {
        P=(PtrToNode)malloc(sizeof(struct Node));
        printf("ÇëÊäÈëÒª²åÈëµÄÐÅÏ¢==>");
        printf("ÇëÊäÈë±àºÅ==>");
        scanf("%d",&P->num);
        printf("ÇëÊäÈë±àºÅ(%d)ÐÕÃû==>",P->num);
        scanf("%s",P->name);
        P->Next=(PtrToNode)malloc(sizeof(struct Node));
        scanf("%d",&num);
        if(num!=0)
        {

            InsertPos(num,P,L);
            cnt++;
            P=L->Next;
             P=Find(P->num,L);
             if(!P)
                 printf("Ã»ÓÐÕÒµ½\n");
             else
                 printf("ÐÕÃû£º%s\n",P->name);
             printf("cnt£º%d\n",cnt);
            for(i=0; i<cnt; i++)
            {

                printf("±àºÅ:%d\n",P->num);
                printf("ÐÕÃû£º%s\n",P->name);
                P=P->Next;
            }

        }
    }*/
    return 0;
}
int
IsEmpty(List L)
{
    return L->Next == NULL;
}
int
IsLast(Position P,List L)
{
    return P->Next == NULL;
}
Position
InvertList(List L)
{
    List mid,last;
    mid = NULL;

    while(L!=NULL)
    {
        last = mid;
        mid = L;
        L= L->Next;
        mid->Next=last;
    }
    return mid;
}
Position
Find(int X,List L)
{
    Position P;

    P = L->Next;
    while(P != NULL&&P->num != X)
        P= P->Next;
    return P;
}
int
PosNum(int X, List L)
{
    int j=1;
    Position P=L->Next;
    while(P!=NULL&&P->num!=X)
    {
        P=P->Next;
        j++;

    }
    if(P->num==X)
        return j;
    else return 0;
}
void
Delete(int X,List L)
{
    Position P,TmpCell;

    P=FindPrevious(X,L);
    if(!IsLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}
Position
FindPrevious(int X,List L)
{
    Position P;
    P=L;
    while(P->Next!=NULL&&P->Next->num!=X)
    {
        P = P->Next;
    }
    return P;
}

void
Insert(int X,List L)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell==NULL)
        printf("Out of space!!!");

    TmpCell->num = X;
    TmpCell->Next = L->Next;
    L->Next = TmpCell;
}
void InsertPos(int num,List P,List L)
{
    Position Tmp;

    Tmp=Find(num,L);
    P->Next=Tmp->Next;
    Tmp->Next=P;
}
void
DeleteList(List L)
{
    Position P,tmp;

    P=L->Next;
    L->Next=NULL;
    while(P!=NULL)
    {
        tmp=P->Next;
        free(P);
        P=tmp;
    }
}

