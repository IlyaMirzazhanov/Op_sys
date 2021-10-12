#include <stdlib.h>
#include <stdio.h>                              
#include <sys/resource.h>
#include <unistd.h>                     
//by Ilya Mirzazhanov BS20-06
int main() {
    int N = 120; int data = 1024 * 1024 * N;                    
    
    for (int i = 0; i < N; i++) {
        int *p =(int*) malloc(data); memset(p, 0, data);                
        struct rusage memuse; getrusage(RUSAGE_SELF,&memuse);                   
        printf("MEMUSE: %ld\n", memuse.ru_maxrss);                      

         sleep(1);   
     }
    return 0;
}                    