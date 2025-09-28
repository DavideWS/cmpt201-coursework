#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void historyInsert(char *line, char *array[], int *index) {
  if (*index < 5) {
    array[*index] = line;
    *index = *index + 1;
  } else {
    array[0] = array[1];
    array[1] = array[2];
    array[2] = array[3];
    array[3] = array[4];
    array[4] = line;
  }
}

void printing(char *array[], int *index) {
  if (*index < 5) {
    for (int i = 0; i < *index; i++) {
      printf("%s", array[i]);
    }
  } else {
    for (int i = 0; i < 5; i++) {
      printf("%s", array[i]);
    }
  }
}

int main() {
  char *history[5];
  int index = 0;
  while (1) {
    printf("Enter input: ");
    char *buff = NULL;
    size_t size = 0;
    ssize_t num_char = getline(&buff, &size, stdin);
    if (num_char == -1) {
      perror("getline failed");
      exit(EXIT_FAILURE);
    }

    historyInsert(buff, history, &index);

    if (strcmp(buff, "print\n") == 0) {
      printing(history, &index);
    }
  }

  return 0;
}
