#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
  
    // Check empty vector
    if (A.empty()) return vector<int>();
    
    const int begin_idx = A.size() - K % A.size();
    rotate(begin(A), begin(A) + begin_idx, end(A));
    
    return A; 
}