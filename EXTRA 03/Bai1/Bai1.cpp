#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 10000 + 5;

vector<bool> prb(MAXN, true);
vector<ll> prs;

void sieve()
{
  prb[0] = prb[1] = false;

  for (ll i = 2; i * i < MAXN; i++)
    if (prb[i])
      for (ll j = i * i; j < MAXN; j += i)
        prb[j] = false;

  for (ll i = 2; i < MAXN; i++)
    if (prb[i])
      prs.push_back(i);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("Bai1.inp", "r", stdin);
  freopen("Bai1.out", "w", stdout);

  sieve();

  ll q;
  while (cin >> q)
  {

    vector<ll> dp(q + 1, -1e18);
    dp[0] = 0;

    for (ll pr : prs)
      for (ll k = 0; k < 2; k++)
        for (ll j = q; j >= pr; j--)
          dp[j] = max(dp[j], dp[j - pr] + 1);

    cout << dp[q] << "\n";
  }
}