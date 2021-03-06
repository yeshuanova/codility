# [Brackets](https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/)

## Problem

給定一字串 S，其中每個 字元(char)為 "**[](){}**" 其中之一。現若下列條件成立

- S is empty;
- S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
- S has the form "VW" where V and W are properly nested strings.

則可稱 S 為 **properly nested**。如 S = "{[()()]} 則成立。反之若 S = "([)()]" 則為否。

- Assume
  - N is an integer within the range [0..200,000];
  - String S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".

- Complexity(worst-case)
  - Time complexity is O(N);
  - Space complexity is O(N) (not counting the storage required for input arguments).

## Idea

建立一個 **Stack Container**，對 String S 中每個值進行尋訪巡訪

- 假如 char **s** 為 "**(**", "**[**", "**{**" 其中之一，則將其放入 stack 中。
- 如果不為上列的 char 之一，則取出在 stack 中最上面的 char 進行比對是否為對應的 char 如 `'()', '[]', '{}'`。如果不是則代表 string 不滿足條件（回傳 0）。如果為對應的 char 則移除 stack 中最上面的字元。
- 反覆處理直到尋訪結束。假如處理完的 stack 為空則帶表 string 滿足條件，反之則否。

## Code

[Brackets.cpp](Brackets.cpp)

```cpp
const auto pairs = vector<tuple<char, char>>{
    make_tuple('(', ')'),
    make_tuple('{', '}'),
    make_tuple('[', ']')
};

bool isPaired(char lhs, char rhs) {
    for (auto &p : pairs) {
        if (lhs == std::get<0>(p) && rhs == std::get<1>(p)) {
            return true;
        }
    }
    return false;
}

bool isLeft(char s) {
    for (auto &p : pairs) {
        if (s == std::get<0>(p)) return true;
    }
    return false;
}

int solution(string &S) {

    // Check size of string if it is odd number
    if ((S.size() % 2) == 1) return 0;

    auto buffer = std::stack<char>();

    for (char s: S) {
        if (isLeft(s)) {
            buffer.push(s);
            continue;
        }

        const auto pre_char = buffer.top();

        if (isPaired(pre_char, s)) {
            buffer.pop();
        } else {
            return 0;
        }
    }
    return buffer.empty() ? 1 : 0;
}
```

## Reference

- [codility-brackets](http://thisthread.blogspot.tw/2014/11/codility-brackets.html)
- [solution-to-brackets-by-codility](https://codesays.com/2014/solution-to-brackets-by-codility/)
- [codility-brackets-solution](https://www.martinkysel.com/codility-brackets-solution/)
