# [Triangle](https://codility.com/programmers/lessons/6-sorting/triangle/)

## Problem

給定三個數字`(P, Q, R)`，假如

- `P + Q > R`
- `Q + R > P`
- `R + P > Q`

則可稱該三數集合為**Triangular**。現在給定一數組`[A[0], A[1], ..., A[N-1] ]`，判斷其中是否存在任意三個數字為**Triangular**。如數組`A = [10, 2, 5, 1, 8, 20]`，其中`(A[0], A[2], A[4]) = (10, 5, 8)`即為**Triangular**。

- Assume
  - N is an integer within the range [0..100,000];
  - Each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

- Complexity(Worst-Case)
  - Time complexity - O(N*log(N));
  - Space complexity - O(N)

## Idea

先將數值由小到大排序後得到一新數組`[S[0], S[1], ..., S[N-1]]`，其中`S[i] <= S[i+k]`。由此特性可推導出

- `S[i] <= S[i+k]` => `S[i] < S[i+k] + S[i+k+1]`
- `S[i+k] <= S[i+k+1]` => `S[i+k] < S[i] + S[i+k+1]`

因此我們只需要檢查`S[i+k+1] < S[i] + S[i+k]`是否成立即可。

> 1. 注意 Overflow 與 Underflow 問題
> 1. N範圍為從**0**開始，因此需處理 N 的數值範圍問題。

## Code

[Triangle.cpp](Triangle.cpp)

## Reference

- [Solution to Triangle by codility](https://codesays.com/2014/solution-to-triangle-by-codility/)
