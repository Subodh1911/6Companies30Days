class helper {
public:
    bool operator()(string &s1, string &s2) {
        if(s1.size() != s2.size()) { return s1.size() < s2.size(); }
        return s1 < s2;
    }
};


class Solution {
public:
//     bool isB(string s1, string s2) {
//         if(s1.size() != s2.size())
//             return s1.size() < s2.size();

//         return s1 < s2;
//     }
    
//     string kthLargestNumber(vector<string>& nums, int k) {
//         int n = nums.size();
//         k=k-1;
//         int from = 0, to = n-1;
//         while(from<to) {
//             int r=from, w = to;
//             string mid = nums[(r+w)/2];
//             while(r<w) {
//                 if(isB(nums[r],mid)) {
//                     string t = nums[r];
//                     nums[r] = nums[w];
//                     nums[w] = t;
//                     w--;
//                 }
//                 else { r++; }
//             }
//             if(isB(nums[r],mid)) { r--; }
//             if(k<=r) { to==r; } else { from = r+1; }
//         }
//         return nums[k];
        
//     }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, helper> pq;
        for(auto i : nums) { pq.push(i); }
        while(--k) { pq.pop(); }
        return pq.top();
    }
};