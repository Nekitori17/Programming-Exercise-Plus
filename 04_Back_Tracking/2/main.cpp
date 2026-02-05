#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> used;
vector<ll> ans;

void backtrack(ll &n, ll l)
{
  if (l == n + 1)
  {
    for (ll i = 0; i < n; i++)
    {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (ll i = 1; i <= n; i++)
  {
    if (!used[i])
    {
      used[i] = true;
      ans[l - 1] = i;
      backtrack(n, l + 1);
      used[i] = false;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;
  used.resize(n + 1);
  ans.resize(n);

  backtrack(n, 1);

  return 0;
};