//n - 1 - "1"
//n - 2 - "11"
//n - 3 - "21"
//n - 4 - "1211"
//n - 5 - "1112211"

string countAndSay(int n)
{
  if (n == 1) 
    return "1";
  
  if (n == 2) 
    return "11";
  
  string s = "11";
      
  for (int count=3; count<=n; count++)
  {
    string t = " ";
    int i=0, j=1;
      
    while (j < s.length())
    {
      while (s[j] == s[j-1])) 
      {
        j++;
        continue;
      }
      
      t += to_string(j-i);
      t += s[j-1];
      
      j++;
      
      i = j-1;
    }
    
    t += to_string(j-i);
    t += s[j-1];
    
    s = t;        
  }
  
  return s;
}
