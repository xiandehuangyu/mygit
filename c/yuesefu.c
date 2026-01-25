#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    int alive;
}*Node;
int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    Node head=(Node)malloc(sizeof(struct node));
    head->next=NULL;
    Node p=head;
    Node q;
    for(int i=1;i<=n;i++){
        q=(Node)malloc(sizeof(struct node));
        p->next=q;
        q->data=i;
        q->alive=1;
        q->next=NULL;
        p=q;
    }
    p->next=head->next;
    p=head->next;
    int killed=0,kill=0;
    while(killed<n){
        if(p->alive==1){
            kill++;
            if(kill==m){
                p->alive=0;
                printf("%d ",p->data);
                killed++;
                kill=0;
            }
        }
        p=p->next;
    }
}