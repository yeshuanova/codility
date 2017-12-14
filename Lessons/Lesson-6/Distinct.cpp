#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <climits>

using namespace std;

int solution(vector<int> &A) {
    
    int dist_value = 0;
    int current = std::numeric_limits<int>::max();
    
    std::sort(begin(A), end(A), std::less<int>());
    std::for_each(begin(A), end(A), [&](int value) {
        if (value != current) {
            current = value;
            dist_value += 1;
        }
    });

    return dist_value;
}