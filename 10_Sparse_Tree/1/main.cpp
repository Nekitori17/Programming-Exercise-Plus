#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 20e5 + 5;
ll a[MAXN];
ll t[MAXN * 4];

void build(ll id, ll l, ll r)
{
  if (l == r)
  {
    t[id] = a[l];
    return;
  }

  ll mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  t[id] = t[id * 2] + t[id * 2 + 1];
};

void update(ll id, ll l, ll r, ll pos, ll val)
{
  if (l == r)
  {
    t[id] = val;
    return;
  }

  ll mid = (l + r) / 2;
  if (pos <= mid)
    update(id * 2, l, mid, pos, val);
  else
    update(id * 2 + 1, mid + 1, r, pos, val);
  t[id] = t[id * 2] + t[id * 2 + 1];
};

ll get(ll id, ll l, ll r, ll u, ll v)
{
  if (v < l || u > r)
    return 0;

  if (u <= l && r <= v)
    return t[id];

  ll mid = (l + r) / 2;
  return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n >> q;
  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  build(1, 1, n);

  while (q--)
  {
    ll tp;
    cin >> tp;
    if (tp == 1)
    {
      ll k, u;
      cin >> k >> u;
      update(1, 1, n, k, u);
    }
    else
    {
      ll u, v;
      cin >> u >> v;
      cout << get(1, 1, n, u, v) << "\n";
    }
  }

  return 0;
};