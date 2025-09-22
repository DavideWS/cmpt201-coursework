#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while (1) {
    printf("Enter programs to run. \n > ");
    read = getline(&line, &len, stdin);

    // asked chatgpt on how to resolve the newline error
    line[strcspn(line, "\n")] = '\0';

    pid_t pid = fork();

    if (pid == 0) {
      execl(line, line, (char *)NULL);
      perror("Exec failure");
    } else if (pid > 0) {
      waitpid(pid, NULL, 0);
    }
  }

  free(line);
  return 0;
}
