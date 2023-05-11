#include <cstring>
#include "knight.h"

const int BOARD_SIZE = 8;
// horses moves
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(Point start, Point end) {
    bool visited[BOARD_SIZE][BOARD_SIZE];
    memset(visited, false, sizeof(visited)); // create a bool table
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
