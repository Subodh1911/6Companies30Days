class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,int>>> adj(n);
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
       for(int j=0;j<n;j++) {
           for(auto i:adj[j]){
           cout<<i.first<<" "<<i.second;}cout<<endl;
       } priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        vector<double> dist(n,0);
        dist[start]=1;
        while(!pq.empty()) {
            double cd=dist[pq.top().second];
            int cnode=pq.top().second;
            pq.pop();
            for(auto i:adj[cnode]) {
              double nd=cd*i.first;
                if(dist[i.second]<nd) {
                    pq.push({nd,i.second});
                    dist[i.second]=nd;
                }
            }
        }
        return dist[end];
        
        
    }
};