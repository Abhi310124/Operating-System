#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        cin >> at[i] >> bt[i];
    }

    int time = 0;
    for(int i=0;i<n;i++){
        if(time < at[i]) time = at[i];
        time += bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "WT:\n";
    for(int i=0;i<n;i++) cout << wt[i] << " ";
    cout << "\nTAT:\n";
    for(int i=0;i<n;i++) cout << tat[i] << " ";

    return 0;
}

