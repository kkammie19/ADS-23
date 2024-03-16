#include <iostream>
using namespace std;

struct Node
{
    string word;
    Node* next;

    Node(string word){
        this->word = word;
        this->next = NULL;
    }
};

struct LL{
    Node* head;
    Node* tail;
    LL(){
        head = tail = NULL;
    }

    void insert(string word){
        Node* node = new Node(word);
        if(head == NULL){
            head = node;
            tail = node;
        }
        else{
            tail ->next = node;
            tail = node;
        }
    }

    void shiftCyclic(int k){
        if(k == 1){
            return;
        }
        Node* cur = head;
        while(k!=1){
            tail->next = cur;
            tail = cur;
            cur = cur->next;
            k--;
        }
        head = cur->next;
        cur->next = NULL;
    }

    void print(){
        Node* cur = head;
        while(cur != NULL){
            cout<< cur->word << ' ';
            cur = cur->next;
        }
    }
};

int main(){
    LL LinkedList;

    int n, k;
    cin>> n >> k;

    while(n--){
        string s;
        cin>> s;
        LinkedList.insert(s);
    }
    LinkedList.shiftCyclic(k);
    LinkedList.print();
}