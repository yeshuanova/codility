
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <iterator>
#include <tuple>

using namespace std;

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