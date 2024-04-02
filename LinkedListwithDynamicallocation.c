//Ons Bouzidi//
// Linked Lists with Dynamic allocation // 

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>



struct Node
{

int val; //the value of the Node
struct Node *Nextptr; // a Pointer that points to the next Node

};


//Pointers that wil be used to add or delete nodes
struct Node* currentptr;
struct Node* previousptr;


uint8_t nodeFound; // a char variable that we will use to denote when we find a node that we're searchig for


int main () 
{

struct Node* headNode = NULL; // first item of a Linked list
struct Node* secondNode = NULL; // second item
struct Node* thirdNode = NULL; // third item 

struct Node* NewNode = NULL;


// allocate the Nodes in the heap 

headNode = (struct Node*)malloc(sizeof(struct Node)); //headNode now points to the memory that was just allocated
secondNode =(struct Node*)malloc(sizeof(struct Node)); 
thirdNode = (struct Node*)malloc(sizeof(struct Node));


// initialize the nodes
headNode -> val =2;
headNode->Nextptr = secondNode; 
secondNode->val =3;
secondNode->Nextptr = thirdNode;
thirdNode->val=4;
thirdNode->Nextptr = NULL;


//create a nex node , it is not placed in the list yet 
NewNode = (struct Node*) malloc (sizeof(struct Node));
NewNode ->val=4; 

//initialize the node pointers : Initially, both pointers need to point to the beginning of the list 
currentptr = headNode;
previousptr = headNode;
nodeFound =0; // nodeFound will be set to one when we find the node that we are looking for



// INSERT A NEW NODE IN OUR LIST
while (previousptr ->Nextptr !=NULL) // parse until the end of the list

{
 if ((currentptr->val) > (NewNode->val))   

 {
  nodeFound =1; 
  NewNode->Nextptr = currentptr; // the currentptr will be next to the new added node

  if (currentptr !=headNode) // if we're not on the first item of the list
  previousptr->Nextptr = NewNode; // then previous item should be the new added node

else // if we're on the first item of the list 
headNode = NewNode; // the first item of the list will become the new added node

break; // Exit the loop after inserting the NewNode at the correct position
 }

        previousptr = currentptr;   //increment in the list  
        currentptr = currentptr -> Nextptr; // this line is uses to move currentptr to the next node in the list, so that currentptr is always pointing to the node after which NewNode should be inserted

 }

if (!nodeFound) // if node was not found we're going to put this new Node at the end of the list
{
previousptr -> Nextptr = NewNode;
NewNode ->Nextptr = NULL;
nodeFound =0;
}


//*************************************************************************************************************//

// DELETE A NODE FROM A LINKED LIST
currentptr = headNode;
previousptr = headNode;
while (previousptr ->Nextptr !=NULL) // parse until the end of the list

{

if ((currentptr->val) ==3)
{

if(currentptr == headNode) // to check if the node we want to delete is at the headnode location
{

    headNode = currentptr ->Nextptr;
    /*to delete the head node , we set headnode to point to the next node
    this removes the current head node from the list and makes 
    the next node the new head node*/
}
else if (currentptr -> Nextptr = NULL) // to check if the node we want to delete is at the end of the list
{
 previousptr -> Nextptr = NULL;


}
else  // node we want to delete is either the first item or the last
{
previousptr->Nextptr = currentptr -> Nextptr ; 
/*the Nextptr of the previous Node will skip over currentptr 
and point directly to currentptr->Nextptr, effectively removing currentptr from the list*/

}

free(currentptr); //to free the memory occupied by the deleted node
break;

}

previousptr=currentptr;
currentptr = currentptr -> Nextptr; 



}


















}
















}

