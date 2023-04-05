#include <iostream>

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CStaticSortLinkedList
{
private:
    Node* head;
    int size;
    int capacity;

public:
    CStaticSortLinkedList(int cap)
    {
        capacity = cap;
        head = nullptr;
        size = 0;
    }

    void BubbleSort(bool rising)
    {
        bool swapped = true;
        int temp;
        Node* curr;

        while (swapped)
        {
            swapped = false;
            curr = head;

            while (curr->next != nullptr)
            {
                if (rising ? curr->data > curr->next->data : curr->data < curr->next->data)
                {
                    temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = true;
                }

                curr = curr->next;
            }
        }
    }

    void AddToHead(int val)
    {
        if (size < capacity)
        {
            Node* temp = new Node(val);
            temp->next = head;
            head = temp;
            size++;
        }
        else {
            std::cout << "List is already at capacity" << std::endl;
        }
    }

    void Insert(int val)
    {
        if (size < capacity) {
            Node* temp = new Node(val);

            if (head == nullptr || val < head->data)
            {
                temp->next = head;
                head = temp;
            }
            else
            {
                Node* curr = head;
                while (curr->next != nullptr && curr->next->data < val)
                {
                    curr = curr->next;
                }

                temp->next = curr->next;
                curr->next = temp;
            }

            size++;
        }
        else {
            std::cout << "List is already at capacity" << std::endl;
        }
    }

    void Display()
    {
        Node* curr = head;
        while (curr != nullptr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};