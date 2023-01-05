class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        int l=0,i=1;
        vector<int>lps(n,0);
        while(i<n)
        {
            if(s[i]==s[l])
            {
                lps[i]=l+1;
                l++;
                i++;
            }
            else 
            {
               if(l!=0)l=lps[l-1];
               else i++;
            }
        }
        return s.substr(0,lps[n-1]);
    }
};
