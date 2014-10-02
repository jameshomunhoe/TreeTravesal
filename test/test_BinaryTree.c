#include "unity.h"
#include "BinaryTree.h"
#include "Traversal.h"
#include "mock_Print.h"
#include "mock_Stack.h"

void setUp(void){}
void tearDown(void){}

/**
*		 6
*		/ \
*	   -   -
*/

void test_binary_tree_with_1_node(void){
	Node root = {NULL, NULL, 6};
	Stack stack;
	
	printf("Starts test_binaryTree_with_1_node\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(6);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTravesalInOrder(&root);
}

/**
*		10
*		/ \
*	   5   -
*/

void test_binary_tree_with_2_nodes_parent_and_left_child(void){
	Node leftChild = {NULL, NULL, 5};
	Node root = {&leftChild, NULL, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_2_nodes_parent_and_left_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack, &root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack, &root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack, NULL);
	
	stackDel_Expect(&stack);
	
	binaryTreeTravesalInOrder(&root);
}

/**
*		10
*		/ \
*	   5   20
*/

void test_binary_tree_with_3_node_parent_with_2_child(void){
	Node leftChild = {NULL, NULL, 5};
	Node rightChild = {NULL, NULL, 20};
	Node root = {&leftChild, &rightChild, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_3_node_parent_with_2_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack, &root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack, &root);
	display_Expect(10);
	stackPush_Expect(&stack, &root);
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	
	stackDel_Expect(&stack);
	
	binaryTreeTravesalInOrder(&root);
}

/**
*		10
*		/ \
*	   -   20
*/

void test_binary_tree_with_2_node_parent_with_right_child(void){
	Node rightChild = {NULL, NULL, 20};
	Node root = {NULL, &rightChild, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_2_node_parent_with_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(10);
	stackPush_Expect(&stack, &root);
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	
	stackDel_Expect(&stack);
	
	binaryTreeTravesalInOrder(&root);
}

/**
*		10
*		/ \
*	   5   -
*	  / \
*	 1   7
*/

void test_binary_tree_with_4_node_parent_with_left_child_with_2_child(void){
	Node Child1 = {NULL, NULL, 1};
	Node Child7 = {NULL, NULL, 7};
	Node Child5 = {&Child1, &Child7, 5};
	Node root = {&Child5, NULL, 10};
	Stack stack;
	
	printf("Starts test_binary_tree_with_4_node_parent_with_left_child_with_2_child\n");
	stackNew_ExpectAndReturn(&stack);
	
	stackPush_Expect(&stack, &root);
	stackPush_Expect(&stack, &Child5);
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack, &Child5);
	display_Expect(5);
	stackPush_Expect(&stack, &Child5);
	display_Expect(7);
	stackPop_ExpectAndReturn(&stack, &Child5);
	stackPop_ExpectAndReturn(&stack, &root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack, NULL);
	
	stackDel_Expect(&stack);
	
	binaryTreeTravesalInOrder(&root);
}


/**
*		10
*		/ \
*	   5   -
*	  / \
*	 1   -
*/
void test_binaryTreePrintInOrder_1_5_10(void){
	
	Node Child1 = {NULL, NULL, 1};
	Node Child5 = {&Child1, NULL, 5};
	Node root = {&Child5, NULL, 10};
	
	printf("test_binaryTreePrintInOrder_1_5_10\n");
	binaryTreePrintInOrder(&root);

}

/**
*		10
*	   /   \
*	  5    15
*/
void test_binaryTreePrintInOrder_5_10_15(void){
	
	Node Child15 = {NULL, NULL, 15};
	Node Child5 = {NULL, NULL, 5};
	Node root = {&Child5, &Child15, 10};
	
	printf("test_binaryTreePrintInOrder_5_10_15\n");
	binaryTreePrintInOrder(&root);

}

/**
*		10
*	  /  	 \
*	 5  	 15
*	/  \ 	 / \
*  1	6  	12  17
*/
void test_binaryTreePrintInOrder_1_5_6_10_12_15_17(void){
	
	Node Child17 = {NULL, NULL, 17};
	Node Child12 = {NULL, NULL, 12};
	Node Child15 = {&Child12, &Child17, 15};
	
	Node Child1 = {NULL, NULL, 1};
	Node Child6 = {NULL, NULL, 6};
	Node Child5 = {&Child1, &Child6, 5};
	Node root = {&Child5, &Child15, 10};
	printf("test_binaryTreePrintInOrder_1_5_6_10_12_15_17\n");
	binaryTreePrintInOrder(&root);

}