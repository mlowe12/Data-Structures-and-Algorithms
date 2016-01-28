#include <iostream>

using namespace std;

int insertionSort(int array[], int size) {
	int temp;
	int i, j;
	for (i=0; i <size; i++) {
		temp=array[i];
		for(j=i; j>0 && array[j-1] > temp; j--) {
			array[j] = array[j-1];
		}
		array[j] = temp;
	}
	return array[i];
}

void printSortedArray(int array[], int size) {
	for (int t = 0; t<size; t++) {
		cout<< array[t] << endl;
	}
}

int reverseArray(int array[], int start, int end) {
	int temp; 
}




int main() {
	int arraySize;

	cin >> arraySize;

	int *myArray = new int[arraySize];

	//get input for myArray
	for (int z = 0; z < arraySize; z++) {
		cin >> myArray[z];
	}

	int start;
	int end;

	cout << "Start: " << flush; 
	cin >> start;
	cout << "End: " << flush;
	cin >> end;
	

	insertionSort(myArray, arraySize);
	cout << endl;
	printSortedArray(myArray, arraySize);

	return 0;

}
