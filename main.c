#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void esecuzione(float matrix[MAX][MAX], int rmax, int cmax, FILE* fp_out);

int main(int argc, char *argv[])
{
    FILE* fp_in;
    FILE* fp_out;
    int nr;
    int nc;
    int r;
    int c;
    float matrice[MAX][MAX];

    //APERTURA FILE + CONTROLLO
    if(argc!=3)
    {
        printf("ERRORE PARAMETRI INGRESSO");
        return -1;
    }
    fp_in= fopen(argv[1], "r");
    fp_out= fopen(argv[2], "w");
    if((fp_in==NULL)||(fp_out==NULL))
    {
        printf("ERRORE APERTURA FILE");
        return -2;
    }

    //ESECUZIONE
    fscanf(fp_in, "%d%d", &nr, &nc); //LETTURA DIMENSIONI MATRICE
    for(r=0; r<nr; r++) //CREAZIONE MATRICE
    {
        for(c=0; c<nc; c++)
            fscanf(fp_in, "%f", &matrice[r][c]);
    }
    esecuzione(matrice, nr, nc, fp_out);
    printf("Calcolo matrice eseguito");

    //CHIUSURA FILE
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

void esecuzione(float matrice[MAX][MAX], int rmax, int cmax, FILE* fp_out)
{
    int r;
    int c;
    int num;
    int somma;
    float risultato;

    num= 0;
    somma= 0;
    for(r=0; r<rmax; r++) //ESECUZIONE
    {
        for(c=0; c<cmax; c++)
        {
            if((r-1)>=0)//CONTROLLO RIGA SOPRA
            {
                if((c-1)>=0)
                {
                    somma= somma + matrice[r-1][c-1];
                    num++;
                }
                if(((c+1)<cmax)&&((c+1)<=MAX))
                {
                    somma= somma + matrice[r-1][c+1];
                    num++;
                }
                somma= somma + matrice[r-1][c];
                num++;
            }
            if(((r+1)<rmax)&&((r+1)<=MAX))//CONTROLLO RIGA SOTTO
            {
                if((c-1)>=0)
                {
                    somma= somma + matrice[r+1][c-1];
                    num++;
                }
                if(((c+1)<cmax)&&((c+1)<=MAX))
                {
                    somma= somma + matrice[r+1][c+1];
                    num++;
                }
                somma= somma + matrice[r+1][c];
                num++;
            }
            if((c-1)>=0) //CONTROLLO CASELLA SINISTRA
            {
                somma= somma + matrice[r][c-1];
                num++;
            }
            if(((c+1)<cmax)&&((c+1)<=MAX)) //CONTROLLO CASELLA DESTRA
            {
                somma= somma + matrice[r][c+1];
                num++;
            }
            risultato= somma/(float)num;
            fprintf(fp_out, "%.3f    ", risultato);
            somma= 0;
            num= 0;
        }
        fprintf(fp_out, "\n");
    }
}
