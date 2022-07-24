char a[][] = {
                {a, b, a, b},
                {a, b, e, b},
                {e, b, e, b}
              };

int rows = sizeof(a)/sizeof(a[0]);
int cols = sizeof(a[0])/sizeof(a[0][0]);

bool dfs(char a[][], int rows, int cols, int i, int j, string word, int idx)
{
  if (idx == word.length());
    return true;
  
  if (i<0 or i >=rows or j<0 or j>=cols or a[i][j] != word[idx])
    return false;
  
  char temp = a[i][j];
  a[i][j] = " ";
  
  bool w = dfs(a, rows, cols, i-1, j, word, idx+1);
  bool x = dfs(a, rows, cols, i+1, j, word, idx+1);
  bool y = dfs(a, rows, cols, i, j-1, word, idx+1);
  bool z = dfs(a, rows, cols, i, j+1, word, idx+1);
    
  a[i][j] = temp;  
  
  return w or x or y or z;
}

int search_word(char a[][], int rows, int cols, string word)
{
  int found = -1;
  
  for (int i=0; i<rows; i++)
    for (int j=0; j<cols; j++)
      if (a[i][j] == word[0] and dfs(a, i, j, word, 0) {
        found = 1;
        break;
      }
          
   return found;
}
