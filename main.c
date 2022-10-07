#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  pid_T pid;

  char * argv[] = {"/bin/ls","-l",NULL}; // NULL para saber o fim da string

  pid = fork();
  if(pid == -1){
    return -1;
  }

  if(pid == 0){ // PROCESSO FILHO
    int teste = execve(argv[0], argv , NULL); // caso tenha erro retorna -1. Usando variável teste para saber o retorno
    if( teste == -1 ){
      perror("Erro,Deu ruim!");
    }
  }else{ // PROCESSO PAI
    wait(NULL);
    printf("Deu certo :)");
  }
  
  
  return 0;
}