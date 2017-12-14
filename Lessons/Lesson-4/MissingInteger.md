# [MissingInteger](https://codility.com/programmers/lessons/4-counting_elements/missing_integer/)

## Problem

給定一數組`A[0], A[1], ..., A[N-1]`，找出未出現在數組中的**最小正整數**。如`A = [1 ,2, 3]`則未出現最小正整數為`4`，若`A = [-1, -3]`，則未出現最小正整數為`1`。

- Assume
  - N is an integer within the range [1..100,000];
  - Each element of array A is an integer within the range [−1,000,000..1,000,000].

- Complexity(worst-cast)
  - Time complexity - O(N);
  - Space complexity - O(N)

## Idea

給定一大小為`N`的計數Array `C`，並對`A`中的元素進行計數，如`A[0] = 3`則`A[2] += 1`，若`A[i] <= 0`或`N < A[i]`則不給予計數。當統計完後尋找最先出現`A[i] == 0`的`i`值，`i+1`即為未出現的最小正整數。若無為0的數值，則`N+1`為未出現的最小正整數。

## Code

[MissingInteger.cpp](MissingInteger.cpp)