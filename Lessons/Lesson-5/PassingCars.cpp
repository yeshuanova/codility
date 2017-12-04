#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int sum = 0;
    int count = 0;
    for (auto value : A) {
        if (value == 0) {
            count += 1;
        } else {
            sum += count;
            if (sum > 1'000'000'000) {
                return -1;
            }
        }
    }
    return sum;
}