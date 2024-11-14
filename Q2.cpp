#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int getMax(Node* head) {
    int max = head->data;
    Node* temp = head->next;

    while (temp != nullptr) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

void countingSort(Node*& head, int place) {
    Node* buckets[10] = {nullptr}; 
    Node* bucketTails[10] = {nullptr}; 

    Node* temp = head;
    while (temp != nullptr) {
        int index = (temp->data / place) % 10;
        
        if (buckets[index] == nullptr) {
            buckets[index] = temp;
        } else {
            bucketTails[index]->next = temp;
        }
        bucketTails[index] = temp;

        temp = temp->next;
    }

    Node* sortedList = nullptr;
    Node* sortedTail = nullptr;
    for (int i = 0; i < 10; i++) {
        if (buckets[i] != nullptr) {
            if (sortedList == nullptr) {
                sortedList = buckets[i];
            } else {
                sortedTail->next = buckets[i];
            }
            sortedTail = bucketTails[i];
        }
    }

    if (sortedTail != nullptr) {
        sortedTail->next = nullptr; 
    }

    head = sortedList;
}

void radixsort(Node*& head) {
    int max = getMax(head);

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(head, place);
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* head = nullptr;
    int arr[] = {136, 487, 358, 469, 570, 247, 598, 639, 205, 609};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insertEnd(head, arr[i]);
    }

    cout << "Before sorting, the elements are - \n";
    printList(head);

    radixsort(head);

    cout << "After applying Radix sort, the elements are - \n";
    printList(head);

    return 0;
}
