#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* fromJsonString_int(char string[], int* tam){
    int *vetor, i=0;
    char *numero = strtok(string, ", \n");

    while (numero != NULL){
        //PRIMEIRO CASO
        if(i == 0)
            vetor= malloc(sizeof(int));
        //SEM SER O PRIMEIRO CASO PARA REALOCAR
        else{
            vetor = realloc(vetor, sizeof(int)*(i+1));
        }
        //PRIMEIRO CASO
        if(i==0){
            vetor[0]= atoi(&string[1]);
        }
        //DEPOIS DO PRIMEIRO CASO
        else{
            vetor[i] = atoi(numero);
        }
        //ANDAR NO VETOR
        numero = strtok(NULL, ", \n");

        //ATUALIZAÇÃO
        i++;
        *tam = i;
    }
    return vetor;

    free(numero);
    free(vetor);
}

double* fromJsonString_double(char str[], int* t){
    double *v;
    int j=0;
    char *num= strtok(str, ", \n");

    while (num != NULL){
        //PRIMEIRO CASO
        if(j == 0)
            v= malloc(sizeof(double));
        //SEM SER O PRIMEIRO CASO PARA REALOCAR
        else{
            v = realloc(v, sizeof(double)*(j+1));
        }
        //PRIMEIRO CASO
        if(j==0){
            v[0]= atof(&str[1]);
        }
        //DEPOIS DO PRIMEIRO CASO
        else{
            v[j] = atof(num);
        }
        //ANDAR NO VETOR
        num = strtok(NULL, ", \n");

        //ATUALIZAÇÃO
        j++;
        *t = j;
    }
    return v;

    free(v);
    free(num);
}

int main(){
    int N=0, i=0, j=0, k=0, l=0, control=0, tamanho=0, tamanh=0, a=0, b=0;
    int *numeros;
    double *num;
    char texto[201]; //[200 + \0]

    //LER A QUANTIDADE DE VETORES 
    scanf("%d\n", &N);

    for (i = 0; i < N; i++){
        //LER A STRING
        fgets(texto, 201, stdin);

        //CASO SEJA UM VETOR VAZIO
        if(texto[0]=='[' && texto[1] == ']'){
            printf("vetor vazio\n");
        }
        else{
            for (j = 0; j < strlen(texto); j++){
            //PERCORRER O TEXTO E VER SE TEM PONTO, CASO TENHA É DOUBLE
            if(texto[j] == '.'){
                control++;
            }
        }
        //FUNÇÃO INT (SEM PONTO)
        if(control == 0){
            numeros = fromJsonString_int(texto, &tamanho);
            //PRINTAR NÚMEROS INT QUE FORAM ALOCADOS
            for (k = 0; k < tamanho; k++){
            printf("%d ", numeros[k]);
            }
            //PULAR A LINHA
            printf("\n");
        }
        //FUNÇÃO DOUBLE (COM PONTO)
        else{
            num = fromJsonString_double(texto, &tamanh);

            //PRINTAR NÚMEROS DOUBLE QUE FORAM ALOCADOS
            for (l = 0; l < tamanh; l++){
                printf("%lf ", num[l]);
            }
            //PULAR A LINHA
            printf("\n");
        }

        //ATUALIZAÇÃO
        control=0;
        }
    }

    free(numeros);
    free(num);
    
    return 0;
}