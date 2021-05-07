//Queue Start

//Header
#ifndef __my_Deque_h__
#define __my_Deque_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct Deque Deque;
typedef Deque *PtrToDeque;
typedef double ElementType;
struct Deque
{

    ElementType x;
    // ElementType y;
    Deque *NextElement;
    Deque *PreviousElement;
    Deque *FirstElement;
    Deque *LastElement;
};

PtrToDeque MakeNode(ElementType x);
void CreateEmptyDeque(PtrToDeque *S);
void push(PtrToDeque *S, ElementType x);
void pop(PtrToDeque *S, ElementType *x);
void eject(PtrToDeque *S, ElementType *x);
void exitFunc(PtrToDeque S);
void PrintDeque(PtrToDeque S);
void inject(PtrToDeque *S, ElementType x);

PtrToDeque * Find(PtrToDeque *S, ElementType F);
void Delete(PtrToDeque *S,ElementType F);

#endif
//Header END

#include <assert.h>

PtrToDeque MakeNode(ElementType x)
{
    PtrToDeque P = (PtrToDeque)malloc(sizeof(Deque));
    assert(P != NULL);

    P->x = x;

    P->NextElement = NULL;

    return P;
}
PtrToDeque * Find(PtrToDeque *S, ElementType F)
{
    PtrToDeque * Node=S;

    while((*S) != (*S)->LastElement->PreviousElement)
    {
        if((*Node)->x==F)
        {
            return Node;
        }
        (*Node)=(*Node)->NextElement;
    }

    return NULL;
}
void Delete(PtrToDeque *S,ElementType F)
{
    PtrToDeque*  NodePosition = Find(S,F);
    if(!(*NodePosition))
    {
        printf("Delete Failed: Does not exist.");
    }
    else
    {
        (*NodePosition)->PreviousElement->NextElement=(*NodePosition)->NextElement;
        (*NodePosition)->NextElement->PreviousElement=(*NodePosition)->PreviousElement;
        free(NodePosition);
    }
}
void CreateEmptyDeque(PtrToDeque *S)
{
    PtrToDeque SS = MakeNode(0.0);
    *S = SS;
    (*S)->NextElement = MakeNode(0.0);
    (*S)->FirstElement = (*S);
    (*S)->LastElement = (*S)->NextElement;
    (*S)->NextElement->PreviousElement = (*S);
    (*S)->PreviousElement = NULL;
    (*S)->LastElement->NextElement=NULL;
}
void push(PtrToDeque *S, ElementType x)
{
    PtrToDeque PNew = MakeNode(x);

    PtrToDeque L = *S;
    PNew->x = x;
    //PNew->y=y;
    PNew->NextElement = L->FirstElement->NextElement;
    PNew->PreviousElement = L->FirstElement;
    PNew->FirstElement = L->FirstElement;
    PNew->LastElement = L->LastElement;
    L->FirstElement->NextElement->PreviousElement = PNew;
    L->FirstElement->NextElement = PNew;
}
void inject(PtrToDeque *S, ElementType x)
{
    PtrToDeque PNew = MakeNode(x);

    PtrToDeque L = *S;
    PNew->x = x;
    // PNew->y=y;
    PNew->NextElement = L->LastElement;
    PNew->PreviousElement = L->LastElement->PreviousElement;
    PNew->FirstElement = L->FirstElement;
    PNew->LastElement = L->LastElement;
    L->LastElement->PreviousElement->NextElement = PNew;
    L->LastElement->PreviousElement = PNew;
}
void pop(PtrToDeque *S, ElementType *x)
{
    if (((*S)->FirstElement->NextElement->x == 0.0) && (((*S)->FirstElement->NextElement->NextElement == NULL))) //&& (S->FirstElement->NextElement->y == 0.0)
    {
        printf("There is nothing to pop! Deque is empty!");
        printf("\n Input your Command :- (exit kills the loop)\n");
    }
    else
    {
        *x = (*S)->FirstElement->NextElement->x;
        //*y = (*S)->FirstElement->NextElement->y;
        PtrToDeque Temp2 = (*S)->FirstElement->NextElement;
        (*S)->FirstElement->NextElement = (*S)->FirstElement->NextElement->NextElement;
        (*S)->FirstElement->NextElement->PreviousElement = (*S);
        free(Temp2);
    }
}
void eject(PtrToDeque *S, ElementType *x) //, ElementType *y
{
    if (((*S)->LastElement->PreviousElement->x == 0.0) && (((*S)->LastElement->PreviousElement->PreviousElement == NULL))) //&& (S->LastElement->PreviousElement->y == 0.0)
    {
        printf("There is nothing to eject! Deque is empty!");
        printf("\n Input your Command :- (exit kills the loop)\n");
    }
    else
    {
        *x = (*S)->LastElement->PreviousElement->x;
        //*y = (*S)->LastElement->PreviousElement->y;
        PtrToDeque Temp2 = (*S)->LastElement->PreviousElement;
        (*S)->LastElement->PreviousElement = (*S)->LastElement->PreviousElement->PreviousElement;
        (*S)->LastElement->PreviousElement->NextElement = (*S);
        free(Temp2);
    }
}
void exitFunc(PtrToDeque S)
{
    PtrToDeque temp2 = S;
    while (S->NextElement != NULL)
    {
        PtrToDeque temp = S->NextElement;
        S = S->NextElement;
        free(temp);
    }
    free(temp2);
}
void PrintDeque(PtrToDeque S)
{
    printf("\nThe Current Deque is:-\n");

    while (S != S->LastElement->PreviousElement)
    {
        printf(" {%lf} ", S->NextElement->x); //+ %lf i ,S->NextElement->y

        S = S->NextElement;
        /* code */
    }
    puts(" ");
}

//Queue END