
#include <vector>
#include <algorithm>
#include <climits>
#include <iterator>
#include <functional>

using namespace std;

int solution(vector<int> &A) {
    
    if (A.size() < 3) return 0;

    sort(begin(A), end(A), std::greater<int>());
    
    return max(A[0] * A[1] * A[2], A[0] * A[A.size() - 1] * A[A.size() - 2]);
}