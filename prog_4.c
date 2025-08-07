#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertAfter(struct Node* head, struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        return head;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, struct Node* delNode) {
    if (head == NULL || delNode == NULL) {
        return head;
    }
    if (head == delNode) {
        head = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    free(delNode);
    return head;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);

    printf("Original list:\n");
    printList(head);

    head = insertAfter(head, head, 4);
    printf("After inserting 4 after first node:\n");
    printList(head);

    head = deleteNode(head, head->next);
    printf("After deleting second node:\n");
    printList(head);

    return 0;
}
