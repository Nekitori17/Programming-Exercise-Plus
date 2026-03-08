#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;
const int MAXN = 1000000 + 5;

ll fact[MAXN];
ll invfact[MAXN];

ll binpow(ll a, ll b)
{
  if (b == 0)
    return 1;

  ll t = binpow(a, b / 2);

  if (b % 2 == 0)
    return (t * t) % MOD;
  else
    return (t * t % MOD) * a % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = 1;
  for (int i = 1; i < MAXN; i++)
    fact[i] = fact[i - 1] * i % MOD;

  invfact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);

  for (int i = MAXN - 2; i >= 0; i--)
    invfact[i] = invfact[i + 1] * (i + 1) % MOD;

  int Q;
  cin >> Q;

  while (Q--)
  {
    ll n, k;
    cin >> n >> k;

    ll ans = fact[n];
    ans = ans * invfact[k] % MOD;
    ans = ans * invfact[n - k] % MOD;

    cout << ans << "\n";
  }
}