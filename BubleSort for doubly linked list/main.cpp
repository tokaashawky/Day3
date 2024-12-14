#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Linked_list {
    Node* head;
    Node* tail;
public:
    Linked_list() {
        this->head = NULL;
        this->tail = NULL;
    }

    Node* GetNode(int _data) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == _data)
                return current;
            current = current->next;
        }
        return NULL;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfter(int data, int afterData) {
        Node* preNode = GetNode(data);
        if (preNode == NULL) {
            cout << "Data not found" << endl;
            return;
        }
        Node* newNode = new Node(afterData);
        newNode->next = preNode->next;
        newNode->prev = preNode;
        preNode->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        } else {
            newNode->next->prev = newNode;
        }
    }

     void insertBefore(int data, int beforeData) {
        Node* curNode = GetNode(data);
        if (curNode == NULL) {
            cout << "Data not found" << endl;
            return;
        }
        Node* newNode = new Node(beforeData);
        newNode->next = curNode;
        newNode->prev = curNode->prev;

        if (curNode->prev == NULL) {
                head = newNode;

        } else {
             curNode->prev->next = newNode;
        }
        curNode->prev = newNode;
    }

    int getcount() {
        int countt = 0;
        Node* current = head;
        while (current != NULL) {
            countt++;
            current = current->next;
        }
        return countt;
    }

    void remove(Node* node) {

        if (node->prev) {node->prev->next = node->next;}
        else { head = node->next;}

        if (node->next) {node->next->prev = node->prev;}
        else {tail = node->prev;}

        node->next = NULL;
        node->prev = NULL;
}

    void display() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    void bubbleSort_with_data() {
    if (head==NULL) return;
    bool swapped;
    do {
        swapped = false;
        Node* temp = head;
        while (temp->next) {
            if (temp->data > temp->next->data) {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;}
            temp = temp->next;}
    }while (swapped);
    }

    void bubbleSort_with_nodes() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Node* temp = head;

        while (temp && temp->next) {
            if (temp->data > temp->next->data) {
                Node* nextNode = temp->next;
                remove(nextNode);
                insertAfter(temp->data, nextNode->data);
                remove(temp);
                insertAfter(nextNode->data, temp->data);
                swapped = true;}
            else {
                temp = temp->next;}}
    } while (swapped);
}
};
int main() {
    Linked_list L;
    L.append(2);
    L.append(5);
    L.append(6);
    L.append(3);
    L.append(8);
    L.append(4);
    cout << "Original List: ";
    L.display();
    L.bubbleSort_with_data();
    cout << "List Sorted_with_data: ";
    L.display();
    L.bubbleSort_with_nodes();
    cout << "List Sorted_with_nodes: ";
    L.display();

    return 0;
}
