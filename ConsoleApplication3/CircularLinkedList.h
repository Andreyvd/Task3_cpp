#include <iostream>
#include <string>

template<typename T>

class CircularLinkedList {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* head;
    int size;
    
public:
    class Iterator {
    private:
        Node* ptr;
        bool isEnd;
        CircularLinkedList<T>& list; 

    public:
        Iterator(Node* p = nullptr, bool end = false, CircularLinkedList<T>& lst = nullptr) : ptr(p), isEnd(end), list(lst) {}
        Iterator(const Iterator& other) {
            ptr = other.ptr;
            isEnd = other.isEnd;
            list = other.list;
        }

        Iterator& operator=(const Iterator& other) {
            ptr = other.ptr;
            isEnd = other.isEnd;
            list = other.list;
            return *this;
        }

        T& operator*() {
            return ptr->value;
        }

        Iterator& operator++() {
            
            ptr = ptr->next;
            if (ptr->next == list.getHead()) { 
                isEnd = true;
            }
            
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr || isEnd != other.isEnd; 
        }
    };

 
    CircularLinkedList() : head(nullptr), size(0) {}

    ~CircularLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            if (index == 0) {
                head = head->next;
            }
            current->next = temp->next;
            delete temp;
        }
        size--;
    }

    T& get(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index" << std::endl;
            return *(new T());
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    int get_size() {
        return size;
    }

    Iterator begin() {
        return Iterator(head, false, *this);
    }

    Iterator end() {
        return Iterator(head, true, *this);
    }

    Node* getHead() const {
        return head;
    }

   
};


