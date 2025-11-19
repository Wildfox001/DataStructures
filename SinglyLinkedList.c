#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node *NODE;

NODE insertFront(NODE first);
NODE insertRear(NODE first);
NODE insertAfter(NODE first);
NODE insertBefore(NODE first);
NODE insertAtPos(NODE first);
NODE deleteFront(NODE first);
NODE deleteRear(NODE first);
NODE deleteAfterEle(NODE first);
NODE deleteBeforeEle(NODE first);
NODE deleteElement(NODE first);
NODE deletePos(NODE first);
void display(NODE first);

void main()
{
    NODE first=NULL;
    int choice;
    while(1)
    {
        printf("\n\n*****Singly linked list implementation*****");
        printf("\n 1. Insert Front \n 2. Insert rear \n 3. Insert After \n 4. Insert Before \n 5. Insert At Postition \n 6. Delete Front \n 7. Delete Rear \n 8. Delete After \n 9. Delete Before \n 10. Delete Element \n 11. Delete At Position \n 12. Display \n 13. Exit");
        printf("\n\t***********");
        printf("\nEnter your choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: first=insertFront(first);
            break;
        case 2: first=insertRear(first);
            break;
        case 3: first=insertAfter(first);
            break;
        case 4: first=insertBefore(first);
            break;
        case 5: first=insertAtPos(first);
            break;
        case 6: first=deleteFront(first);
            break;
        case 7: first=deleteRear(first);
            break;
        case 8: first=deleteAfterEle(first);
            break;
        case 9: first=deleteBeforeEle(first);
            break;
        case 10: first=deleteElement(first);
            break;
        case 11: first=deletePos(first);
            break;
        case 12: display(first);
            break;
        case 13: printf("\n Program exits now");
        exit(0);
        default: printf("enter valid choice");
        }
    }
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    printf("No elements to display");
    else
    {
        cur=first;
        printf("\n Elements of Singly linked list are:\t");
        while(cur!=NULL)
        {
            printf("%d\t",cur->info);
            cur=cur->next;
        }
    }
}

NODE insertFront(NODE first)
{
    NODE temp=NULL;
    temp=(NODE)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("Insufficient memory");
        return first;
    }
    printf("\n Enter element to be inserted");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(first==NULL)
    first=temp;
    else    {
        temp->next=first;
        first=temp;
        return first;
    }
}
NODE insertRear(NODE first)
{
    NODE temp=NULL,cur=NULL;
    temp=(NODE)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("Insufficient memory");
        return first;
    }
    printf("\n Enter element to be inserted");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(first==NULL)
    first=temp;
    else
    {
        cur=first;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
    }
    return first;
}

NODE insertAfter(NODE first)
{
    NODE temp=NULL,cur=NULL;
    temp=(NODE)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("Insufficient memory");
        return first;
    }
    int ele,item;
    if(first==NULL)
    {
        printf("linked list is empty");
        return first;
    }
        printf("\n Enter element after which new node to be inserted");
        scanf("%d",&ele);
        cur=first;
        while(cur!=NULL&&cur->info!=ele)
            cur=cur->next;
        if(cur==NULL)
        {
            printf("Element not found");
            return first;
        }
        printf("\nEnter element to be inserted");
        scanf("%d",&item);
        temp->info=item;
        temp->next=NULL;
        temp->next=cur->next;
        cur->next=temp;
        return first;
}

NODE insertBefore(NODE first)
{
    NODE temp=NULL, cur=NULL, prev=NULL;
    int ele,item;
    temp=(NODE)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("Insufficient memory");
        return first;
    }
    printf("\n Enter element before which new node to be inserted");
    scanf("%d",&ele);
    cur=first;
        while(cur!=NULL&&cur->info!=ele)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==NULL)
        {
            printf("Element not found");
            return first;
        }
        printf("Element to be inserted");
        scanf("%d",&item);
        temp->info=item;
        temp->next=NULL;
        temp->next=cur;
        if(prev!=NULL)
            prev->next=temp;
        else
            first=temp;
        return first;
}

