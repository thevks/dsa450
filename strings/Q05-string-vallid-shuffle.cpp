//Write a program to check if a string is valid suffle of two strings or not

string s = "XY";
string t = "12";

string res = "1XY2";   //Valid shuffle
//string res = "Y1X2";   //Valid shuffle
//string res = "Y21XX";  //Not a valid shuffle

bool dp[1001][1001];  //Initialize based on the constatants in question

bool solve(string s, string t, string res, int m, int n, int len)
{
  if (len == -1) return true;
    
  if (dp[m][n]) return dp[m][n]; 

  bool a = false, b = false;
  
  if (res[len] == s[m]) a = solve(s, t, res, m-1, n, len-1);
  
  if (res[len] == t[n]) b = solve(s, t, res, m, n-1, len-1);
  
  return dp[m][n] = a or b;
}

int validShuffle(string s, string t, string res)
{
  int m = s.length();
  int n = t.length();
  
  if (res.length() != m + n)
    return -1;
  
  dp[m][n];
    
  for (int i=0; i<m; i++)
    for (int j=0; j<n; j++)
      dp[i][j] = false;
  
  return solve(s, t, res, m-1, n-1, res.length()-1);
}
