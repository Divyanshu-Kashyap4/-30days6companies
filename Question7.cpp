class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n= prerequisites.size();
       vector<int>adj[numCourses];
       for(int i=0;i<n;i++)
       {
           int u= prerequisites[i][0];
           int v= prerequisites[i][1];
           adj[u].push_back(v);
       }
       vector<int>indegree(numCourses);
       for(int i=0;i<numCourses;i++)
       {
           for(auto x:adj[i])
           {
               indegree[x]++;
           }
       }
       queue<int>q;
       vector<int>ans;
       for(int i=0;i<numCourses;i++)
       {
           if(indegree[i]==0)q.push(i);
       }
       while(!q.empty())
       {
           auto node=q.front();
           q.pop();
            if(indegree[node]==0)
            {
                ans.push_back(node);
            }
            for(auto x:adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
       }
       if(ans.size()==numCourses)return true;
       return false;
    }
};