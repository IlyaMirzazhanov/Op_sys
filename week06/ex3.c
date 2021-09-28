#include <stdio.h>                              
#include <stdbool.h>                                

#define MAX_PROC 10                             
//by Ilya Mirzazhanov BS20-06
int main() {                                        
    int at[MAX_PROC] = {};                                                
    int bt[MAX_PROC] = {};                                             
    int tat[MAX_PROC] = {};
    int et[MAX_PROC] = {};              
    int wt[MAX_PROC] = {};                                       
    int bt_f[MAX_PROC] = {};                         
    bool exec[MAX_PROC] = {};                                 
         
    int N, QUA; float totTAT = 0., totWT = 0.;                              

    // Enter n < MAX_PROC                    
    scanf("%d", &N);

    printf("Quantum: ");                                
    scanf("%d", &QUA);

    printf("Enter AT and BT:\n");
                                            
    int i;
    for (i = 0; i < N; i++) {
        printf("AT of %d process: ", i+1);
            scanf("%d", &at[i]); exec[i] = false;                               

        printf("BT of %d process: ", i+1);                              
            scanf("%d", &bt[i]); bt_f[i] = bt[i];                                                                 
    }

    //Round robin algorithm
    int CUR_TIME = at[0], fin = 0; i = 0;
    while (fin != N) {                              
        if (exec[i] == true) {
            i = (i + 1)%N;                                  
                continue;
        }

        if (bt[i] <= QUA) {                         
            CUR_TIME += bt[i];                                                        
                et[i] = CUR_TIME;                           
            tat[i] = et[i]-at[i];                                                   
                totTAT += tat[i];                           
            wt[i] = tat[i]-bt_f[i];
                totWT += wt[i]; fin++;                             
                exec[i] = true;                             
                i = (i + 1)%N;                           
        } else {                            
            CUR_TIME += QUA;                    
            bt[i] -= QUA;                                       
            i = (i + 1)%N;
        }
    }

    // Formatting output
    printf("P#\t AT\t BT\t TAT\t ET\t WT\n\n");                                 
    for (int i = 0; i < N; i++)                                                     
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt_f[i], tat[i], et[i], wt[i]);            

    printf("Average TAT is %f\n", totTAT/N);                        
    printf("Average WT is %f\n", totWT/N);                              
}
