/*

	A C Program To Implement List Abstract Data Type with help of Linked List using Pointers
	
	Sample Input && Output:

	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 1

	Enter the Element to Insert: 45

	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 1

	Enter the Element to Insert: 78

	Enter the Position(List Size 1): 2

	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 4

	List: 45 78


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 1

	Enter the Element to Insert: 85

	Enter the Position(List Size 2): 1

	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 4

	List: 85 45 78


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 1

	Enter the Element to Insert: 56

	Enter the Position(List Size 3): 3

	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 4

	List: 85 45 56 78


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 1

	Enter the Element to Insert: 22

	Enter the Position(List Size 4): 2

	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 4

	List: 85 22 45 56 78


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 4

	List: 85 22 45 56 78


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 3
	Enter the Element to Find: 85

	The Element Found at 1.


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 3
	Enter the Element to Find: 78

	The Element Found at 5.


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 4

	List: 85 22 45 56 78


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 3
	Enter the Element to Find: 45

	The Element Found at 3.


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 3
	Enter the Element to Find: 100

	Element Not Found.


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 4

	List: 85 22 45 56 78


	1.Insert
	2.Delete
	3.Find
	4.Print
	(0 to Exit)
	Enter Your Choice: 0

*/

//Including Required Header Files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Declaration of List(Node)
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node List;

//Function Declaration
void Insert();
void Delete();
void Find();
void Print();

//Head Pointer
List *head = NULL;

//Length of the List
int List_Size = 0;

int main(){
	int choice;
	while(1){
		printf("\n1.Insert\n2.Delete\n3.Find\n4.Print\n(0 to Exit)\nEnter Your Choice: ");
		scanf("%d", &choice);

		if (choice == 0){	
			return 0;
		}
		switch (choice)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Find();
			break;
		case 4:
			Print();
			break;
		default:
			printf("\nWrong Choice!!!\n");
			break;
		}
	}
}

//Definition of Insert Function to insert elements into the list
void Insert(){
	int pos;
	List *newnode = malloc(sizeof(List));
	printf("\nEnter the Element to Insert: ");
	scanf("%d", &newnode->data);
	if (head == NULL){
		newnode->next = NULL;
		head = newnode;
		List_Size += 1;
		return;
	}
	List *ptr = head;
	List *preptr = ptr;
	printf("\nEnter the Position(List Size %d): ", List_Size);
	scanf("%d", &pos);

	if (pos > List_Size){
			while (ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = newnode;
			newnode->next = NULL;
			List_Size += 1;
			return;
	}
	if (pos == 1){
			newnode->next = head;
			head = newnode;
			List_Size++;
			return;
		}
	int position = 1;
	while(ptr != NULL){
		if (pos == position){
			preptr->next = newnode;
			newnode->next = ptr;
			List_Size += 1;
			return;
		}
		position++;
		preptr = ptr;
		ptr = ptr->next;
	}
}


//Definition of Delete Function to Remove elements from the list
void Delete(){
	int data, count = 0;
	printf("Enter the Element to Delete: ");
	scanf("%d", &data);
	List *ptr = head;
	List *preptr = ptr;
	while(ptr != NULL){
		if (data == ptr->data){
			preptr->next = ptr->next;
			if (count  == 0){
				head = ptr->next;
				List_Size--;
				return;
			}
			if (count >= List_Size){
				ptr->next = NULL;
			}
			List_Size--;
			return;
		}
		preptr = ptr;
		ptr = ptr->next;
		count++;
	}
	printf("\nElement Not Found.\n");
}


//Definition of Find Function to Find a element in the list
void Find(){
	if (head == NULL){
		printf("\nList is Empty\n\n");
		return;
	}
	int val, pos = 1;
	printf("Enter the Element to Find: ");
	scanf("%d", &val);
	List *ptr = head;
	while(ptr != NULL){
		if (val == ptr->data){
			printf("\nThe Element Found at %d.\n\n", pos);
			return;
		}
		pos += 1;
		ptr = ptr->next;
	}
	printf("\nElement Not Found.\n\n");
	return;
}


//Definition of Print Function to print the List
void Print(){
	if (head == NULL){
		printf("\nList Empty!!\n\n");
		return;
	}
	printf("\nList: ");
	List *ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
	return;
}