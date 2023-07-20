// linear search Tc -> O(max-min) * O(n), O(1)
// binary Tc->O(nlogn + (log base 2 [n-1][0] * n)) ,sc-> O(1)

#include <bits/stdc++.h>

bool isPossible(vector<int>&stalls,int dist, int cows ){
    int cntCows = 1, last = stalls[0];
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i] - last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //Write your code here.
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];

    while(low<=high){
        int mid = (low+high) /2;
        if(isPossible(stalls,mid,k)==true){
            low = mid +1;
        }
        else{
            high  = mid-1;
        }
    }
    return high;
}
