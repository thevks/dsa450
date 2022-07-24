//Print length of longest common subsequence between two strings



string s = "abcd"; int m = s.length();
string t = "abzd"; int n = t.length();

//Top Down Approach
int dp[m+1][n+1];

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
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
}

cout << dp[m][n] << endl;


//Bottom Up Approach
int dp[m][n];
memset(dp, -1, sizeof(dp));
int lcs(string s, string t, int m, int n)
{
  if (m < 0 or n < 0)
    return 0;
  
  if (dp[m][n] != -1)
    return dp[m][n];
  
  if(s[m] == t[n])
    dp[m][n] = 1 + lcs(s, t, m-1, n-1);
  else {
    int a = lcs(s, t, m, n-1);
    int b = lcs(s, t, m-1, n);
    dp[m][n] = max(a, b);
  }
  
  return dp[m][n];
   
}
cout << lcs(s, t, m-1, n-1);
