# CyclicRotation

## Problem

給定一個Array A，將其往右環形移動 **K** 次後，回傳結果。如Array `A = [3, 8, 9, 7, 6]`以及移動次數`K = 3`，則回傳的Array內容為`[9, 7, 6, 3, 8]`。

- Assume
  - N and K are integers within the range [0..100];
  - each element of array A is an integer within the range [−1,000..1,000].

- Complexity (No, focus on correctness)

## Idea

1. 先計算移動後對應的資料的開始位置。（使用**mod**）
1. 並使用C++中的std::rotate()函數，將Array中的資料位置重新排序後回傳。

## Code

[CyclicRotation.cpp](CyclicRotation.cpp)