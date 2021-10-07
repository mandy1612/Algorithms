#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node *next;
} nd;
nd *top = NULL;
nd *ptr = NULL;
int max = 0;

void pop()
{
    ptr = top;
    top = top->next;
    free(ptr);
}
void push(int val)
{
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    ++max;
}

void change(int index, int val)
{
    ptr = top;
    if (top == NULL || index <= 0)
    {
        printf("Indexed item not present in stack");
        exit(0);
    }
    index--;
    while (index--)
        top = top->next;
    if (top == NULL)
    {
        printf("Indexed item not present in stack");
        exit(0);
    }
    else
    {
        top->data = val;
        top = ptr;
    }
}
void display()
{

    ptr = top;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else
    {
        printf("Stack is empty\n");
        exit(0);
    }
}
// int main()
// {
//     int n, index, val;
//     while (1)
//     {
//         scanf("%d ", &n);
//         switch (n)
//         {
//         case 1:
//             if (max < 10)
//             {
//                 scanf("%d", &val);
//                 push(val);
//             }
//             else
//             {
//                 printf("Stack Overflow\n");
//             }
//             break;
//         case 2:
//             if (max <= 0)
//             {
//                 printf("Stack Underflow\n");
//             }
//             else
//             {
//                 pop();
//             }
//             break;
//         case 3:
//             scanf("%d %d", &index, &val);
//             if (index <= max)
//                 change(index, val);
//             break;
//         case 4:
//             display();
//             break;

//         default:
//             printf("Operation not supported");
//             exit(0);
//         }
//     }
//     return 0;
// }
int main()
{
    int n, index, val;
    do
    {
        scanf("%d ", &n);
        switch (n)
        {
        case 1:
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            scanf("%d %d", &index, &val);
            change(index, val);
            break;
        case 4:
            display();
            break;
        default:
            printf("Operation not supported");
            exit(0);
            break;
        }
    } while (n != 4);

    return 0;
}
