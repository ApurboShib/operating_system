#include <bits/stdc++.h>
using namespace std;

#define max_process 10
#define max_resources 10

// Check korbo allocate kore jabe kina.
bool allocate(int need[], int available[], int num_res) {
    for (int i = 0; i < num_res; i++) {
        if (need[i] > available[i]) {
            return false;
        }
    }
    return true;
}

// is it safe?
bool is_safe(int max[][max_resources], int allocation[][max_resources], int available[], int num_proc, int num_res, int safe_seq[]) {
    int need[max_process][max_resources];
    bool finish[max_process] = {false};
    int work[max_resources];

    // Calc the need matrix
    for (int i = 0; i < num_proc; i++) {
        for (int j = 0; j < num_res; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Init work 
    for (int i = 0; i < num_res; i++) {
        work[i] = available[i];
    }

    int cnt = 0;
    while (cnt < num_proc) {
        bool f = false;
        for (int i = 0; i < num_proc; i++) {
            if (!finish[i] && allocate(need[i], work, num_res)) {
                for (int j = 0; j < num_res; j++) {
                    work[j] += allocation[i][j];
                }
                safe_seq[cnt++] = i;
                finish[i] = true;
                f = true;
            }
        }
        if (!f) return false; // No process could be allocated
    }
    return true; // Safe sequence exists
}

int main() {
    int num_proc, num_res;

    cout << "Number of processes: ";
    cin >> num_proc;

    cout << "Number of resources: ";
    cin >> num_res;

    int max[max_process][max_resources];
    cout << "Enter the max matrix: \n";
    for (int i = 0; i < num_proc; i++) {
        for (int j = 0; j < num_res; j++) {
            cin >> max[i][j];
        }
    }

    int allocation[max_process][max_resources];
    cout << "Enter the allocation matrix: \n";
    for (int i = 0; i < num_proc; i++) {
        for (int j = 0; j < num_res; j++) {
            cin >> allocation[i][j];
        }
    }

    int available[max_resources];
    cout << "Enter the available resources: ";
    for (int i = 0; i < num_res; i++) {
        cin >> available[i];
    }

    int safe_seq[max_process];
    if (is_safe(max, allocation, available, num_proc, num_res, safe_seq)) {
        cout << "The system is safe.\n";
        cout << "The safe sequence is: ";
        for (int i = 0; i < num_proc; i++) {
            cout << safe_seq[i] << " ";
        }
        cout << endl;
    } else {
        cout << "The system is not safe.\n";
    }

    return 0;
}
