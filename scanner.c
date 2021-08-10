#include <stdio.h>
#include "scanner.h"

enum{FDT,SEP,CAD};

int tokenDeCaract(char caract)
{
    if(caract == ',')
    {
        return SEP;
    }
    else if (caract != ',' && caract >= 34 && caract <= 254)
    {
        return CAD;
    }
    else if(caract == EOF)
    {
        return FDT;
    }
    else
    {
        return -1;
    }
}

void get_token(){
    char caracter;
    char vec[300];
    int i=0;
    int token;
    int cantCadena = 0;
    caracter = getchar();
    while(caracter != EOF)
    {
        vec[i] = caracter;
        i++;
        caracter = getchar();
    }
    vec[i] = caracter;
    for(int j=0 ; j<=i ; j++)
    {
        token = tokenDeCaract(vec[j]);
        switch(token)
        {
            default:
            if(cantCadena)
            {
                printf("\n Cadena: ");
                for(int k=cantCadena ; k>0 ; k--)
                {
                    printf("%c", vec[j-k]);
                }
                cantCadena = 0;
            }
            break;

            case FDT:
            if(cantCadena)
            {
                printf("\n Cadena: ");
                for(int k=cantCadena ; k>0 ; k--)
                {
                    printf("%c", vec[j-k]);
                }
                cantCadena = 0;
            }
            printf("\n Fin de Texto");
            break;

            case SEP:
            if(cantCadena)
            {
                printf("\n Cadena: ");
                for(int k=cantCadena ; k>0 ; k--)
                {
                    printf("%c", vec[j-k]);
                }
                cantCadena = 0;
            }
            printf("\n Separador: ,");
            break;

            case CAD:
            cantCadena++;
            break;
        }
    }
}