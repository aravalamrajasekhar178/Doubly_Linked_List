#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head=NULL;

// Creating the node
struct Node* create(int val){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=val;
    node->next=NULL;
    node->prev=NULL;
    return node;
}

// Inserting the node at the beginning
void insert_at_begin(int val){
    if(head==NULL){
        head=create(val);
    }else{
        struct Node* temp1=create(val);
        temp1->next=head;
        head->prev=temp1;
        head=temp1;
    }
}

//Inserting the node at the end
void insert_at_end(int val){
    if(head==NULL){
        head=create(val);
    }
    else{
        struct Node* temp1=create(val);
        struct Node* temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp1->prev=temp2;
        temp2->next=temp1;
    }
}

// Inserting the node after the specified position
void insert_at_somePosition(int val,int pos){
    if(head==NULL){
        printf("Node can't be inserted because list is empty\n");
    }
    else{
        struct Node* temp1=create(val);
        struct Node* temp2=head;
        for(int i=0;i<pos-1;i++){
            temp2=temp2->next;
            if(temp2==NULL){
                printf("Node can't be inserted\n");
                return;
            }
        }
        if(temp2->next==NULL){
            temp1->prev=temp2;
            temp2->next=temp1;
        }
        else{
            struct Node* temp3=temp2->next;
            temp2->next=temp1;
            temp1->prev=temp2;
            temp1->next=temp3;
            temp3->prev=temp1;
        }
    }
}

// Searching an element in the Doubly Linked List
int search(int val){
    struct Node* temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

// Printing Doubly Linked List in forward direction
void print_LinkedList_forward(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
    return;
}

//Printing Doubly Linked List in backward direction
void print_LinkedList_backward(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        if(temp->prev==NULL){
            printf("%d\n",temp->data);
            return;
        }
        printf("%d -> ",temp->data);
        temp=temp->prev;
    }
}

//Deleting the Node at the beginning of the Doubly Linked List
void delete_at_begin(){
    if(head==NULL){
        printf("Node can't be deleted because list is empty\n");
        return;
    }
    if(head->next==NULL){
        struct Node* temp=head;
        head=NULL;
        free(temp);
        return;
    }
    struct Node* temp=head;
    head->next->prev=NULL;
    head=head->next;
    free(temp); 
}

//Deleting the Node at the end of the Doubly Linked List
void delete_at_end(){
    if(head==NULL){
         printf("Node can't be deleted because list is empty\n");
         return;
    }
    if(head->next==NULL){
       struct Node* temp=head;
       head=NULL;
       free(temp);
       return;
    }
    struct Node* slow=head;
    struct Node* fast=head->next;
    while(fast->next!=NULL){
          fast=fast->next;
    }
    struct Node* temp=fast;
    slow->next=NULL;
    fast->prev=NULL;
    free(fast);
}

//Deletion of Node in Doubly Linked List after the specified position
void delete_after_somePosition(int pos){
    if(head==NULL || head->next==NULL){
        printf("Node can't be deleted after the specfied position because list is empty");
        return;
    }
    struct Node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("No node is deleted after specified position\n");
            return;
        }
    }
    if(temp->next==NULL){
        printf("No Node can be deleted\n");
        return;
    }
    struct Node* temp1=temp->next;
    if(temp1->next==NULL){
        temp->next=temp1->next;
        temp1->prev=NULL;
        free(temp1); // free() method is used to deallocate the dynamically allocated memory to the node and helps in reducing the memory wastage
        return;
    }
    struct Node* temp2=temp1->next;
    temp1->next=NULL;
    temp1->prev=NULL;
    temp->next=temp2;
    temp2->prev=temp;
    free(temp1);
    return;
}
int main(){
    printf("1. Insert the Node at the beginning\n");
    printf("2. Insert the Node at the end\n");
    printf("3. Insert the Node after the specified position\n");
    printf("4. Deleting of the node at the beginning\n");
    printf("5. Deleting of the node at the end\n");
    printf("7. Searching the Element\n");
    printf("8. Printing the list in forward direction\n");
    printf("9. Printing the list in backward direction\n");
    printf("Other than this: Exit\n");
    printf("-------------------------\n");
    while(1){
        int n,flag=0,val,pos;
        printf("Enter your choice :\n");
        scanf("%d",&n);
        switch(n){
            case 1:printf("Enter the value to insert at beginning:\n");
                   scanf("%d",&val);
                   insert_at_begin(val);
                   break;
            case 2:printf("Enter the value to insert at end:\n");
                   scanf("%d",&val);
                   insert_at_end(val);
                   break;
            case 3:printf("Enter the value to insert:\n");
                   scanf("%d",&val);
                   printf("Enter the position(starting from 1) after which node should be inserted:\n");
                   scanf("%d",&pos);
                   insert_at_somePosition(val,pos);
                   break;
            case 4:delete_at_begin();
                   break;
            case 5:delete_at_end();
                   break;
            case 6:printf("Enter the position(starting from 1) after which the node should be deleted\n");
                   scanf("%d",&pos);
                   while(pos<1){
                       printf("position should be starting from 1\n");
                       printf("Re-Enter the position:\n");
                       scanf("%d",&pos);
                   }
                   delete_after_somePosition(pos);
                   break;
            case 7:printf("Enter the element to search:\n");
                   scanf("%d",&val);
                   if(search(val)){
                       printf("Element found\n");
                   }
                   else{
                       printf("Element not found\n");
                   }
                   break;
            case 8:print_LinkedList_forward();
                   break;
            case 9:print_LinkedList_backward();
                   break;
            default:flag=1;
                
        }
        if(flag==1){
            break;
        }
        
    }
}
}