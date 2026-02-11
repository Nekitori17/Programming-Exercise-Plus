#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;
  vector<vector<ll>> gp(n, vector<ll>(n));
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < n; j++)
      cin >> gp[i][j];

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  vector<vector<ll>> dist(n, vector<ll>(n, 1e18));
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
  pq.push({gp[0][0], {0, 0}});
  dist[0][0] = gp[0][0];

  while (!pq.empty())
  {
    ll d = pq.top().first;
    ll x = pq.top().second.first;
    ll y = pq.top().second.second;
    pq.pop();

    if (d > dist[x][y])
      continue;

    for (ll i = 0; i < 4; i++)
    {
      ll nx = x + dx[i];
      ll ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;

      ll nd = d + gp[nx][ny];
      if (nd < dist[nx][ny])
      {
        dist[nx][ny] = nd;
        pq.push({nd, {nx, ny}});
      }
    }
  }

  cout << dist[n - 1][n - 1] << endl;

  return 0;
};