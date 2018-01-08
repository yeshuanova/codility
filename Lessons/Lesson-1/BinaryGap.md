# [BinaryGap](https://codility.com/programmers/lessons/1-iterations/binary_gap/)

## Problem

輸入一個數值，找出該數值的二進位表示數字中，包夾在 **1** 中間的 **0** 的最長字串，如數字 **9** 的二進位表示為 **1001**，則 binary gap 為 **2**。數字 **8** 的二進位表示為 **1000**，則 binary gap 為  **0**。

- Assume
  - N is an integer within the range [1..2,147,483,647].

- Complexity (Worst-Case)
  - Time complexity - O(log(N))
  - Space complexity - O(1)

## Ideas

將資料以二進位模式進行 shift 位移，並與數字 **1** 做 **and** 運算，如果為 **0** 則累加 gap 寬度，如為 **1** 則比較累加寬度與最長寬度，如大於最長寬度則將累加寬度設為最常寬度，直到所有資料比較完畢為止。

## Example

[BinaryGap.cpp](BinaryGap.cpp)

```cpp
int solution(int N) {
    const int b_size = sizeof(N) * 8;
    bool start_count = false;
    int max_gap = 0;
    int gap = 0;s

    for (int shift = 0; shift < b_size; ++shift) {    
        if ((N >> shift) & 1) {
            if (start_count) {
                max_gap = std::max(gap, max_gap);
            }
            start_count = true;
            gap = 0;
        } else {
            ++gap;
        }
    }
    return max_gap;
}
```
