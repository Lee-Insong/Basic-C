/**
 * @file main.c
 * @author Lee Insong 
 * @brief Example of Singly-Linked-List
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "DoublyLinkedList.h"
#include <stdio.h>

int main(void){
    int i,count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* new_node;

    printf("*Init List Data*\n");
    // Create 5 Nodes
    for(i = 0; i<5; i++){
        new_node = DLL_CreateNode(i);
        DLL_AppendNode(&list, new_node);
    }
    
    // Create 5 Nodes
    for(i = -1; i>=-5; i--){
        new_node = DLL_CreateNode(i);
        DLL_PrependNode(&list, new_node);
    }
    
    count = DLL_GetNodeCount(list);
    for(i = 0; i<count;i++){
        current = DLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n",i,current->data);
    }

    //Insert -6 at head
    new_node = DLL_CreateNode(-6);
    DLL_InsertNewHead(&list, new_node);
    
    //Insert 5 at tail
    new_node = DLL_CreateNode(5);
    count = DLL_GetNodeCount(list);
    current = DLL_GetNodeAt(list,count-1);
    DLL_InsertAfter(current, new_node);

    printf("*Changed List Data(1)*\n");
    count = DLL_GetNodeCount(list);
    for(i = 0; i<count;i++){
        current = DLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n",i,current->data);
    }

    //Insert a new node after 5rd node
    current = DLL_GetNodeAt(list,5-1);
    new_node = DLL_CreateNode(3000);
    DLL_InsertAfter(current, new_node);

    //Insert a new node before 7rd node
    current = DLL_GetNodeAt(list,7-1);
    new_node = DLL_CreateNode(2000);
    DLL_InsertBefore(current, new_node);

    printf("*Changed List Data(2)*\n");
    count = DLL_GetNodeCount(list);
    for(i = 0; i<count;i++){
        current = DLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n",i,current->data);
    }

    //Delete all node
    current = DLL_GetNodeAt(list,1-1);
    DLL_DestroyList(current);

    return 0;
}