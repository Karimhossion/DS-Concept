#include <stdio.h>
#define size 8
int queue[size], front = -1, rear = -1;
void enqueue(int item)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = item;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d\n", queue[rear]);
    }
}
int main()
{
    int item, l;
    while (1)
    {
        printf("Enter the element to enqueue: ");
        scanf("%d", &item);
        enqueue(item);
        printf("1.continue and 0.exit (1/0): ");
        scanf("%d", &l);
        if (l == 0)
        {
            break;
        }
    }
    display();

    return 0;
}
