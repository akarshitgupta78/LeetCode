class Solution {
public:
    bool dfs(int i, int j, int k,vector<vector<char>> &board,vector<vector<int>> &vis,string &word)
    {
        int m = board.size(),n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n)return 0;
        if(vis[i][j]) return 0;

        if(board[i][j] != word[k]) return 0;

        if(k == word.size()-1) return 1;
        vis[i][j] = 1;
        bool flag = dfs(i+1,j,k+1,board,vis,word) || dfs(i-1,j,k+1,board,vis,word) 
                    || dfs(i,j+1,k+1,board,vis,word) || dfs(i,j-1,k+1,board,vis,word);

        vis[i][j] = 0;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j] == word[0] && dfs(i,j,0,board,vis,word))
                    return 1;
            }
        }
    return 0;
    }
};
