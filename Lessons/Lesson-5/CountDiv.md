# [CountDiv](https://codility.com/programmers/lessons/5-prefix_sums/count_div/)

## Problem

給定兩數字整數`A`與`B`，其中`A <= B`。設定一整數`K`並找出`A`到`B`之間（包含`A`與`B`）所有能被`K`整除的數字數量。

- Assume
  - A and B are integers within the range [0..2,000,000,000];
  - K is an integer within the range [1..2,000,000,000];
  - A ≤ B.

- Complexity(Worst-Case)
  - Time complexity - O(1)
  - Space complexity - O(1)

## Idea

可將問題拆成兩部份

1. `A`能被`K`整除，則只需考慮`A`到`B`之間的能被K整除的數字範圍大小。
1. `A`不能被`K`整除，則需考慮`A`到下一個可被整除數，以及`A`與`B`中間的範圍大小，來計算可被整除數量。

> 因為`A`與`B`數字大，需注意加減運算時**Overflow**或**Underflow**的問題。

## Code

[CountDiv.cpp](CountDiv.cpp)