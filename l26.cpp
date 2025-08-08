#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class PreviousSmaller {
    stack<int> st; // stack to store elements

public:
    void findPreviousSmaller(const vector<int>& nums) {
        vector<int> prevSmaller(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements >= current from the stack
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }

            // If stack empty, no smaller element on left
            prevSmaller[i] = st.empty() ? -1 : st.top();

            // Push current element into stack
            st.push(nums[i]);
        }

        // Print result
        for (int x : prevSmaller) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> v = {3, 1, 0, 8, 6};
    PreviousSmaller ps;
    ps.findPreviousSmaller(v);
    return 0;
}
