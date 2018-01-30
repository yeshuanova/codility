# [FrogRiverOne](https://codility.com/programmers/lessons/4-counting_elements/frog_river_one/)

## Problem

青蛙過河問題。給定一數組 A[0], A[1]], ..., A[N-1] 與整數 X，其中 A[i] <= X。求 **1** 到 **X** 中所有整數均出現過的索引值。如 A = [1, 3, 1, 4, 2, 3, 5, 4]，則當 A[6] = 5 時滿足條件，所求索引值即為 **6**。

- Assume
  - N and X are integers within the range [1..100,000];
  - Each element of array A is an integer within the range [1..X].

- Complexity(worst-case)
  - Time complexity - O(N);
  - Space complexity - O(X)

## Idea

先建立一長度為 **X** 的Array，並循序統計 A 中的數值是否出現過並計算未出現過次數`U`。假都出現過代表`U == X`，則循序到的位置即為所求數值。

## Code

[FrogRiverOne.cpp](FrogRiverOne.cpp)

```cpp
int solution(int X, vector<int> &A) {
    
    auto path_vec = vector<bool>(X, false);
    int fill_count = 0;

    for (size_t idx = 0; idx < A.size(); ++idx) {
        int pos = A[idx] - 1;
        if (!path_vec[pos]) {
            ++fill_count;
            path_vec[pos] = true;
        }
        if (fill_count == X) return idx;
    }
    return -1;
}
```