# [MinAvgTwoSlice](https://codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/)

## Problem

給定一長度為 **N** 的非零數組 A[0], A[1], ..., A[N-1]，存在 (P, Q) 且 0 <= P < Q < N。找出使 **(A[P] + A[P+1] + ... + A[Q])/(Q-P+1)** 為**最小**的 **P** 值。

假定數組為 A = [4, 2, 2, 5, 1, 5, 8]，則 Slice(1, 2) = (2+2)/2 = 2 ， Slice(1, 4) = (2+2+5+1)/4 = 2.5。最後可得最小起始值為 **1**。

- Assume
  - N is an integer within the range [2..100,000];
  - Each element of array A is an integer within the range [−10,000..10,000].

- Complexity(Worst-Case)
  - Time complexity - O(N)
  - Space complexity - O(N)

## Idea

可經由數學[證明](https://github.com/daotranminh/playground/blob/master/src/codibility/MinAvgTwoSlice/proof.pdf)，只要檢查長度為 **2** 與 **3** 的連續數組即可得出最小值。

## Code

[MinAvgTwoSlice.cpp](MinAvgTwoSlice.cpp)

```cpp
void checkMinIndex(float &min_idx, float &min_value, float mean, size_t idx) {
    if (mean < min_value) {
        min_value = mean;
        min_idx = idx;
    }
}

int solution(vector<int> &A) {
    float min_idx = 0;
    float min_value = numeric_limits<float>::max();

    for (size_t idx = 0; idx < A.size() - 1; ++idx) {
        checkMinIndex(min_idx, min_value, (A[idx] + A[idx+1]) / 2.0f, idx);
        if (idx < A.size() - 2) {
            checkMinIndex(min_idx, min_value, (A[idx] + A[idx+1] + A[idx+2]) / 3.0f, idx);
        }
    }
    return min_idx;
}
```

## Reference

- [daotranminh - GitHub](https://github.com/daotranminh/playground/blob/master/src/codibility/MinAvgTwoSlice/proof.pdf)

- [Martinkysel - Solution](https://www.martinkysel.com/codility-minavgtwoslice-solution/)