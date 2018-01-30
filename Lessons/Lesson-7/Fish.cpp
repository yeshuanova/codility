
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int solution(vector<int> &A, vector<int> &B)
{    
    auto count = stack<int>();

    for (size_t idx = 0; idx < A.size(); ++idx) {
        int size = A[idx];
        int dir = B[idx];
        
        if (count.empty()) {
            count.push(idx);
        } else {
            while(!count.empty() && dir - B[count.top()] == -1 && A[count.top()] < size) {
                count.pop();
            }

            if (!count.empty()) {
                if (dir - B[count.top()] != -1) count.push(idx);
            } else {
                count.push(idx);
            }

        }

    }

    return count.size();
}