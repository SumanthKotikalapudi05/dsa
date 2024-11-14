#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*prev;
    int data;
    struct node*next;

};
void print_data(struct node*head){
    
    if (head==NULL)
    {
        /* code */
        printf("the linkced list is empty");
    }
    struct node*ptr=NULL;

    ptr= head;
    while (ptr!=NULL)
    {
        /* code */
        printf(" %d\n",ptr->data);
        ptr=ptr->next;
    }
printf("\n");
}
void insert_start(struct node* head,int data){
        struct node*new=malloc(sizeof(struct node));
        new->prev=NULL;
        new->data=data;
        new->next=head;
        head->prev=new;
        head=new;
}
void add_pos(struct node*head,int data,int pos){
            struct node*p1=head;
            struct node*p2=malloc(sizeof(struct node));
            while(pos!=1){
                p1=p1->next;
                pos--;
            }
            p2->next = p1;
            p2->prev = p1->prev;
            if (p1->prev != NULL) {
             p1->prev->next = p2;
}
            p1->prev = p2;
            print_data(head);
}
int main(){
    struct node* head= malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=30;
    head->next=NULL;
    insert_start(head,40);

    //print_data(head);
    add_pos(head,50,2);
    return 0;
}