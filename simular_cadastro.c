#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_USUARIOS 10

typedef struct Usuarios{
    int id_usuario;
    char nome[50];
    int cpf;
    char extrato[100][120];
} Usuarios;

void salvar_usuario(Usuarios* usuario,int tamanho){

    FILE* arquivo = fopen("teste", "wb");

    fwrite(usuario,sizeof(Usuarios),tamanho,arquivo);

    fclose(arquivo);
}

void ler_usuario(Usuarios* usuario,int tamanho){
    FILE* arquivo = fopen("teste", "rb");

    fread(usuario,sizeof(Usuarios),tamanho,arquivo);

    fclose(arquivo);
}

void cadastrar_usuario();

int main(void){
    Usuarios usuario[LIMITE_USUARIOS];
    for(int i = 0; i < LIMITE_USUARIOS; i++){
        usuario[i].id_usuario = i;
        printf("Qual o nome do usuario com id %d", usuario[i].id_usuario);
        fgets(usuario[i].nome,50,stdin);
    }
    salvar_usuario(&usuario,LIMITE_USUARIOS);
    // limpando  todos os usuarios
    for(int i = 0; i < LIMITE_USUARIOS; i++){
        usuario[i].id_usuario = 0;
    }
    // lendo os usuarios zerados
    printf("Antes de ler %d\n", usuario[0].cpf);
    for(int i = 0; i < LIMITE_USUARIOS; i++){
        printf("Id: %d, %s",usuario[i].id_usuario,usuario[i].nome);
    }
    // lendo apos ler o arquivo
    ler_usuario(&usuario,LIMITE_USUARIOS);
    printf("Depois de ler %d", usuario[0].cpf);
    for(int i = 0; i < LIMITE_USUARIOS; i++){
        printf("Id: %d, %s",usuario[i].id_usuario,usuario[i].nome);
    }

    return 0;
}