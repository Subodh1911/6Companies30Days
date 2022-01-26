// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    // int x[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    // int y[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
    bool search(vector<vector<char>>& board, string word, int &row, int &col, int ind, int i, int j) {
       if(ind==word.size()-1) { return true; }
       ind++;
       board[i][j]='0';
       for(int k=0;k<4;k++) {
           int nx = i+dx[k];
           int ny = j+dy[k];
           if(nx>=0 && ny>=0 && nx<row && ny<col && board[nx][ny]==word[ind]) {
               if(search(board,word,row,col,ind,nx,ny)) { return true; }
           }
       }
       board[i][j] = word[ind-1];
       return false;
    }

    bool isWordExist(vector<vector<char>>& board, string &word) {
        // Code here
        int n = word.size();
        if(n==0) { return 1; }
        int row = board.size();
        if(row==0) { return 0; }
        int col = board[0].size();
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(board[i][j]==word[0]) {
                    if(search(board,word,row,col,0,i,j)) { return true; }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
