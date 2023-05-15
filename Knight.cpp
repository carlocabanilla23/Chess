#include <cstring>
#include "knight.h"

const int BOARD_SIZE = 8;
// horses moves
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(Point start, Point end, const std::vector<Point>& obstacles) {
    bool visited[BOARD_SIZE][BOARD_SIZE];
    memset(visited, false, sizeof(visited));
    for (const auto& obstacle : obstacles) {
        visited[obstacle.x][obstacle.y] = true;
    }
    std::queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        if (p.x == end.x && p.y == end.y) {
            return p.dist;
        }
        for (int i = 0; i < 8; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && !visited[nx][ny]) {
                q.push(Point(nx, ny, p.dist + 1));
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

