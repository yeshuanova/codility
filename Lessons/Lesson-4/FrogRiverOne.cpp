#include <vector>
#include <algorithm>

using namespace std;

int solution(int X, vector<int> &A) {
    
    auto path_vec = vector<bool>(X, false);
    int fill_count = 0;

    for (size_t idx = 0; idx < A.size(); ++idx) {
        int pos = A[idx] - 1;
        if (!path_vec[pos]) {
            ++fill_count;
            path_vec[pos] = true;
        }
        if (fill_count == X) return idx;
    }
    return -1;
}