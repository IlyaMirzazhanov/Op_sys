
#include <stdio.h>
#define MAX_PROC 10                                     
//by Ilya Mirzazhanov BS20-06
int main() {                                    
    int at[MAX_PROC] = {};                                      
    int bt[MAX_PROC] = {}; 
    int tat[MAX_PROC] = {};
    int et[MAX_PROC] = {}; 
    int wt[MAX_PROC] = {};

    int N; float totTAT = 0., totWT = 0.;

    // Enter n < MAX_PROC
    scanf("%d", &N);
    printf("Enter AT and BT:\n");

    for (int i = 0; i < N; i++) {
        printf("AT of %d process: ", i+1);                                            
        scanf("%d", &at[i]);

        printf("BT of %d process: ", i+1);                
        scanf("%d", &bt[i]);
    }

    //FCFS
    int CURRRENT_TIME = at[0];
    for (int i = 0; i < N; i++) {
        CURRRENT_TIME+=bt[i]; et[i] = CURRRENT_TIME;
        tat[i] = et[i]-at[i]; totTAT+=tat[i];                           
        wt[i] = tat[i]-bt[i]; totWT+=wt[i];
    }                                                                       

    printf("P#\t AT\t BT\t TAT\t WT\n ET\n\n");
    for (int i = 0; i < N; i++)                                                         
    printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt[i], tat[i], wt[i], et[i]);                                  

    printf("Average TAT is %f\n", totTAT/N);
    printf("Average WT is %f\n", totWT/N);                                                              
}
