#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        //Greedy approach 
        //keep smaller digits at the start
        //Then get rid of the larger ones-->K larger
        //Put one by one element in the stack if it's less than the top element then remove top element and do k--

        //Edge case-->
        //if(K==N) 

        //O(3n+k)
        //SC-O(2N)
        stack<char> st;
        for(int i=0; i<num.size() ; i++){
            while(!st.empty() && k>0 && (st.top()-'0') > (num[i]-'0')){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";

        string res="";
        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
        while(res.size() > 0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";
        return res;
    }
};