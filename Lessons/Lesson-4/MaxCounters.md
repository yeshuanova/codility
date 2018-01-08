# [MaxCounters](https://codility.com/programmers/lessons/4-counting_elements/max_counters/)

## Problem

給定一個長度為 **N** ，數值均為 **0** 的 Counting Array - **C**，現在給定一個 Operating Array **A** 指定要執行的動作：

- **increase(X)** - `A[K] == X` 且 `1 <= X <= N`，則對執行`C[X-1] += 1`，即對`C[X-1]`執行累加動作。
- **max counter** - `A[K] == N + 1`，則將 C 中所有數字設為 **max(C)**（C 中存在的最大值）。

現在設 **N = 5**， Operating Array **A** 內容為

```c++
A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4
```

則執行後的Counting Array **C** 變動如下

```c++
A[0] = 3, C = [0, 0, 1, 0, 0]
A[1] = 4, C = [0, 0, 1, 1, 0]
A[2] = 4, C = [0, 0, 1, 2, 0]
A[3] = 6, C = [2, 2, 2, 2, 2]
A[4] = 1, C = [3, 2, 2, 2, 2]
A[5] = 4, C = [3, 2, 2, 3, 2]
A[6] = 4, C = [3, 2, 2, 4, 2]
```

現給定函式輸入 N 與 A 後回傳執行後的結果 C。如輸入 N = 5 與 A = [3, 4, 4, 6, 1, 4, 4]，則回傳結果為 [3, 2, 2, 4, 2]。

- Assume
  - N and M are integers within the range [1..100,000];
  - Each element of array A is an integer within the range [1..N + 1].

- Complexity(Worst-Case)
  - Time complexity - O(N+M);
  - Space complexity - O(N)

## Solution

設定兩個counting variable **max_count** 與 **current_max**，其中

- **max_count** - 目前 C 中的最小基底數字，若執行 **max counter** 動作則將 max_count 的值設為current_max 的值。
- **current_max** - 尋訪 A 執行**increase(X)**，紀錄檢查到的最大值。

執行步驟

- 建立大小為 **N** 的Array，初始值均為零。
- 對 **A** 進行巡訪
  - 若 A[K] 執行 **increase**
    - 判斷`C[A[K]-1] > max_count`是否成立，如果否則將 C[A[K]-1] 設定為 max_count。
    - 累加`C[A[K]-1]`。
    - 判斷`C[A[K]-1] > current_max`是否成立，如成立則將 C[A[K]-1] 設定為 current_max。
  - 若 A[K] 執行 **max_count**
    - 將 max_count 值設為 current_max 的值。

- 對 C 進行巡訪，如果`C[i] < max_count`成立，則將 C[i] 設為 max_count。
- 數組 **C** 即為所求的結果。

## Code

[MaxCounters.cpp](MaxCounters.cpp)

```cpp
vector<int> solution(int N, vector<int> &A) {
    
    auto counts = vector<int>(N, 0);
    int max_count = 0;
    int current = 0;

    for_each(begin(A), end(A), [&](int value) {
        if (value >= (N+1)) {
            max_count = current;
        } else {
            const int idx = value - 1;
            counts[idx] = max(counts[idx], max_count);
            counts[idx] += 1;
            current = max(counts[idx], current);
        }
    });


    replace_if(begin(counts), end(counts),[&](int value){
        return value < max_count;},
        max_count);

    return counts;
}
```

## Reference

- [Code-Say](https://codesays.com/2014/solution-to-max-counters-by-codility/)