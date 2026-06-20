#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
private:
    Node* head;
    Node* tail;
    int length;

public:
    // Constructor
    List() {
        head = tail = nullptr;
        length = 0;
    }

    // Destructor (free memory)
    ~List() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    // Push at front
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    // Push at back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // Print Linked List
    void printLL() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search (returns index)
    int search(int key) const {
        Node* temp = head;
        int idx = 0;
        while (temp != nullptr) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // Delete a node by value
    void delete_node(int key) {
        if (head == nullptr) return;

        // If head needs to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
            if (head == nullptr) tail = nullptr;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != key) {
            curr = curr->next;
        }

        if (curr->next != nullptr) {
            Node* temp = curr->next;
            curr->next = temp->next;

            if (temp == tail) {
                tail = curr;
            }

            delete temp;
            length--;
        }
    }

    // Reverse Linked List
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode;

        tail = head;

        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    // Get size
    int size() const {
        return length;
    }
};

int main() {
    List ll;

    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(40);

    cout << "Linked List: ";
    ll.printLL();

    cout << "Size: " << ll.size() << endl;

    int pos = ll.search(20);
    cout << "Position of 20: " << pos << endl;

    ll.delete_node(20);
    cout << "After deleting 20: ";
    ll.printLL();

    ll.reverse();
    cout << "After reversing: ";
    ll.printLL();

    return 0;
}