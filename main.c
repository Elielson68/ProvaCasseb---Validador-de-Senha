#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char *senha;
    int LetraMaiuscula = 0;
    int LetraMinuscula = 0;
    int Caracter = 0;
    int inicio_letra = 0;
    int fim_letra = 0;
    int SenhaValida = 0;
    int tentativa = 0;
    char caracter;
    int n=0;
    while(tentativa != 3){
      senha = (char*) malloc(1*sizeof(char));
      printf("\nSenha: ");
      while(1) {
        senha[n] = getchar();
        if (senha[n] == '\n'){
          if(n<6){
            printf("Senha inválida, necessário que ela possua mais de 6 digitos");
            free(senha);
            n=0;
            break;
          }
          for(int i=0;i<n;i++){
            if(senha[i] >= 65 && senha[i]<=90){
              if(i==0){
                inicio_letra = 1;
              }
              if(i==n-1){
                fim_letra = 1;
              }
              LetraMaiuscula = 1;
            }
            if(senha[i] >= 97 && senha[i]<=122){
              if(i==0){
                inicio_letra = 1;
              }
              if(i==n-1){
                fim_letra = 1;
              }
              LetraMinuscula = 1;
            }
            if((senha[i] >= 33 && senha[i]<=47) || (senha[i] >= 58 && senha[i]<=64) || (senha[i] >= 91 && senha[i]<=94) || (senha[i] == 96) || (senha[i] >= 123 && senha[i]<=126)){
              Caracter = 1;
            }
          }
          break;
        }
        senha = (char*) realloc(senha, 1*sizeof(char));
        n = n + 1;
      }
      if(LetraMaiuscula==1 && LetraMinuscula==1 && Caracter==0 && inicio_letra==0 && fim_letra==0){
        printf("Senha Válida!\n");
        tentativa=5;
        SenhaValida = 1;
        break;
        

      }
      else{
        free(senha);
        if(LetraMaiuscula==0){
          printf("\nNão possui letra maiúscula!\n");
          
        }
        if(LetraMinuscula==0){
          printf("\nNão possui letra minúscula!\n");
        }
        if(Caracter==1){
          printf("\nSenha possui caracter especial!\n");
        }
        if(inicio_letra==1){
          printf("\nA senha está iniciando com letra!!\n");
        }
        if(fim_letra==1){
          printf("\nA senha está finalizando com letra!\n");
        }
        LetraMaiuscula = 0;
        LetraMinuscula = 0;
        Caracter = 0;
        inicio_letra = 0;
        fim_letra = 0;
        n=0;
        tentativa +=1;
      }
    }
    if(SenhaValida==0){
      printf("\nSuas tentativas acabaram!");
    }
    if(SenhaValida==1){
      printf("Cadastrado com sucesso!");
    }
    

  return 0;
}