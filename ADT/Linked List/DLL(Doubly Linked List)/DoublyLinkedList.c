/**
 * @file DoublyLinkedList.c
 * @author Lee Insong 
 * @brief Library of Doubly-Linked-List
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "DoublyLinkedList.h"
#include <stdlib.h>

/**
 * @brief Create New Node.
 * 
 * @param data 
 * @return Node* 
 */
Node* DLL_CreateNode(ElementType data){
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
void DLL_DestroyNode(Node* node){
    free(node);
}

/**
 * @brief Release List Memory.
 * 
 * @param head 
 */
void DLL_DestroyList(Node* head){
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        DLL_DestroyNode(temp);
    }
}

/**
 * @brief Append New Node.
 * 
 * @param head 
 * @param new_node 
 */
void DLL_AppendNode(Node** head, Node* new_node){
    if (*head == NULL) { 
        *head = new_node;
        return;
    }
    Node* tail = *head;
    while (tail->next != NULL) {  
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->prev = tail; 
}

/**
 * @brief Prepend New Node.
 * 
 * @param head 
 * @param new_node 
 */
void DLL_PrependNode(Node** head, Node* new_node){
    if (*head == NULL) {  
        *head = new_node;
        return;
    }
    new_node->next = *head;     
    (*head)->prev = new_node;  
    *head = new_node;      
}

/**
 * @brief Insert A New Node After A Specific Node.
 * 
 * @param current 
 * @param new_node 
 */
void DLL_InsertAfter(Node* current, Node* new_node){
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
void DLL_InsertBefore(Node* current, Node* new_node){
    new_node->prev = current->prev;
    new_node->next = current;
    if(current->prev !=NULL){
        current->prev->next = new_node;
        current->prev = new_node;
    }
}

/**
 * @brief Insert A New Node At Head.
 * 
 * @param head 
 * @param new_head 
 */
void DLL_InsertNewHead(Node** head, Node* new_head){
    if(*head == NULL){
        *head = new_head;
    }
    else{
        new_head->next = *head;
        *head = new_head;
    }
}


/**
 * @brief Remove A Specific Node.
 * 
 * @param head 
 * @param remove 
 */
void DLL_RemoveNode(Node** head, Node* remove){
    if(*head == remove){
        *head = remove->next;
    }
    else{
        Node* current = *head;
        while(current != NULL && current->next != remove){
            current = current->next;
        }
        if(current != NULL){
            current->next = remove->next;
        }
    }
}

/**
 * @brief Find The Node That Exists At The Nth Position.
 * 
 * @param head 
 * @param location 
 * @return Node* 
 */
Node* DLL_GetNodeAt(Node* head, int location){
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
int DLL_GetNodeCount(Node* head){
    int cnt = 0;
    Node* current = head;

    while(current != NULL){
        current = current->next;
        cnt++;
    }
    return cnt;
}