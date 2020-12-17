#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 4

int calcolo(char numero[]);

int main()
{
    int somma;
    char numero[MAX];

    printf("Inserire un valore da %d cifre: ", MAX);
    scanf("%s", numero);
    somma= calcolo(numero);
    printf("\nIl numero inserito corrisponde a %d in base 10", somma);
    return 0;
}

int calcolo(char num[])
{
    int i;
    int cifra;
    int massimo;
    int risultato;
    int valore[MAX];

    massimo= 0;
    risultato= 0;
    if(num[0]=='-') //CONTROLLO SEGNO
    {
        for(i=1; i<MAX; i++) //CICLO SEGNO NEGATIVO
        {
            valore[i]= num[i]-48;
            if(valore[i]>massimo)
                massimo= valore[i];
        }
        for(i=1; i<MAX; i++)
        {
            cifra= valore[i] * (float)pow(massimo+1, MAX-(i+1));
            risultato= (risultato + cifra)*(-1);
        }
    }
    else
    {
        for(i=0; i<MAX; i++) //CICLO SEGNO POSITIVO
        {
            valore[i]= num[i]-48;
            if(valore[i]>massimo)
                massimo= valore[i];
        }
        for(i=0; i<MAX; i++)
        {
            cifra= valore[i] * (float)pow(massimo+1, MAX-(i+1));
            risultato= risultato + cifra;
        }
    }
    return risultato;
}
