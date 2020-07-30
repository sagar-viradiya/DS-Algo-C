// Leetcode July challenge Week 2, Problem 3
#include<iostream>

using namespace std;

class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
};

Node* flattenList(Node* head) {
    while(head->next != nullptr || head->child != nullptr) {
        if (head->child != nullptr) {
            Node* node = flattenList(head->child);
            node->next = head->next;
            if (head->next != nullptr) {
                head->next->prev = node;
            }
            head->next = head->child;
            head->child = nullptr;
            head->next->prev = head;
            head = node;
            continue;
        }
        head = head->next;
    }
    return head;
}


int main(int argc, char const *argv[])
{

    /*
        Creation of link list

        1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
    */
    Node node12 = Node();
    node12.val = 12;
    Node node11 = Node();
    node11.val = 11;
    node12.prev = &node11;
    node11.next = &node12;
    Node node10 = Node();
    node10.val = 10;
    Node node9 = Node();
    node9.val = 9;
    node10.prev = &node9;
    node9.next = &node10;
    Node node8 = Node();
    node8.val = 8;
    node8.child = &node11;
    node8.next = &node9;
    node9.prev = &node8;
    Node node7 = Node();
    node7.val = 7;
    node7.next = &node8;
    node8.prev = &node7;
    Node node6 = Node();
    node6.val = 6;
    Node node5 = Node();
    node5.val = 5;
    node5.next = &node6;
    node6.prev = &node5;
    Node node4 = Node();
    node4.val = 4;
    node4.next = &node5;
    node5.prev = &node4;
    Node node3 = Node();
    node3.val = 3;
    node3.next = &node4;
    node4.prev = &node3;
    node3.child = &node7;
    Node node2 = Node();
    node2.val = 2;
    node2.next = &node3;
    node3.prev = &node2;
    Node node1 = Node();
    node1.val = 1;
    node1.next = &node2;
    node2.prev = &node1;
    flattenList(&node1);
    Node* head = &node1;
    while(head != nullptr) {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
    return 0;
}
