#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char input[BUFFER_SIZE];
  while (1) {
    int val = read(from_client, input, BUFFER_SIZE);
    if (val < 0) {
      printf("Error: %s\n", strerror(errno));
      return 0;
    }

    int len = strlen(input);
    char line[strlen(input)];
    for (int i = 0; i < len; i ++) {
      line[len - 1 - i] = input[i];
    }
    line[len] = '\0';
    write(to_client, line, sizeof(line));
  }
}
