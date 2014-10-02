#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"

void binaryTreeTravesalInOrder(Node *rootPtr){
	Stack *stackPtr = stackNew();
	Node *currentNode;
	currentNode = rootPtr;
	
	currentNode->state = ENTERED_NODE;
	
while(1){
	if(currentNode->state == ENTERED_NODE){
		if(currentNode->left != NULL){
			stackPush(stackPtr,currentNode);
			currentNode = currentNode->left;
			currentNode->state = ENTERED_NODE;
		}
		else
			currentNode->state = VISITED_LEFT_NODE;
	}
	if(currentNode->state == VISITED_LEFT_NODE){
		if(currentNode->right != NULL){
			display(currentNode->data);
			stackPush(stackPtr,currentNode);
			currentNode = currentNode->right;
			currentNode->state = ENTERED_NODE;
		}
		else{
			display(currentNode->data);
			currentNode->state = VISITED_RIGHT_NODE;
		}
	}
	if(currentNode->state == VISITED_RIGHT_NODE){
		currentNode = stackPop(stackPtr);
		
		if(currentNode == NULL)
			break;
		if(currentNode->state == ENTERED_NODE)
			currentNode->state = VISITED_LEFT_NODE;
		else if(currentNode->state == VISITED_LEFT_NODE)
			currentNode->state = VISITED_RIGHT_NODE;	
	}
}
	
	stackDel(stackPtr);
}


void binaryTreePrintInOrder(Node *node){

	if(node != NULL){
		binaryTreePrintInOrder(node->left);
		printf("data : %d \n", node->data);
		binaryTreePrintInOrder(node->right);
	}
}