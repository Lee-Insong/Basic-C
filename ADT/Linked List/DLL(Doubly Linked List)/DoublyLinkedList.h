/**
 * @file DoublyLinkedList.h
 * @author Lee Insong 
 * @brief Library of Doubly-Linked-List
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __DOUBLY_LINKED_LISK_H__
#define __DOUBLY_LINKED_LISK_H__


// Define Data Size
typedef int ElementType;

// Define Node Structure
typedef struct Node {
    int data;               // Node Data
    struct Node* prev;      //Previous Node Address
    struct Node* next;      // Next Node Address
} Node;

// Function Declaration
Node* DLL_CreateNode(ElementType data);
void DLL_DestroyNode(Node* node);
void DLL_DestroyList(Node* head);
void DLL_AppendNode(Node** head, Node* new_node);
void DLL_PrependNode(Node** head, Node* new_node);
void DLL_InsertAfter(Node* current, Node* new_node);
void DLL_InsertBefore(Node* current, Node* new_node);
void DLL_InsertNewHead(Node** head, Node* new_head);
void DLL_RemoveNode(Node** head, Node* remove);
Node* DLL_GetNodeAt(Node* head, int location);
int DLL_GetNodeCount(Node* head);

#endif