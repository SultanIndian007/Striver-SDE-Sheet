class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int soln = INT_MIN;
        for(auto i: nums){
            sum += i;
            soln = max(sum, soln);
            if(sum<0) sum=0;
        }
        return soln;
    }
};