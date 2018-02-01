# [StoneWall](https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/)

## Problem

石牆建造問題。要建造一個長度為 N 公尺的石牆。給定ㄧ長度為 N 的 Array **H**，其中 H[i] 的值代表由 **i** 到 **i+1** 公尺位置的石牆高度。如 H[0] 為最左端的高度而 H[N-1] 則代表最右端的高度。且石牆由 Cuboid Stone Block (長方形區塊) 的石塊所堆疊而成。形狀如下所示

![example](https://codility-frontend-prod.s3.amazonaws.com/media/task_static/stone_wall/static/images/auto/4f1cef49cc46d451e88109d449ab7975.png)

現給定一個 function 傳入高度 Array **H** 後，傳回建造該牆所需的**最少** Cuboid Stone Block 數量。

- Assume
  - N is an integer within the range [1..100,000];
  - each element of array H is an integer within the range [1..1,000,000,000].
- Complexity (worst case)
  - Time complexity is O(N);
  - Space complexity is O(N)

## Idea

給定一 Stack 資料結構紀錄磚塊高度，**若有 Push 進入 Stack 的動作則將最小區塊數量累加**。之後對高度 Array H 進行巡訪：

- 如 Stack 為空則將 高度資料 Push 入 Stack 中。
- 若不為空，則比較 Stack 最上層資料與新高度資料
  - 假如 `height > stack.top()`，則將高度資料 Push 入 Stack。
  - 假如 `height < stack.top()`，則將 stack 中高度資料 pop 出去直到不滿足條件為止。
    - 若 `height != stack.top()`，則將高度資料 Push 入 Stack
    - 若相等則繼續處理下一筆資料。

> 需注意 Stack Container 的大小問題，不然可能出現 Segmentation Fault 錯誤。

## Code

[StoneWall.cpp](StoneWall.cpp)

```cpp
int solution(vector<int> &A) {
    auto container = vector<int>();
    container.reserve(A.size());    // Avoid Segmentation Fault
    auto stone_stack = stack<int, vector<int>>(container);

    int stone_num = 0;
    for (const auto& height : A) {

        if (stone_stack.empty()) {
            stone_stack.push(height);
            stone_num += 1;
            continue;
        }

        if (height > stone_stack.top()) {
            stone_stack.push(height);
            stone_num += 1;
        } else {
            while (!stone_stack.empty() && height < stone_stack.top()) {
                stone_stack.pop();
            }
            if (height != stone_stack.top()) {
                stone_stack.push(height);
                stone_num += 1;
            }
        }
    }
    return stone_num;
}
```
