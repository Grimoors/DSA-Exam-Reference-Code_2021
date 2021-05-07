#ifndef __my_Deque_h__
#define __my_Deque_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct Deque Deque;
typedef Deque* PtrToDeque;

struct Deque{

    double x;
    
    Deque* NextElement; 
    Deque* PreviousElement;
    Deque* FirstElement;
    Deque* LastElement;
};

 

PtrToDeque MakeNode(double x);
void CreateEmptyDeque(PtrToDeque * S);
void push(PtrToDeque* S, double x);
void pop(PtrToDeque* S ,double *x);
void eject(PtrToDeque* S, double *x);
void exitFunc(PtrToDeque S);
void PrintDeque(PtrToDeque S);
void inject(PtrToDeque* S, double x);


#endif