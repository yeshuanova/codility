#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    if (A.empty()) return 1;

    auto count_vec = vector<int>(A.size() + 1, 0);

    for_each(begin(A), end(A), [&](int value){ count_vec[value-1] += 1; });

    auto result = find(begin(count_vec), end(count_vec), 0);
    
    return distance(begin(count_vec), result) + 1;
}