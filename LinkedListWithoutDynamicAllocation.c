//Ons Bouzidi //
//Linked List without dynamic allocation //
//using array//

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define TOTAL_NODES 25

//create the node structure

struct Node

{
uint8_t locationIsAvailable; // This variable will be used to check if the Node in the List is available or not
uint32_t __attribute__((packed)) val;
struct  __attribute__((packed)) Node* nextptr; 

/*__attribute__((packed)) is  a compiler-specific attribute that can be 
applied to structs or classes in C++. It tells the compiler to pack the 
members of the struct together without adding any padding bytes between them */
};



// Reserve Memory for our 25 nodes, we will be using the array for memory allocation

struct Node ReservedMemoryForList[TOTAL_NODES];


struct Node* currentptr;
struct Node* previousptr;


// create a newNode that will be used to place data within the list
struct Node* newNode;

// first Node in the list
struct Node* headNode;


uint8_t nodeFound; // a variable that will be used to determiine if the search found the node that we were looking for uint8_t i;




void main(void) 

{

uint8_t i;

currentptr = &ReservedMemoryForList[0]; //currentptr is set to the address of the first element of the array


for (i=0; i< TOTAL_NODES; i++)

{
currentptr -> locationIsAvailable =1; // all nodes are available to us
currentptr ->val =0; //clear the value
currentptr->nextptr = NULL;
/*By setting nextptr to NULL for each node in the array, we are essentially setting
up a list where each node is isolated and not connected to any other node
initially. This is a common practice when initializing a linked list, as we will 
later update this nextptr values to link the nodes together in the correct order during the construction 
of insetion of the list. */
currentptr++;


} /*in this for loop currentpt++ is used to move currentptr
to point to each element of the array, after each iteration of the loop
currentptr will point to the next Node in the array, allowing us
to initialize or modify each element individually*/

headNode = &ReservedMemoryForList[0];

headNode->val=2;
headNode ->locationIsAvailable = 0; // this node is not available
headNode->nextptr = ++currentptr;


currentptr->val =3;
currentptr->locationIsAvailable=0;
currentptr->nextptr = ++currentptr;

currentptr->val =4;
currentptr->locationIsAvailable=0;
currentptr->nextptr= NULL; // this is the last Node in our Linked List

newNode = NULL; // this is the node that we will insert into the list in a numerical order


for (i=0 ; i<TOTAL_NODES ; i++) // for loop to look for an available Node
{
    if (currentptr->locationIsAvailable) // if locationIsAvailable is one, then we found the available Node
    {
        newNode = currentptr; 
        newNode -> locationIsAvailable =0; // Now that we found this Node we set it to no longer available
        break;

    }
currentptr++;
}


/*if we come out of this loop with newNode still NULL then it means there was no Node available found*/

if (newNode !=NULL)
{

newNode-> val=4; // this available node we will instert it in the list in a numerical order


currentptr= headNode;
previousptr = headNode;
nodeFound =0;

//insertion of Node in a numerical Order

    while(previousptr -> nextptr != NULL) // parse until the end of the list
        {
            if((currentptr -> val) > (newNode -> val))
            {
                nodeFound = 1;
                newNode -> nextptr = currentptr; // insert newNode before currentptr
            
                if(currentptr != headNode)
                    previousptr -> nextptr = newNode;
// if currentptr is not pointing to the first element of list, Insert newNode after previousptr        
                else
                    headNode = newNode;
//if currentptr is pointing to the first element of the list then newNode is the new first element of the list(headNode)
                break;
            }

            previousptr = currentptr;        
            currentptr = currentptr -> nextptr;
        } 



//Check if a node was found.  If not, put the value at the end of the list    
        if(!nodeFound)
        {
            previousptr -> nextptr = newNode;
            newNode -> nextptr = NULL;        
            nodeFound = 0;
        }
    
        nodeFound = 0;
}

//delete a Node

    currentptr = headNode;
    previousptr = headNode;
    
    while(previousptr -> nextptr != NULL)
    {
        if((currentptr -> val) == 3) // the Node we want to delete with the value 3
        {
            if(currentptr == headNode) 
            //if the Node we will delete is the first element of the List
            {
                headNode = currentptr -> nextptr;
                // the new headNode it's its next Node 
            }
            
            else if(currentptr -> nextptr == NULL)
             //if the Node we will delete at the end of the list
            {
                previousptr -> nextptr = NULL;
                //previousptr is now pointing to NULL instead of the Node that we deleted
            }
            
            else
            {
                previousptr -> nextptr = currentptr -> nextptr;
            }
            
            currentptr -> locationIsAvailable = 1; 
        

            currentptr -> nextptr = NULL;
            break;            
        }

        previousptr = currentptr;        
        currentptr = currentptr -> nextptr;
    }     

    while(1);









}





