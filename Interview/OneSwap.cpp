#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

bool solution(vector<int> &A) {
    
    auto A_sort =  A;
    sort(begin(A_sort), end(A_sort), greater<int>());
    
    int diff_count = 0;
    for (size_t idx = 0; idx < A.size(); ++idx) {
        if (A[idx] != A_sort[idx]) {
            ++diff_count;
        }
    }

    return (diff_count <= 2) ? true : false;
}