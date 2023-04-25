#include <iostream>
using namespace std;
// Build a basic linked list with input and output

class Node {
    public:
        int val;
        string name;
        Node *next;

        Node(int v, string s) {
            val = v;
            name = s;
            next = NULL;
        }
        void print() {
            cout << "val = " << val << " name = " << name << endl;
        }
};

int main() {
        int n;
        cout << "Enter how many nodes: ";
        cin >> n;
        int values[n];
        string names[n];
        for (int i = 0; i < n; i++)
        {
            cin >> values[i] >> names[i];
        }
        Node *head = new Node(values[0], names[0]);
        Node *tmp,*cur;
        cur = head;

        for (int i = 1; i < n; i++)
        {
            tmp = new Node(values[i], names[i]);
            cur->next = tmp;
            cur = cur->next;

        }
        tmp = head;
        
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->next;
        }
        
}