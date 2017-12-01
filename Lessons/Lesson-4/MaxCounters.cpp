#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

vector<int> solution(int N, vector<int> &A) {
    
    auto counts = vector<int>(N, 0);
    int max_count = 0;
    int current = 0;

    for_each(begin(A), end(A), [&](int value) {
        if (value >= (N+1)) {
            max_count = current;
        } else {
            const int idx = value - 1;
            counts[idx] = max(counts[idx], max_count);
            counts[idx] += 1;
            current = max(counts[idx], current);
        }
    });


    replace_if(begin(counts), end(counts),[&](int value){
        return value < max_count;},
        max_count);

    return counts;
}
