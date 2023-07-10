// O(logN), O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h = nums.size() -1;
        while(l<=h){
            int m = (l+h) >> 1;
            if(nums[m] == target) return m;

            if(nums[m] >=nums[l]){
                if(nums[l] <= target && target <= nums[m]){
                    h = m-1;
                }
                else{
                    l = m+1;
                }
            }
            else{
                if(target <= nums[h] && target >= nums[m]){
                    l = m+1;
                }
                else h =m-1;
            }
        }
        return -1;
    }
};