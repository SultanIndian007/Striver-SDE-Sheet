class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto it : nums)
        {
            mp[it]++;
        }

        for (auto i : mp)
        {
            pq.push(make_pair(i.second, i.first));
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};