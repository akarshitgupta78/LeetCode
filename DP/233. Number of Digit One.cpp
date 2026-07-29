class Solution {
public:
    int solve(string &s,int i,int tight,int cnt,vector<vector<vector<int>>> &dp)
    {   
        if(i==s.size()) return cnt;
        if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];
        int lb=0,ub=tight ? s[i]-'0':9;
        int ans=0;
        for(int j=lb;j<=ub;j++)
        {
            ans += solve(s,i+1,(tight && j==ub),cnt+(j==1),dp);
        }
    return dp[i][tight][cnt] = ans;
    }

    int countDigitOne(int n) 
    {
        string s= to_string(n);
        int m=s.size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (2,vector<int> (10,-1)));
    return solve(s,0,1,0,dp);
    }
};
