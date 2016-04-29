#include "dll.h"
int main()
{
	List *myList;
	char menuselect = 0;
	   char confirm = 0;
	Node *temp;
	Node *newNode;
	int input, seeker, validInput;

	while (menuselect != 'Q')
	{
		printf("==========What would you like to do?===========\n");
		printf("=====Press 'C' to create a linked list=========\n");
		printf("=====Press 'L' to display the list forwards====\n");
		printf("=====Press 'l' to display the list backwards===\n");
		printf("=====Press 'A' to append a node into the list==\n");
		printf("=====Press 'I' to insert a node into the list==\n");
		printf("=====Press 'R' to remove a node from the list==\n");
		printf("=====Press 'S' to sort the list================\n");
		printf("=====Press 'D' to clear the list===============\n");
		printf("=====Press 'Q' to quit=========================\n");
		printf("===============================================\n");
		scanf("%c", &menuselect);
		if (menuselect == 10)
			scanf("%c", &menuselect);
		else
			getchar();

		switch (menuselect)
		{
		case 'C':
			myList = build();
			break;
		case 'L':
			displayf(myList);
			break;
		case 'l':
			displayb(myList);
			break;
		case 'A':
				    printf("Current list : \n"); //new
				    printf("------------------------------\n");
				    displayf(myList); //new
				    printf("------------------------------\n");
			printf("Which node would you like to append after? :");
			scanf("%d", &input);
			temp = myList->start;
			for (seeker = 0; seeker < (input); seeker++)
			{
				temp = temp->next;
			}
			printf("Enter the value to be appended after Node [%d]:", input); //new
			scanf("%d", &input);
			newNode = (Node *) malloc(sizeof(Node));
			newNode->value = input;

			myList = append(myList, temp, newNode);

			break;
		case 'I':
				    printf("Current list : \n"); //new
				    printf("------------------------------\n");
				    displayf(myList); //new
				    printf("------------------------------\n");
			temp = myList->start;
			printf("Which node would you like to insert before?: ");
			scanf("%d", &input);

			for (seeker = 0; seeker < (input); seeker++)
			{
				temp = temp->next;
			}

			printf("enter the value to be inserted before Node [%d]?: ", input); //new
			scanf("%d", &input);
			newNode = (Node *) malloc(sizeof(Node));
			newNode->value = input;
			myList = insert(myList, temp, newNode);
			break;
		case 'R':
			temp = myList->start;
			printf("which node would you like to remove? :");
			scanf("%d", &input);
				    printf("Are you sure that you want to remove Node %d? (y/n) :", input);
				    scanf("%c", &confirm);
				    if (confirm == 10){
					scanf("%c", &confirm);
			}else{
					getchar();
			}
				    if (( confirm == 'n') || (confirm == 'y')) {
				    		validInput =1;
				    }
				    if ((validInput == 0) || (confirm == 'n')){
					   		if (validInput ==0){
							printf("Input not understood\n");
						}
						printf("Node [%d] will not be deleted\n", input);
						break;
					}

			for (seeker = 0; seeker < (input); seeker++)
			{
				temp = temp->next;
			}
			myList = getNode(myList, &temp);
			break;
		case 'S':
			//sortList(myList);
			       myList=sortList(myList);
			break;
		case 'D':
			//        myList=clearlist(myList);
			break;
		case 'Q':
			printf("Goodbye, cruel world\n");
			break;
		default:
			printf("Amplify Query!\n");
		}
	}

	return (0);

}
 
