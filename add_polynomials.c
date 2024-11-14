#include<stdio.h>
#include<stdlib.h>

struct list
{
    float coeff;
    int exp;
    struct list*next;
    /* data */
};

int add_polynomial(struct list*head1, struct list*head2,struct list*head3){
    if(head1->exp==head2->exp){
        head3->coeff=head1->coeff+head2->coeff;
        
    }
}

int main()
{
    int n;
    printf("enter the number of terms of your polynomial");
    scanf("%d",&n);
    struct list*head=malloc(sizeof(struct list*));
    while(n--){
        struct list*temp=head;
        
    }
    return 0;
}

