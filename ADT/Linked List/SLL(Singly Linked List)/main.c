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

#include "SinglyLinkedList.h"
#include <stdio.h>

int main(void){
    int i,count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* new_node;

    printf("*Init List Data*\n");
    // Create 5 Nodes
    for(i = 0; i<5; i++){
        new_node = SLL_CreateNode(i);
        SLL_AppendNode(&list, new_node);
        printf("List[%d] : %d\n",i, new_node->data);
    }

    //Insert -1 at head
    new_node = SLL_CreateNode(-1);
    SLL_InsertNewHead(&list, new_node);
    
    //Insert -2 at head
    new_node = SLL_CreateNode(-2);
    SLL_InsertNewHead(&list, new_node);

    printf("*Changed List Data(1)*\n");
    count = SLL_GetNodeCount(list);
    for(i = 0; i<count;i++){
        current = SLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n",i,current->data);
    }

    //Insert a new node after 3rd node
    current = SLL_GetNodeAt(list,3-1);
    new_node = SLL_CreateNode(3000);
    SLL_InsertAfter(current, new_node);

    printf("*Changed List Data(2)*\n");
    count = SLL_GetNodeCount(list);
    for(i = 0; i<count;i++){
        current = SLL_GetNodeAt(list,i);
        printf("List[%d] : %d\n",i,current->data);
    }

    //Delete all node
    current = SLL_GetNodeAt(list,1-1);
    SLL_DestroyList(current);

    return 0;
}