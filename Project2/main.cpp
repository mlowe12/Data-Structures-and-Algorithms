#include <iostream> 
#include <vector> 
#include <list> 
#include <algorithm>
#include "mitra.h" 
#include <string>


int LongestIncreasingSubsequence(int arr[], int n) {
	// n is magiCount
}

int main(int argc, char** argv)
{
	int numberOfRealms; 
	std::string charm; 
	int magiCount; 
	std::string magiOrder; 
	int numberOfCharms = 1; //the charm can change, but only one can exist at a time. 
		
	std::cin>>numberOfRealms; // recieve number of realms
 
	
	/*iterate for the  number of realms and attributes of input stream*/ 
	for(int i =0; i < numberOfRealms; ++i)
	{ 
		 
		/*start to recieve arguments*/ 
 
		std::getline(std::cin, charm); //recieves name of charm 
		int numberOfMagi; 	
		std::cin >> numberOfMagi; //recieves number of Magi in realm 
		std::getline(std::cin, magiOrder);  // recieves array of Magi as a string *parse later*
	}
	
	/* argument recpetion complete*/ 
 
	/*quinton*/
	//find the Longest Increasing Subsequence of the Magi Order
	/*joe or bradon?*/
	//that sequence indicated how many changes you can make the Charm Name

	/*working on this*/
	//function for Edit distance between one realm and all the others -- Do this for all realms

		return 0; 
}

