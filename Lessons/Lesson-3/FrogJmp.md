# [FrogJmp](https://codility.com/programmers/lessons/3-time_complexity/frog_jmp/)

## Problem

給定數字 **X** 與 **Y** 與單次移動距離 **D**，計算至少需要移動多少次才能從 **X** 移至超過 **Y** 的位置。如 X = 10, Y = 85, D = 30，則需要移動 3 次才能從 **X** 到達 **Y** 的位置。

- Assume
  - X, Y and D are integers within the range [1..1,000,000,000];
  - X ≤ Y.

- Complexity(worst-case)
  - Time complexity - O(1);
  - space complexity - O(1).

## Idea

計算 **X** 與 **Y** 之間的距離 **R** 後，判斷距離 **R** 對是否能被整除，如果可以直接計 **R/D**。如果無法整除則必須多移動一次才能越過 **Y**，即計算 **(R/D) + 1**。

> 注意 **X 等於 Y** 時的特殊狀況處理。且若直接使用`std::ceil`來處理，可能會遇到浮點數精度問題。

## Code

[FrogJmp.cpp](FrogJmp.cpp)

```cpp
int solution(int X, int Y, int D) {
    
    const int dist = Y - X;

    if (dist % D == 0) {
        return dist / D;
    } else {
        return dist / D + 1;
    }
}
```