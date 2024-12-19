/**
 * @file SinglyLinkedList.c
 * @author Lee Insong 
 * @brief Library of Singly-Linked-List
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "SinglyLinkedList.h"
#include <stdlib.h>

/**
 * @brief Create New Node.
 * 
 * @param data 
 * @return Node* 
 */
Node* SLL_CreateNode(ElementType data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Release Node Memory.
 * 
 * @param head 
 */
void SLL_DestroyNode(Node* node){
    free(node);
}

/**
 * @brief Release List Memory
 * 
 * @param head 
 */
void SLL_DestroyList(Node* head){
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        SLL_DestroyNode(temp);
    }
}

/**
 * @brief Append New Node At Tail.
 * 
 * @param head 
 * @param new_node 
 */



void SLL_AppendNode(Node** head, Node* new_node){
    if(*head == NULL){
        *head = new_node;
    }
    else{
        Node* tail = *head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = new_node;
    }
}

/**
 * @brief Insert A New Node After A Specific Node.
 * 
 * @param current 
 * @param new_node 
 */
void SLL_InsertAfter(Node* current, Node* new_node){
    new_node->next = current->next;
    current->next = new_node;
}

/**
 * @brief Insert A New Node At Head.
 * 
 * @param head 
 * @param new_head 
 */
void SLL_InsertNewHead(Node** head, Node* new_head){
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
void SSL_RemoveNode(Node** head, Node* remove){
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
Node* SLL_GetNodeAt(Node* head, int location){
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
int SLL_GetNodeCount(Node* head){
    int cnt = 0;
    Node* current = head;

    while(current != NULL){
        current = current->next;
        cnt++;
    }
    return cnt;
}