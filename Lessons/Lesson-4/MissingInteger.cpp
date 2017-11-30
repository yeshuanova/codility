#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int solution(vector<int> &A) {
    
    auto counts = vector<int>(A.size(), 0);

    for_each(begin(A), end(A), [&](int value){
        
        if (value <= 0) return;
        if (counts.size() < size_t(value)) return;

        counts[value-1] += 1;
    });

    auto min_pos = find(begin(counts), end(counts), 0);

    return distance(begin(counts), min_pos) + 1;
}