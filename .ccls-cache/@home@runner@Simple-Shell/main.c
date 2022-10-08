#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  pid_t pid; // variável que vai guardar o valor do pid

  char * argv[] = {"/bin/ls","-l",NULL}; // NULL para saber o fim da string

  pid = fork(); // criado o PROCESSO FILHO
  if(pid == -1){ // teste se não tem erro
    return -1;
  }

  if(pid == 0){ // Checando se está no PROCESSO FILHO
    int teste = execve(argv[0], argv , NULL); // caso tenha erro retorna -1. Usando variável teste para saber o retorno
    if( teste == -1 ){
      perror("Erro,Deu ruim!");
    }
  }else{ // PROCESSO PAI
    wait(NULL); // PROCESSO PAI vai esperar o fim do PROCESSO FILHO 
    printf("Deu certo :)");
  }
  
  
  return 0;
}