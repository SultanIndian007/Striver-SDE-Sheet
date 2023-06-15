// Moore Voting algo SC -> O(1) TC -> O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ele = nums[0];

        for(int num : nums){
            if(count==0){
                ele = num;
            }
            if(ele == num) count+=1;
            else count -=1;
        }
        return ele;
    }
};


// Using hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int ans=-1;
        for(auto it: mp){
            if (it.second>n/2){
                ans = it.first;
            }
        }
        return ans;
    }
};
