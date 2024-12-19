/**
 * @file CircularDoublyLinkedList.c
 * @author Lee Insong 
 * @brief Library of Doubly-Linked-List
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "CircularDoublyLinkedList.h"
#include <stdlib.h>

/**
 * @brief Create New Node.
 * 
 * @param data 
 * @return Node* 
 */
Node* CDLL_CreateNode(ElementType data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
/**
 * @brief Release Node Memory.
 * 
 * @param head 
 */
void CDLL_DestroyNode(Node* node){
    free(node);
}

/**
 * @brief Release List Memory.
 * 
 * @param head 
 */
void CDLL_DestroyList(Node* head){
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * @brief Append New Node.
 * 
 * @param head 
 * @param new_node 
 */
void CDLL_AppendNode(Node** head, Node* new_node){
    if (*head == NULL) { 
        *head = new_node;
        (*head)->next = new_node;
        (*head)->prev = new_node;
        return;
    }
    Node* tail = (*head)->prev;
    tail->next->prev = new_node;
    tail->next = new_node;

    new_node->next = (*head);
    new_node->prev = tail;
}

/**
 * @brief Prepend New Node.
 * 
 * @param head 
 * @param new_node 
 */
void CDLL_PrependNode(Node** head, Node* new_node){
    if (*head == NULL) {  
        *head = new_node;
        (*head)->next = new_node;
        (*head)->prev = new_node;
        return;
    }
    Node* tail = (*head)->prev;
    new_node->next = *head;
    new_node->prev = tail;

    tail->next->prev = new_node;
    tail->next = new_node;
    *head = new_node;   
}

/**
 * @brief Insert A New Node After A Specific Node.
 * 
 * @param current 
 * @param new_node 
 */
void CDLL_InsertAfter(Node* current, Node* new_node){
    new_node->next = current->next;
    new_node->prev = current;
    if(current->next !=NULL){
        current->next->prev = new_node;
        current->next = new_node;
    }
}

/**
 * @brief Insert A New Node Before  A Specific Node.
 * 
 * @param current 
 * @param new_node 
 */
void CDLL_InsertBefore(Node* current, Node* new_node){
    new_node->prev = current->prev;
    new_node->next = current;
    if(current->prev !=NULL){
        current->prev->next = new_node;
        current->prev = new_node;
    }
}

/**
 * @brief Remove A Specific Node.
 * 
 * @param head 
 * @param remove 
 */
void CDLL_RemoveNode(Node** head, Node* remove){
    if(*head == remove){
        (*head)->prev->next = remove->next;
        (*head)->next->prev = remove->prev;
        *head = remove->next;
    }
    else{
        remove->prev->next = remove->next;
        remove->next->prev = remove->prev;
    }
    remove->prev = NULL;
    remove->next = NULL;
}

/**
 * @brief Find The Node That Exists At The Nth Position.
 * 
 * @param head 
 * @param location 
 * @return Node* 
 */
Node* CDLL_GetNodeAt(Node* head, int location){
    Node* current = head;

    while(current!= NULL && --location >= 0){
        current = current->next;
    }
    return current;
}

/**
 * @brief Count The Number Of Total Nodes.
 * 
 * @param head 
 * @return int 
 */
int CDLL_GetNodeCount(Node* head){
    int cnt = 0;
    Node* current = head;

    while(current != NULL){
        current = current->next;
        cnt++;
        if(current == head) break;
    }
    return cnt;
}