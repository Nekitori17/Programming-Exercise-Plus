#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 5e6;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("NTMAX.inp", "r", stdin);
  freopen("NTMAX.out", "w", stdout);

  vector<bool> pr(MAXN + 1, true);
  pr[0] = pr[1] = false;

  for (ll i = 2; i * i <= MAXN; i++)
  {
    if (pr[i])
    {
      for (ll j = i * i; j <= MAXN; j += i)
      {
        pr[j] = false;
      }
    }
  }

  string s;
  cin >> s;

  ll am = 0;
  ll ans = 0;
  string temp = "";

  for (char c : s)
  {
    if (isdigit(c))
    {
      am++;
      temp += c;
    }
    else
    {
      if (!temp.empty())
      {
        ll num = stoll(temp);
        if (num <= MAXN && pr[num])
          ans = max(ans, num);
        temp.clear();
      }
    }
  }

  if (!temp.empty())
  {
    ll num = stoll(temp);
    if (num <= MAXN && pr[num])
      ans = max(ans, num);
  }

  cout << am << "\n"
       << ans;

  return 0;
}