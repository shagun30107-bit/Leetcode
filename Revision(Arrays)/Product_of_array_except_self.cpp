#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int leftprod=1,rightprod=1;
        vector<int> output(nums.size(),1);
        for(int i=0;i<nums.size() ; i++){
            output[i]=leftprod;
            leftprod*=nums[i];
        }
        for(int i=nums.size()-1 ; i>=0 ; i--){
            output[i]*=rightprod;
            rightprod*=nums[i];
        }
        return output;
    }
};