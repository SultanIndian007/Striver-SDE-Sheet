// naive approach -> xor all elements so everything becomes 0 except unique no
// tc -> O(N), but array is sorted so try binary search

// edge case -> ele at last index   
// O(log(n)), O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() -2 ;

        while(l <= h){
            int mid = (l+h) >> 1;
            if(nums[mid] == nums[mid^1]){  
// mid^1 -> if its even no we get next odd, if it is an odd no we get prev even no so no need to check index even or odd
                l = mid + 1;
            }
            else{
                h = mid -1;
            }
        }
        return nums[l];
    }
};

// old soln
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        while(start<end){
            int mid = start + (end-start)/2;

            if((mid%2 == 0 && nums[mid] == nums[mid+1]) || 
            (mid%2 == 1 && nums[mid]==nums[mid-1])) { start = mid+1;}
            else{end = mid;}
        }
        return nums[start];
    }
};