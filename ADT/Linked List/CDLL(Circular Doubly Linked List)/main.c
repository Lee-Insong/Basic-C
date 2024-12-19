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

#include "CircularDoublyLinkedList.h"
#include <stdio.h>

int main(void){
    int i,count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* new_node;

    printf("*Init List Data*\n");
    // Create 5 Nodes
    for(i = 0; i<5; i++){
        new_node = CDLL_CreateNode(i);
        CDLL_AppendNode(&list, new_node);
    }
    // Create 5 Nodes
    for(i = -1; i>=-5; i--){
        new_node = CDLL_CreateNode(i);
        CDLL_PrependNode(&list, new_node);
    }
    
    count = CDLL_GetNodeCount(list);
    current = CDLL_GetNodeAt(list,0);
    for(i = 0; i<count*2;i++){
        printf("List[%d] : %d\n",i,current->data);
        current = current->next;
    }

    //Insert a new node after 5rd node
    current = CDLL_GetNodeAt(list,5-1);
    new_node = CDLL_CreateNode(3000);
    CDLL_InsertAfter(current, new_node);

    //Insert a new node before 7rd node
    current = CDLL_GetNodeAt(list,7-1);
    new_node = CDLL_CreateNode(2000);
    CDLL_InsertBefore(current, new_node);

    printf("*Changed List Data*\n");
    count = CDLL_GetNodeCount(list);
    for(i = 0; i<count;i++){
        current = CDLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n",i,current->data);
    }

    //Delete all node
    current = CDLL_GetNodeAt(list,1-1);
    CDLL_DestroyList(current);

    return 0;
}