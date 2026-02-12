#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge
{
  ll i, v, w;
};

bool wSort(Edge a, Edge b)
{
  return a.w < b.w;
};

struct DSU
{
  vector<ll> p;

  DSU(ll n)
  {
    p.resize(n + 1);
    for (ll i = 1; i <= n; i++)
      p[i] = i;
  }

  ll find(ll x)
  {
    if (p[x] == x)
      return x;
    return p[x] = find(p[x]);
  }

  bool unite(ll x, ll y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    p[x] = y;
    return true;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m;
  cin >> n >> m;
  vector<Edge> e(m);
  for (ll i = 0; i < m; i++)
  {
    cin >> e[i].i >> e[i].v >> e[i].w;
  }
  sort(e.begin(), e.end(), wSort);

  DSU dsu(n);
  ll res = 0;
  ll cnt = 0;
  for (ll i = 0; i < m; i++)
  {
    if (dsu.unite(e[i].i, e[i].v))
    {
      res += e[i].w;
      cnt++;
    }
  }

  if (cnt == n - 1)
    cout << res;
  else
    cout << "IMPOSSIBLE";

  return 0;
};