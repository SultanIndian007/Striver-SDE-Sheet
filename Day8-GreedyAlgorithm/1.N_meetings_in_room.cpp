class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            int a=start[i];
            int b=end[i];
            v.push_back(make_pair(b,a));
        }
        sort(v.begin(),v.end());
        
        int i=0,j=1,ans=1;
        while(j<n)
        {
            if(v[i].first<v[j].second)
            {
                ans++;
                i=j;
                j++;
            }
            else
            j++;
        }
        return ans;
    }
};