#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
void WT(int p[], int n, int bt[], int wt[]) {
    int completion_time[n];
    completion_time[0] = bt[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i-1] + bt[i-1];
        wt[i] = completion_time[i] - bt[i];
    }
}
void TAT(int p[], int n, int bt[], int wt[], int tat[]) {
    for(int i = 0; i  < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void AVG(int p[], int n, int bt[]) {
    int wt[n],tat[n];
    WT(p, n, bt, wt);
    TAT(p, n, bt, wt, tat);
    int total_wt = 0;
    int total_bt = 0;
    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_bt += tat[i];
    }

cout << fixed << setprecision(2) <<  " total average waiting time : " << (float) total_wt/n << endl;
cout << fixed << setprecision(2) <<  " total TAT  time : " << (float) total_bt /n << endl;


}
int main() {
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int bt[n];
    for(int i = 0; i < n; i++) {
        cin >> bt[i];
    }
    AVG(p, n, bt);
}