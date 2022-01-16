// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        int i = 0, des=0;
        while(1) { des = des+i; i++; 
            if(des==D) { return i-1; break; }
            if(des>D && (des-D)%2==0) { return i-1; break; }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends