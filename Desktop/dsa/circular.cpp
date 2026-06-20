#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
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
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            tail = current;
            tail->next = head;
        }

        delete temp; // ✅ important
    }
};

int main() {
    CircularList cl;

    cl.insert(10);
    cl.insert(20);
    cl.insert(30);

    cl.display();       // 10 20 30

    cl.pop_front();
    cl.display();       // 20 30

    cl.pop_end();
    cl.display();       // 20

    return 0;
}