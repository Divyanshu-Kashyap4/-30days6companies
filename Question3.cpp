class Solution {
public:
    string getHint(string secret, string guess) {
        string ans="";
        map<char,int>mp;
        for(int i=0;i<secret.size();i++)
        {
            mp[secret[i]]++;
        }
        int a=0,b=0;
        vector<int>vis(guess.size(),0);
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                a++;
                mp[secret[i]]--;
                vis[i]=1;
            }
        }
        for(auto x:mp)
        {
            map<char,int>mp1;
            for(int i=0;i<guess.size();i++)
            {
                if(!vis[i])
                {
                    if(guess[i]==x.first)mp1[x.first]++;
                }
            }
            if(mp1.find(x.first)!=mp1.end())
            {
                if(mp1[x.first]<x.second)b+=mp1[x.first];
                else b+=x.second;
            }
        }
        ans+=to_string(a)+"A"+to_string(b)+"B";
        return ans;
    }
};