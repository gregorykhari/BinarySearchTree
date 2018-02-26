#include"LinkedList.h"
#include<iostream>

using namespace std;

int main()
{
	int input = 1;
	LinkedList list1;
	LinkedList list2;
	while (input != 0)
	{
		cout << "Enter data to add to new node " << endl;
		cin >> input;
		list1.insertNode(input);
	}
	list1.printList();
	list1.deleteNode();
	list1.deleteNode();
	list1.printList();
	cout << "=======" << endl;
	list2 = list1;
	list2.printList();
	return 0;
}