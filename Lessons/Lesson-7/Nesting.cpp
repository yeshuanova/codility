#include <string>

using namespace std;

int solution(string &S) {
    int round_count = 0;
    for (auto& c : S) {
        if (c == '(') {
            round_count += 1;
        } else {
            round_count -= 1;
            if (round_count < 0) return 0;
        } 
    }
    return (round_count == 0) ? 1 : 0;
}