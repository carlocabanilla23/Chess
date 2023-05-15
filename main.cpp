#include <iostream>
#include "point.h"
#include "knight.h"

using namespace std;

int main() {
    while (true) {
        cout << "Enter start point separated by space: ";
        int sx, sy, ex, ey;
        cin >> sx >> sy ;
        cout << "End start point separated by spaces: ";
        cin >> ex >> ey;
        Point start(sx, sy, 0);
        Point end(ex, ey, 0);

        cout << "Enter obstacles separated by spaces (end with -1 -1): ";
        vector<Point> obstacles;
        while (true) {
            int x, y;
            cin >> x >> y;
            if (x == -1 && y == -1) {
                break;
            }
            obstacles.emplace_back(x, y, 0);
        }

        int dist = bfs(start, end, obstacles);
        if (dist == -1) {
            std::cout << "No path found\n";
        } else {
            std::cout << "Minimum distance: " << dist << '\n';
        }

        std::cout << "Do you want to continue? (y/n) ";
        char choice;
        std::cin >> choice;
        if (choice != 'y') {
            break;
        }
    }

    return 0;
}
