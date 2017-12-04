# [PassingCars](https://codility.com/programmers/lessons/5-prefix_sums/passing_cars/)

## Problem

給定一個包含長度為`N`的數組`A`，其中`A`的值為`0`或`1`，計算當中`(A[P] = 0, A[Q] = 1)`的組數數量，其中`0 < P < Q < N`。如當`A = [0, 1, 0, 1, 1]`時，符合條件的數組為`(0,1),(0,3),(0,4),(2,3), (2,4)`。

> 當數組數量超過**1,000,000,000**時則回傳`-1`

- Assume
  - N is an integer within the range [1..100,000];
  - Each element of array A is an integer that can have one of the following values: 0, 1.

- Complexity(worst-case)
  - Time complexity - O(N)
  - Space complexity - O(1)

## Idea

- 設定數組總量`sum = 0`與數組累加數`count = 0`。
- `for 0 ... N-1`，當
  - `A[i] == 0`時`count += 1`。
  - `A[i] == 1`時將`count`值累加到`sum`中。且如果`sum > 1'000'000'000`則回傳`-1`

最後`sum`值即是所求值。

## Code

[PassingCars.cpp](PassingCars.cpp)