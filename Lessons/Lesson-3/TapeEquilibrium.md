# [TapeEquilibrium](https://codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/)

## Problem

假定有一數組 A = [ A[0], A[1], ..., A[N-1] ] ，給定一索引位置 **P** 可切割數組為 A[0], A[1], ..., A[P-1] 與 A[P], ..., A[N-1]。找出使 **| (A[0] + A[1] + ... + A[P−1]) − (A[P] + A[P+1] + ... + A[N−1]) |** 為最小的 **P** 數值。

如 A = [3, 1, 2, 4, 3]，則當 **P = 1** 時，T[1] = |(A[0]) − (A[1] + A[2] + A[3] + A[4])| = |3 - 10| = 7。同理可得 T[4] = |10 - 3| = 7。

- Assume
  - N is an integer within the range [2..100,000];
  - Each element of array A is an integer within the range [−1,000..1,000].

- Complexity (Worst-Case)
  - Time complexity - O(N)
  - Space complexity - O(N)

## Idea

因為數組可拆分為左右兩邊相加的結果，因此可先計算數組加總量，再以此基礎來計算 **T[P]** 的右半邊的數量並得出最小值。

## Code

[TapeEquilibrium.cpp](TapeEquilibrium.cpp)

```cpp
int solution(vector<int> &A) {

    const auto sum = std::accumulate(begin(A), end(A), 0);
    
    int result = std::numeric_limits<int>::max();
    int sum_l = 0;
    for (size_t idx = 0; idx < A.size() - 1; ++idx){
        sum_l += A[idx];
        result = std::min(result, abs(sum_l - (sum - sum_l)));
    }

    return result;
}
```