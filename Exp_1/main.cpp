#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    int top;
    int capacity;
    T* arr;

public:

    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }


    ~Stack() {
        delete[] arr;
    }


    bool isEmpty() {
        return top == -1;
    }


    bool isFull() {
        return top == capacity - 1;
    }


    void push(T item) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << item << endl;
        } else {
            arr[++top] = item;
            cout << item << " pushed into stack." << endl;
        }
    }


    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    T getTop() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
            return T();
        }
        return arr[top];
    }
};

int main() {
    Stack<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.getTop() << endl;

    s.pop();
    cout << "Top element after pop: " << s.getTop() << endl;

    Stack<string> s2(3);
    s2.push("Hello");
    s2.push("World");

    cout << "Top element in string stack: " << s2.getTop() << endl;

    return 0;
}
