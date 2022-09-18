#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data)
{
	// This function is only for empty list
	if (last != NULL)
	return last;

	// Creating a node dynamically.
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

	// Assigning the data.
	temp -> data = data;
	last = temp;

	// Creating the link.
	last -> next = last;

	return last;
}

struct Node *addBegin(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;

	return last;
}

struct Node *addEnd(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;
	last = temp;

	return last;
}

struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
		return NULL;

	struct Node *temp, *p;
	p = last -> next;
	do
	{
		if (p ->data == item)
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp -> data = data;
			temp -> next = p -> next;
			p -> next = temp;

			if (p == last)
				last = temp;
			return last;
		}
		p = p -> next;
	} while(p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;

}
/* Function to delete a given node from the list */
void deleteNode(struct Node* head, int key)
{
    if (head == NULL)
        return;

    // Find the required node
    struct Node *curr = head, *prev;
    while (curr->data != key)
    {
        if (curr->next == head)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    // Check if node is only node
    if (curr->next == head)
    {
        head = NULL;
        free(curr);
        return;
    }
    // If more than one node, check if
    // it is first node
    if (curr == head)
    {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }
    // check if node is last node
    else if (curr->next == head && curr == head)
    {
        prev->next = head;
        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
}
void traverse(struct Node *last)
{
	struct Node *p;

	// If list is empty, return.
	if (last == NULL)
	{
		cout << "List is empty." << endl;
		return;
	}

	// Pointing to first Node of the list.
	p = last -> next;

	// Traversing the list.
	do
	{
		cout << p -> data << " ";
		p = p -> next;

	}
	while(p != last->next);

}

// Driven Program
int main()
{
	struct Node *last = NULL;

	last = addToEmpty(last, 6);
	last = addBegin(last, 4);
	last = addBegin(last, 2);
	last = addEnd(last, 8);
	last = addEnd(last, 12);
	last = addAfter(last, 10, 8);

	traverse(last);
    deleteNode(last, 4);
    cout<<"\nList After Deletion of 4 : ";
    traverse(last);
	cout<<"\n";
	return 0;
}
