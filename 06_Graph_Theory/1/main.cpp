#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int i, int j, vector<vector<bool>> &visited)
{
  if (i < 1 || i > visited.size() - 1 || j < 1 || j > visited[0].size() - 1)
  {
    return;
  }

  if (!visited[i][j])
  {
    visited[i][j] = true;
    dfs(i + 1, j, visited);
    dfs(i - 1, j, visited);
    dfs(i, j + 1, visited);
    dfs(i, j - 1, visited);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m;
  cin >> n >> m;
  vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, true));
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++)
    {
      if (s[j - 1] == '.')
      {
        visited[i][j] = false;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (!visited[i][j])
      { 
        ans++;
        dfs(i, j, visited);
      }
    }
  }

  cout << ans;

  return 0;
};