#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//Brute approach-->
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> NGE(nums.size());
        stack<int> st;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            while(!st.empty() && st.top()<= nums[i]) st.pop();
            if(st.empty()) NGE[i]= -1;
            else NGE[i]=st.top();
            st.push(nums[i]);
        }
        return NGE;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> NGE= nextGreaterElements(nums2);
        vector<int> ans(nums1.size());
        for(int i=0; i<nums1.size() ; i++){
            for(int j=0; j<nums2.size() ; j++){
                if(nums1[i]== nums2[j]){
                    ans[i]= NGE[j];
                    break;
                }
            }
        }
        return ans;
    }
};


//Optimal solution -->
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        stack<int> st;

        // Find NGE for every element of nums2
        for(int i = nums2.size() - 1; i >= 0; i--) {

            while(!st.empty() && st.top() <= nums2[i])
                st.pop();

            if(st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        // Answer nums1
        vector<int> ans;

        for(int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};