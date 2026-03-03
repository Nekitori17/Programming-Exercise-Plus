#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 5;

struct Edge
{
  int v, id;
};

vector<Edge> adj[MAX];
ll timer = 0, n, m;
ll num[MAX], low[MAX];
bool is_bridge[MAX], vis[MAX];

void find_bridges(int u, int p_id)
{
  num[u] = low[u] = ++timer;

  for (Edge &e : adj[u])
  {
    if (e.id == p_id)
      continue;

    if (num[e.v])
      low[u] = min(low[u], num[e.v]);
    else
    {
      find_bridges(e.v, e.id);

      low[u] = min(low[u], low[e.v]);

      if (low[e.v] > num[u])
        is_bridge[e.id] = true;
    }
  }
}

void dfs_size(int u, int &sz)
{
  vis[u] = true;
  sz++;

  for (auto &e : adj[u])
    if (!is_bridge[e.id] && !vis[e.v])
      dfs_size(e.v, sz);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("BAI5.inp", "r"))
  {
    freopen("BAI5.inp", "r", stdin);
    freopen("BAI5.out", "w", stdout);
  }
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++)
  {
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  for (int i = 1; i <= n; i++)
    if (!num[i])
      find_bridges(i, -1);

  ll ans = 0;

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      int sz = 0;
      dfs_size(i, sz);
      ans += (ll)sz * (sz - 1) / 2;
    }
  }
  
  cout << ans;
}