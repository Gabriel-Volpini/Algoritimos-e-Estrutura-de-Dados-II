#include <stdio.h>
#include <stdlib.h>
#include "fila_ponteiro.h"

int main()
{
    Fila roberto;
    createFila(&roberto);
    for(int i=111; i<777; i+=111){

        FilaAdd(&roberto,i);
        printFila(&roberto);
    }
    for(int i=111; i<777; i+=111){

        printf("REMOVIDO: %d",FilaRemove(&roberto));
        printFila(&roberto);
    }
    FilaDestroy(&roberto);
    return 0;
}
