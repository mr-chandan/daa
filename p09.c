// 9. Implement **Insert and Delete** operaƟons in a **Queue** using an array.
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int value;
    if (rear == MAX - 1)
    {
        printf("Queue overflow! Cannot insert more elements.\n");
    }
    else
    {
        printf("Enter the value to insert: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue\n", value);
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow! No elements to delete.\n");
    }
    else
    {
        printf("%d deleted from the queue\n", queue[front]);
        front++;

        // Reset pointers when the queue becomes empty
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
