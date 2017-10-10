#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P,List L);
Position Find(int X,List L);
void Delete(int X,List L);
Position FindPrevious(int X,List L);
void Insert(int X,List L);
void InsertPos(int num,List P,List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
Position InvertList(List L);
int Retrieve(Position P);
struct Node
{
    int num;
    char name[10];
    char address[50];
    int PosNum;
    Position Next;

};
#endif // LIST_H_INCLUDED
