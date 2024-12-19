/**
 * @file CircularDoublyLinkedList.h
 * @author Lee Insong 
 * @brief Library of Doubly-Linked-List
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __CIRCULAR_DOUBLY_LINKED_LIST_H__
#define __CIRCULAR_DOUBLY_LINKED_LIST_H__


// Define Data Size
typedef int ElementType;

// Define Node Structure
typedef struct Node {
    int data;               // Node Data
    struct Node* prev;      //Previous Node Address
    struct Node* next;      // Next Node Address
} Node;

// Function Declaration
Node* CDLL_CreateNode(ElementType data);
void CDLL_DestroyNode(Node* node);
void CDLL_DestroyList(Node* head);
void CDLL_AppendNode(Node** head, Node* new_node);
void CDLL_PrependNode(Node** head, Node* new_node);
void CDLL_InsertAfter(Node* current, Node* new_node);
void CDLL_InsertBefore(Node* current, Node* new_node);
void CDLL_RemoveNode(Node** head, Node* remove);
Node* CDLL_GetNodeAt(Node* head, int location);
int CDLL_GetNodeCount(Node* head);

#endif