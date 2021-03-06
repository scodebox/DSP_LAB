#include <stdio.h>
#include <stdlib.h>

// Structure for each node.
struct node
{
	int data;
	struct node *link;
} *front = NULL, *rear = NULL;

// Function to check QUEUE is empty.
int is_empty()
{
	if (NULL == front && NULL == rear)
		return 1;
	else
		return 0;
}

// Function for enqueue operation.
int enqueue(int item)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if (NULL == new_node)
	{
		printf("\n\tOVERFLOW!");
		return -1;
	}
	else
	{
		new_node->data = item;
		new_node->link = NULL;
		if (is_empty())
			front = rear = new_node;
		else
		{
			rear->link = new_node;
			rear = new_node;
		}
		return 1;
	}
}

// Function for dequeue operation.
int dequeue()
{
	if (is_empty())
	{
		printf("\n\tUNDERFLOW!");
		return -1;
	}
	else
	{
		int item = front->data;
		struct node *del = front;

		if (front == rear)
			front = rear = NULL;
		else
			front = front->link;
		del->link = NULL;

		free(del);
		return item;
	}
}

// Main function.
int main()
{
	int choice, input;
	while (1)
	{
		// Options
		printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
		printf("\n1 ENQUEUE");
		printf("\n2 DEQUEUE");
		printf("\n3 CHECK EMPTY");

		printf("\n\n0 EXIT\n");

		printf("---------------------------------------");

		printf("\nENTER CHOICE : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			exit(1);
		case 1:
			printf("\nENTER ITEM : ");
			scanf("%d", &input);
			enqueue(input);
			break;
		case 2:
			printf("\nITEM POPED : %d", dequeue());
			break;
		case 3:
			if (is_empty())
				printf("\n\tQUEUE IS EMPTY!");
			else
				printf("\n\tQUEUE IS NOT EMPTY!");
			break;
		default:
			printf("\nINVALID INPUT!");
		}
	}
	return 0;
}