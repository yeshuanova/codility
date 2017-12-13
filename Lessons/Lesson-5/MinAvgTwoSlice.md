# [MinAvgTwoSlice](https://codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/)

## Problem

給定一長度為`N`的非零數組`A[0], A[1], ..., A[N-1]`，存在`(P,Q)`且`0 <= P < Q < N`。找出使`(A[P] + A[P+1] + ... + A[Q])/(Q-P+1)`為最小的`P`值。

假定數組為`A = [4, 2, 2, 5, 1, 5, 8]`，則`Slice(1, 2) = (2+2)/2 = 2`，`Slice(1, 4) = (2+2+5+1)/4 = 2.5`。最後可得最小起始值為`1`。

- Assume
  - N is an integer within the range [2..100,000];
  - Each element of array A is an integer within the range [−10,000..10,000].

- Complexity(Worst-Case)
  - Time complexity - O(N)
  - Space complexity - O(N)

## Idea

可經由數學[證明](https://github.com/daotranminh/playground/blob/master/src/codibility/MinAvgTwoSlice/proof.pdf)，只要檢查長度為`2`與`3`的連續數組即可得出最小值。

## Code

[MinAvgTwoSlice.cpp](MinAvgTwoSlice.cpp)

## Reference

- [daotranminh - GitHub](https://github.com/daotranminh/playground/blob/master/src/codibility/MinAvgTwoSlice/proof.pdf)

- [Martinkysel - Solution](https://www.martinkysel.com/codility-minavgtwoslice-solution/)