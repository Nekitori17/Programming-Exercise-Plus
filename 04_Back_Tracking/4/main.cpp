#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool board[8][8];

bool c[8];
bool d1[15];
bool d2[15];

void backtrack(int y)
{
  if (y == 8)
  {
    ans++;
    return;
  }

  for (int x = 0; x < 8; x++)
  {
    if (!board[y][x])
      continue;
    if (c[x] || d1[x + y] || d2[x - y + 7])
      continue;

    c[x] = d1[x + y] = d2[x - y + 7] = true;

    backtrack(y + 1);

    c[x] = d1[x + y] = d2[x - y + 7] = false;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  for (int i = 0; i < 8; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < 8; j++)
    {
      if (s[j] == '.')
        board[i][j] = true;
      else
        board[i][j] = false;
    }
  }

  backtrack(0);
  cout << ans;

  return 0;
}