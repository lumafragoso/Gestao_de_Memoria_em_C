#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* juntar(char **vetor_strings, int tamanho_vetor){
    int tamanho_final = 0, i=0, len=0, j=0, t=0;
    char *strings_unidas;

    strings_unidas = malloc(sizeof(char));

    //DESCOBRIR O TAMANHO DO VETOR COM AS PALAVRAS SEM ESPAÇO
    for (i = 0; i < tamanho_vetor; i++){
        len+=(int)strlen(vetor_strings[i]);
    }

    //REALOCAR O TAMANHO DO VETOR DE STRING
    strings_unidas = realloc(strings_unidas, sizeof(char*)*(len));

    //COLOCAR O ESPAÇO ENTRE AS STRINGS
    for (j = 0; j < tamanho_vetor; j++){
        strcat(strings_unidas, vetor_strings[j]);
        strcat(strings_unidas, " ");
    }

    return strings_unidas;

    free(strings_unidas);
}

char** separa(char* str, int* quantidadeTextos){
    char **textoSeparado;
    char *texto = strtok(str," ");
    int cont = 0;

    while(texto != NULL){
        //PRIMEIRO CASO
        if(cont == 0){
            textoSeparado= malloc(sizeof(char*));
        }
        //SEM SER O PRIMEIRO CASO PARA REALOCAR
        else{
            textoSeparado[cont] = realloc(textoSeparado, sizeof(char*) * (cont + 1));

        }
        textoSeparado[cont] = texto;

        //ATUALIZAÇÃO
        cont ++;

        //ANDAR NO VETOR
        texto = strtok(NULL," ");
    }
    //PASSAR O TAMANHO DO VETOR
    *quantidadeTextos = cont;

    return textoSeparado;

    free(texto);
}

char* embaralha(char* T){
    const int S=5940;
    int k=0, N=0, n=0, j=0, para=0, i=0, count=0;
    int l=1, p=0;
    char **E;
    char *R;

    //CHAMAR A FUNÇÃO PARA SEPARAR CADA STRING
    char **M= separa(T, &N);

    char palavra[N];

    //INICIALIZAR O VETOR COM TODOS OS LUGARES COM 0
    for (l = 0; l < N; l++){
        palavra[l] =0;
    }
    

    //INICIALIZAR COM VALOR SEMENTE
    srand(S);
    
    //SORTEIO DO RANDOM E COLOCAR NA STRING
    do{
        //SORTEAR O NUMERO
        n = rand();

        //PREENCHER E[]
        if(k==0){
            E = malloc(sizeof(char*));
        }
        else{
            E = realloc(E, sizeof(char*) * (k + 1));
        }

        //INICIALIZAR O ESPAÇO DO VETOR COMO NULO
        E[k] = NULL;

		E[k] =malloc(sizeof(char*)* (strlen(M[n % N])+1));

        //COLOCAR O VALOR ALEATORIO DENTRO DO VETOR
		E[k] = M[n % N];

        //VERIFICAR SE A PALAVRA JÁ FOI REPETIDA
        for (i = 0; i < N; i++){
            //CASO AS PALAVRAS SEJAM IGUAIS
            if(M[i] == E[k]){
                //SE A PALAVRA AINDA NAO FOI COLOCADA OU REPETIDA
                if(palavra[i] == 0){
                    palavra[i] = 1;
                    count++;
                }
            }
        }

        //QUANDO O VETOR DE PALAVRAS ESTIVER COM TODOS OS LUGARES COM '1' ENTÃO PODEMOS PARAR O LOOP
        if(count== N){
            break;
        }

        //ATUALIZAÇÃO
        para=0;
        k++;
    }
    while(p==0);

    //FUNÇÃO PARA ADICIONAR O ESPAÇO
    R = juntar(E, k+1);

    return R;

    free(E);
    free(R);
    free(T);
}

int main(){
    char string[501]; //500 + \0
    char *txt;

    //RECEBER A STRING
    fgets(string, 501, stdin);

    //CHAMAR A FUNÇÃO EMBARALHA PARA COLOCAR A MENSAGEM EMBARALHADA EM 'TXT'
    txt = embaralha(string);

    //PRINTAR A MENSAGEM EMBARALHADA
    printf("%s", txt);

    free(txt);
    return 0;
}