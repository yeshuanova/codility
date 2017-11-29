# [FrogJmp](https://codility.com/programmers/lessons/3-time_complexity/frog_jmp/)

## Problem

給定數字`X`與`Y`與移動距離`D`，計算至少需要移動多少次才能從`X`超過`Y`的位置。如`X = 10, Y = 85, D = 30`，則需要移動`3`次才能從`X`到`Y`的位置。

- Assume
  - X, Y and D are integers within the range [1..1,000,000,000];
  - X ≤ Y.

- Complexity(worst-case)
  - Time complexity - O(1);
  - space complexity - O(1).

## Idea

計算`X`與`Y`之間的距離`R`後，判斷距離`R`對是否能被整除，如果可以直接計算`(Y - X) / D`。如果無法整除則必須多移動一次才能越過`Y`，即計算`(Y - X) / D + 1`。

> 注意`X == Y`時的特殊狀況處理。
> 若直接用`std::ceil`來處理，可能會遇到浮點數精度問題。

## Code

[FrogJmp.cpp](FrogJmp.cpp)