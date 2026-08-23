#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    vector<int> arr;
public:
    //Stand at the current day and count backward !!
    //Brute approach
    StockSpanner() {
        //constructor is empty
    }
    //TC-O(Total No. of days)
    //SC-O(Total No. of next calls)

    int next(int price) {
        StockSpanner();
        arr.push_back(price);
        int count=1;
        for(int i=arr.size()-2; i>=0 ; i--){
            if(arr[i] <= price) count++;
            else break;
        }
        return count;
    }
};



//2nd approach via stack
class StockSpanner {
    //TC-O(2*N)
    //SC-O(N)
private:
    stack<pair<int,int>> st;
    int ind;
public:
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind=ind+1;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans=ind-(st.empty() ? -1: st.top().second);
        st.push({price,ind});
        return ans;

    }
};