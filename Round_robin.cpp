#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

void WT(int p[], int n, int bt[], int wt[], int quantum) {
    int rem_time[n];
    for(int i = 0; i < n; i++) {
        rem_time[i] = bt[i];
    }
    int time = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (rem_time[i] > 0) {
                done = false; 
                if (rem_time[i] > quantum) {
                    time += quantum;
                    rem_time[i] -= quantum;
                } else {
                    time += rem_time[i];
                    wt[i] = time - bt[i];
                    rem_time[i] = 0;
                }
            }
        }
        if (done) {
            break;
        }
    }
}

void TAT(int p[], int n, int bt[], int wt[], int tat[]) {
    for(int i = 0; i  < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}
void AVG(int p[], int n, int bt[], int quantum) {
    int wt[n],tat[n];
    WT(p, n, bt, wt, quantum);
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
    int quantum;
    cin >> quantum;
    AVG(p, n, bt, quantum);
}
