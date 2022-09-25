#ifndef IVANOVAMARIYA_MINSUBARRAY_H
#define IVANOVAMARIYA_MINSUBARRAY_H

#include <vector>

using namespace std;

class MinSubarray {

public:

    // Поиск подмассива с максимальной суммой (Алгоритм Кадане 1984г)
    int static run(vector<int> &v) {
        int n = v.size();

        int ans = v[0],     // максимальная сумма
            ans_l = 0,      // левая граница максимального подмассива
            ans_r = 0,      // правая граница максимального подмассива
            sum = 0,        // текущая сумма
            minus_pos = -1; // переменная, которая запоминает левую границу (если текущая сумма превысила ответ, то обновляем ответ как ans_l = minus_pos + 1)

        for (int r = 0; r < n; r++) {

            // обновляем сумму
            sum += v[r];

            if (sum > ans) {
                // обновляем границы отрезка и максимальную сумму
                ans = sum;
                ans_l = minus_pos + 1;
                ans_r = r;
            }

            if (sum < 0) {
                // если сумма стала неположительной, то, согласно алгоритму Кадане, выбрасываем текущий отрезок
                sum = 0;
                minus_pos = r;
            }
        }

        return ans;
    }
};

#endif
