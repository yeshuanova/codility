#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int solution(vector<int> &A) {

    auto check_vec = vector<bool>(A.size(), 0);
    for (auto value : A) {

        if ( value < 1 || size_t(value) > A.size()) return 0;
        
        if (check_vec[value - 1]) return 0;

        check_vec[value - 1] = true;
    }
    return 1;
}