#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            // A collision only happens if top is moving RIGHT (+) and current is moving LEFT (-)
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (st.back() < abs(ast)) {
                    st.pop_back(); // The right-moving top asteroid explodes; continue checking
                    continue;
                } else if (st.back() == abs(ast)) {
                    st.pop_back(); // Both asteroids explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // The current left-moving asteroid explodes
                    break;
                }
            }
            
            // If the current asteroid wasn't destroyed, push it to the stack
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};