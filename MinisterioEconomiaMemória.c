#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adicionarLinhas(int n, char **l, char string[]){
    int i=0;
    static int  j=0, count=0;
    
    //SE NÃO ATINGIRMOS O NÚMERO DE LINHAS SOLICITADAS
   if(count<n){
       //ALOCAR NA MEMORIA CASO AINDA NÃIO TENHAMOS COLOCADO NENHUMA PARTE ANTERIOR DO TEXTO
       if(l[j] == NULL){ 
			l[j] = malloc(sizeof(char)*(strlen(string)+1));
			strcpy(l[j],"");
		}
        //REALOCAR A STRING AUMENTADA CASO JÁ TENHAMOS ALOCADO TEXTO ANTERIORMENTE
		else{
            //STRING ANTIGA E NOVA CONCATENADAS
			l[j] = realloc(l[j], sizeof(char)*(strlen(l[j])+strlen(string)+1));
        }

        //STRING ANTIGA + STRING NOVA
		strcat(l[j],string);

        //VERIFICAR SE LEMOS O FINAL DA LINHA PARA PASSAR PRO PRÓXIMO INDICE DO VETOR
		if(string[strlen(string)-1] == '\n'){
			j++;
            count++;
        }
        //RETORNAR 1 PARA CONTINUAR O LOOP
        return 1;
    }
    //SE ATINGIRMOS O NÚMERO DE LINHAS SOLICITADAS
   else if (count>=n){
       return 0;
   }
   
}
void imprimirLinhas(int num, char **line){
    int i=0;

    //IMPRIMIR O CONTEÚDO DE CADA LINHA DO VETOR DE PONTEIROS
    for (i = 0; i < num; i++){
        printf("%s", line[i]);
    }
    
}
void liberarLinhas(int numero, char **lin){
    int i=0;

    //LIBERAR CADA VETOR DE PONTEIROS, PARA ISSO FAZEMOS UM LOOP
    for (i = 0; i < numero; i++){
        free(lin[i]);
    }
    
}

int main(){
  char str[10];
  int N, i, j;   
  scanf("%d\n", &N);
  char *linhas[N];
  
  for(i=0; i<N; i++)
    linhas[i]=NULL;   
  
  do{
    fgets(str,10,stdin);
  }while(adicionarLinhas(N, linhas,str));
  
  printf("Texto liberado pelo Ministro\n");

  imprimirLinhas(N, linhas);
  
  liberarLinhas(N, linhas);
  
  return 0;
}