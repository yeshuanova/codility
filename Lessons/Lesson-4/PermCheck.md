# [PermCheck](https://codility.com/programmers/lessons/4-counting_elements/perm_check/)

## Problem

給定一個長度為**N**的Array，檢查Array是否包含**1**到**N**的所有整數，若有則稱該Array有 **Permutation**的性質。如`A = [4, 1, 3, 2]`則`A`為Permutation，若`A = [4, 1 ,3]`則不為Permutation。

- Assume
  - N is an integer within the range [1..100,000];
  - Each element of array A is an integer within the range [1..1,000,000,000].

- Complexity(Worst-Case):
  - Time complexity is `O(N)`
  - Space complexity is `O(N)`

## Idea

因 Array 中每個數值應該只出現一次，因此可建立一個與原始資料相同大小的Array來記錄每個數字是否出現過，若有出現過或有數字大小超出 N，則可判定。若全部均通過則可確定為Permutation Array。

## Code

[PermCheck.cpp](PermCheck.cpp)