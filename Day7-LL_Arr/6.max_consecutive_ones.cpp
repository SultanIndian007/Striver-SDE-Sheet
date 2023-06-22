// O(n), O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count = 0, maxCount = 0;
        for(int i=0; i<n; i++){
            if(nums[i]){
                count++;
            }
            else{
                count = 0;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};