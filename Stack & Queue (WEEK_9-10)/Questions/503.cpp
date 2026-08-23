#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> NGE(nums.size());
        stack<int> st;
        for(int i=2*nums.size() ; i>=0 ; i--){
            while(!st.empty() && st.top()<= nums[i% nums.size()]) st.pop();
            if(i< nums.size()) {
                if(st.empty()) NGE[i]= -1;
                else NGE[i]=st.top();
            }
            st.push(nums[i%nums.size()]);
        }
        return NGE;
    }
};