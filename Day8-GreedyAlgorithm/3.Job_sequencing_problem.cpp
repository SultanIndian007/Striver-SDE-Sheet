// O(nlogn) + O(m*n), O(m)
class Solution 
{
    public:
    static bool cmp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
           sort(arr,arr+n,cmp);
           vector<int>v(n+1,-1);
           for(int i=0;i<n;i++){
                   int k=0;
               if(v[arr[i].dead]==-1){
                   
               v[arr[i].dead]=arr[i].profit;
               }
               else{
                   for(int j=arr[i].dead-1;j>=1;j--){
                       if(v[j]==-1){
                           v[j]=arr[i].profit;
                           break;
                       }
                           k++;
                   }
               }
           }
            int sum=0;
            int m=0;
            for(int i=0;i<=n;i++){
                if(v[i]!=-1){
                    m++;
                    sum+=v[i];
                }
            }
           return {m,sum};
    } 
};