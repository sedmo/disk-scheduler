/*
 * Author: Stephan Edmonson
 * Role: Creator
 * Problem: Hard drives have an issue of latency due to relatively slow moving parts. 
 * As a process in the input queue requires files not in residence via invalid bit(assuming that we are using paging),
 * the process must fetch said data from the backing store. As a result, we want to make this process as efficient as 
 * possible by using an optimal algorithm to solve such issue.   
 */

#include <iostream>
#include "dsa.h"

using namespace std;
int main()
{
	int pos;
	char choice;
	cout<<"Enter initial position of head: ";
	cin>>pos;
	cout<<endl;
	if(pos < 0 || pos > 5000){
	       	cout<<"Entered incorrect number";
		return -1;
	}
	else{
		DSA test(pos);
		test.print();		
	}
}
