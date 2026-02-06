#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll st = 1, ed;
ll ans = -1;
vector<ll> bc;

void bfs(vector<vector<ll>> &gp, vector<bool> &vis)
{
  queue<pair<ll, ll>> q;
  q.push({st, 0});

  while (!q.empty())
  {
    pair<ll, ll> curr = q.front();
    q.pop();

    ll u = curr.first;
    ll dist = curr.second;

    if (u == ed)
    {
      ans = dist + 1;
      return;
    }

    for (ll v : gp[u])
    {
      if (!vis[v])
      {
        bc[v] = u;
        vis[v] = true;
        q.push({v, dist + 1});
      }
    }
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
  ed = n;
  bc.resize(n + 1);

  vector<vector<ll>> gp(n + 1);
  for (ll i = 0; i < m; i++)
  {
    ll x, y;
    cin >> x >> y;
    gp[x].push_back(y);
    gp[y].push_back(x);
  }

  vector<bool> vis(n + 1, false);
  vis[st] = true;
  bfs(gp, vis);

  if (ans == -1)
  {
    cout << -1 << "\n";
    return 0;
  }

  cout << ans << "\n";

  vector<ll> path;
  ll curr = ed;
  while (curr != st)
  {
    path.push_back(curr);
    curr = bc[curr];
  }
  path.push_back(st);
  reverse(path.begin(), path.end());
  for (ll x : path)
    cout << x << " ";

  return 0;
};