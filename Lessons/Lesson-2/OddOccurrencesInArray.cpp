#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int unpair_num = 0;
    for (auto value : A) {
        unpair_num ^= value;
    }
    return unpair_num;
}

