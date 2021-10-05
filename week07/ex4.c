#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//by Ilya Mirzazhanov BS20-06
#define SIZE 5
#define NEW_SIZE 10

void* myRealloc(void* ptr, size_t n_size, size_t o_size) {              
  if (n_size) {                         
    if (ptr) {                              
      void* n_mem = malloc(n_size); memcpy(n_mem, ptr, n_size > o_size ? o_size : n_size);              
      free(ptr);                
      return n_mem;                     
    }
        else return malloc(n_size);
  }
  else {                            
    free(ptr);                                  
        return NULL;
  }
}                   

int main() {
  size_t o_size = SIZE * sizeof(int); int* arr = malloc(o_size);                        
    arr = myRealloc(arr, NEW_SIZE * sizeof(int), o_size);                       

  free(arr);                
  return 0;
}