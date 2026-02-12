#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;
const ll LOG = 18;

ll a[MAXN];
ll st[MAXN][LOG];

void preprocess(ll n)
{
  for (ll i = 1; i <= n; i++)
    st[i][0] = a[i];

  for (ll j = 1; j < LOG; j++)
  {
    for (ll i = 1; i + (1 << j) - 1 <= n; i++)
    {
      st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
};

ll query(ll l, ll r)
{
  ll j = __lg(r - l + 1);
  return __gcd(st[l][j], st[r - (1 << j) + 1][j]);
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

  preprocess(n);

  while (q--)
  {
    ll l, r;
    cin >> l >> r;
    cout << query(l, r) << "\n";
  }

  return 0;
};