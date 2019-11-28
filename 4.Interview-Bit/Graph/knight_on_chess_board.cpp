#define pii pair<int, pair<int, int>>
#define w(x) cout << (#x) << " is :" << x << "\n"
bool isSafe(int i, int j, int A, int B)
{
    if (i >= 0 && i < A && j >= 0 && j < B)
    {
        return true;
    }
    return false;
}
int bfs(vector<vector<int>> &visited, int x1, int y1, int x2, int y2, int A, int B)
{
    queue<pii> q;
    vector<int> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
    vector<int> dy = {-1, -2, -2, -1, 1, 2, 2, 1};
    q.push({x1, {y1, 0}});
    visited[x1][y1] = 1;
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        // w(f.first);
        // w(f.second.first);
        if (f.first == x2 && f.second.first == y2)
        {
            return f.second.second;
        }
        for (int i = 0; i < 8; i++)
        {

            // Important I made Mistake Here .... Cautious ...add the dx and dy to the front of the queue
            int nx = f.first + dx[i];
            int ny = f.second.first + dy[i];
            if (isSafe(nx, ny, A, B) && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;

                q.push({nx, {ny, f.second.second + 1}});
            }
        }
    }
    return -1;
}
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    vector<vector<int>> visited(A, vector<int>(B, 0));
    return bfs(visited, C - 1, D - 1, E - 1, F - 1, A, B);
}
