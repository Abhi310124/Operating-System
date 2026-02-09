#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];
    bool done[n];

    for(int i=0;i<n;i++){
        cin >> at[i] >> bt[i];
        done[i] = false;
    }

    int time = 0, completed = 0;

    while(completed < n){
        int idx = -1;
        int mn = INT_MAX;

        for(int i=0;i<n;i++){
            if(!done[i] && at[i] <= time && bt[i] < mn){
                mn = bt[i];
                idx = i;
            }
        }

        if(idx == -1){
            time++;
        } else {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            done[idx] = true;
            completed++;
        }
    }

    cout << "WT:\n";
    for(int i=0;i<n;i++) cout << wt[i] << " ";
    cout << "\nTAT:\n";
    for(int i=0;i<n;i++) cout << tat[i] << " ";

    return 0;
}

