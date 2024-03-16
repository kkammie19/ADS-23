#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    string name;
};

void removeDuplicates(Node *head)
{
    if (!head || !head->next)
        return;
    string cur_name = head->name;

    while (head->next != NULL)
    {
        Node *temp = head->next;

        if (cur_name == temp->name)
        {
            Node *node = temp;
            head->next = node->next;
            delete node;
        }
        else
        {
            head = head->next;
        }
        cur_name = head->name;
    }
}

int getCount(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void push(Node **head_ref, string new_data)
{
    Node *new_node = new Node();

    new_node->name = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->name << "\n" ;
        node = node->next;
    }
}

int main()
{
    int n;
    string s;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        push(&head, s);
    }

    removeDuplicates(head);
    cout << "All in all: " << getCount(head);

    cout << "\nStudents: \n";
    printList(head);

    return 0;
}