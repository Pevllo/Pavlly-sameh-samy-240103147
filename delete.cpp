#include<iostream>
using namespace std;
 struct node{
        int data;
        node * next;
    };


class linkedlist{
    node * head;

public:
    linkedlist(){head=NULL;}
    
    void add_first(int value){
        node* newnode=new node();
        
        if(head==NULL){
            head=newnode;
            newnode->next=NULL;
            newnode->data=value;}

        else{
            newnode->data=value;
            newnode->next=head;
            head=newnode;}
    }


    
    void add_last(int value){
        node * endelement;
        endelement=head;
        while(endelement->next!=NULL){
            endelement=endelement->next;
        }

        node * newnode=new node();
        endelement->next=newnode;
        newnode->data=value;
        newnode->next=NULL;
    }

    void add_at_position(int value, int position){
       node * x;
       x=head;
       int counter=0;
       while(x!=NULL && position!=counter){
           x=x->next;
           counter=counter+1;
       }
       node * newnode=new node();
        newnode->data=value;
        newnode->next=x->next;
        x->next=newnode;
    }

    void add_after_value(int target_value, int new_value) {
    node* x = head;

    while (x != NULL && x->data != target_value) {
        x = x->next;
    }
        node* newnode = new node();
        newnode->data = new_value;
        newnode->next = x->next;
        x->next = newnode; }

    
    
    
    void delete_atfirst(){
    if(head == NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    }




    void delete_atlast() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // If there is only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    node* prev = NULL;

    // Move to the last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // temp is the last node, prev is the second-last
    prev->next = NULL;
    delete temp;
    }




    void delete_at_position(int position){
    if(head == NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // deleting the first node
    if(position == 0){
        delete_atfirst();
        return;
    }

    node* temp = head;
    node* prev = NULL;
    int counter = 0;

    // move until we reach the position
    while(temp != NULL && counter < position){
        prev = temp;
        temp = temp->next;
        counter++;
    }

    // position does not exist
    if(temp == NULL){
        cout << "Position out of range!" << endl;
        return;
    }

    // unlink and delete the node
    prev->next = temp->next;
    delete temp;
   }



   void delete_by_value(int value){
    if(head == NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // Case 1: the value is in the first node
    if(head->data == value){
        delete_atfirst();
        return;
    }

    node* temp = head;
    node* prev = NULL;

    // Search for the value
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if(temp == NULL){
        cout << "Value not found!" << endl;
        return;
    }

    // Unlink and delete
    prev->next = temp->next;
    delete temp;
    }




    };

    






int main(){

    return 0;
}