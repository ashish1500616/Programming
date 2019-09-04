#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = nullptr;

node *new_node(int value)
{
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    return temp;
}

void insert_node(int position, int value)
{
    node *t_h = head;
    node *t_n = new_node(value);
    if (position == 1)
    {
        t_h = t_n;
        return;
    }
    else
    {
        cout << "Later Nodes Created\n";
        int c = 1;
        while (t_h->next && c < position - 1)
        {
            t_h = t_h->next;
            c += 1;
        }
        if(t_h->next!=nullptr)
        t_n->next = t_h->next;
        t_h = t_n;
    }
}

void delete_node(int position)
{
    node *t_h = head;
    int c = 1;
    while (c < position)
    {
        t_h = t_h->next;
        c += 1;
    }
    t_h->next = t_h->next->next;
    // @params position, integer
}

void print_ll()
{
    // node *t_h=head;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    // Output each element followed by a space
}
int main()
{
    int cases = 0, position = 0, value = 0;
    cin >> cases;
    char ch;
    for (int i = 0; i < cases; i++)
    {
        cin >> ch;
        switch (ch)
        {
        case 'i':
            cin >> position;
            cin >> value;
            insert_node(position, value);

            // cout<<"Inside Insert Node"<<"\n";
            break;
        case 'd':
            cin >> position;
            delete_node(position);
            break;
        case 'p':
            print_ll();
            cout << "\n";
            break;
        default:
            cout << "Check Your Input\n";
        }
    }
    return 0;
}