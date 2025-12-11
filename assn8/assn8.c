#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int total = 0;

void do_ls(char[], int indent);

int main(int ac, char *av[]) {
  if (ac == 1) {
    do_ls(".", 1);
  } else
    while (--ac) {
      printf("%s:\n", *++av);
      do_ls(*av, 1);
    }

  printf("\nTOTAL = %d\n", total);
}
void do_ls(char dirname[], int indent) {
  DIR *dir_ptr;
  struct dirent *direntp;
  struct stat info;

  printf("%*sDIR: %s\n", indent - 2, " ", dirname);
  if ((dir_ptr = opendir(dirname)) == NULL) {
    fprintf(stderr, "ls01: cannot open %s\n", dirname);

  } else {
    while ((direntp = readdir(dir_ptr)) != NULL) {
      stat(direntp->d_name, &info);
      if (direntp->d_type == DT_DIR) {
        if (!strcmp(direntp->d_name, "..") || !strcmp(direntp->d_name, ".")) {
          continue;
        } else /*IF DIRECTORY */ {
          char path[1024];
          strncpy(path, dirname, sizeof(path) - 1);
          strcat(path, "/");
          do_ls(strcat(path, direntp->d_name), indent + 3);
        }

      } else /*IF REGULAR FILE*/ {
        printf("%*s %d: %s\n", indent, " ", (int)info.st_size, direntp->d_name);
        total += (int)info.st_size;
      }
    }
    closedir(dir_ptr);
    return;
  }
}
