#include <dirent.h> 
#include <stdio.h> 
//by Ilya Mirzazhanov BS20-06
int main(void) {
  DIR *D; struct dirent *dir;
  D = opendir(".");
  if(D) while ((dir = readdir(D)) != NULL) printf("%s\n", dir->d_name);
    closedir(D);
  return(0);
}