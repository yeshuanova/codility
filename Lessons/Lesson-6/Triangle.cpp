#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

int solution(vector<int> &A) {

    if (A.size() < 3) return 0;

    sort(begin(A), end(A), less<int>());

    for (size_t idx = 0; idx < A.size()-2; ++idx) {
        if (int64_t(A[idx]) + int64_t(A[idx+1]) > int64_t(A[idx+2])) {
            return 1;
        }
    }

    return 0;
}