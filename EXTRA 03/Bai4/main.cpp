#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<ll> M, ll N, ll T) {
  ll sumT = 0;
  ll machine = 0;

  for (ll i = 0; i < M.size(); i++) {
    sumT += M[i];
    if (sumT > T) {
      machine++;
      sumT = M[i];
    }

    if (machine > N)
      return false;
  }

  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll N, K;
  cin >> N >> K;

  vector<ll> M(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> M[i];

  ll L = *max_element(M.begin(), M.end());
  ll R = accumulate(M.begin(), M.end(), 0LL);

  ll ans = 1e9;
  while (L <= R) {
    ll mid = (L + R) / 2;

    if (check(M, N, mid)) {
      R = mid - 1;
      ans = min(ans, mid);
    } else {
      L = mid + 1;
    }
  }

  cout << ans;

  return 0;
};