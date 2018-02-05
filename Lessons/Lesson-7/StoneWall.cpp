
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &A) {
    auto container = vector<int>();
    container.reserve(A.size());    // Avoid Segmentation Fault

    auto stone_stack = stack<int, vector<int>>(container);

    int stone_num = 0;
    for (const auto& height : A) {

        if (stone_stack.empty()) {
            stone_stack.push(height);
            stone_num += 1;
            continue;
        }

        if (height > stone_stack.top()) {
            stone_stack.push(height);
            stone_num += 1;
        } else {
            while (!stone_stack.empty() && height < stone_stack.top()) {
                stone_stack.pop();
            }
            if (height != stone_stack.top()) {
                stone_stack.push(height);
                stone_num += 1;
            }
        }
    }
    return stone_num;
}