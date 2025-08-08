// Next greater element 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class NextGreater {
    stack<int> n; // stack to store elements

public:
    void findNextGreater(vector<int> nums) {
        vector<int> nextGreaterInt(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            // Pop elements smaller or equal to current
            while (!n.empty() && n.top() <= nums[i]) {
                n.pop();
            }

            // If empty, no greater element to the right
            nextGreaterInt[i] = n.empty() ? -1 : n.top();

            // Push current element
            n.push(nums[i]);
        }

        // Print result
        for (int x : nextGreaterInt) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> v = {6, 8, 0, 1, 3};
    NextGreater ng;
    ng.findNextGreater(v);
    return 0;
}
