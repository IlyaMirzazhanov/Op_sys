#include <stdio.h>                                  
#include <stdlib.h>                                     
#include <string.h>                          
//by Ilya Mirzazhanov BS20-06                        
int main(){                         
    int HIT_R = 0, MISS_R = 0, SIZE = 0;                                    
        printf("Page frames: \n"); scanf("%d",&SIZE);                               

    FILE *FILE; FILE = fopen("Lab_09_input.txt", "r");              
    int current;                                             
    int *AG = (int*) calloc(SIZE, sizeof( int )); memset(AG, 0, SIZE);                                  
    int *FR = (int*) calloc(SIZE, sizeof( int )); memset(FR, 0, SIZE);                     
         printf("%d",fscanf(FILE, "%d", &current));                          

        while(fscanf(FILE, "%d", &current)!=EOF){                                   
                    int NUM_OF_FRAME = -1;                              
                for (int i=0; i<SIZE; i++){                                         
                    if (current==FR[i]){                                
                        NUM_OF_FRAME = i; break;                    
                    }
                }
         if(NUM_OF_FRAME != -1){                                 
                    HIT_R++; AG[NUM_OF_FRAME] >>= 1; AG[NUM_OF_FRAME] |= 1<<7;                  
         }else{                                             
                    MISS_R++; int MIN = 0;                              
            for (int i=0;i<SIZE;i++){                                                    
                    if (AG[i]<AG[MIN]){                                                                        
                            MIN = i;                        
                    }                                                                                    
            }                                                                      
                FR[MIN] = current; AG[MIN] = 0; AG[MIN] |= 1<<7;                                                 
        }                                               
    }                                                         
     printf("HIT rate: %d\nMISS rate :%d\n", HIT_R, MISS_R);                                                                   
        if(MISS_R != 0) {                                
            printf( "HITs/MISSes: %lf\n", (double)HIT_R/(double)MISS_R );                     
	    }                           
        fclose(FILE);                                       
     return 0;                                  
    }                    
