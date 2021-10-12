#include <stdlib.h>                                           
#include <stdio.h>                                                                                  
#include <sys/resource.h>                                                          
#include <unistd.h>                                                                   
//by Ilya Mirzazhanov BS20-06
int main() {                                        
    int N = 10; int dt = 1024*1024*N;                                                                                                           
    for (int i=0; i<N; i++) {                           
       int *p = (int*) malloc(dt); memset(p, 0, dt );                                             
        struct rusage memuse; getrusage(RUSAGE_SELF, &memuse);   //using getrusage                                                       
         printf(" MEMUSE: %ld\n", memuse.ru_maxrss );                              
                                    
            sleep(1);   
     }                                      
     return 0;                                                       
}                                      
