#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

class doublyLinkedList {
    node* head;
    node* tail;

public:
    doublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void add_first(int value) {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = head;
        newnode->prev = NULL;

        if (head != NULL)
            head->prev = newnode;
        else
            tail = newnode; // list was empty

        head = newnode;
    }

    void add_last(int value) {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = tail;

        if (tail != NULL)
            tail->next = newnode;
        else
            head = newnode; // list was empty

        tail = newnode;
    }

    void add_at_position(int value, int position) {
        if (position == 0) {
            add_first(value);
            return;
        }

        node* temp = head;
        int counter = 0;

        while (temp != NULL && counter < position - 1) {
            temp = temp->next;
            counter++;
        }

        if (temp == NULL || temp->next == NULL) {
            add_last(value);
            return;
        }

        node* newnode = new node();
        newnode->data = value;
        newnode->next = temp->next;
        newnode->prev = temp;

        temp->next->prev = newnode;
        temp->next = newnode;
    }

    void delete_first() {
        if (head == NULL) {
            cout << "List is empty."<<endl;
            return;
        }

        node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    void delete_last() {
        if (tail == NULL) {
            cout << "List is empty."<<endl;
            return;
        }

        node* temp = tail;
        tail = tail->prev;

        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
    }

    void delete_at_position(int position) {
        if (position == 0) {
            delete_first();
            return;
        }

        node* temp = head;
        int counter = 0;

        while (temp != NULL && counter < position) {
            temp = temp->next;
            counter++;
        }

        if (temp == NULL) {
            cout << "Position out of range."<<endl;
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }

    void delete_by_value(int value) {
        node* temp = head;

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found."<<endl;
            return;
        }

        if (temp == head)
            delete_first();
        else if (temp == tail)
            delete_last();
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void display_forward() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }

    void display_backward() {
        node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL"<<endl;
    }
};

int main() {
    doublyLinkedList list;

    list.add_first(10);
    list.add_last(20);
    list.add_last(30);
    list.add_at_position(15, 1);

    list.display_forward();
    list.display_backward();

    list.delete_by_value(15);
    list.delete_at_position(1);

    list.display_forward();

    return 0;
}
