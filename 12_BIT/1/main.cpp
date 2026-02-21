#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;

ll bit[MAXN];
ll a[MAXN];
int n, q;

void update(int i, ll val) {
  while (i <= n) {
    bit[i] += val;
    i += (i & -i);
  }
}

ll sum(int i) {
  ll res = 0;
  while (i > 0) {
    res += bit[i];
    i -= (i & -i);
  }
  return res;
}

ll rangeSum(int l, int r) { return sum(r) - sum(l - 1); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i]);
  }

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int i;
      ll x;
      cin >> i >> x;

      update(i, x);

      a[i] = x;
    } else if (type == 2) {
      int l, r;
      cin >> l >> r;
      cout << rangeSum(l, r) << "\n";
    }
  }

  return 0;
}