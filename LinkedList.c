#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void LinkedlIstTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insertion functions (unchanged)
struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *insertAfterNode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Deletion functions
// Case 1: Delete first node
struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Delete at index
struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Delete last node
struct node *deleteAtLast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4: Delete by value
struct node *deleteByValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q != NULL && q->data != value)
    {
        p = p->next;
        q = q->next;
    }
    if (q != NULL && q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

// search functionality
struct node *searchElement(struct node *head, int key)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return current; // Element found, return pointer to node.
        }
        current = current->next;
    }
    return NULL; // Element not found.
}

// update functionality
void updateValue(struct node *head, int oldValue, int newValue)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == oldValue)
        {
            current->data = newValue;
            printf("Value updated from %d to %d.\n", oldValue, newValue);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", oldValue);
}

int main()
{
    int choose;
    int key;

    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
    forth = malloc(sizeof(struct node));

    head->data = 20;
    head->next = second;
    second->data = 80;
    second->next = third;
    third->data = 40;
    third->next = forth;
    forth->data = 30;
    forth->next = NULL;

    // Overwriting sample list values as given
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = forth;
    forth->data = 66;
    forth->next = NULL;

    do
    {
        printf("\nMenu:\n");
        printf("1. LinkedList Traversal\n");
        printf("2. LinkedList Insertion\n");
        printf("3. LinkedList Deletion\n");
        printf("4. LinkedList Search\n");
        printf("5. LinkedList Update\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("Traversal of linked list:\n");
            LinkedlIstTraversal(head);
            break;
        case 2:
            printf("LinkedList Insertion\n");
            {
                char insertionChoose;
                do
                {
                    printf(" a. Insert at first\n");
                    printf(" b. Insert at index\n");
                    printf(" c. Insert at end\n");
                    printf(" d. Insert after node\n");
                    printf("Choose where you need to insert: ");
                    scanf(" %c", &insertionChoose);

                    switch (insertionChoose)
                    {
                    case 'a':
                        printf("Inserting at first of linked list\n");
                        printf("Enter a key to insert at first: ");
                        scanf("%d", &key);
                        head = insertAtFirst(head, key);
                        LinkedlIstTraversal(head);
                        break;
                    case 'b':
                    {
                        printf("Inserting at index of linked list\n");
                        printf("Enter a key to insert at index: ");
                        scanf("%d", &key);
                        int index;
                        printf("Enter index to insert: ");
                        scanf("%d", &index);
                        head = insertAtIndex(head, key, index);
                        LinkedlIstTraversal(head);
                        break;
                    }
                    case 'c':
                        printf("Inserting at end of linked list\n");
                        printf("Enter a key to insert at end: ");
                        scanf("%d", &key);
                        head = insertAtEnd(head, key);
                        LinkedlIstTraversal(head);
                        break;
                    case 'd':
                    {
                        printf("Inserting after a node in linked list\n");
                        printf("Enter a key to insert after node: ");
                        scanf("%d", &key);
                        int NodeChoose;
                        struct node *selectedNode = NULL;
                        do
                        {
                            printf("Which node do you want to insert after?\n");
                            printf(" 1. Head\n");
                            printf(" 2. Second\n");
                            printf(" 3. Third\n");
                            printf(" 4. Forth\n");
                            printf("Choose Node: ");
                            scanf("%d", &NodeChoose);

                            if (NodeChoose == 1)
                            {
                                selectedNode = head;
                            }
                            else if (NodeChoose == 2)
                            {
                                selectedNode = second;
                            }
                            else if (NodeChoose == 3)
                            {
                                selectedNode = third;
                            }
                            else if (NodeChoose == 4)
                            {
                                selectedNode = forth;
                            }
                            else
                            {
                                printf("Invalid choice. Try again.\n");
                            }
                        } while (NodeChoose < 1 || NodeChoose > 4);
                        head = insertAfterNode(head, selectedNode, key);
                        LinkedlIstTraversal(head);
                        break;
                    }
                    default:
                        printf("Invalid insertion option, try again.\n");
                    }
                } while (insertionChoose != 'a' && insertionChoose != 'b' &&
                         insertionChoose != 'c' && insertionChoose != 'd');
            }
            break;
        case 3:
            printf("LinkedList Deletion\n");
            {
                char deletionChoose;
                do
                {
                    printf(" a. Delete first node\n");
                    printf(" b. Delete node at index\n");
                    printf(" c. Delete last node\n");
                    printf(" d. Delete node by value\n");
                    printf("Choose deletion option: ");
                    scanf(" %c", &deletionChoose);

                    switch (deletionChoose)
                    {
                    case 'a':
                        head = deleteFirst(head);
                        LinkedlIstTraversal(head);
                        break;
                    case 'b':
                    {
                        int index;
                        printf("Enter index to delete: ");
                        scanf("%d", &index);
                        head = deleteAtIndex(head, index);
                        LinkedlIstTraversal(head);
                        break;
                    }
                    case 'c':
                        head = deleteAtLast(head);
                        LinkedlIstTraversal(head);
                        break;
                    case 'd':
                    {
                        int value;
                        printf("Enter value to delete: ");
                        scanf("%d", &value);
                        head = deleteByValue(head, value);
                        LinkedlIstTraversal(head);
                        break;
                    }
                    default:
                        printf("Invalid deletion option, try again.\n");
                    }
                } while (deletionChoose != 'a' && deletionChoose != 'b' &&
                         deletionChoose != 'c' && deletionChoose != 'd');
            }
            break;
        case 4:
            printf("LinkedList Search\n");
            {
                int search;
                printf("Enter element to search: ");
                scanf("%d", &search);
                struct node *found = searchElement(head, search);
                if (found != NULL)
                    printf("Element %d found in the list.\n", search);
                else
                    printf("Element %d not found in the list.\n", search);
            }
            break;
        case 5:
            printf("Updating the LinkedList\n");
            {
                int oldValue, newValue;
                printf("Enter the value to update: ");
                scanf("%d", &oldValue);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                updateValue(head, oldValue, newValue);
                LinkedlIstTraversal(head);
            }
            break;
        default:
            printf("You chose a wrong choice.\n");
        }
    } while (choose != 0);

    return 0;
}
