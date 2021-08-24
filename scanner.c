#include <stdio.h>
#include "scanner.h"
#include <ctype.h>

int get_token(char *buffer)
{
    static int i = 0;
    int caracter = getchar();
    if(!isspace(caracter))
    {
        if(caracter == ',')
        {
            if(i!=0)
            {
                buffer[i] = '\0';
                i = 0;
                ungetc(caracter, stdin);
                return CAD;
            }
            else
            {
                return SEP;
            }
        }
        else if(caracter == EOF)
        {
            if(i!=0)
            {
                buffer[i] = '\0';
                i = 0;
                ungetc(caracter, stdin);
                return CAD;
            }
            else
            {
                return FDT;
            }
        }
        else
        {
            buffer[i] = caracter;
            i++;
            return OTRO;
        }
    }
    else
    {
        if(i!=0)
        {
            buffer[i] = '\0';
            i = 0;
            return CAD;
        }
        return OTRO;
    }
}