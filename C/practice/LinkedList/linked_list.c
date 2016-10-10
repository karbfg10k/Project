#include <string.h>
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
void build_rand_list(struct node** head, int size);

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

//Reverse list -> {1, 2, 3, 4} becomes {4, 3, 2, 1}
void reverse_list(struct node** head);

//Print middle index of Linked List (in case of even size, print second of two)
void print_middle(struct node** head);

//Merge 2 sorted lists -> {1, 2, 3} and {3, 4, 5} becomes {1, 2, 3, 3, 4, 5}
struct node* merge_sorted(struct node* head_A, struct node* head_B);

//Split into 2 lists -> {1, 2, ,3, 4} becomes {1, 2} and {3, 4}
void list_split(struct node** head, struct node** front, struct node** back);

//Recursive merge sort
void merge_sort(struct node** head);

//Split into 2 lists -> {1, 2, ,3, 4} becomes {1, 3} and {2, 4}
void alt_split(struct node* source, struct node** a, struct node** b);

int main(){
    struct node* head = NULL;
    build_rand_list(&head, 10);
    merge_sort(&head);
    list_print(&head);
    struct node* a = NULL;
    struct node* b = NULL;
    alt_split(head, &a, &b);
    list_print(&a);
    list_print(&b);
    return 0;
}

//Split into 2 lists -> {1, 2, ,3, 4} becomes {1, 3} and {2, 4}
void alt_split(struct node* source, struct node** a, struct node** b){
    struct node* current = source;
    assert(source != NULL);
    *a = current;
    *b = NULL;
    if(current->next)
        *b = current->next;
    else
        return;
    
    struct node* current_a = *a;
    struct node* current_b = *b; 
    current = current->next->next;
    
    while(current != NULL){
        current_a->next = current;
        current_a = current_a->next;
        current = current->next;
        if(current != NULL){
            current_b->next = current; 
            current_b = current_b->next;
            current = current->next;
        }
    }
    current_a->next = NULL;
    current_b->next = NULL;
}


//Recursive merge sort
void merge_sort(struct node** head){
    struct node* headR = *head;

    if( (headR == NULL) || (headR->next == NULL) )
        return;
   
    struct node* a;
    struct node* b;

    list_split(&headR, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *head = merge_sorted(a, b);

}

//Split into 2 lists -> {1, 2, ,3, 4} becomes {1, 2} and {3, 4}
void list_split(struct node** head, struct node** front, struct node** back){
    if(*head == NULL || (*head)->next == NULL ){
        *front = *head;
        *back = NULL;
    }
    else{
        struct node* slow_ptr = *head;
        struct node* fast_ptr = (*head)->next;
        while(fast_ptr != NULL){
            fast_ptr = fast_ptr->next;
            if(fast_ptr){
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
        }
        *front = *head;
        *back = slow_ptr->next;
        slow_ptr->next = NULL;
    }
}

//Merge 2 sorted lists 
struct node* merge_sorted(struct node* head_A, struct node* head_B){
    struct node* result = NULL;
    struct node* current_A = head_A;
    struct node* current_B = head_B;
    struct node** current_result = &result;
    while(1){
       if(current_A == NULL && current_B == NULL)
           break;
       else if(current_A == NULL){
           *current_result = current_B;
           break;
       }
       else if(current_B == NULL){
           *current_result = current_A;
           break;
       }
       else if(current_A->data <= current_B->data ){
           *current_result = current_A;
           current_A = current_A->next;
           (*current_result)->next = NULL;
       }
       else{ 
           *current_result = current_B;
           current_B = current_B->next;
           (*current_result)->next = NULL; 
       }
       current_result = &((*current_result)->next); 
    }
    return result;
}

//Print middle index of Linked List (in case of even size, print second of two)
void print_middle(struct node** head){
    assert(head != NULL);
    struct node* slow_ptr = *head;
    struct node* fast_ptr = *head;
    while(fast_ptr != NULL){
        fast_ptr = fast_ptr->next;
        if(fast_ptr){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
    }
    if(slow_ptr)
        printf("Middle is: %d\n", slow_ptr->data);
}

//Reverse list -> {1, 2, 3, 4} becomes {4, 3, 2, 1}
void reverse_list(struct node** head){
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* current = *head;
    while(current != NULL){
        next = current->next;
        current->next= prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void list_print(struct node** head){
    printf("List size is %d: List: ", list_length(head));
    for(struct node* current = *head; current!= NULL; current = current->next)
        printf("%d ", current->data);
    printf("\n");
}

void build_rand_list(struct node** head, int size){
    //Assume head is NULL
    assert(*head == NULL);
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        int random_num = rand() % 99;
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
