#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//by Ilya Mirzazhanov BS20-06
int main() {
    
    //Task 2: From vmstat: free memory amount is decreasing, si and so is always 0  
    //Task 3 VIRT and RES memory usage increases, %MEM increases

    // vmstat 1 runned
    
	int N = 10;                              
	int mult = 10 * 1024 * 1024;                                     
    for (int i = 0; i < N; i++) {                                   
         int * p = (int*)malloc(mult);
         memset(p, 0, mult); sleep(1);                               
    }

    /*for (int i = 0; i < 10; ++i) {
        calloc(sizeof(char), 1024 * 1024 * 10);
        sleep(1);
    }*/

    return 0;
}