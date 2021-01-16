class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), output = 0;
        stack<int> Stack;
        Stack.push(-1);
        for(int i = 0; i<n; ++i) {
            char ch = s[i];
            if(ch == '(') {
                Stack.push(i);
            } else {
                Stack.pop();
                if(Stack.empty()) {
                    Stack.push(i);
                } else {
                    output = max(output, i-Stack.top());
                }
            } 
        }   
        return output;
    }    
};
