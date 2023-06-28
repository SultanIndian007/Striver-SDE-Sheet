// 1st give pick n non pick method 2^n tc then put it in set for unique elements only
// Tc- 2^n * n , SC -> 2^n * O(k) && O(n) auxillary space complexity
class Solution {
private:
    void findSubsets(int ind, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=ind; i<nums.size(); i++){
            if(i!= ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);

            findSubsets(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());

        findSubsets(0,nums,ds,ans);
        return ans;
    }
};