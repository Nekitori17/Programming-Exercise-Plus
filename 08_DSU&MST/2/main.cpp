#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge
{
  ll u, v;
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
  vector<Edge> e(m + 1);
  for (ll i = 1; i <= m; i++)
  {
    cin >> e[i].u >> e[i].v;
  }

  ll q;
  cin >> q;
  vector<bool> bk(m + 1, false);
  vector<ll> bkl;
  for (ll i = 1; i <= q; i++)
  {
    ll x;
    cin >> x;
    bkl.push_back(x);
    bk[x] = true;
  }

  DSU dsu(n);
  ll cnt = n;
  for (ll i = 1; i <= m; i++)
  {
    if (bk[i])
      continue;

    if (dsu.unite(e[i].u, e[i].v))
    {
      cnt--;
    }
  }

  vector<ll> ans;
  ans.push_back(cnt);
  for (ll i = q - 1; i >= 1; i--)
  { 
    if (dsu.unite(e[bkl[i]].u, e[bkl[i]].v))
    {
      cnt--;
    }
    ans.push_back(cnt);
  }

  reverse(ans.begin(), ans.end());
  for (ll i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << "\n";
  }

  return 0;
};