NODE insertAtPos(NODE first)
{
    NODE temp=NULL,cur=NULL;
    temp=(NODE)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("Insufficient memory");
        return first;
    }
    int ele,pos;
    if(first==NULL)
    {
        printf("linked list is empty");
        return first;
    }
    printf("Enter pos at which new element to be inserted ");
    scanf("%d",&pos);
    printf("Enter element to be inserted at pos ");
    scanf("%d",&ele);
    if(pos==1)
    {
        first=insertFront(first);
        return first;
    }
    cur=first;
    int i=1;
    while(cur!=NULL&&i<pos-1)
    {
        cur=cur->next;
        i++;
    }
    if(cur==NULL)
        {
            printf("Element not found");
            return first;
        }
        temp->info=ele;
        temp->next=NULL;
        temp->next=cur->next;
        cur->next=temp;
        return first;
}

NODE deleteFront(NODE first)
{
    NODE temp=NULL;
    if(first==NULL)
    {
        printf("Linked List is empty, create Linked list");
        return first;
    }
    temp=first;
    first=first->next;
    printf("Element being deleted is %d",temp->info);
    free(temp);
    return first;
}
NODE deleteRear(NODE first)
{
    NODE cur=NULL,prev=NULL;
    prev=(NODE)malloc(sizeof(struct node));
    if (prev==NULL)
    {
        printf("Insufficient memory");
        return first;
    }
    if(first==NULL)
    {
        printf("LL is empty");
        return first;
    }
    cur=first;
    prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    printf("Element being deleted is %d",cur->info);
    free(cur);
    return first;
}

NODE deleteElement(NODE first)
{
    NODE cur = NULL, prev = NULL;
    int item;
    if(first==NULL)
    {
        printf("\nThe list is empty\n");
        return first;
    }
    printf("\nEnter the element to be deleted :");
    scanf("%d",&item);
    cur=first;
    while(cur!=NULL && cur->info!=item)
    {
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("\nElement to be deleted doesnt exist in the list\n");
        return first;
    }
    if(prev==NULL)
    {
        first = deleteFront(first);
        return first;
    }
    prev->next = cur->next;
    printf("\nElement being deleted is : %d\n", cur->info);
    free(cur);
    return first;
}

NODE deletePos(NODE first)
{
    NODE cur = NULL, prev = NULL;
    int pos, k;
    if(first==NULL)
    {
        printf("\nThe list is empty.. no elements to delete...\n");
        return first;
    }
    printf("\nEnter the position of element to be deleted :");
    scanf("%d",&pos);
    if(pos==1)
    {
        first = deleteFront(first);
        return first;
    }
    cur=first;
    k=1;
    while(cur!=NULL && k<pos)
    {
        prev=cur;
        cur=cur->next;
        k++;
    }
    if(cur==NULL)
    {
        printf("\nPosition doesnt exist in the list\n");
        return first;
    }
    prev->next = cur->next;
    printf("\nElement being deleted is : %d\n", cur->info);
    free(cur);
    return first;
    }

NODE deleteBeforeEle(NODE first)
{
    NODE cur = NULL, prev = NULL, pprev = NULL;
    int ele;
    if(first==NULL)
    {
        printf("\nThe list is empty.. no elements to delete...\n");
        return first;
    }
    printf("\nEnter an element whose left element to be deleted :");
    scanf("%d",&ele);
    cur=first;
    while(cur!=NULL && cur->info!=ele)
    {
        pprev = prev;
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("\nElement doesnt exist in the list\n");
        return first;
    }
    if(pprev==NULL)
    {
        first = deleteFront(first);
        return first;
    }
    pprev->next = prev->next;
    printf("\nElement being deleted is : %d\n", prev->info);
    free(prev);
    return first;
}

NODE deleteAfterEle(NODE first)
{
    NODE cur = NULL, temp = NULL;
    int ele;
    if(first==NULL)
    {
        printf("\nThe list is empty.. no elements to delete...\n");
        return first;
    }
    printf("\nEnter an element whose right element to be deleted :");
    scanf("%d",&ele);
    cur=first;
    while(cur!=NULL && cur->info!=ele)
    {
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("\nElement doesnt exist in the list\n");
        return first;
    }
    if(cur->next == NULL)
    {
        printf("\nNo elements to delete after the given element...");
        return first;
    }
    temp = cur->next;
    cur->next = temp->next;
    printf("\nElement being deleted is : %d\n", temp->info);
    free(temp);
    return first;
}
