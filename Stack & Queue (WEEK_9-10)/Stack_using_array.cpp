//pathhh
// Intro 
// What is Stack
// What is queue
// Implementing stack and queue using inbuilt library
// Implementing stack using array
// Implementing queue using array
// Implementing stack using linked list
// Implementing queue using linked list
// Implementing stack using queue
// Implementing queue using stack (approach 1)
// Implementing queue using stack (approach 2)

//STACK--------------->
//It's the data structure which hold certain type of data it can be integer,pair,character etc. 
//Follow LIFO mechanism
//Last in first out
//Pop function removes the element , return nothing 
//Top function returns the most recently added element without removing it from the stack

//QUEUE--------------->
//Queue same as stack
//Follow FIFO mechanism
//First in first out

//STACK USING ARRAY
//(To this implementation i need maximum size of the array)
//It's the restriction of that (size)--it's not dynamic in nature



#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
private:
    // Array to hold elements
    int* stackArray;
    // Maximum capacity
    int capacity; 
     // Index of top element  
    int topIndex;   

public:
    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        // Initialize stack as empty
        topIndex = -1; 
    }

    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Pushes element x 
    void push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x; //++topIndex means first change the value and then use the value
    }

    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        return stackArray[topIndex--]; //topIndex-- means first use the value then change the value
    }

    // Returns top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }

   /* Returns true if the 
   stack is empty, false otherwise*/
    bool isEmpty() {
        return topIndex == -1;
    }
};

// Main Function
int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
}