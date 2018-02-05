# [Nesting](https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/)

## Problem

給定一字串 **S**，假如 S 符合下述條件則可稱字串 S 有 properly nested 的性質。

- S is empty;
- S has the form "(U)" where U is a properly nested string;
- S has the form "VW" where V and W are properly nested strings.

例如 "(()(())())" 為 properly nested，但 "())" 則否。現給定一函式傳入字串 S，如為 properly nested 則回傳 **1**，否則回傳 **0**。

- Assume
  - N is an integer within the range [0..1,000,000]
  - String S consists only of the characters "(" and/or ")".

- Complexity (worst-case)
  - Time complexity is O(N)
  - Space complexity is **O(1)**

## Idea

給定一計數 `count` 來計算是否每個 parenthesis 都有另一個對應的結果。

- 對字串 S 進行巡訪並對每個字元進行比較。
  - 如果字元為 '(' 則 count 加 1。
  - 如果字元為 ')' 則 count 減 1。
    - count 為負數，則字串不為 properly nested 並回傳 0
- 尋訪結束後檢查 count 數，如果等於 0，則代表 parenthesis 有正確倆倆對應，因此字串 S 為 properly nested，反之則否。

> 與之前的 [Brackets](https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/) 問題最大的不同點為，空間複雜度必須是 O(1) 即常數大小，不能跟著 N 的大小變動

## Code

[Nesting.cpp](Nesting.cpp)

```cpp
#include <string>

using namespace std;

int solution(string &S) {
    int round_count = 0;
    for (auto& c : S) {
        if (c == '(') {
            round_count += 1;
        } else {
            round_count -= 1;
            if (round_count < 0) return 0;
        }
    }
    return (round_count == 0) ? 1 : 0;
}
```

## Reference

- [solution-to-nesting-by-codility](https://codesays.com/2014/solution-to-nesting-by-codility/)