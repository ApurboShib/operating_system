
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
void WT(int p[], int n, int bt[], int wt[], int prio[]) {
    int completion_time[n];
    completion_time[0] = bt[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + bt[i-1];
        wt[i] = completion_time[i] - bt[i];
    }
}

void TAT(int p[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void AVG(int p[], int n, int bt[], int prio[]) {
    int wt[n], tat[n];
    WT(p, n, bt, wt, prio);
    TAT(p, n, bt, wt, tat);

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

   cout << fixed << setprecision(2) <<  " total average waiting time : " << (float) total_wt/n << endl;
   cout << fixed << setprecision(2) <<  " total TAT  time : " << (float) total_tat /n << endl;

}

int main() {
    int p[] = {1, 2, 3};
    int n = 3;
    int bt[] = {6, 8, 7};
    int prio[] = {2, 1, 3}; // Lower number means higher prio

    AVG(p, n, bt, prio);
    return 0;
}

