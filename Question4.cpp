class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
       vector<int>v(n);
       int val=0;
       int sum=0;
       for(int i=0;i<n;i++)
       {
           val+=i*nums[i];
           sum+=nums[i];
       }
    v[0]=val;
    for(int i=1;i<n;i++)
    {
        v[i]=sum-n*nums[n-i];
    }
     int ans=v[0];
    for(int i=1;i<n;i++)
    {
        v[i]+=v[i-1];
        ans=max(ans,v[i]);
    }
    return ans;
}
};