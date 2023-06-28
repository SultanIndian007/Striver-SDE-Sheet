// Striver 2^n tc & sc
class Solution
{
public:
    void func(int ind, int sum, vector<int>&arr, int N, vector<int> &subSet){
        if(ind==N){
            subSet.push_back(sum);
            return;
        }
        
        func(ind+1, sum + arr[ind], arr, N ,subSet);
        
        func(ind+1, sum, arr, N, subSet);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>subSet;
        func(0,0,arr,N,subSet);
        sort(subSet.begin(), subSet.end());
        return subSet;
    }
};

// ME
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
         vector<int> sum;
        sum.push_back(0);

        for (int i = 0; i < N; i++) {
            int size = sum.size();  // Get the current size of the sum vector
            for (int j = 0; j < size; j++) {
                sum.push_back(sum[j] + arr[i]);  // Add the current element to all the existing sums
            }
        }

        // Output the resulting sums
        // for (int i = 0; i < sum.size(); i++) {
        //     cout << sum[i] << " ";
        // }

        return sum;
    }
};