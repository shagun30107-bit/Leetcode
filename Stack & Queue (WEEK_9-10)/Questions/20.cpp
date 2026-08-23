#include <bits/stdc++.h>
using namespace std;

//TC-O(N)
//Put all th openning bracket in the stack whenever closed bracket come check it with top element of stack
//In the last if stack is empty that means all pair up else no 
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();
                if(s[i]==')' && ch=='(' || s[i]==']' && ch=='[' || s[i]=='}' && ch=='{') continue;
                else return false;
            }
        }
        return (st.empty());
    }
};