string s = "dsfsdfsdfdsg";
int n = s.length();

int dp[n][n];
memset(dp, -1, sizeof(dp));

int count(string s, int i, int j)
{
  if (i == j)
    return 1;
  
  if (i>j)
    return 0;
  
  if (dp[i][j] != -1)
    return dp[i][j];
  
  if (s[i] == s[j])
    dp[i][j] = 1 + count(s, i+1, j-1);
  else
    dp[i][j] = count(s, i+1, j) + count(s, i, j-1) - count(s, i+1, j-1);
  
  return dp[i][j];

}

cout << count(s, 0, n-1) << endl;
