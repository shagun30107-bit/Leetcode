#include <bits/stdc++.h>
using namespace std;

//Approach_1
// Queue implementation using stack
class StackQueue1 {
private:
    stack <int> st1, st2;

public: 
    // Empty Constructor
    StackQueue1 () {
        
    }
    //TC-O(2*N)
    void push(int x) {
        //S1->S2
        //X->S1
        //S2->S1
        /* Pop out elements from the first stack 
        and push on top of the second stack */
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Insert the desired element
        st1.push(x);
        
        /* Pop out elements from the second stack 
        and push back on top of the first stack */
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    //O(1)
    // Method to pop element from the queue
    int pop() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Get the top element
        int topElement = st1.top();
        st1.pop(); // Perform the pop operation
        
        return topElement; // Return the popped value
    }
    //O(1)
    // Method to get the front element from the queue 
    int peek() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Return the top element
        return st1.top();
    }
    
    // Method to find whether the queue is empty
    bool isEmpty() {
        return st1.empty();
    }
};



//APPROACH-2
class StackQueue2 {
  public:
    stack<int> input, output;

    // Initialize your data structure here
    StackQueue2() {}

    // Push element x to the back of queue
    //O(1)
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        //O(N)
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    // Get the front element
    //O(1)
    int peek() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

    // Returns true if the queue is empty, false otherwise
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

int main() {
    StackQueue1 q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.pop() << endl;
    q.push(5);
    cout << "The front of the queue is " << q.peek() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

// int main() {
//     StackQueue2 q;
    
//     // List of commands
//     vector<string> commands = {"StackQueue", "push", "push", 
//                                "pop", "peek", "isEmpty"};
//     // List of inputs
//     vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

//     for (int i = 0; i < commands.size(); ++i) {
//         if (commands[i] == "push") {
//             q.push(inputs[i][0]);
//             cout << "null ";
//         } else if (commands[i] == "pop") {
//             cout << q.pop() << " ";
//         } else if (commands[i] == "peek") {
//             cout << q.peek() << " ";
//         } else if (commands[i] == "isEmpty") {
//             cout << (q.isEmpty() ? "true" : "false") << " ";
//         } else if (commands[i] == "StackQueue") {
//             cout << "null ";
//         }
//     }
    
//     return 0;
// }