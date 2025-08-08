// Stock Span Problem

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpan {
    stack<int> pH; // stores indices

public:
    void calculateSpan(vector<int> prices) {
        vector<int> span(prices.size());

        for (int i = 0; i < prices.size(); i++) {
            // Pop while stack is not empty and current price >= price at top index
            while (!pH.empty() && prices[pH.top()] <= prices[i]) {
                pH.pop();
            }

            // If stack is empty, span = i + 1
            // Else, span = difference between current index and last higher price index
            span[i] = pH.empty() ? (i + 1) : (i - pH.top());

            // Push current index
            pH.push(i);
        }

        // Print result
        for (int i : span) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    StockSpan s;
    s.calculateSpan(price);
    return 0;
}
