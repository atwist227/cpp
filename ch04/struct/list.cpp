// Incomplete code
#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* constructList(unsigned int len){
    if (!len){
        return nullptr;
    }
    Node* head{new Node{0}};
    Node* current{head};
    for (int i{1}; i < len; i++){
        current->next = new Node{i};
        current = current->next;
    }
    current->next = nullptr;
    return head;
}

Node* getNode(Node *head, unsigned int num){// TODO: Beyond the length of the list
    Node* current{head};
    for (int i{0}; i < num; i++){
        current = current->next;
    }
    return current;
}

void printListData(Node*head){
    Node* current{head};
    while (current){
        std::cout << (*current).data << std::endl;
        current = current->next;
    }
}

void addNode(Node* prev, int data){// todo: link to next, add at head
    Node* temp{new Node{data}};
    temp->next = prev->next;
    prev->next = temp;
}

void deleteNextNode(Node* prev){
    Node* temp{prev->next};
    prev->next = temp->next;
    delete temp;
}

void deleteHeadNode(Node* head){
    Node* temp{head};
    head = temp->next;
    delete temp;
}

void deleteList(Node* head){
    while(head){
        deleteHeadNode(head);
    }
}

int main(){
    // construct list
    Node* head{constructList(5)};
    // printListData(head);
    // std::cout << "中文" << std::endl;
    Node* temp{getNode(head,2)};
    std::cout << temp->data << std::endl;
    deleteNextNode(temp);
    printListData(head);
    deleteList(head);
}