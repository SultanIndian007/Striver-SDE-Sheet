// optimal O(n^2), O(m)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;

        for(int i=0; i<n-2; i++){
            if(i==0 || (i>0 && nums[i] != nums[i-1] )){
                int low = i+1, high =n-1, sum = 0 -nums[i];

                while(low<high){
                    if(nums[low] + nums[high] == sum){
                        vector<int>temp;

                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);

                        while(low <high && nums[low] == nums[low+1]) low++;
                        while(low <high && nums[high] == nums[high-1]) high--;
                        
                        low++; high--;
                    }
                    else if(nums[low] + nums[high] < sum) low++;
                    else high--;
                }
            }
        }
        return res;
    }
};


// sorting, 2 loops, hashing
// O(n^2), O(n)hashtable
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>op;
        set<vector<int>>st;

        for(int i=0; i<n; i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    st.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
        for(auto it: st){
            op.push_back(it);
        }       
        return op;
    }
};

// brute force, O(n^3), fails
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        st.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        vector<vector<int>>op;
        for(auto it: st){
            op.push_back(it);
        }       
        return op;
    }
};