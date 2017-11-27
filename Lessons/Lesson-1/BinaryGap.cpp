
#include <algorithm>

int solution(int N) {
    
    const int b_size = sizeof(N) * 8;
    bool start_count = false;
    int max_gap = 0;
    int gap = 0;
    
    for (int shift = 0; shift < b_size; ++shift) {    
        if ((N >> shift) & 1) {
            if (start_count) {
                max_gap = std::max(gap, max_gap);
            }
            start_count = true;
            gap = 0;
        } else {
            ++gap;
        }    
    }
    return max_gap;
}