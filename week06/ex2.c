#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_PROC 10
//By Ilya Mirzazhanov BS20-06
int main() {
    int at[MAX_PROC] = {};                                      
    int bt[MAX_PROC] = {};                                  
    int tat[MAX_PROC] = {};
    int et[MAX_PROC] = {}; 
    int wt[MAX_PROC] = {};                          
    bool exec[MAX_PROC] = {};

    int N, MIN_AT = INT_MAX;                    
    float totTAT = 0., totWT = 0.;                  

    // Enter n < MAX_PROC
    scanf("%d", &N);                    

    printf("Enter AT and BT:\n");

    for (int i = 0; i < N; i++) {
        exec[i] = false;                        

        printf("AT of %d process: ", i+1);                           
        scanf("%d", &at[i]);

        if (at[i] < MIN_AT) MIN_AT = at[i];                     

        printf("BT of %d process: ", i+1);                   
        scanf("%d", &bt[i]);                        
    }                       

    //SJF
    int CURRRENT_TIME = MIN_AT;                     
    for (int i = 0; i < N; i++) {
        int POS = 0, MIN_BT = INT_MAX;                  

        for (int j = 0; j < N; j++) {
            if (!exec[j] && at[j]<=CURRRENT_TIME && bt[j]<MIN_BT) {
                    POS = j; MIN_BT = bt[j];
            }
        }

        exec[POS] = true; CURRRENT_TIME += bt[POS];
        et[POS] = CURRRENT_TIME;

        tat[POS] = et[POS]-at[POS];
        totTAT+=tat[POS];

        wt[POS] = tat[POS]-bt[POS];
        totWT+=wt[POS];
    }

    printf("P\t AT\t BT\t TAT\t WT\t ET\n\n");
    for (int i = 0; i < N; i++)                                                         
    printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt[i], tat[i], wt[i], et[i]);                                  

    double AVG_TAT = totTAT/N, AVG_WT = totWT/N;
    printf("Average TAT %f\n", AVG_TAT);                        
    printf("Average WT %f\n", AVG_WT);
}
