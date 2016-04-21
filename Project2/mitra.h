#ifndef MITRA_H_1234
#define MITRA_H_1234

#include <string>
#include <iostream>
#include <vectors>
#include <iterator>

using namespace std;

class Node {
	public:
		string charm;
		Node* travelPath;
		int magiCounts;
		int orderOfMagi[];

		Node() {
			charm = " ";
			int magiCount = 0;
			travelPath = NULL;
		}

		Node(string s, int c) {
			charm = s;
			magiCounts = c;
			travelPath = NULL;
		}

		Node(string s, int c, int arr[], Node* p) {
			charm = s;
			magiCounts = c;
			orderOfMagi = arr;
			travelPath = p;
		}


};

#endif
