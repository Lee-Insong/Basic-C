/**
 * @file SinglyLinkedList.h
 * @author Lee Insong 
 * @brief Library of Singly-Linked-List
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __SINGLY_LINKED_LISK_H__
#define __SINGLY_LINKED_LISK_H__


// Define Data Size
typedef int ElementType;

// Define Node Structure
typedef struct Node {
    int data;               // Node Data
    struct Node* next;      // Next Node Address
} Node;

// Function Declaration
Node* SLL_CreateNode(ElementType data);
void SLL_DestroyNode(Node* node);
void SLL_DestroyList(Node* head);
void SLL_AppendNode(Node** head, Node* new_node);
void SLL_InsertAfter(Node* current, Node* new_node);
void SLL_InsertNewHead(Node** head, Node* new_head);
void SSL_RemoveNode(Node** head, Node* remove);
Node* SLL_GetNodeAt(Node* head, int location);
int SLL_GetNodeCount(Node* head);

#endif