#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void){

    time_t seconds;
    time(&seconds); // pega a data (dds,mmm,ddd,hour,minute,seconds,year)

    char* data_hora = ctime(&seconds); // pega a string gerada pelo ctime()

    data_hora[strcspn(data_hora, "\n")] = 0; // Retira um conteudo indesejado na string, no caso o \n

    float tx = 0.3;

    int id_usuario;

    char extrato[10][4][120]; // 10 usuarios com 100 EXTRATOS cada com espaço para 120 caracteres

    do{
        fflush(stdin);
        printf("Qual o usuario: ");
        scanf("%d", &id_usuario);
        
        // sprintf(extrato[id_usuario][1], "%s + valor  moeda  CT: cota TX: %.2f REAL: reais BTC: bitcoins ETH: ethereums: XRP: ripples\n\n",data_hora,tx); // salva strings formatadas
        // printf("%s", extrato[id_usuario][1]); // extrato 1
        if(id_usuario != 11){
            sprintf(extrato[id_usuario][1], "para id: %d TESTANDO\n\n",id_usuario,tx); // salva strings formatadas
            printf("%s", extrato[id_usuario][1]); // extrato 2
        }
        else{
            fflush(stdin);
            puts("ID inalcancavel");
        }
    }while(id_usuario != 11);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j <= 1; j++){
            if(extrato[i][j]!=NULL){
                printf("%s", extrato[i][j]);
            }
            else{
                puts("Nada salvo");
            }
        }
    }
    return 0;
}

/// testes


    // for(int i = 0; i < 100; i++){
    //     extrato[i] = malloc(120);
    //     sprintf(extrato[i], "extrato de numero[%d] %s + valor  moeda  CT: cota TX: tx REAL: reais BTC: bitcoins ETH: ethereums: XRP: ripples\n\n",i,data_hora); // salva strings formatadas
    //     if(extrato[i] == NULL){
    //         printf("Vazio");
    //     }
    //     else{
    //         printf("%s", extrato[i]);
    //     };
    // } 
    // for(int i = 0; i < 100; i++){
    //         free(extrato[i]);
    // }