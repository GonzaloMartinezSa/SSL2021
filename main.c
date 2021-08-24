#include <stdio.h>
#include "scanner.h"


int main(){
    char buffer[100];
    int token = -1;
    int j=0;
    while(token != FDT)
    {
        token = get_token(buffer);
        switch (token)
        {   
            case OTRO:
            break;

            case SEP:
                printf("\n Separador: ,");
            break;
            
            case CAD:
                printf("\n Cadena: ");
                printf("%s", buffer);
                while(buffer[j]!='\0')
                {
                    buffer[j] = 0;
                    j++;
                }
                buffer[j+1] = 0;
                j=0;
            break;

            case FDT: 
                printf("\n Fin de Texto");
            break;
        }
    }
    return 0;
}