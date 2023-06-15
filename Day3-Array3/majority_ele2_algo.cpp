// Using extended Boyer Moore's voting algo Tc-> O(n) + O(n) , SC -> O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2) count2++;
            else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        count1 = count2 =0;
        for(int i=0; i<n; i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }
        }
        if(count1>n/3){
            ans.push_back(num1);
        }
        if(count2 > n/3){
            ans.push_back(num2);
        }
        return ans;
    }
};


// Using hashmap nlogn, n
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto it : mp){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};