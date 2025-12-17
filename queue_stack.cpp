#include <iostream>
using namespace std;
// Reuse the same Node structure
struct Node {
 int data;
 Node* next;
};
class Stack {
    private:
        Node* top; // points to the top node of the stack
    public:
        Stack() {
             top = NULL;} // constructor

        ~Stack() {
        while (!isEmpty()) {
            pop();
        }
        }

        bool isEmpty(){
            return top==NULL;
        }
       
        void push(int value) {
        Node* newNode=new Node();
        newNode->data=value;
        newNode->next=top;
        top=newNode;
        }
        
        void pop() {
        
            if (isEmpty()) {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }

            Node* temp = top;   // store current top
            top = top->next;    // move top to next node
            delete temp;        // delete old top
        }
        
        int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1;
        }
        return top->data;
        }
        
        void display() {
        if (isEmpty) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack (top to bottom): ";
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class Queue {
    private:
        Node* front; // points to the first node
        Node* rear; // points to the last node
    public:
    Queue() {
        front = rear = NULL;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == NULL;
    }
    // Function to add a new element to the queue
    void enqueue(int value) { 
        Node* newNode=new Node();
        newNode->data=value;
        newNode->next=NULL;

        if(isEmpty()){
            front=rear=newNode;
           
        }else{
            rear->next=newNode;
            rear=newNode;
        }


    } 
    // Function to remove the front element 
    void dequeue() { 
        if(isEmpty()){
            cout<<"the queue is empty. "<<endl;

        }else if(front==rear){
            Node* temp=front;
            front=rear=NULL;
            delete temp;
        }else{
            Node* temp=front;
            front=front->next;
            delete temp;
        }
    } 
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing at front." << endl;
            return -1;
        }
        return front->data;
    }
   
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue (front to rear): ";
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    };

main() {
        Stack s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.display(); // Expected: 30 20 10

        Queue q;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.display(); // Expected: 10 20 30
        return 0;
}
