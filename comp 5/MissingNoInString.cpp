// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int getVal(const string& str, int i, int m) {
    if(m+i>str.size()) { return -1; }
    int val = 0;
    for(int k=i;k<i+m;k++) {
        int c = str[k] - '0';
        if(c<0 || c>9) { return -1; }
        val = val*10 + c;
    }
    return val;
}

int missingNumber(const string& str)
{
    // Code here
    for(int i=1;i<=6;i++) {
        int n = getVal(str,0,i);
        if(n==-1) { break; }
        int ans = -1;
        bool ind = 0;
        for(int k=i;k<str.size();k+=1+log10l(n)) {
            if(ans==-1 && getVal(str,k,1+log10l(n+2))==n+2) {
                ans = n+1; n+=2;
            }
            else if(getVal(str,k,1+log10l(n+1))==n+1) { n++; }
            else { ind = 1; break; }
        }
        if(ind==0) { return ans; }
    }
    return -1;
}