/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head == NULL) return false;
    Node* n1 = head;
    Node* n2 = head;
    
    while(n2 != NULL && n2->next != NULL)
    {
        n1 = n1->next;
        n2 = n2->next->next;
        if(n1 == n2) break;
    }
    
    if(n2 == NULL || n2->next == NULL) return false;
    return true;
    
}

