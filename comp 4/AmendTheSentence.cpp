// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans = ""; int j=0, i=0;
        if(s[i]>='A' && s[i]<='Z') s[0] = s[0]+ 32;
        for(i=0;i<s.size();i++) {
            if(s[i]>='A' && s[i]<='Z') { s[i]+=32; ans+=s.substr(j,i-j) + " "; j = i; }
        }
        ans+=s.substr(j,i-j);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends