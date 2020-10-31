// Leetcode Oct Challenge Week 1 Day 7

#include<iostream>

using namespace std;

// Inputs

// Link list definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

// Construct the LL
ListNode node5 = ListNode(5);
ListNode node4 = ListNode(4, &node5);
ListNode node3 = ListNode(3, &node4);
ListNode node2 = ListNode(2, &node3);
ListNode node1 = ListNode(1, &node2);
ListNode* head = &node1;

int k = 4;

int main(int argc, char const *argv[])
{
    int n;
    ListNode* next = head;
    ListNode* prev = next;
    while(next != nullptr) {
        prev = next;
        next = next->next;
        n++;
    }
    prev->next = head;

    next = head;
    for(int i = 0; i < n - (k % n) - 1; i++) {
        next = next->next;
    }
    head = next->next;
    next->next = nullptr;

    while(head != nullptr) {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
    return 0;
}
