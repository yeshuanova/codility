#include <vector>
#include <iterator>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

int solution(vector<int> &A) {

    const auto sum = std::accumulate(begin(A), end(A), 0);
    
    int result = std::numeric_limits<int>::max();
    int sum_l = 0;
    for (size_t idx = 0; idx < A.size() - 1; ++idx){
        sum_l += A[idx];
        result = std::min(result, abs(sum_l - (sum - sum_l)));
    }

    return result;
}