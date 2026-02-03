#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_L = 10e6;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<char> p(MAX_L + 1, 1);
  p[0] = p[1] = 0;

  for (ll i = 2; i * i <= MAX_L; i++)
  {
    if (p[i])
    {
      for (ll j = i * i; j <= MAX_L; j += i)
      {
        p[j] = 0;
      }
    }
  }

  vector<ll> ps(MAX_L + 1, 0);
  for (int i = 1; i <= MAX_L; i++)
  {
    ps[i] = ps[i - 1] + p[i];
  }

  ll q;
  cin >> q;
  while (q--)
  {
    ll l, r;
    cin >> l >> r;
    cout << ps[r] - (l > 0 ? ps[l - 1] : 0) << '\n';
  }
}
