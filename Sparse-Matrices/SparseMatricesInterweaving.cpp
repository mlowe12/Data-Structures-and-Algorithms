// Quinton Reddick
// COP530 - Section 15A6
// Assignment 3 - Sparse Matrices
// Copyright (c) 2016
// All Rights Reserved

#include <iostream>

using namespace std;


class ChainNode {
	// data members
	
	public:
		int element;
		int column;
		ChainNode *next;

		//methods Constructor
		ChainNode () {}
		
		// create a chain node that holds two values
		ChainNode (int a, int b) {
			column = a;
			element = b;
		}
		
		// create a chain node that holds two values and a node pointer
		ChainNode (int a, int b, ChainNode *n) {
			column = a;
			element = b;
			next = n;
		}
};


class Chain {
	public:
		// create a node first and last

		ChainNode *first;
		ChainNode *last;
		int listSize;
		
		//constructor, copy constructor,
		Chain();
		

		
		int size(); 

		// gets a node at a certain index
		ChainNode *getNode(int theIndex) {
			
			// create a node and clarify what it is
			ChainNode *f = first;

			while (theIndex > 0) {
				theIndex--;
				if (f != NULL) {
					f = f->next;
				} else {
					return NULL;
				}
			}
			return f;
		}

		// get an element at a certain index
		int getElement(int theIndex);
		
		// insert an element at a certain index
		//void insert(int theIndex, int element);

		// insert elements into a linked list in the order they are inputed, add element at end of chain
		void add(int column, int element); // this function also appends to the last element

		
		//void merge(Chain addIn, int step);

		// print the linked list
		void output();

		//void matrix_add(Chain a[], Chain b[], Chain c[], int rowcount);

};


Chain::Chain() {
	// Constructor

	// when creating a new Chain set the first and last node to NULL
	first = NULL;
	last = NULL;

	//initial size of chain is 0
	listSize = 0;
}

int Chain::size() {
	// use S for start to keep track of first
	ChainNode *f = first;
	int size = 0;

	while (f != NULL) {
		size++;
		f = f->next;
	}
	return size;
}

int Chain::getElement(int theIndex) {
	// get the index and set the node pointer to it
	ChainNode *f = getNode(theIndex);
	// pointer will return the element that it's pointing to
	return f->element;
}


/*void Chain::insert(int element, int theIndex) {
	// Insert the element so that its index is theIndex.
	ChainNode *beforeNode = getNode(theIndex - 1);

	if (theIndex == 0) {
		first = new ChainNode(element);
	} else {
		beforeNode->next = new ChainNode(element, beforeNode->next);
	}
	listSize++;
}*/

void Chain::add(int column, int element) {
	ChainNode *temp = new ChainNode(column, element, NULL);

	if (first == NULL) {
		first = last = temp;
		return;
	} else {
		
		while (last->next != NULL) {
			last = last->next;
		}
		// appends to the last element in the Linked List
		last->next = temp;
	}


}


/*void Chain::merge(Chain addIn, int step) {
	for (int i = 0; i < addIn.listSize; i++) {
		this->insert(addIn.getElement(i), (step + 1) * i + step);
	}

}*/


void Chain::output() {
	// Print linklist

	ChainNode *f = first;

	// run through the linked list and print the element at each node 
	while (f != NULL) {
		cout << f->element << " ";
		f = f->next;
	}
}

