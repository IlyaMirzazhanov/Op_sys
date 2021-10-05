#include <stdlib.h>
#include <stdio.h>              
//by Ilya Mirzazhanov BS20-06
int main() {                        
  printf("Input numbers:\n");                              
                                 
  unsigned int n = 1; scanf("%u", &n);

  size_t* array = malloc(n * sizeof(size_t));               

  for (size_t i = 0; i < n; i++) {
    array[i] = i; printf("%u\n", array[i]);                     
  }                         

  free(array);                          
  return 0;
}