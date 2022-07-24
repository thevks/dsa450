//Bottom Up Approach

string s = "axxzxy";
//o/p - xx

int dp[n][n];
memset(dp, -1, sizeof(dp));

int lcs(string s, string t, int m, int n)
{
  if (m < 0 or n < 0)
    return 0;
  
  if (dp[m][n] != -1)
    return dp[m][n];
  
  if(s[m] == t[n] and m != n)     //Index should be different
    dp[m][n] = 1 + lcs(s, t, m-1, n-1);
  else {
    int a = lcs(s, t, m, n-1);
    int b = lcs(s, t, m-1, n);
    dp[m][n] = max(a, b);
  }
  
  return dp[m][n];
   
}

cout << lcs(s, s, n, n);
