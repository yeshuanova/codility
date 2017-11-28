# [OddOccurrencesInArray](https://codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/)

給定一個長度為 N 的 Array（N is odd number），除了其中一個數組外其他均兩兩相對。現給定一函式輸入Array後回傳唯一沒有成對存在的數值。

- Assume
  - N is an odd integer within the range [1..1,000,000];
  - each element of array A is an integer within the range [1..1,000,000,000];
  - all but one of the values in A occur an even number of times.

- Complexity(Worst Case)
  - Time complexity - O(N)
  - Time complexity - O(1)

## Idea

可應用[**XOR**運算特性](https://en.wikipedia.org/wiki/Exclusive_or)快速得到結果

- 交換律 - `A ^ B = B ^ A`
- 結合律 - `A ^ (B ^ C) = (A ^ B) ^ C`
- 恆等律 - `A ^ 0 = A`
- 歸零律 - `A ^ A = 0`

因此對一連續數組`[A_1, A_2, ..., A_n]`進行連續**XOR**運算，可將數組轉換為相同的數值兩兩相消，最後得到`0 ^ A = A`的結果，進而取得唯一沒有兩兩相對的數值。

## Code

[OddOccurrencesInArray](OddOccurrencesInArray.cpp)