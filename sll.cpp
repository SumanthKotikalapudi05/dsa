#include <iostream>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data1, node* next1 = nullptr) {
        data = data1;
        next = next1;
    }    // constructor1

    node(int data2) {
        data = data2;
        next = nullptr;
    }    // constructor2
};

/* to convert any GIVEN ARRAY to LINKLIST */
node* arraytoLL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    node* head = new node(arr);
    node* p = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        node* temp = new node(arr[i]);
        p->next = temp;
        p = temp;
    }
    return head;
}

/* to print the list */
void printList(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* deletion at start */
node* deleteFromFirst(node* head) {
    if (head == nullptr) return nullptr;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

/* deletion at end */
node* deleteFromLast(node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    node* t1 = head->next;
    node* t2 = head;
    while (t1->next != nullptr) {
        t2 = t1;
        t1 = t1->next;
    }
    t2->next = nullptr;
    delete t1;
    return head;
}

/* deletion at any point in list */
node* deleteInBetween(node* head, int data) {
    if (head == nullptr) return nullptr;
    if (head->data == data) {
        return deleteFromFirst(head);
    }
    node* p1 = head;
    node* p2 = head->next;
    while (p2 != nullptr && p2->data != data) {
        p1 = p2;
        p2 = p2->next;
    }
    if (p2 == nullptr) return head; // Data not found
    p1->next = p2->next;
    delete p2;
    return head;
}

