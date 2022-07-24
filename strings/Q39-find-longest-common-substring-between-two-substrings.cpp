//Print length of longest common substrings between two strings
//Top Down Approach

string s = "abcd"; int m = s.length();
string t = "abzd"; int n = t.length();

int dp[m+1][n+1];
int res = 0;

for (int i=0; i<m; i++)
{
  for(int j=0; j<n; j++) 
  {
    if (i == 0 or j == 0)
      dp[i][j] = 0;
    else
    {
      if (s[i] == t[j]) {
        dp[i][j] = 1 + dp[i-1][j-1];
        res = max(res, dp[i][j]);
      }
      else
        dp[i][j] = 0;
    }
  }
}

cout << res << endl;
