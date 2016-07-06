#include <stdio.h>
#include <stdlib.h>

// using namespace std;
class Node
{

public:

Node* next;

int data;

};


void showListData(Node* node)
{

	while(node && node->next)
	{

		// std::cout<<node->data;

		node = node->next;

	}

}


int main(int args,char** argv)
{

	Node* headNode = new Node();

	headNode->data = 0;


	Node* curNode = headNode;

	for(int i = 1; i < 10;i++)
	{

		Node* temp= new Node();

		temp->data = i;

		curNode->next = temp;

		curNode = temp;

	}


	showListData(headNode);


	/*

	A->B->C->D

	B->A->C->D

	C->B->A->D

	D->C->B->A

	*/

	while(headNode->next)
	{

		Node* temp = headNode->next;

		headNode->next = temp->next;

		temp->next = headNode;

		headNode = temp;

	}

	showListData(headNode);

}