#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "assignment.h" 
void ex6() 
{
	node_t *a=Initialize('1'); node_t *b=NULL; PrintList(a);
	InsertFirstList(&a, 'V'); InsertFirstList(&a, 'M');
	PrintList(a); InsertLastList(&a, 'C'); PrintList(a);
	SplitList(&a, &b, 2); PrintList(a); PrintList(b);
	DeleteFirstList(&a); PrintList(a); InsertLastList(&a, 'G');
	DeleteLastList(&b); PrintList(b); InsertLastList(&b,'0');
	PrintList(b); InsertLastList(&b, '1'); PrintList(b);
	MergeList(&a,&b); PrintList(a);
	char target='G';
	printf("Count '%c': %d\n",target, SearchList(&a,target));
	target='1';
	printf("Count '%c': %d\n",target, SearchList(&a,target));
	FreeList(&a);
	return 0;
}
node_t *Initialize(char ch) 
{
	node_t *head;
	head=(node_t*)calloc(1,sizeof(node_t));
	if(head==NULL){ fprintf(stderr,"Failed to assign memory!\n"); exit(-1); }
	head->next=NULL; head->ch=ch;
	return head;
}
void PrintList(node_t *head) 
{
	node_t *temp=head;
	printf("***Print Linked List***\n");
	while(temp!=NULL) { printf("%c ",temp->ch); temp=temp->next; }
	printf("\n****Print Finished****\n\n");
}
void FreeList(node_t **head) 
{
	node_t *tmp=NULL; node_t *pHead=*head;
	while(pHead->next!=NULL) { tmp=pHead; pHead=pHead->next; free(tmp); }
	free(pHead);
}
bool IsEmptyList(node_t *head)
{
	if(head=NULL)return true;
	else return false;
}
int SearchList(node_t **head, char target)
{
	int i=0;
	while(1)
	{
		if((*head)->ch==target)i++;
		if((*head)->next==NULL)break;
		head=&((*head)->next);
	}
	return i;
}

void MergeList(node_t **head1, node_t **head2)
{
	while((*head1)->next)head1=&((*head1)->next); 
	(*head1)->next=*head2;
	*head2=NULL;
}

void InsertFirstList(node_t **head,char insert_char) {
    node_t *newnode=malloc(sizeof(node_t));
    newnode->ch=insert_char;
    newnode->next=*head;
    *head=newnode;
}
int SizeList(node_t *head) {
    node_t *temp=head;
    int size=0;
    while (temp!=NULL) {
        temp=temp->next;
        size++;
    }
    return size;
}
void SplitList(node_t **head, node_t **tail, int pos) {
    for (int i=1;i<pos;i++) {head=&((*head)->next);}
    *tail=(*head)->next;
    (*head)->next=NULL;
}
void InsertLastList(node_t **head,char insert_char){
    node_t *temp;
    temp=(node_t*)calloc(1,sizeof(node_t));
    if(head==NULL){ fprintf(stderr,"Failed to assign memory!\n"); exit(-1); }
    while((*head)->next!=NULL){head=&((*head)->next);}
    temp->next=NULL;
    (*temp).ch=insert_char;
    (*(*head)).next=temp;
}

void DeleteFirstList(node_t **head){
    node_t *temp=(*head)->next;
    free(*head);
    *head=temp;
}

void DeleteLastList(node_t **head){
    node_t *temp=*head;
    while(((temp->next)->next)!=NULL){temp=temp->next;}
    free(temp->next);
    (temp->next)=NULL;
    }
