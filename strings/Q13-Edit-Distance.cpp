//String s to be transformed be like string t

string s = "geek"; int m = s.length();
string t = "gesek"; int n = t.length();
int dp[1001][1001]; //Adjust constants based on questions

int edit_distance(string s, string t, int m, int n)
{
  if (m == -1)  return n+1;
  if (n == -1)  return m+1;
    
  if (dp[m][n] != -1)
    return dp[m][n];
  
  if (s[m] == t[n])
    return dp[m][n] = edit_distance(s, t, m-1, n-1);
 
  int a = edit_distance(s, t, m-1, n-1);  //update on both strings
  int b = edit_distance(s, t, m, n-1);    //Insert in string s //Equivalent to delete from string t
  int c = edit_distance(s, t, m-1, n);    //Delete in string s
  
  dp[m][n] = min(a, min(b,c));
  
  return dp[m][n];
}

int main() 
{
  dp[m][n];
  memset(dp, -1, sizeof(dp));
  cout << edit_distance(s, t, m-1, n-1) << endl;
}
