string s = "abcdedbca";
int n = s.length();

int dp[n][n];

memset(dp, -1, sizeof(dp));

int lps(string s, int i, int j)
{
  if (i == j)
    return 1;
  
  if (i > j)
    return 0;
  
  if (dp[i][j] != -1)
    return dp[i][j];
  
  if (s[i] == s[j])
    dp[i][j] = 2 + lps(s, i+1, j-1);
  else {
    int x = lps(s, i+1, j);
    int y = lps(s, i, j-1);
    dp[i][j] = max(x, y);
  }
  
  return dp[i][j];
}

cout << lps(s, 0, n-1);
