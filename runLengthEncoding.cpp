// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here
  string ans = "";
  for(int i=1;i<src.length();i++) {
      int cn = 1;
      while(src[i-1]==src[i]) {
          cn++;
          i++;
      }
      ans+=src[i-1] + to_string(cn);
  }
  if(src[src.length()-2]!=src[src.length()-1])  {ans+=src[src.length()-1] + to_string(1); }
  return ans;
}     
 
