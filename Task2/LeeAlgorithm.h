#ifndef IVANOVAMARIYA_LEEALGORITHM_H
#define IVANOVAMARIYA_LEEALGORITHM_H

#include <vector>
#include <queue>

using namespace std;

class LeeAlgorithm {

    // up - 1
    // right - 2
    // down - 3
    // left - 4

    /*
     * v - граф в виде матрицы смежности
     * sx, sy - координаты начала
     * fx, fy - координаты финиша
     *
     * (v[i][j] == 1) - в клетку нельзя пройти
     *
     * возвращает минимальное расстояние и путь от начала до финиша
     *
     *  [
     *      up - 1
     *      right - 2
     *      down - 3
     *      left - 4
     *  ]
     */

public:

    pair<int, vector<int>> static run(vector<vector<int>> &v, int sx, int sy, int fx, int fy) {
        // n, m - размерности матрицы
        int n = v.size();
        int m = v[0].size();

        // dist[i][j] минимальная дистанция до вершины i, j
        // prev[i][j] откуда пришли в вершину i, j (например если prev[i][j] == 2, то пришли слева)
        vector<vector<int>> dist(n, vector<int>(m, -1));
        vector<vector<int>> prev(n, vector<int>(m, -1));

        // прибавляются к индексам текущей вершины для достижения соседних (например cur.x + xx[i], cur.y + yy[i] - соседняя вершина)
        vector<int> xx = {-1, 0, 1, 0};
        vector<int> yy = {0, 1, 0, -1};

        // обычный поиск в ширину на матрице
        // очередь хранит индесы вершины
        queue<pair<int, int>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        while(q.size() != 0) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = cur.first + xx[i];
                int ny = cur.second + yy[i];

                // если не вышли за границы матрицы и вершина проходима и еще не посещена то идем в нее (добавляем в очередь)
                if(0 <= nx && nx < n && 0 <= ny && ny < m && v[nx][ny] != 1 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    prev[nx][ny] = i + 1;
                    q.push({nx, ny});
                }
            }
        }

        // пути не существует
        if(dist[fx][fy] == -1) return {-1, vector<int>()};

        int ans = dist[fx][fy];
        // минимальный путь от старта до финиша
        vector<int> path;

        // восстанавливаем путь начиная с конца (добавляем направление последнего движения и делаем шаг назад пока не дошли до стартовой вершины)
        while(sx != fx || sy != fy) {
            path.push_back(prev[fx][fy]);
            if(prev[fx][fy] == 1) {
                fx++;
            } else if(prev[fx][fy] == 2) {
                fy--;
            } else if(prev[fx][fy] == 3) {
                fx--;
            } else if(prev[fx][fy] == 4) {
                fy++;
            }
        }
        // разворачиваем путь так как восстанавливали путь начиная с конца [(конец -> начало) -> (начало -> конец)]
        reverse(path.begin(), path.end());

        return {ans, path};
    }

};

#endif
