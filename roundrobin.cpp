#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    for(int i=0;i<n;i++){
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    int tq;
    cin >> tq;

    queue<int> q;
    int time = 0, completed = 0;

    // push first arrived
    q.push(0);

    while(completed < n){
        int i = q.front();
        q.pop();

        if(time < at[i]) time = at[i];

        int run = min(tq, rt[i]);
        time += run;
        rt[i] -= run;

        // add newly arrived processes
        for(int j=0;j<n;j++){
            if(j != i && at[j] <= time && rt[j] > 0){
                q.push(j);
            }
        }

        if(rt[i] > 0){
            q.push(i);
        } else {
            ct[i] = time;
            completed++;
        }
    }

    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "WT:\n";
    for(int i=0;i<n;i++) cout << wt[i] << " ";
    cout << "\nTAT:\n";
    for(int i=0;i<n;i++) cout << tat[i] << " ";

    return 0;
}

