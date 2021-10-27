#include <iostream>
#include <utility>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

using NodePtr = Node *;

void pushBackElement(NodePtr *sPtr, int value);
void insertElement(NodePtr *sPtr, int value);
pair<bool, int> deleteElement(NodePtr *sPtr, int value);
int isEmpty(NodePtr sPtr);
void printList(NodePtr currentPtr);
NodePtr ReverseAfter(NodePtr head, int value);
NodePtr ReverseAfter2(NodePtr head, int value);

void pushBackElement(NodePtr *sPtr, int value)
{
    NodePtr newPtr = nullptr;
    NodePtr previousPtr = nullptr;
    NodePtr currentPtr = nullptr;

    newPtr = new Node;

    if (newPtr != nullptr) {
        newPtr->value = value;
        newPtr->next = nullptr;

        previousPtr = nullptr;
        currentPtr = *sPtr;

        while (currentPtr != nullptr) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (previousPtr == nullptr) {
            newPtr->next = *sPtr;
            *sPtr = newPtr;
        } else {
            previousPtr->next = newPtr;
            newPtr->next = currentPtr;
        }
    } else {
        cerr << value << "%c not inserted. No memory available." << endl;
    }
}

void insertElement(NodePtr *sPtr, int value)
{
    NodePtr newPtr = nullptr;
    NodePtr previousPtr = nullptr;
    NodePtr currentPtr = nullptr;

    newPtr = new Node;

    if (newPtr != nullptr) {
        newPtr->value = value;
        newPtr->next = nullptr;

        previousPtr = nullptr;
        currentPtr = *sPtr;

        while (currentPtr != nullptr && value > currentPtr->value) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (previousPtr == nullptr) {
            newPtr->next = *sPtr;
            *sPtr = newPtr;
        } else {
            previousPtr->next = newPtr;
            newPtr->next = currentPtr;
        }
    } else {
        cerr << value << "%c not inserted. No memory available." << endl;
    }
}

pair<bool, int> deleteElement(NodePtr *sPtr, int value)
{
    NodePtr previousPtr = nullptr;
    NodePtr currentPtr = nullptr;
    NodePtr tempPtr = nullptr;

    if (value == (*sPtr)->value) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->next;
        delete tempPtr;
        return { true, value };
    }
    previousPtr = *sPtr;
    currentPtr = (*sPtr)->next;

    while (currentPtr != nullptr && currentPtr->value != value) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    if (currentPtr != nullptr) {
        tempPtr = currentPtr;
        previousPtr->next = currentPtr->next;
        delete tempPtr;
        return { true, value };
    }

    return { false, 0 };
}

int isEmpty(NodePtr sPtr)
{
    return sPtr == nullptr;
}

void printList(NodePtr currentPtr)
{

    if (isEmpty(currentPtr)) {
        cout << "List is empty." << endl;
    } else {
        bool first = true;
        while (currentPtr != nullptr) {
            if (first) {
                first = false;
            } else {
                cout << ' ';
            }
            cout << currentPtr->value;
            currentPtr = currentPtr->next;
        }
        cout << endl;
    }
}

NodePtr ReverseAfter2(NodePtr head, int value)
{
    auto [status, result] = deleteElement(&head, value);
    if (status) {
        pushBackElement(&head, value);
    }
    return head;
}

NodePtr ReverseAfter(NodePtr head, int value)
{
    NodePtr previousPtr = nullptr;
    NodePtr currentPtr = nullptr;
    NodePtr tempPtr = nullptr;

    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    if (value == head->value) {
        tempPtr = head;
        head = head->next;
        previousPtr = head;
        currentPtr = head->next;
    } else {
        previousPtr = head;
        currentPtr = head->next;
        while (currentPtr != nullptr && currentPtr->value != value) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
        if (currentPtr != nullptr) {
            tempPtr = currentPtr;
            previousPtr->next = currentPtr->next;
            currentPtr = currentPtr->next;
        }
    }

    while (currentPtr != nullptr) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    previousPtr->next = tempPtr;
    if (tempPtr) {
        tempPtr->next = nullptr;
    }

    return head;
}

int main()
{
    {
        cout << "ReverseAfter2" << endl;
        NodePtr first = nullptr;
        pushBackElement(&first, 1);
        pushBackElement(&first, 2);
        pushBackElement(&first, 3);
        pushBackElement(&first, 4);
        printList(first);

        first = ReverseAfter2(first, 3);
        printList(first);

        first = ReverseAfter2(first, 1);
        printList(first);

        first = ReverseAfter2(first, 1);
        printList(first);
    }

    {
        cout << "ReverseAfter" << endl;
        NodePtr first = nullptr;
        pushBackElement(&first, 1);
        pushBackElement(&first, 2);
        pushBackElement(&first, 3);
        pushBackElement(&first, 4);
        printList(first);

        first = ReverseAfter(first, 3);
        printList(first);

        first = ReverseAfter(first, 1);
        printList(first);

        first = ReverseAfter(first, 1);
        printList(first);
    }

    return 0;
}
