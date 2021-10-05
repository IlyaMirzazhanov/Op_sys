#include <stdlib.h>
#include <stdio.h>                                  
//by Ilya Mirzazhanov BS20-06                                           
int main() {                            
  srand(time(NULL));

  printf("Enter original array size:");
  int n1 = 0; scanf("%d", &n1);

  int* a1 = malloc(n1 * sizeof(int));                       
  for (int i = 0; i < n1; i++) {
    a1[i] = 100;
        printf("%d ", a1[i]);
  }                         

  printf("\nEnter new array size: ");
  int n2 = 0;
  scanf("%d", &n2);

  a1 = realloc(a1, n2 * sizeof(int));

  if (n2>n1) {
    for (int j = 0; j<n2; j++) {
      		a1[j] = 0;
    }                       
  }                     

  for (int i = 0; i<n2; i++) {
        printf("%d ", a1[i]);
  }                     
  printf("\n");
  free(a1);
  return 0;
}