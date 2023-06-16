// Hashmap O(n), O(n) tc and sc
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int complement = target - nums[i];
            if(mp.count(complement)){
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};


// Brute force n^2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    return{i,j};
                }
            } 
        }
        return {};
    }
};