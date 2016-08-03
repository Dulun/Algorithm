#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int a;
    struct Node * next;
};


struct Node * Create(int num)
{
    if(num == 0) return NULL;

    const int NODE_SIZE = sizeof(struct Node);
    struct Node * head = (struct Node * )malloc(NODE_SIZE);

    scanf("%d", &head->a);

    int k = 1;

    struct Node * now = NULL, *pre = head;
    while(k++ < num)
    {
        now = (struct Node *)malloc(NODE_SIZE);
        now -> next = NULL;
        scanf("%d", &now->a);
        pre -> next = now;
        pre = now;
    }


    return head;
}

void Show(struct Node * head)
{
    struct Node * p = head;
    while(p != NULL)
    {
        printf("%p  :  %d\n", p, p->a);
        p = p->next;
    }
}


struct Node * Reverse(struct Node * head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    struct Node * pre = NULL;
    struct Node * now = head;
    struct Node * nxt = NULL;

    while(now != NULL)
    {
        nxt = now -> next;
        now -> next = pre;
        pre = now;
        now = nxt;
    }
    return pre;
}

void Destory(struct Node * head)
{
    struct Node *p = head, *nxt;
    while(p != NULL)
    {
        nxt = p->next;
        free(p);
        p = nxt;
    }
}

struct Node * Sort(struct Node * head)
{
    if(head == NULL) return NULL;

    struct Node h;
    h.next = head;

    for(struct Node * i = &h; i->next->next != NULL ;i=i->next)
    {
        for(struct Node * j = &h; j->next->next != NULL; j=j->next)
        {
            if(j->next->a < j->next->next->a)
            {
                struct Node * a = j->next;
                struct Node * b = a->next;
                struct Node * c = b->next;

                j->next = b;
                a->next = c;
                b->next = a;
            }
        }
    }
    return h.next;
}


int main()
{
    struct Node * head = Create(2);
    Show(head);
    head = Reverse(head);
    printf("\n\n");
    Show(head);
    head = Sort(head);
    printf("\n\n");

    Show(head);

    return 0;
}
