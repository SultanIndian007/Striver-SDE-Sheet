class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>hashSet;
        for(int num : nums){
            hashSet.insert(num);
        }

        int longestStreak = 0;
        for(int num : nums){
            if(!hashSet.count(num-1)){
                int currNum = num;
                int currentStreak = 1;

                while(hashSet.count(currNum+1)){
                    currNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

// Brute force
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int count = 1;
        int longestCount = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                count++;
                longestCount = max(longestCount, count);
            } else if (nums[i] != nums[i - 1]) {
                count = 1;
            }
        }
        
        return longestCount;
    }
};