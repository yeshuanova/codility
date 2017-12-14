# Distinct

## Problem

給定一長度為`N`的數組`A[0], A[1], ...,A[N]`，找出`A`中**Distinct Value**。假設`A = [2, 1, 1, 2, 3, 1]`則獨立整數為`[1, 2, 3]`，因此**Distinct Value**為`3`。

- Assume
  - N is an integer within the range [0..100,000]
  - Each element of array A is an integer within the range [−1,000,000..1,000,000].

- Complexity(worst-case)
  - Time complexity - O(N*log(N))
  - Space complexity - O(N)

## Idea

將`A`進行排序後對`A`進行尋訪，統計所出現不同數字的次數後，即可得出 Distinct Value。

## Code

[Distinct.cpp](Distinct.cpp)