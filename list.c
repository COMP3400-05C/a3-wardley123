#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    if(head == NULL){
        return NULL;
    }
    return head;
}
/**
 * TODO 
 * @param head pointer to the first node in the linked list
 * @return the head of the linked list 
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL){
        return NULL;
}
    struct ll_node *current = head;
    while(current->next != NULL){
        current = current-> next;
    }
    return current;
}

/**
 * TODO: returns number of elements in a linked list
 */
int ll_size(struct ll_node *head) {
  if(head == NULL){
    return 0;
  }
  int counter = 0;
  struct ll_node *current = head;
  while(current != NULL){
    current = current-> next;
    counter++;

  }
  return counter;
}

/**
 * TODO: loop thru a linked list and returns the node where the value was found
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
   while(head != NULL){
    if (head ->data == value){
        return head;
    }

    head = head -> next;
}
    return NULL;
}

/**
 * TODO: converts linked list into an array
 */
int *ll_toarray(struct ll_node *head) {
    if(head == NULL){
    return NULL;
   }
    int n= 0;
    struct ll_node *temp = head;

    //count the nodes we have 
    while(temp != NULL){
        temp = temp -> next;
        n++;
    }
    //allocate memory for the array using malloc
    int* arr = malloc(n * sizeof(int));

   //fill in the array by putting the nodes in the array
   temp = head;
   for(int i = 0; i < n; i++ ){
    arr[i] = temp->data;
    temp = temp -> next;
   }
   return arr;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_create(int data) {
    struct ll_node *new_node = malloc(sizeof(struct ll_node));
    if(new_node == NULL){
        return NULL;
    }

    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
   
}

/**
 * TODO: Describe what the function does
 */
void ll_destroy(struct ll_node *head) {

    struct ll_node *current = head;
    struct ll_node *next_node;
    while(current!= NULL){
        next_node = current->next;
        free(current);
        current = next_node;

    }
    return;
}

/**
 * TODO: create a new linked list and append it to an existing one
 */
void ll_append(struct ll_node *head, int data) {

    struct ll_node *new_node = ll_create(data);
    if(new_node == NULL){
        return;
    }
    if(head == NULL){
        return;
    }

    struct ll_node *current = head;
    while(current->next != NULL && current != NULL){
        current = current-> next;
    }
    current->next = new_node;
}

/**
 * TODO: Create a linked list from an array
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (len == 0){
        return NULL;
    }

    struct ll_node *head = malloc(sizeof(struct ll_node));
    head->data = data[0];
    head->next = NULL;

    struct ll_node *tail = head;

    for(int i = 1; i < len; i++){
        struct ll_node *new_node = malloc(sizeof(struct ll_node));
        new_node->data = data[i];
        new_node->next = NULL;

        tail->next = new_node;
        tail = new_node;
    }
    return head;
}

/**
 * TODO: remove a value from a linked list
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL){
        return NULL;
    }

    struct ll_node *current = head;
    struct ll_node *prev = NULL;

    while(current != NULL && current->data != value){
        prev = current;
        current = current->next;
    }

    if(current == NULL){
        return head;
    }

    if(prev == NULL){
        struct ll_node *new_head = head ->next;
        free(head);
        return new_head;
} else{
    prev->next = current->next;
    free(current);
    return head;
}

}

