# [Fish](https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/)

## Problem

**大魚吃小魚遊戲**。給定兩個一長度為 N 的數列 A 與 B ( N 不為 0)。其中 A[P] 代表第 P 隻魚的**大小**，而 B[P] 代表第 P 隻魚的**行進方向**。**B[P] = 0** 代表魚往 **上游（upstream）**移動，反之 **B[P] = 1** 則代表往 **下游（downstream）**移動。

現有兩個位置 P 與 Q 且 P < Q，則代表 P 在 Q 的上游(upstream)。當 P 與 Q 之間沒有其他魚（PQ 相鄰)且兩隻魚相互面對（ **B[P] = 1** 且 **B[Q] = 0**），則大魚會吃掉小魚。 

- A[P] > A[Q] 則 P 吃掉 Q, 且 P 繼續往下游(downstream)移動。
- A[Q] > A[P] 則 Q 吃掉 P, 且 Q 繼續往上游(upstream)移動。

假設每隻魚的行進速度相等且方向永遠不變，給定一函數計算 **最後有多少魚還活著**。

- Assume
  - N is an integer within the range [1..100,000];
  - Each element of array A is an integer within the range [0..1,000,000,000];
  - Each element of array B is an integer that can have one of the following values: 0, 1;
  - The elements of A are all distinct.

- Complexity(worst case)
  - Time complexity is O(N);
  - Space complexity is O(N)

## Idea

### Stack Method

給定一個 stack count 來記錄現在存活的魚位置，接著將每隻魚的索引(Index)放入 Stack 中。

- 假如 stack 為空，則將現在的 index 加入 stack 中
- 如果不為空，則檢查新位置與 stack 中最上層的 index 所對應的行進方線是否相互面對。
  - 檢查新加入 index 是否與舊資料相互面對且大於舊資料，如成立則將舊 index 移出 stack。重複檢查舊 index 資料直到不成立為止後，再將新 index 加入 stack 中。
  - 如果非相互面對，則直接將 index 加入 stack 中。
- 執行完畢後檢查 count 大小，該大小極為**存活數量**。

## Code

- [Fish.cpp](Fish.cpp)

```cpp
int solution(vector<int> &A, vector<int> &B) {
    auto count = stack<int>();

    for (size_t idx = 0; idx < A.size(); ++idx) {
        int size = A[idx];
        int dir = B[idx];

        if (count.empty()) {
            count.push(idx);
        } else {
            while(!count.empty() && dir - B[count.top()] == -1 && A[count.top()] < size) {
                count.pop();
            }

            if (!count.empty()) {
                if (dir - B[count.top()] != -1) count.push(idx);
            } else {
                count.push(idx);
            }
        }
    }
    return count.size();
}
```

## Reference

- [Codility Fish](https://rafal.io/posts/codility-fish.html)
- [Cody Say](https://codesays.com/2014/solution-to-fish-by-codility/)