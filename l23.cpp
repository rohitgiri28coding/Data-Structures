// Valid Parentheses

#include <iostream>
#include <stack>
using namespace std;

class ValidParentheses {
    stack<char> s;

public:
    char convertBracket(char ch) {
        if (ch == ']') return '[';
        if (ch == '}') return '{';
        if (ch == ')') return '(';
        return 0;
    }

    bool isValid(string str) {
        for (char c : str) {
            if (c == '[' || c == '{' || c == '(') {
                s.push(c);
            } else {
                // Check if stack is empty first
                if (s.empty() || convertBracket(c) != s.top()) {
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};

int main() {
    ValidParentheses v;
    cout << v.isValid("{[()]}") << endl; // 1 (true)
    cout << v.isValid("{[(])}") << endl; // 0 (false)
    cout << v.isValid(")") << endl;      // 0 (false)
    return 0;
}
