#include "dll.h"

List *build()
{

        List *myList = (List *) malloc(sizeof(List));

        myList->start = myList->end = NULL;

        int input, nodeCount = 0;
	   myList->qty=0;	

        printf("Enter a value for Node %d (-1 to quit): ", nodeCount);
        scanf("%d", &input);
	   nodeCount++;
        while (input != -1)
      {
                if (myList->start == NULL)
                {
                        myList->start = myList->end =
                            (Node *) malloc(sizeof(Node));
                        myList->start->value = input;
                        myList->end->prev = myList->start->next = NULL;
			myList->qty=myList->qty+1;
                }
                else
                {
                        myList->end->next = (Node *) malloc(sizeof(Node));
                        myList->end->next->value = input;
                        myList->end->next->next = NULL;
                        myList->end->next->prev = myList->end;
                        myList->end = myList->end->next;
			myList->qty=myList->qty+1;
                }

                printf("Enter value for Node %d (-1 to quit): ", nodeCount);
                scanf("%d", &input);
	   nodeCount++;
        }
        return (myList);
}
//display forwards
void displayf(List * myList)
{
        int input = 0;
        Node *temp = NULL;

        temp = myList->start;
        while (temp != NULL)
        {
                printf("Node [%d] Has Value (%d)->\n", input, temp->value);
                temp = temp->next;
                input = input + 1;
        }
        printf("NULL\n");
	printf("The quantity of nodes currently is: %d\n",myList->qty);

}
//display backwards
void displayb(List * myList)
{
        int input = 0;
        Node *temp = NULL;

        temp = myList->end;
        while (temp != NULL)
        {
                printf("Node [%d] Has Value (%d)->\n", input, temp->value);
                temp = temp->prev;
                input = input + 1;
        }
        printf("NULL\n");
	printf("The quantity of nodes currently is: %d\n",myList->qty);

}
//append
List *append(List * myList, Node * place, Node * newNode)
{
        if (place == myList->end)
        {
                newNode->next = NULL;
                newNode->prev = place;
                place->next = newNode;
                myList->end = newNode;
        }
        else
        {
                newNode->next = place->next;
                newNode->prev = place;
                newNode->next->prev = newNode;
                place->next = newNode;

        }
	myList->qty=myList->qty+1;
        return (myList);
}
//insert
List *insert(List * myList, Node * place, Node * newNode)
{
        if (place == myList->start)
        {
                newNode->next = place;
                place->prev = newNode;
                newNode->prev = NULL;
                myList->start = newNode;
        }
        else
        {
                newNode->next = place;
                place->prev->next = newNode;
                newNode->prev = place->prev;
                place->prev = newNode;
        }
	myList->qty=myList->qty+1;
        return (myList);
}
//remove
List *getNode(List * myList, Node ** place)
{
        if (myList->start->next == NULL)
        {
                myList->start = NULL;
        }
        else if (*place == myList->start)
        {
                myList->start = myList->start->next;
                myList->start->prev = NULL;
                (*place)->next = NULL;
        }
        else if (*place == myList->end)
        {
                myList->end = myList->end->prev;
                myList->end->next = NULL;
                (*place)->prev = NULL;
        }
        else
        {
                (*place)->prev->next = (*place)->next;
                (*place)->next->prev = (*place)->prev;
                (*place)->prev = (*place)->next = NULL;
        }
	myList->qty=myList->qty -1;
        return (myList);
}

List * sortList(List * myList){
        int sortCount=1;
        Node **temp = myList->start;
        Node *tempN2 = NULL;
        Node *oldNode = NULL;
        List **tempL = myList;
        
        
        printf("**DEBUG**\nvalue at temp is %d\n", temp->value);
                if (tempL->start->value > tempL->start->next->value){
                        printf("value at temp->next is %d\n", tempL->next->value);
                        oldNode = temp;
                        *temp->value = *temp->next->value;
                        *temp->next->value = oldNode->value; 
                }  
               
      myList = tempL;
      return myList;
}

List * mklist(){

	List * myList=(List*)malloc(sizeof(List*));
	myList->start=NULL;
	myList->end=NULL; 
	myList->qty=0;
	return(myList);
}

Node * create(){

	Node * temp;
	temp=(Node*)malloc(sizeof(Node*));
	temp->prev=temp->next=NULL;
	temp->value=0;
	return(temp);
}
