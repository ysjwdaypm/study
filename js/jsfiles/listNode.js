function Node(next,data){
	this.next = next;
	this.data = data;
}

function showListData(node){
	var curNode = node;
	while(curNode.next){
		debug(curNode.data);
		curNode = curNode.next;
	}

}

 /*

A->B->C->D

B->A->C->D

C->B->A->D

D->C->B->A

*/
function reverse(node){

	var head = node;
	while(node && node.next){
		var curNode = node.next;
		node.next = curNode.next;
		curNode.next = head;
		head = curNode;
		
	}

	return head;
}


function start(){
	var headNode = new Node(null,0);

	var curNode = headNode;
	for(var i=1 ;i < 10;i++){
		var node = new Node(null,i);
		curNode.next = node;
		curNode = node;
	}

	showListData(headNode);
	headNode = reverse(headNode);
	showListData(headNode);
	

}

start();