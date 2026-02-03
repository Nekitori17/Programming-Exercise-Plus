#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n >> q;
  vector<vector<ll>> g(n + 1, vector<ll>(n + 1, 0));
  for (ll i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    for (ll j = 0; j < n; j++)
    {
      if (s[j] == '*')
      {
        g[i][j + 1] = g[i - 1][j + 1] + g[i][j] - g[i - 1][j] + 1;
      }
      else
      {
        g[i][j + 1] = g[i - 1][j + 1] + g[i][j] - g[i - 1][j];
      }
    }
  }

  for (ll i = 0; i < q; i++)
  {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    cout << g[r2][c2] - g[r1 - 1][c2] - g[r2][c1 - 1] + g[r1 - 1][c1 - 1] << "\n";
  }

  return 0;
};