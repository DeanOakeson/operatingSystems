// Dean Oakeson
// CS3060-001 Fall 2025
// Assn #2

/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//////////////////////
// HELPER FUNCTIONS //
//////////////////////

void removeFirstElement(int *argc, char *argv[]) {
  for (int i = 1; i < *argc; i++) {
    argv[i - 1] = argv[i];
  }
  argc--;
}

void multipleArguments(int *argc, char *argv[]) {
  char *command = argv[1];
  removeFirstElement(argc, argv);

  int status_code = execvp(command, argv);

  if (status_code == -1) {
    printf("PROCESS TERMINATED INCORRECTLY\n");
  }
}

void singleArgument(char *argv[]) {
  char *command = argv[1];
  int status_code = execlp(command, command, NULL);

  if (status_code == -1) {
    printf("PROCESS TERMINATED INCORRECTLY\n");
  }
}

//////////////////
// MAIN PROGRAM //
/////////////////

int main(int argc, char *argv[]) {

  printf("PARENT started, now waiting for process ID#%d\n", getpid());
  pid_t pid;
  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "FORK FAILED\n");
    exit(1);
  }

  else if (pid == 0) {

    printf("CHILD started. ");

    if (argc == 2) {
      printf("One argument provided, Calling execlp.\n");
      singleArgument(argv);

    } else if (argc > 2) {
      printf("Multiple arguments provided. Calling execvp.\n");
      multipleArguments(&argc, argv);

    } else if (argc <= 1) {
      printf("No arguments provided. Terminating CHILD\n");
    }

  } else {
    int w = wait(NULL);
    printf("PARENT resumed, Child exit code of %d.\n", WEXITSTATUS(w));
  }

  return 0;
}
