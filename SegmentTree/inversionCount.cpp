#include<bits/stdc++.h>
using namespace std;
/***
 * @brief  
 * we can use this segment tree to find inversion count in an array
 * this segment tree can also be used in range queries like find number of elements in a range
 * min/max value in a range
 * we can also update the tree dynamically, so it will work in online algorithms
 */
class Node {
public:
    int val, minVal, maxVal, frequency, greater_count;
    Node *left, *right;
    Node(int val, int minVal, int maxVal) {
        this->val = val;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->frequency = 0;
        this->greater_count = 0;
        this->left = NULL;
        this->right = NULL;
    }
    void printNode() {
        cout << "val: " << val << " minVal: " << minVal << " maxVal: " << maxVal << endl;
        cout << "frequency: " << frequency << " greater_count: " << greater_count << endl;
    } 
    void printTreeLevelWise() {
        queue<Node*> q;
        q.push(this);
        while(!q.empty()) {
            Node *node = q.front();
            q.pop();
            node->printNode();
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
    void printTreeInOrder (int level = 0) {
        if (left != NULL) {
            left->printTreeInOrder(level + 1);
        }
        
        if (right != NULL) {
            right->printTreeInOrder(level + 1);
        }
        cout << "level: " << level << " ";
        printNode();
    }
};

vector<vector<Node*>> segment_tree;
void build_segment_tree(vector<int> & v) {
    int n = v.size();
    set<int> s;
    for (int x: v) {
        s.insert(x);
    }
    vector<Node*> row;
    for (int x: s) {
        row.push_back(new Node(x, x, x));
    }
    // build segment tree
    segment_tree.push_back(row);
    while(segment_tree.back().size() > 1) {
        vector<Node*> row;
        for (int i = 0; i + 1 < segment_tree.back().size(); i += 2) {
            Node *left = segment_tree.back()[i];
            Node *right = segment_tree.back()[i+1];
            Node *newNode = new Node((left->maxVal + right->minVal)/2, left->minVal, right->maxVal);
            newNode->left = left;
            newNode->right = right;
            row.push_back(newNode);
        }
        if (segment_tree.back().size() % 2 == 1) {
            row.push_back(segment_tree.back().back());
        }
        segment_tree.push_back(row);
    }
}

void insert(Node* root, int x) {
    if (x == root->val) {
        root->frequency++;
    }
    else if (x > root->val) {
        
        root->greater_count++;
        if (root->right != NULL) {
            insert(root->right, x);
        }
    } else if (root->left != NULL) {
        insert(root->left, x);
    }
}

long long get_total_greater_count(Node *root, long long x) {
    if (root == NULL) return 0;
    if (root->val == x) return root->greater_count;
    if (root->val < x)
        return root->right == NULL ? 0 : get_total_greater_count(root->right, x);
    return root->frequency + root->greater_count + (root -> left == NULL ? 0 : get_total_greater_count(root->left, x));
}


int main() {

    vector<int> v = {17, 4, 9, 8, 16, 1, 12, 19, 7, 11, 5, 14, 2, 20, 15, 10, 3, 18, 6, 13};
    build_segment_tree(v);
    Node *root = segment_tree.back()[0];
    long long inversion_count = 0LL;
    for (int x: v) {
        inversion_count += get_total_greater_count(root, (2*(long long)x));
        insert(root, x);
    }
    cout << "ans = "<< inversion_count << endl;
    //root->printTreeLevelWise();
}


