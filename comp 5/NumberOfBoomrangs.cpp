class Solution {
public:
    int square(int n) {
        return n*n;
    }
    // int numberOfBoomerangs(vector<vector<int>>& points) {
    //     if(points.size()<3) { return 0; }
    //     int n = points.size();
    //     int ans = 0;
    //     for(int i=0;i<n-2;i++) {
    //         for(int j=i+1;j<n-1;j++) {
    //             for(int k=j+1;j<n;j++) {
    //                 int a = square(points[i][0] - points[j][0]) + square(points[i][1] - points[j][1]);
    //                 int b = square(points[i][0] - points[k][0]) + square(points[i][1] - points[k][1]);
    //                 if(a==b) { ans++; }
    //             }
    //         }
    //     }
    //     return 2*ans;
    // }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int dist=square(points[i][0] - points[j][0])+ square(points[i][1] - points[j][1]);
                mp[dist]++;
            }            
            for(auto&[k,v]:mp)ans+=v*(v-1);
            mp.clear();
        }
        return ans;
    }
    
};