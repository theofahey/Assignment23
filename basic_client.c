#include "pipe_networking.h"


int main() {


  int from_server;

  from_server = client_handshake();
  while(1){
    char buffer[BUFFER_SIZE];
    printf("Write Input: ");
    fgets(buffer,BUFFER_SIZE,stdin);
    write(from_server,buffer,BUFFER_SIZE);
    printf("Wrote Input to server\n ");
    char buffer2[BUFFER_SIZE];
    read(from_server, buffer2, BUFFER_SIZE);
    printf("Output: %s\n", buffer2);
  }
}
