#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> st;
pair<ll, ll> ed;

ll ans = -1;

void bfs(vector<vector<bool>> &visited)
{
  queue<pair<pair<ll, ll>, ll>> q;
  q.push({st, 0});
  visited[st.first][st.second] = true;

  while (!q.empty())
  {
    pair<pair<ll, ll>, ll> curr = q.front();
    q.pop();

    if (curr.first.first == ed.first && curr.first.second == ed.second)
    {
      ans = curr.second;
      return;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
      ll nx = curr.first.first + dx[i];
      ll ny = curr.first.second + dy[i];

      if (nx >= 0 && nx < visited.size() && ny >= 0 && ny < visited[0].size() && !visited[nx][ny])
      {
        visited[nx][ny] = true;
        q.push({{nx, ny}, curr.second + 1});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m;
  cin >> n >> m;
  vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, true));
  for (ll i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (ll j = 0; j < m; j++)
    {
      if (s[j] == '.')
      {
        visited[i][j] = false;
      }

      if (s[j] == 'A')
      {
        st = {i, j};
        visited[i][j] = false;
      }
      else if (s[j] == 'B')
      {
        ed = {i, j};
        visited[i][j] = false;
      }
    }
  }

  bfs(visited);

  cout << ans;

  return 0;
};