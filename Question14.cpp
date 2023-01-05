class Solution {
public:
void fac(int n,set<int>&factors)
{
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i==n/i)factors.insert(i);
            else 
            {
                factors.insert(i);
                factors.insert(n/i);
            }
        }
    }
}
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++)
        {
            g=gcd(g,numsDivide[i]);
        }
        set<int>factors;
        cout<<endl;
        fac(g,factors);
        for(auto x:factors)
        {
            cout<<x<<" ";
        }
        int ans=0;
        bool fl=0;
        int val;
        for(auto j=factors.begin();j!=factors.end();j++)
        {
                if(find(nums.begin(),nums.end(),*j)!=nums.end())
                {
                    fl=1;
                    val=*j;
                    break;
                }
        }
        if(!fl)return -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<val)ans++;
        }
        return ans;
    }
};

