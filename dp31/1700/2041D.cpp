#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct State {
    int x, y, dir, k;
    ll cost;
};

struct cmp {
    bool operator()(const State &a, const State &b) const {
        return a.cost > b.cost; // min-heap
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) cin >> maze[i];

    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') sx = i, sy = j;
            if (maze[i][j] == 'T') tx = i, ty = j;
        }
    //this was very imp making states for boht dir and k very very important bkc very important 
    vector<vector<vector<vector<ll>>>> dist(n, vector<vector<vector<ll>>>(m, vector<vector<ll>>(4, vector<ll>(4, LLONG_MAX))));

    priority_queue<State, vector<State>, cmp> pq;
    for (int d = 0; d < 4; d++) {
        dist[sx][sy][d][0] = 0;
        pq.push({sx, sy, d, 0, 0});
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!pq.empty()) {
        
        auto cur = pq.top();
        ll x = cur.x;
        ll y = cur.y;
        ll dir = cur.dir;
        ll k = cur.k;
        ll cost = cur.cost;
        pq.pop();
        if (cost > dist[x][y][dir][k]) continue;

        for (int nd = 0; nd < 4; nd++) {
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || maze[nx][ny] == '#') continue;

            ll ncost = cost + 1;
            int nk = (nd == dir ? k + 1 : 1);

            if (nk > 3) {
                ncost += 2;
                nk = 2;
            }

            if (ncost < dist[nx][ny][nd][nk]) {
                dist[nx][ny][nd][nk] = ncost;
                pq.push({nx, ny, nd, nk, ncost});
            }
        }
    }

    ll ans = LLONG_MAX;
    for (int d = 0; d < 4; d++)
        for (int k = 0; k < 4; k++)
            ans = min(ans, dist[tx][ty][d][k]);

    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
}
