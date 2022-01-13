//DFS approach : check whether cycle is present or not.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<unordered_set<int>> make_graph(int n, vector<pair<int,int>>& pre) {
        vector<unordered_set<int>> graph(n);
        for(auto i:pre) {
            graph[i.second].insert(i.first);
        }
        return graph;
    }
    
    bool Iscycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, 
                                                                vector<bool>& visited) {
            if(visited[node]) { return false; }
            onpath[node] = true; visited[node] = true;
            for(int i : graph[node]) {
                if(onpath[i]||Iscycle(graph,i,onpath,visited)) { return true; }
            }
            return onpath[node] = false;
    }

	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<unordered_set<int>> graph = make_graph(n,pre);
	    vector<bool> onpath(n, false), visited(n,false);
	    for(int i=0;i<n;i++) {
	        if(!visited[i] && Iscycle(graph,i,onpath, visited)) { return false; }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends