// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //string decodedString(string s){
        // code here
        //string ans = "";
        // stack<char> qq;
        // stack<int> ss;
        // for(int i=0;i<s.size();i++) {
        //     char c = s[i];
        //     if(s[i]>'0' && s[i]<='9') { ss.push(s[i]-'0'); }
        //     else if(c!=']') { qq.push(c); }
        //     else {
        //         while(c!='[') {
        //             c = qq.top();
        //             ans = c + ans;
        //             qq.top();
        //         }
        //         int t = ss.top();
        //         for(int j=0;j<t;j++) { ans+=ans; }
        //         ss.top();
        //         i++; 
        //     }
        // }
        // return ans;
        // }
        
        string decode(string &s, int &idx) {
        int times = 0;
        string word = "";
        
        while(idx < s.length()) {
            if(s[idx] >= '0' && s[idx] <= '9')
                times = times * 10 + (s[idx] - '0');
            else if(s[idx] == '[') {
                idx++;
                string temp = decode(s, idx);
                while(times--) word += temp;
                times = 0;
            }
            else if(s[idx] == ']')
                return word;
            else
                word += s[idx];
            idx++;
        }
        return word;
    }

    string decodedString(string s){
        // code here
        int ix = 0;
        return decode(s, ix);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends