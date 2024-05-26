#include <stdio.h>
#define size 8
int stack[size], top = -1;
void push(int item)
{
    if (top >= (size - 1))
    {
        printf("Stack full\n");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack empty\n");
    }
    else
    {
        int item = stack[top];
        top--;
        printf("Popped: %d\n", item);
    }
}
void display()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    int item, l;
    while (1)
    {
        printf("Enter the element to push: ");
        scanf("%d", &item);
        push(item);
        printf("1.continue and 0.exit (1/0): ");
        scanf("%d", &l);
        if (l == 0)
        {
            break;
        }
    }
    display();
    pop();
    display();

    return 0;
}