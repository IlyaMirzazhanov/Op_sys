#include <string.h>
#include <stdlib.h>
#include <stdio.h>                                          
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>                                            
//by Ilya Mirzazhanov BS20-06
int main() {
     DIR *dir = opendir("tmp");
   
     if(dir==NULL) {                                                                         
        return 1;                                       
    }

     char tmp[512]; struct dirent *dp; struct stat ST; strcpy(tmp, "tmp/");
      while((dp=readdir(dir))!=NULL) {                                        
        stat(tmp, &ST); strcat(tmp, dp->d_name);
        if((strcmp(dp->d_name,".")!=0) & (strcmp(dp->d_name,"..")!=0) & (ST.st_nlink >= 2)) {
                     printf("link: %s files:\n", dp->d_name);
            struct dirent *LINK; DIR *dir2 = opendir("tmp");                                                  
             while((LINK = readdir(dir2)) != NULL){
                if((dp->d_ino == LINK->d_ino ) & (strcmp(LINK -> d_name, dp->d_name) != 0)) {                                
                    printf("%s ", LINK -> d_name); printf("\n");    
                }
            }
                        printf("\n");                                       
        } else if((strcmp(dp->d_name,".")!=0)&(strcmp(dp->d_name,"..")!=0))                         
                 printf("file %s have no links\n", dp -> d_name);                            

                        strcpy(tmp, "tmp/");
    }
    return 0;                                                
}
