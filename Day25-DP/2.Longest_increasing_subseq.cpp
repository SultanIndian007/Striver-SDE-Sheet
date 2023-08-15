class Solution {
public:
    int f(vector<int>&arr, int n, int ind, int prev_ind, vector<vector<int>>&dp){
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        int notTake =0 + f(arr,n,ind+1,prev_ind,dp);
        int take = 0;

        if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
            take = 1+f(arr,n,ind+1, ind,dp);
        }
        return dp[ind][prev_ind+1] = max(notTake,take);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n =arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(arr,n,0,-1,dp);
    }
};