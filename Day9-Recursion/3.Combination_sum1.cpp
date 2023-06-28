// tc- 2^t * k, sc -> k*x(avg length * x combinations ) still unpredictable coz its recursion
class Solution {
public:
    void findCombination(int ind, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds){
        if(ind == arr.size()){
            if(target ==0){
                ans.push_back(ds);
            }
            return;
        }
        // pick
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind, target -arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        // dont pick
        findCombination(ind +1, target, arr, ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};