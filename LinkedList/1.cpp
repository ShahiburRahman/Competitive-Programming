#include <iostream>
using namespace std;
// Build a basic linked list and print it

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

        Node *head = new Node(1, "Jim");
        Node *secondNode = new Node(2, "Jinan");
        Node *tail = new Node(3, "Adib");

        head->next = secondNode;
        secondNode->next = tail;

        Node *tmp;
        tmp = head;
        
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->next;
        }
}