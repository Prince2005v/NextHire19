#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;   // ✅ added

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;   // ✅ fixed
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }
    }

    void display() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    void pop_front() {
        if (head == NULL) return;

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }

        delete temp;
    }

    void pop_end() {
        if (head == NULL) return;

        Node* temp = tail;

        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;   // ✅ no traversal needed
            tail->next = head;
            head->prev = tail;
        }

        delete temp;
    }
};

int main() {
    CircularList cl;

    cl.insert(10);
    cl.insert(20);
    cl.insert(30);

    cl.display();   // 10 20 30

    cl.pop_front();
    cl.display();   // 20 30

    cl.pop_end();
    cl.display();   // 20

    return 0;
}