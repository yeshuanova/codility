#include <algorithm>
#include <vector>
#include <string>
#include <array>
#include <iterator>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    
    auto genomic_arr = array<char, 4>{'A', 'C', 'G', 'T'};
    auto count = vector<vector<int>>(4, vector<int>(S.size()+1, 0));

    for (size_t g = 0; g < count.size(); ++g) {
        auto& g_count = count[g];
        for (size_t idx = 0; idx < S.size(); ++idx) {
            g_count[idx+1] = g_count[idx];
            if (S[idx] == genomic_arr[g]) g_count[idx+1] += 1;
        }
    }

    auto result = vector<int>(P.size(), 0);
    for (size_t idx = 0; idx < P.size(); ++idx) {
        const int p = P[idx];
        const int q = Q[idx];
        for (size_t g = 0; g < 4; ++g) {
            if (count[g][q+1] - count[g][p] > 0) {
                result[idx] = g + 1;
                break;
            }
        }
    }
    return result;
}
