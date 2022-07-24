//To find the smallest window length - which contains all the chars of given string at least once.
string s = "aabcbcdbca";
unorderd_map<char, int> m;

for (int i=0; i<s.length(); i++)
  m[s[i]]++;

//Count distinct chars in the string
int count = 0;
for (auto x: m)
  count++;

unorderd_map<char, int> table;
int c=0;
int i = 0;
int min_win_size = 0;

for (int j=0; j<s.length(); j++)
{
  table[s[j]]++;
  if (table[s[j]] == m[s[j]]) 
    c++;
  
  //if we got the reqired set of chars in current windows - try minimizing, if possible
  while (c == count)
  {
    min_win_size = min(min_win_size, j-i+1);
    if (table[s[i]])
      table[s[i]]--;
    else
      c = 0;
           
     i++;   //Advance windows from left 
   }
}

cout << min_win_size << endl;
