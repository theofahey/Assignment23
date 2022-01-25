#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  from_client = server_setup();
  while(1){
    to_client = server_connect(from_client);
    char buffer[BUFFER_SIZE];
    int f = fork();
    if (f){break;}
    if (!f){
      while(read(to_client,buffer,BUFFER_SIZE)){
        {
          printf("read from_client\n");
          int i,hold,length;
          length = strlen(buffer);
          for (i = 0; i < length/2;i++){
            hold = buffer[i];
            buffer[i] = buffer[length - i - 1];
            buffer[length - i - 1] = hold;
          }
          write(to_client,buffer,BUFFER_SIZE);
        }
      }
  }

}
}
