class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod=1e9+7;
        vector<vector<pair<long long,long long>>>adj;
        adj.resize(n);
        for(auto it:roads)
        {
            long long u=it[0];
            long long v=it[1];
            long long wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
       priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,1e18);
        vector<long long>paths(n,0);
        dist[0]=0;
        paths[0]=1;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it=pq.top();
            long long distance=it.first;
            long long node=it.second;
            pq.pop();
            for(auto x:adj[node])
            {
                long long next=x.first;
                long long dista=x.second;
                if(dist[next]>distance+dista)
                {
                    dist[next]=dist[node]+dista;
                    pq.push({dist[next],next});
                    paths[next]=paths[node];
                }
                else if(distance+dista==dist[next])
                {
                    paths[next]=(paths[next]+paths[node])%mod;
                }
            }
        }
        return paths[n-1]%mod;
    }
};
