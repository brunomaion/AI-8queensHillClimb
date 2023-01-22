//IA - HILL CLIMB 8 QUEENS P1 - BRUNO MAION, LUCCA NERES
//TESTAR SE O ALGORITMO ACHAR UMA SOLUÇÃO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int i, j, x=0, y, v[8], tabuleiro[8][8] = {0};
int attacks, attackMesmaLinha=0, interations=0;


void printVet(int *v);
int posiVet(int *v);
void printBoard(int *v);
int attacksCount(int *v);

int main () {

    //RAND MUDAR NUMEROS
   	srand(time(NULL));


    posiVet(v);
    //printVet(v);
    //printBoard(v);
    attacksCount(v);



    while (attacksCount(v)!=0)
    {
        posiVet(v);
        interations+=1;
        //printf("Interações = %d\n", interations);
    }
    
    printBoard(v);

    printf("Conflitos = %d\nInterações totais para encontrar solução = %d\n", attacks, interations); 

    return 0;
}

int posiVet(int *v) { //FUNÇÃO PARA NAO REPETIR COLUNA

        for (i = 0; i < 8; i++) {

        v[i] = (rand() % 8);

        
    }

    return *v;
}

void printVet(int *v) { //FUNÇÃO PRINT VETOR COLUNAS

    printf("VETOR VERDADEIRO: ");
    for (i = 0; i < 8; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    printf("VETOR +1 TABULEIRO: ");
    for (i = 0; i < 8; i++) {
        printf("%d ", v[i]+1);
    }
    printf("\n");

}

void printBoard(int *v) { //FUNÇÃO PRINT TABULEIRO 

    printf("\nA B C D E F G H\n");

    for (x = 0; x < 8; x++) {
     for (y = 0; y < 8; y++) {

        if (x==v[y])
        {
            tabuleiro[x][y] = v[y]+1;
        }
        
        if(tabuleiro[x][y]==0) {
            printf("- ");
            }   else {
                printf("X ");

        }
            //printf("%d ", tabuleiro[x][y]);
        }
        printf("%d\n", x+1);
    }

    printf("\n");


    /*/PRINTMATRIZ I J
    for (x = 0; x < 8; x++) {
     for (y = 0; y < 8; y++) {


        printf("%d%d  ", x, y);
   
        }
        printf("\n");
    }

    printf("\n");*/
}

int attacksCount(int *v) {  //FUNÇÃO CONTAR ATAQUES CONFLITOS SEM REPETIR

    /*/TESTE CONTAGENS CONFLITOS COM 8 IGUALS TEM Q SER 28 (7+6+5+4+3+2+1)
    for(int i=0; i<=8; i++) {
        v[i] = 0;
        printf("%d ", v[i]);
    } 
    printf("\n");*/

    /*/TESTE CONTAGENS CONFLITOS COM 0 NUMEROS IGUAIS (0 CONFLITOS)
    for(int i=0; i<8; i++) {
        v[i] = i;
        printf("%d ", v[i]);
    } 
    printf("\n"); */




    x=0;
    //contagem de numeros iguais == mesma linha
    for ( i = 1; i <= 7; i++) {
        for (j = 0; j < i; j++){
           if (v[i-j-1]==v[i]) {
            x+=1; 
            //printf("v[i-j]=%d  v[i]=%d  i=%d j=%d\n", v[i-j], v[i], i, j);
           }
        } 
    }
    
    //printf("CONFLITOS MESMA LINHA: %d\n", x);


    //CONFLITOS DIAGONAIS

    y=0;
    for ( i = 1; i <= 7; i++) {
        for (j = 0; j <= i-1; j++){
        
            if(v[i]>v[j]){
                if(v[i]==v[j]+(i-j)){
                    y+=1;
                    //printf("1- v[i]=%d  v[j]=%d  i=%d j=%d conta = %d\n", v[i], v[j], i, j, (v[j]+(i-j)));
                }
            }
            
            if(v[i]<v[j]){
                if(v[i]==v[j]-(i-j)){
                    y+=1;
                    //printf("2- v[i]=%d  v[j]=%d  i=%d j=%d conta = %d \n", v[i], v[j], i, j, (v[j]-(i-j)));
                }
            }
        
        } 
    }
    

    //printf("\nCONFLITOS DIAGONAIS: %d\n\n", y);
    attacks = x + y;
    //printf("TESTE SOMA: %d+%d= %d\n", x, y, attacks);

    return attacks;
}