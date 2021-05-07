#ifndef __my_Deque_c__
#define __my_Deque_c__
#include "my_Deque.h"
#include <assert.h>

PtrToDeque MakeNode(double x, double y)
{
        PtrToDeque P = (PtrToDeque)malloc(sizeof(Deque));
    assert(P != NULL);

    P->x = x;
    P->y = y;
    P->NextElement=NULL;

    return P;
}
void CreateEmptyDeque(PtrToDeque * S)
{
    PtrToDeque SS=MakeNode(0.0,0.0);
    *S=SS;
    (*S)->NextElement=MakeNode(0.0,0.0);
    (*S)->FirstElement=(*S);
    (*S)->LastElement=(*S)->NextElement;
    (*S)->NextElement->PreviousElement=(*S);
    (*S)->PreviousElement=NULL;
}
void push(PtrToDeque* S, double x, double y)
{
       PtrToDeque PNew = MakeNode(x,y);

    PtrToDeque L = *S;
        PNew->x=x;
    PNew->y=y;
    PNew->NextElement = L->FirstElement->NextElement;
    PNew->PreviousElement=L->FirstElement;
    PNew->FirstElement=L->FirstElement;
    PNew->LastElement=L->LastElement;
    L->FirstElement->NextElement->PreviousElement=PNew;
    L->FirstElement->NextElement = PNew;
}
void inject(PtrToDeque* S, double x, double y)
{
       PtrToDeque PNew = MakeNode(x,y);

    PtrToDeque L = *S;
    PNew->x=x;
    PNew->y=y;
    PNew->NextElement = L->LastElement;
    PNew->PreviousElement=L->LastElement->PreviousElement;
    PNew->FirstElement=L->FirstElement;
    PNew->LastElement=L->LastElement;
    L->LastElement->PreviousElement->NextElement=PNew;
    L->LastElement->PreviousElement=PNew;
    
}
void pop(PtrToDeque* S, double *x, double *y)
{
                    *x = (*S)->FirstElement->NextElement->x;
                    *y = (*S)->FirstElement->NextElement->y;
                    PtrToDeque Temp2 = (*S)->FirstElement->NextElement;
                    (*S)->FirstElement->NextElement = (*S)->FirstElement->NextElement->NextElement;
                    (*S)->FirstElement->NextElement->PreviousElement=(*S);
                    free(Temp2);
}
void eject(PtrToDeque* S, double *x, double *y)
{
                    *x = (*S)->LastElement->PreviousElement->x;
                    *y = (*S)->LastElement->PreviousElement->y;
                    PtrToDeque Temp2 = (*S)->LastElement->PreviousElement;
                    (*S)->LastElement->PreviousElement = (*S)->LastElement->PreviousElement->PreviousElement;
                    (*S)->LastElement->PreviousElement->NextElement=(*S);
                    free(Temp2);
}
void exitFunc(PtrToDeque S)
{
    PtrToDeque temp2 = S;
    while (S->NextElement!=NULL)
    {
        PtrToDeque temp = S->NextElement;
        S=S->NextElement;
        free(temp);
    }
    free(temp2);
       
}
void PrintDeque(PtrToDeque S)
{
    printf("\nThe Current Deque is:-\n");

    while (S!=S->LastElement->PreviousElement)
    {
        printf(" {%lf + %lf i} ",S->NextElement->x,S->NextElement->y);

        S=S->NextElement;
        /* code */
    }
    puts(" ");
    
}


#endif