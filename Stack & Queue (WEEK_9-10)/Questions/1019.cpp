#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;

        // Convert linked list to array
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(arr.size(), 0);
        stack<int> st;

        // Traverse from right to left
        for (int i = arr.size() - 1; i >= 0; i--) {

            // Remove elements smaller than or equal to current
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // Top is the next greater element
            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};