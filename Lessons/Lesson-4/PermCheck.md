# [PermCheck](https://codility.com/programmers/lessons/4-counting_elements/perm_check/)

## Problem

給定一個長度為 **N** 的 Array **A**，假如 **A** 包含 **1** 到 **N** 的所有整數，則稱該 Array 具有 **Permutation **的性質。如 A = [4, 1, 3, 2] 則 A 為 Permutation，若 A = [4, 1 ,3] 則不具備 Permutation 的特性。

- Assume
  - N is an integer within the range [1..100,000];
  - Each element of array A is an integer within the range [1..1,000,000,000].

- Complexity(Worst-Case):
  - Time complexity is O(N)
  - Space complexity is O(N)

## Idea

因 Array 中每個數值應該只出現一次，因此可建立一個與原始資料相同大小的 Counting Array 來記錄每個數字是否出現過，若**有重複出現過**或**有數字大小超出 N**，則可判定不具備 Permutation 的特性。反之若全部均通過則可確定 **A** 為 Permutation Array。

## Code

[PermCheck.cpp](PermCheck.cpp)

```cpp
int solution(vector<int> &A) {

    auto check_vec = vector<bool>(A.size(), 0);
    for (auto value : A) {

        if ( value < 1 || size_t(value) > A.size()) return 0;
        
        if (check_vec[value - 1]) return 0;

        check_vec[value - 1] = true;
    }
    return 1;
}
```