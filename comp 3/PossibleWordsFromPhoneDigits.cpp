// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    string getNumString(int n) {
        switch(n) {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
        }
    }
    void getWords(int i, int n, int a[], string curr, vector<string> &res) {
        if(i == n) {
            res.push_back(curr);
            return;
        }
        string s = getNumString(a[i]);
        for(int j=0; j<s.size(); j++)
            getWords(i+1, n, a, curr+s[j], res);
    }
public:
    vector<string> possibleWords(int a[], int N) {
        vector<string> res;
        getWords(0, N, a, "", res);
        return res;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends