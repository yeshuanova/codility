# CyclicRotation

## Problem

給定一個 Array **A**，將其往右環形移動 **K** 次後，回傳結果。假如 Array **A** = [3, 8, 9, 7, 6] 而移動次數 **K** = 3，則回傳的 Array 內容為 [9, 7, 6, 3, 8]。

- Assume
  - N and K are integers within the range [0..100];
  - each element of array A is an integer within the range [−1,000..1,000].

- Complexity (No, focus on correctness)

## Idea

1. 先計算移動後對應的資料的開始位置。（使用**mod**）
2. 並使用 C++ 中的 std::rotate() 函數，將 Array 中的資料位置重新排序後回傳。

## Code

[CyclicRotation.cpp](CyclicRotation.cpp)

```cpp
vector<int> solution(vector<int> &A, int K) {
    // Check empty vector
    if (A.empty()) return vector<int>();
    
    const int begin_idx = A.size() - K % A.size();
    rotate(begin(A), begin(A) + begin_idx, end(A));
    
    return A;
}
```