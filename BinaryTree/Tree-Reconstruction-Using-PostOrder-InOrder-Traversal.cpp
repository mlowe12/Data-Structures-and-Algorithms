#include <iostream>
#include <string>
#include <queue>
#include <iterator>
#include <vector>


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
			data = " ";
			left_child = NULL;
			right_child = NULL;
			//Node* root = NULL;
		}
		Node(string d) {
			data = d;
			left_child = NULL;
			right_child = NULL;
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

		Node* construct(vector<string> &in_order, vector<string> &post_order, int iStart, int iEnd, int pEnd);
		Node* buildBinaryTree(vector<string> &in_order, vector<string> &post_order);
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

// Level Order Traversal
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

Node* Node::construct(vector<string> &in_order, vector<string> &post_order, int iStart, int iEnd, int pEnd) {
	
	if (iStart > iEnd) {
		return NULL;
	}

	// Create a Node and set the Data/Root of the node to the last element in PostOrder Traversal otherwise known as the Root of the Tree
	Node* res = new Node(post_order[pEnd]);
	int mid;

	// Find the root in the InOrder Traversal
	for (int i = iStart; i <= iEnd; i++) {
		if (in_order[i] == res->data) {
			// Root found in the InOrder Traversal
			mid = i;
			break;
		}
	}

	// Construct the right side of the tree
	res->right_child = construct(in_order, post_order, mid+1, iEnd, pEnd-1);
	// Construct the left side of the tree
	res->left_child = construct(in_order, post_order, iStart, mid-1, pEnd-1-iEnd+mid);
	return res;
	//print_levelorder(res);
}


Node* Node::buildBinaryTree(vector<string> &in_order, vector<string> &post_order) {

	if (post_order.size() == 0 ) {
		return NULL;
	} else {
		
		// Call the function to construct the Tree from the Inorder and PostOrder Traversal
		return construct(in_order, post_order, 0, in_order.size()-1, post_order.size()-1);
	}
}

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


int main() {
	int numberOfNodes;
	// Get Number of nodes to be inserted into Tree
	cout << "Enter the number of Elements in the Tree: " ;
	cin >> numberOfNodes;

	Node tree;

	string p;
	string n;
	vector<string> postorder;
	vector<string> inorder;

	int i = 0;
	int t = 0;
	cout << endl;

	// Get PostOrder Traveral and store them in a vector
	cout << "PostOrder Traversal: " ;
	while(i < numberOfNodes) {
		cin >> p;
		postorder.push_back(p);
		i++;
	}
	cout << endl;

	// Get InOrder Traversal and store them in a vector
	cout << "InOrder Traversal: " ;
	while (t < numberOfNodes) {
		cin >> n;
		inorder.push_back(n);
		t++;
	}
	cout << endl;


	

	/*
	// Print Out Vector Post Order
	for (vector<string>::iterator it = postorder.begin(); it != postorder.end(); it++) {
		cout << *it << "" ;
	}

	cout << endl;
	
	//Print Out Vector Inorder
	for (vector<string>::iterator it = inorder.begin(); it != inorder.end(); it++) {
		cout << *it << "";
	}
	//cout << endl;
	*/

	//Create a temp Node and assign it to the newly constructed tree
	Node* temp = tree.buildBinaryTree(inorder, postorder);


	// Print Out Level Order Traversal of Newly Construted Tree
	cout << "Level Order Traversal: ";
	print_levelorder(temp);


	return 0;
}
