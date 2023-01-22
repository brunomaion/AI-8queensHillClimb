//IA - HILL CLIMB 8 QUEENS P1 - BRUNO MAION, LUCCA NERES
//Subida da encosta simples e, em caso de platôs, adotar mudança aleatória.
// gcc -o simples simples.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int i, j, x=0, y, v[8];
int attacks, attackMesmaLinha=0, interations=-1;
int vaux[8]= {0};
int vaux2[8]= {0};
int novo, auxiliar, original;
int coluna, indice, flag;
int custoFinal=1, custoInicial;
int vOriginnal[8] = {0};
int trocaAleatoriaCont;
int auxCusto = 0;
int maxInteraction = 100000;



void printVet(int *v);
int posiVet(int *v);
void printBoard(int *v);
int attacksCount(int *v);
int randon(int *v);


int main () {

    int k = 0, l=0, m=0, n=0, o=0, p=0;

    srand(time(NULL));
    posiVet(v);

    custoInicial = attacksCount(v);

        for (n = 0; n < 8; n++)
            {
                vOriginnal[n] =  v[n];
            }


    while (flag==0) {

        flag = 1;

        for (k = 0; k < 8; k++)
        {
            for (m = 0; m < 8; m++)
            {
                vaux[m] =  v[m];
                
            }

            auxiliar = attacksCount(v);

            //printf("\nATE AQUI COPIANDO!!\n");

            for (l = 0; l < 8; l++)
            {

                vaux[k] = l;
                //printf("v[%d] = %d\n", k, l);
                novo = attacksCount(vaux);
                //printf("%d\n", auxiliar);
                //printf("%d\n", novo);
                //printf("\n");

                if (novo <= auxiliar) {
                    
                    if (novo<auxiliar){
                    coluna = k;
                    indice = l;

                    flag = 0;
                    //printf("MELHOROU!!\n\n");
                    break;

                    } else { // ENTROU

                    flag = 0;
                    trocaAleatoriaCont++;
                
                    
                    do // DESCARTA MUDANÇAS PIORES
                    {
                        // COPIA SEGURANÇA
                        for (o = 0; o < 8; o++)
                        {
                            vaux2[o] = v[o];
                        }

                        randon(vaux2);
                        auxCusto = attacksCount(vaux2);
                        
                        if (auxCusto <= novo) {

                        for (o = 0; o < 8; o++)
                        {
                            v[o] = vaux[o];
                        }

                        }

                    } while (novo>auxiliar);
                    
                    
                    }
                }
            }
        }

        v[coluna] = indice;
        custoFinal = attacksCount(v);
        
        if (custoFinal==0 || interations==maxInteraction) {
        flag = 1;
        }

        printf("\n");
        printf("Custo atual = %d\n", custoFinal);
        interations++;
        printVet(v);
        printf("Trocou na coluna = %d;  Indice = %d\n", k, l);
        //printBoard(v);

    }
    


    
    printf("\n************* FIM **********\n\n");
    printf("SOLUÇÃO INICIAL:            ");
    printVet(vOriginnal);
    printf("MELHOR SOLUÇÃO ENCONTRADA:  ");
    printVet(v);
    printf("\n");
    printf("Custo inicial = %d\n", custoInicial);
    printf("Custo final = %d\n", custoFinal);
    printf("\n");
    printf("Interações = %d\n", interations);
    printf("\n");

    
    printf("TABULEIRO INICIAL:  \n");
    printBoard(vOriginnal);
    printf("TABULEIRO FINAL:  \n");
    printBoard(v);

    return 0;
}

int posiVet(int *v) { //FUNÇÃO PARA NAO REPETIR COLUNA

    for (i = 0; i < 8; i++) {

        v[i] = (rand() % 8);

        
    }

    return *v;
}

void printVet(int *v) { //FUNÇÃO PRINT VETOR COLUNAS


    for (i = 0; i < 8; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

}

void printBoard(int *v) { //FUNÇÃO PRINT TABULEIRO 

    int tabuleiro[8][8]= {0};

    int k, l;

    printf("\nA B C D E F G H\n");

    for (k = 0; k < 8; k++) {
     for (l = 0; l < 8; l++) {

        if (k==v[l])
        {
            tabuleiro[k][l] = v[k]+1;
        }
        
        if(tabuleiro[k][l]==0) {
            printf("- ");
            }   else {
                printf("X ");

        }
            //printf("%d ", tabuleiro[x][y]);
        }
        printf("%d\n", k+1);
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

int randon(int *v) {

    int a, b;
    //coluna
    a = (rand() % 8);
    //indice
    b = (rand() % 8);

    v[a] = b;
    return *v;
}
