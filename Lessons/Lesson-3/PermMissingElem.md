# [PermMissingElem](https://codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/)

## Problem

給定一數組`[A[0], A[1], ..., A[N]]`，其中`1 <= A[N] <= N+1`。找出唯一

- Assume
  - N is an integer within the range [0..100,000];
  - The elements of A are all distinct;
  - Each element of array A is an integer within the range [1..(N + 1)].

- Complexity(Worst-Case)
  - Time complexity - O(N);
  - Space complexity is O(1)

## Idea

建立一個長度為`N+1`的Counting Array，對原始數組每個位置統計是否存在，最後尋找沒有被統計到的值，該位置即為目標值。

## Code

[PermMissingElem.cpp](PermMissingElem.cpp)