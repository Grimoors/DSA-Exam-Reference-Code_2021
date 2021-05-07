#include "my_Deque.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    printf("There Exists a Deque 'S' of complex Numbers of 2 dimentions in this program.\n Please use The following three functions -: \n1. push x y | where the complex number is = x+iy, The complex number is pushed onto the Deque. \n2.pop  | The topmost complex Number is popped. \n3.exit |Ends the program )\n");

    char _Command[6];
    PtrToDeque S;
    CreateEmptyDeque(&S);

    printf("\n Input your Command :- (exit kills the loop)\n");
    while (1)
    {
    _StartLabel:
        fflush(stdout);
        fflush(stdin);
        scanf("%s", _Command);

        if (strcmp("exit", _Command) == 0)
        {
            exitFunc(S);
            return 0;
        }

        else
        {
            if (strcmp("push", _Command) == 0)
            {
                double x, y;
                scanf(" %lf %lf", &x, &y);
                push(&S, x, y);
                printf("\nThe complex number Was pushed. \n");
                PrintDeque(S);
                printf("\n Input your Command :- (exit kills the loop)\n");
                goto _StartLabel;
            }
            else
            {
                if (strcmp("pop", _Command) == 0)
                {
                    double x, y;
                    if ((S->FirstElement->NextElement->x == 0.0) && (S->FirstElement->NextElement->y == 0.0) && ((S->FirstElement->NextElement->NextElement == NULL)))
                    {
                        printf("There is nothing to pop! Deque is empty!");
                        printf("\n Input your Command :- (exit kills the loop)\n");
                        goto _StartLabel;
                    }
                    // x = S->NextElement->x;
                    // y = S->NextElement->y;
                    // PtrToDeque Temp2 = S->NextElement;
                    // S->NextElement = (S)->NextElement->NextElement;
                    // free(Temp2);
                    pop(&S, &x, &y);
                    printf("\nThe popped Complex number is = %lf + %lfi \n", x, y);
                    PrintDeque(S);
                    printf("\n Input your Command :- (exit kills the loop)\n");
                    goto _StartLabel;
                }
                else
                {
                    if (strcmp("inject", _Command) == 0)
                    {
                        double x, y;
                        scanf(" %lf %lf", &x, &y);
                        inject(&S, x, y);
                        printf("\nThe complex number Was injected. \n");
                        PrintDeque(S);
                        printf("\n Input your Command :- (exit kills the loop)\n");
                        goto _StartLabel;
                    }
                    else
                    {
                        if (strcmp("eject", _Command) == 0)
                        {
                            double x, y;
                            if ((S->LastElement->PreviousElement->x == 0.0) && (S->LastElement->PreviousElement->y == 0.0) && ((S->LastElement->PreviousElement->PreviousElement == NULL)))
                            {
                                printf("There is nothing to eject! Deque is empty!");
                                printf("\n Input your Command :- (exit kills the loop)\n");
                                goto _StartLabel;
                            }
                            eject(&S, &x, &y);
                            //pop(&S, &x, &y);
                            printf("\nThe ejected Complex number is = %lf + %lfi \n", x, y);
                            PrintDeque(S);
                            printf("\n Input your Command :- (exit kills the loop)\n");
                            goto _StartLabel;
                        }
                        else
                        {
                            printf("\nInvalid command.\n \n Input your Command :- (exit kills the loop) \n There Exists a Deque 'S' of complex Numbers of 2 dimentions in this program.\n Please use The following three functions -: \n1. push x y | where the complex number is = x+iy, The complex number is pushed onto the Deque. \n2.pop  | The topmost complex Number is popped. \n3.exit |Ends the program ) \n");
                            goto _StartLabel;
                        }
                    }
                }
            }
        }
        printf("\n Input your Command :- (exit kills the loop)\n");
    }

    //printf("\n Input your Command :- (exit kills the loop)");
    return 0;
}