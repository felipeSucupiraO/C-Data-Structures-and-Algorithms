#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* alocateNode() {
    Node* pnt = NULL;
    while (pnt == NULL) {
        pnt = (Node*)malloc(sizeof(Node));
    }

    return pnt;
}

Node* newList(int data) {
    printf("testing program\n");
    Node* newNode = alocateNode();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverseLinkedList(Node* head) {
    printf("Traversing Linked List\n");
    Node* currNode = head;
    while (currNode != NULL) {
        printf("Data: %d\n", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

Node* searchLinkedListByData(Node* head, int searchedData) {
    Node* currNode = head;
    while (currNode != NULL) {
        if (currNode->data == searchedData) {
            return currNode;
        }

        currNode = currNode->next;
    }

    return NULL;
}

Node* searchLinkedListByPosition(Node* head, int position) {
    Node* currNode = head;
    int i = 1;
    while (currNode != NULL && i < position) {
        currNode = currNode->next;
        i++;
    }

    return currNode;
}

int linkedListLength(Node* head) {
    Node* currNode = head;
    
    int length = 0;
    while (currNode != NULL) {
        length++;
        currNode = currNode->next;
    }

    return length;
}

Node* insertOnLinkedList(Node* head, int position, int data) {
    if (position < 1) {
        return head;
    } 
    
    Node* newNode = alocateNode();
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* previousNode = searchLinkedListByPosition(head, position - 1);

    if (previousNode == NULL) {
        return head;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;
    return head;
}

Node* deleteFromLinkedList(Node* head, int position) {
    if (head == NULL || position < 1) {
        return head;
    }
    
    Node* deletedNode;
    if (position == 1) {
        deletedNode = head;
        head = head->next;
        free(deletedNode);
        return head;
    }

    Node* previousNode = searchLinkedListByPosition(head, position - 1);
    deletedNode = previousNode->next;
    previousNode->next = deletedNode->next;
    free(deletedNode);

    return head;
}

int main() {
    // add error messages
    return 0;
}