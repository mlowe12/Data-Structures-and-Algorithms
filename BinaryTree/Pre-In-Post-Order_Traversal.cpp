#include <iostream>
#include <string>
#include <queue>

using namespace std;


class Node {
	public:
		string data;
		//int index;
		Node* left_child;
		Node* right_child;
		//Node* parent;
		//Node* root;

		Node() {
			left_child = NULL;
			right_child = NULL;
			//Node* root = NULL;
		}
		Node(string d) {
			data = d;
		}

		Node(string d, Node* left, Node* right) {
			data = d;
			left_child = left;
			right_child = right;
		}

		string Data();

		//void print_inorder(Node* node);
		void setData(string wordData);
		void setLeft(Node* wordLeft);
		void setRight(Node* wordRight);
		//void setParent(Node* wordParent);
		//string Data();
		Node* Left();
		Node* Right();
		//Node* Root();
		//Node* Parent();
};

string Node::Data() {
	return data;
}

Node* Node::Left() {
	return left_child;
}

Node* Node::Right() {
	return right_child;
}

/*Node* Node::Root() {
	return root;
}*/

void Node::setData(string wordData) {
	data = wordData;
}

void Node::setLeft(Node* wordLeft) {
	left_child	= wordLeft;
}

void Node::setRight(Node* wordRight) {
	right_child = wordRight;
}

void print_inorder(Node* node) {
	if(node) {
		print_inorder(node->left_child);
		cout << node->data << " ";
		print_inorder(node->right_child);
	}
}

void print_postorder(Node* node) {
	if(node) {
		print_postorder(node->left_child);
		print_postorder(node->right_child);
		cout << node->data << " ";
	}
}

void print_preorder(Node* node) {
	if(node) {
		cout << node->data << " ";
		print_preorder(node->left_child);
		print_preorder(node->right_child);
	}
}

void print_levelorder(Node* node) {
	queue<Node*> q;

	q.push(node);

	while(!q.empty()) {
		Node* temp_node = q.front();
		q.pop();

		if(temp_node) {
			cout << temp_node->data << " ";
			q.push(temp_node->left_child);
			q.push(temp_node->right_child);
		}
	}
}


int main() {
	int numberOfNodes;
	cout << "Number of Nodes in Tree: " ;
	cin >> numberOfNodes;
	cout << endl;
	
	Node arr[numberOfNodes];

	string nodeData;
	int leftNode;
	int rightNode;

	for (int i = 0; i < numberOfNodes; i++) {
		//Node* temp = 
		cin >> nodeData >> leftNode >> rightNode;
		//arr[i]->setData(nodeData);

		if (leftNode == -1 && rightNode == -1) {
			arr[i].data = nodeData;
			arr[i].left_child = NULL;
			arr[i].right_child = NULL;
		}

		else if (leftNode == -1) {
			arr[i].data = nodeData;
			arr[i].left_child = NULL;
			arr[i].right_child = &arr[rightNode];
		}

		else if (rightNode == -1) {
			arr[i].data = nodeData;
			arr[i].left_child = &arr[leftNode];
			arr[i].right_child =  NULL;
		}

		else {
			arr[i].data = nodeData;
			arr[i].left_child = &arr[leftNode]; 
			arr[i].right_child = &arr[rightNode];

		}
		
	
	}
	print_postorder(&arr[0]);
	cout << endl;
	print_inorder(&arr[0]);
	cout << endl;
	print_preorder(&arr[0]);
	cout << endl;
	print_levelorder(&arr[0]);


	return 0;
}
