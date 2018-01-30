# [OddOccurrencesInArray](https://codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/)

## Problem

給定一個長度為 **N** 的數組（N is odd number），除了其中一個數組外其他均兩兩相對。現給定一函式，輸入數組後可回傳唯一沒有成對存在的數值。

- Assume
  - N is an odd integer within the range [1..1,000,000];
  - each element of array A is an integer within the range [1..1,000,000,000];
  - all but one of the values in A occur an even number of times.

- Complexity(Worst-Case)
  - Time complexity - O(N)
  - Time complexity - O(1)

## Idea

可應用[**XOR**運算特性](https://en.wikipedia.org/wiki/Exclusive_or)快速得到結果

- 交換律 - `A ^ B = B ^ A`
- 結合律 - `A ^ (B ^ C) = (A ^ B) ^ C`
- 恆等律 - `A ^ 0 = A`
- 歸零律 - `A ^ A = 0`

因此對一連續數組 **A[0], A[1], ..., A[N-1]**，進行連續 **XOR** 運算，根據**交換率**與**結合率**可將連續數組內容轉換為相同的數值依照**歸零率**兩兩相消。且因存在唯一一個不相同的數值 **X**，最後依照**恆等率**得到`0 ^ X = X`的結果，由此可知 **X** 即為唯一一沒有兩兩相對的數值。

## Code

[OddOccurrencesInArray.cpp](OddOccurrencesInArray.cpp)

```cpp
int solution(vector<int> &A) {
    int unpair_num = 0;
    for (auto value : A) {
        unpair_num ^= value;
    }
    return unpair_num;
}
```
## Reference

- [Solution to Odd-Occurrences-In-Array by codility](https://codesays.com/2015/solution-to-odd-occurrences-in-array-by-codility/)