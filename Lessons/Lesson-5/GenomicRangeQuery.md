# [GenomicRangeQuery](https://codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/)

## Problem

給定一長度為 N 的字串 S，其中 S 字元為 **A, C, G, T** 四種。每個字元有著不同的 **Impact Factor**，A = 1，C = 2，G = 3 與 T = 4。現給定另外兩個長度為 M 的數組 P 與 Q。找出所有在 S[P[K]] 與 S[Q[K]]之間最小的 Impact Factor數組。如給定以下數組

- S = "**CAGCCTA**"
- P = [2, 5, 0]  與 Q = [4, 5, 6]

因 P[0] = 2，Q[0] = 4，則 S[2] ~ S[4] 之間的字串為 GCC。因 G 和 C 的 Impact Factor 分別為 **3** 與 **2**，因此當 K = 0 時 Impact Factor 為 **2**，同樣的方式可適用於其他 K 值。最終可得出一數組 **F = [2, 4, 1]** 即為所求的最小 Impact Factor 列表。

- Assume
  - N is an integer within the range [1..100,000];
  - M is an integer within the range [1..50,000];
  - Each element of arrays P, Q is an integer within the range [0..N − 1];
  - P[K] ≤ Q[K], where 0 ≤ K < M;
  - String S consists only of upper-case English letters A, C, G, T.

- Complexity(worst-case)
  - Time complexity is O(N+M)
  - Space complexity is O(N)

## Idea

分別統計 A, C, G, T 四種字元在 S 中的變化位置，之後對 P[K] 與 Q[K] 中所對應的位置，從小的 Impact Factor 開始判斷是否有改變過數值。

- 給定長度為 **N+1** 的統計數組 C，分別統計 A, C, G, T 出現次數，其中 C['A'] 則代表 A 字元的統變化統計結果。
- 尋訪字串 **S**，假如 S[i] = "A" 則 `C['A'][i+1] = C['A'][i] + 1`，其他字元統計數值則維持原數字，即 `C['C'][i+1] = C['C'][i]`，同理當 S[i] 為其他字元時則累加對應字元在 C[i+1] 中的數值直到結束為止。
- 對 **P** 與 **Q** 進行巡訪，假如`(C['A'][Q[i]+1] - C['A'][P[i]]) > 0`成立，則代表範圍 ( P[i], Q[i] ) 之間字元 **A** 有出現。因此只要尋找出現過的字元，即可得知最小 Impact Factor 的值。

## Code

[GenomicRangeQuery.cpp](GenomicRangeQuery.cpp)

```cpp
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    
    auto genomic_arr = array<char, 4>{'A', 'C', 'G', 'T'};
    auto count = vector<vector<int>>(4, vector<int>(S.size()+1, 0));

    for (size_t g = 0; g < count.size(); ++g) {
        auto& g_count = count[g];
        for (size_t idx = 0; idx < S.size(); ++idx) {
            g_count[idx+1] = g_count[idx];
            if (S[idx] == genomic_arr[g]) g_count[idx+1] += 1;
        }
    }

    auto result = vector<int>(P.size(), 0);
    for (size_t idx = 0; idx < P.size(); ++idx) {
        const int p = P[idx];
        const int q = Q[idx];
        for (size_t g = 0; g < 4; ++g) {
            if (count[g][q+1] - count[g][p] > 0) {
                result[idx] = g + 1;
                break;
            }
        }
    }
    return result;
}
```

## Reference

- [Code-Says](https://codesays.com/2014/solution-to-genomic-range-query-by-codility/)
- [Gist](https://gist.github.com/arielm/9ca320825bc3602544fa05f5af4e0a1b)
- [CodeSay](https://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/)