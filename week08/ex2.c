#include <stdio.h>
#include <unistd.h> 	 	 	 		 	
#include <stdlib.h> 	 	 	 	 	
//by Ilya Mirzazhanov BS20-06
int main() {
    
    //Task 2: From vmstat: free memory lowering, si and so is always zero 	 	 	   	 	 	 	
    //Task 3 %MEM increases, VIRT and RES memory usage increases
    // vmstat 1 runned
     	 	 	 	 	 	
	int N = 10; int mul = 10 * 1024 * 1024;                                     
    for (int i = 0; i<N; i++) {         	 	 	 	 	 	 	                           
         int * p = (int*)malloc(mul); 	 	 	 	 	 	 	 	 	 	
         memset(p, 0, mul); sleep(1);    	 	 	                            
    }

    /*for (int i = 0; i < 10; i++) { 	 	 	 	 	 	 	
        calloc(sizeof(char), 1024*1024*10); sleep(1); 	 	 	 	 	
    }*/ 	 	 	 	 	 	 		 

    return 0;
} 	 	 	 			 	  
