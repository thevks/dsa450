//TC : O(n^2)

string s = "aaaabbaa";
//o/p - aabbaa

int solve(string s, int i, int j)
{
  int len = 0;
  while (j<n)
  {
    int p = i, q = j;
    while(p>=0 and q<n and s[p] == s[q])
    {
      p--;
      q++;
    }
    
    len = max(len, q-p-1);
 
    i += 2;
    j += 2;             
  }
  
  return len;
}

int longest_palindrome_substring(string s)
{
  int n = s.length();

  //If string is of length 1
  if (s.length() == 1)  return 1;
  
  //If string is of length 2
  if (s.length() == 2)
  {
    if (s[0] == s[1]) return 2;
    else return 1;
  }
  
  //Even length palindrome
  int len1 = solve(s, 0, 1);
  
  //Odd length palindrome
  int len2 = solve(s, 0, 2);
  
  return max(len1, len2);    
}
