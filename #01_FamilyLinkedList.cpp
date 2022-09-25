#include <iostream>
using namespace std;

//CREATING NODE CLASS
class Node{
    public:
    //Creating class objects
    string name;
    int age;
    Node*next;
    Node*prev;
    //calling constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL;
        prev=NULL;
    }
};

//INSERT DATA AT END OF LINKED LIST
void append(Node* &head, string name, int age){
    //Creating a node pointer and storing address of head in temp
    Node*temp=head;
    //creating a new node and storing name and age in it
    Node*new_node=new Node(name,age);
    //Inserting node in empty list
    if(temp==NULL){
        head=new_node;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//TO INSERT DATA AT START OF LINKED LIST
void insert_at_head(Node*&head,string name,int age){
    //Creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//DISPLAYING DATA FROM START OF LINKED LIST
void display_from_start(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<" ( NAME : "<<temp->name<<" AGE : "<<temp->age<<" ) "<<"=";temp=temp->next;}
    cout<<endl;
}

//DISPLAYING DATA FROM END OF LINKED LIST
void display_from_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;}
    cout<<endl;
}

//DELETING ANY INDEX(0,n-1) EXCLUDING LAST ELEMENT 
void delete_ind(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//FUNCTION TO DELETE LAST ELEMENT
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    //INITIALISING an empty linked list
    Node*head=NULL;
    //INSERTING family detais 
    append(head,"ANJALI & ", 19);
    append(head,"VANSHIKA & ", 16);
    append(head,"HIMANSHU & ", 14);
    append(head,"PUSHPA RANI & ", 44);
    append(head,"SOHAN LAL & ", 51);
    cout<<endl;
    //Displaying Family details
    cout<<"Doubly Linked list with my family members as elements is shown below : "<<endl;
    cout<<endl;
    display_from_start(head);
}