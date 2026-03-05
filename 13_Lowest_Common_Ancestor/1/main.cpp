#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int p, int d)
{
  depth[u] = d;
  up[u][0] = p;

  for (int j = 1; j < LOG; j++)
    up[u][j] = up[up[u][j - 1]][j - 1];

  for (int v : adj[u])
    if (v != p)
      dfs(v, u, d + 1);
}

int get_lca(int u, int v)
{
  if (depth[u] < depth[v])
    swap(u, v);

  for (int j = LOG - 1; j >= 0; j--)
    if (depth[u] - (1 << j) >= depth[v])
      u = up[u][j];

  if (u == v)
    return u;

  for (int j = LOG - 1; j >= 0; j--)
    if (up[u][j] != up[v][j])
    {
      u = up[u][j];
      v = up[v][j];
    }

  return up[u][0];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  for (int i = 2; i <= n; i++)
  {
    int p;
    cin >> p;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }

  dfs(1, 1, 0);

  while (q--)
  {
    int u, v;
    cin >> u >> v;
    cout << get_lca(u, v) << "\n";
  }

  return 0;
}