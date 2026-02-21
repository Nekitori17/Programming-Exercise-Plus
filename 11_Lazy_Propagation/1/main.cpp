#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;
ll a[MAXN];
ll t[MAXN * 4];
ll lazy[MAXN * 4];

void push(ll id, ll l, ll r) {
  if (lazy[id] != 0) {
    ll mid = (l + r) / 2;

    ll val = lazy[id];
    t[id * 2] += val * (mid - l + 1);
    lazy[id * 2] += val;

    t[id * 2 + 1] += val * (r - mid);
    lazy[id * 2 + 1] += val;

    lazy[id] = 0;
  }
}

void build(ll id, ll l, ll r) {
  if (l == r) {
    t[id] = a[l];
    return;
  }

  ll mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  t[id] = t[id * 2] + t[id * 2 + 1];
};

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
  if (v < l || u > r)
    return;

  if (u <= l && r <= v) {
    t[id] += val * (r - l + 1);
    lazy[id] += val;
    return;
  }

  push(id, l, r);

  ll mid = (l + r) / 2;
  update(id * 2, l, mid, u, v, val);
  update(id * 2 + 1, mid + 1, r, u, v, val);
  t[id] = t[id * 2] + t[id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v) {
  if (v < l || u > r)
    return 0;

  if (u <= l && r <= v)
    return t[id];

  push(id, l, r);

  ll mid = (l + r) / 2;
  return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n >> q;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, 1, n);

  while (q--) {
    ll type;
    cin >> type;
    if (type == 1) {
      ll u, v, val;
      cin >> u >> v >> val;
      update(1, 1, n, u, v, val);
    } else {
      ll u;
      cin >> u;
      cout << get(1, 1, n, u, u) << "\n";
    }
  }

  return 0;
};