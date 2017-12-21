# [MaxProductOfThree](https://codility.com/programmers/lessons/6-sorting/max_product_of_three/)

## Problem

給定一長度為`N`的數組`A[0], A[1], ...,A[N-1]`，其中存在`P, Q, R`三個位置，使`A[P] * A[Q] * A[R]`的值為最大。現給定一數組`A`後回傳最大乘積數。

- Assume
  - N is an integer within the range [3..100,000];
  - Each element of array A is an integer within the range [−1,000..1,000].

- Complexity(worst-case)
  - Time complexity - O(N*log(N));
  - Space complexity - O(1)

## Idea

先將資料由大到小排序後得到一新數組`A'`，現考慮兩種情況：

1. 前三數相乘結果。
1. 因兩負數相乘為正，因此需考慮最小兩數字與最大數字相乘結果。

將上面兩種情況取最大數字，即為所求的最大乘積。

## Code

[MaxProductOfThree.cpp](MaxProductOfThree.cpp)

## Reference

- [Martinkysel's blog](https://www.martinkysel.com/codility-maxproductofthree-solution/)
