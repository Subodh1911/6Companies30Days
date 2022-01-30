bool sortHelp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }

class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++) {
            p.push_back({speed[i],efficiency[i]});
        }
        sort(p.begin(), p.end(), sortHelp);
        long long ans=0, s=0;
        int m = 1e9+7;
        priority_queue<int> q;
        for(auto i:p) {
            if(q.size()==k) { s+=q.top(); q.pop(); }
            s+=i.first;
            q.push(-i.first);
            long long t = (long long)s*i.second;
            ans = max(ans,t);
        }
        return ans%m;
    }
};