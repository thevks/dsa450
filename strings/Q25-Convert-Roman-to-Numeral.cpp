string s = "XIXV";

//Maintain mapping to Roman to Decimal numbers
unordered_map<string, int> m;

m[I] = 1;
m[V] = 5;
m[X] = 10;
m[L] = 50;
m[C] = 100;
m[D] = 500;
m[M] = 1000;

int i = s.length() - 1;
int total_count = 0;

for(j=s.length()-2; j>0; j--)
{
  int prev_count = m[s[i]];
  int cur_count = m[s[j]];
  
  if (cur_count < prev_count)
    total_count = prev_count - cur_count;
  else
    total_count = prev_count + cur_count;
  
  prev_count = total_count;      
}

cout << total_count << endl;
