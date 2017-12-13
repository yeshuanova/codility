#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void checkMinIndex(float &min_idx, float &min_value, float mean, size_t idx) {
    if (mean < min_value) {
        min_value = mean;
        min_idx = idx;
    }
}

int solution(vector<int> &A) {
    float min_idx = 0;
    float min_value = numeric_limits<float>::max();

    for (size_t idx = 0; idx < A.size() - 1; ++idx) {
        checkMinIndex(min_idx, min_value, (A[idx] + A[idx+1]) / 2.0f, idx);
        if (idx < A.size() - 2) {
            checkMinIndex(min_idx, min_value, (A[idx] + A[idx+1] + A[idx+2]) / 3.0f, idx);
        }
    }
    return min_idx;
}