// add to Matrices
int matrix_add(Chain a[], Chain b[], Chain c[], int z) {
	
	// loop to run through the number of rows
	for (int m = 0; m < z; m++) {
	
		// create  a new node pointer at start of each row of each matrix
		ChainNode *temp1 = a[m].first;
		ChainNode *temp2 = b[m].first;
		 
		//cout << a[i].first->column << endl; // this is for debugging purposes
		//cout << b[i].first->column << endl;

		while (temp1 != NULL && temp2 != NULL) {

			// check to see if the column number of the first matrix is less than the column number of the second
			if (temp1->column < temp2->column) {

				// add the value at that column number into the combined matrix
				c[m].add(temp1->column, temp1->element);
				// update node pointer
				temp1 = temp1->next;				
			} 

			// check to see if the column number of the first matrix is greater than the column number of the second
			else if (temp2->column < temp1->column) {
				// add the value at that column number into the combined matrix
				c[m].add(temp2->column, temp2->element);
				// update the pointer to the next node
				temp2 = temp2->next;
			}

			// check to see if the column numbers are equall
			else if (temp1->column == temp2->column) {
				// check to see if the addtion of the two values are zero
				if ((temp1->element + temp2->element) == 0) {
					// if they are zero then update the node pointer for each matrix
					temp1 = temp1->next;
					temp2 = temp2->next;
				} else {
					// if they do not equal zero then add the combined value to the new matrix
					c[m].add(temp1->column, (temp1->element) + (temp2->element));
					// update the pointer
					temp1 = temp1->next;
					temp2 = temp2->next;
				}
			}
		}

		// finish adding the values left in the second matrix
		if (temp1 == NULL && temp2 != NULL) {
			while (temp2 != NULL) {
				c[m].add(temp2->column, temp2->element);
				temp2 = temp2->next;
			}
		}
		// finish adding the values left in the first matrix
		if (temp2 == NULL && temp1 != NULL) {
			while (temp1 != NULL) {
				c[m].add(temp1->column, temp1->element);
				temp1 = temp1->next;
			}
		}



	}
	// printing out the combined matrix
	/*for (int h = 0; h < z; h++) { // debugging purpose
		c[h].output();
		cout << endl;
	}*/
}

// Search for Values in the Combined Matrices and print out column and values at that spot in the Matrix
void search_matrix(Chain c[], int s, int z) {
	for (int m = 0; m < z; m++) {
		
		// for debugging purposes
		//cout << "I'm happy" << endl;

		ChainNode *temp3 = c[m].first;
		
		while (temp3 != NULL) {

			
			if (temp3->element == s) {
				// if the element is the element you're looking for print it out
				cout << m << " " << temp3->column << " ";
				// update the pointer
				temp3 = temp3->next;
			}
			// if it is not the value you are looking for then update the pointer
			else if (temp3->element != s) {
				temp3 = temp3->next;
			}
		}
	}
}


int main() {
	// synce the cout with print
	ios::sync_with_stdio(false);
	//cout << "Hello World" << endl; //for debugging purposes
	
	
	int rowcount; // create variable for the number of rows
	int numberOfElements; // create variable for the number of elements
	int columnNumber; // create variable for the column number
	int value; // create a variable for the values being entered
	int searchValueNumber; // create a variable for the number of values that will be search
	int searchValue;
	
	// get the number of rows
	cin >> rowcount;

	// craete an Array of Linked List
	Chain Matrix[rowcount];

	// create a loop for getting the column number and values to be entered
	for (int i = 0; i < rowcount; i++) {
		// get the number of element for the row
		cin >> numberOfElements;


		for (int n = 0; n < numberOfElements; n++) {
			// get the column number and values at that column
			cin >> columnNumber >> value;
			
			// add the column number and value into the first Matrix
			Matrix[i].add(columnNumber, value);
		}
	}

	// Print LinkedMatrix - debugging purpose
	/*for (int j = 0; j < rowcount; j++) {
		Matrix[j].output();
		cout << endl;
	}*/

	// get the number of rows for the second matrix
	cin >> rowcount;
	// create the second matrix (array of linked list)
	Chain LinkedMatrix[rowcount];

	for (int k = 0; k < rowcount; k++) {
		
		cin >> numberOfElements;

		for (int i = 0; i < numberOfElements; i++) {
			
			cin >> columnNumber >> value;
			LinkedMatrix[k].add(columnNumber, value);
		}
	}
	// debugging purposes
	/*for (int j = 0; j < rowcount; j++) {
		LinkedMatrix[j].output();
		cout << endl;
	}*/
	
	// create the combined matrix 
	Chain combinedMatrix[rowcount];

	// declare function for addint the two matrices
	matrix_add(Matrix, LinkedMatrix, combinedMatrix, rowcount);

	/*for (int j = 0; j < rowcount; j++) {
		combinedMatrix[j].output();
		cout << endl;
	}*/
		
	cin >> searchValueNumber;

	for (int i = 0; i < searchValueNumber; i++) {

		cin >> searchValue;

		search_matrix(combinedMatrix, searchValue, rowcount);
		cout << endl;
	}



	//cout << endl;
	return 0;
}
