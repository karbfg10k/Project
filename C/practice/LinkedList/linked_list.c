#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

struct node{
    int data;
    struct node* next;
};

//Prints list
void list_print(struct node** head);

//builds a list with 10 random values
void build_rand_list(struct node** head);

//Insert at the top -> {1, 2, 3} becomes {5, 1, 2 ,3}
void insert_top(struct node** head, int data);

//Insert at the end -> {1, 2, 3} becomes {1, 2 ,3, 5}
void insert_end(struct node** head, int data);

//Insert at the ith position -> {1, 2, 3} at 1 becomes {1, 5, 2 ,3}
void insert_nth(struct node** head, int data, int n_pos);

//List size -> {1, 2, 3} should return 3
int list_length(struct node** head);

//Count data occurrence -> {1, 1, 1, 2} with 1 should return 3
int list_count(struct node** head, int data);

//Delete list -> {1, 1, 1, 2} becomes NULL
void list_delete(struct node** head);

//Delete list at nth -> {1, 1, 1, 2} at 3 becomes {1, 1, 1}
int list_delete_nth(struct node** head, int n_pos);

//Pop head -> {1, 1, 1, 2} return 1 and {1, 1, 2}
int list_pop_head(struct node** head);

//Sorted Insert()
void sorted_insert(struct node** headRef, struct node* newNode); 

//InsertSort()
void insert_sort(struct node** headRef);

int main(){
    struct node* head = NULL;
    build_rand_list(&head);
    list_print(&head);
    return 0;
}

void list_print(struct node** head){
    printf("List size is %d: List: ", list_length(head));
    for(struct node* current = *head; current!= NULL; current = current->next)
        printf("%d ", current->data);
    printf("\n");
}

void build_rand_list(struct node** head){
    //Assume head is NULL
    assert(*head == NULL);
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        int random_num = rand() % 11;
        insert_end(head, random_num);
    }
}

void insert_top(struct node** head, int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_end(struct node** head, int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL){
        *head = new_node;
        return;
    }
    struct node* current = NULL;
    for (current = *head; current->next != NULL; current = current->next);
    current->next = new_node;
}

void insert_nth(struct node** head, int data, int n_pos){
    if (n_pos == 0){
        insert_top(head, data);
        return;
    }
    struct node* current = *head;
    for(int i = 0; i < n_pos - 1 ; i++){
        if(current == NULL) return;
        else current = current->next;
    }
    if(current == NULL) return;
    insert_top(&(current->next), data);
}

int list_length(struct node** head){
    int list_length = 0;
    for(struct node* current = *head; current!= NULL; current = current->next)
        list_length++;
    return list_length;
}   

int list_count(struct node** head, int data){
    int ctr = 0;
    for(struct node* current = *head; current!= NULL; current = current->next){
        if (current->data == data)
            ctr++;
    }
    return ctr; 
}

void list_delete(struct node** head){
    struct node* current = *head; 
    struct node* prev = NULL; 
    while(current != NULL){
        prev = current;
        current = current->next;
        free(prev);
    }
}

//Delete list at nth -> {1, 1, 1, 2} at 3 becomes {1, 1, 1}
int list_delete_nth(struct node** head, int n_pos);

//Pop head -> {1, 1, 1, 2} return 1 and {1, 1, 2}
int list_pop_head(struct node** head);

//Sorted Insert()
void sorted_insert(struct node** headRef, struct node* newNode); 

//InsertSort()
void insert_sort(struct node** headRef);
