#include <iostream>
#include "Examples.h"
#include "DataStructure.h"

//---------------------- IOSIF-TASK (Sedjvik p 94) --------------------
// Brief description: task to check advantages of forward lists 
// --------------------------------------------------------------------
void Examples::IosifTask(int M, int N) {
	link t = new node(1, 0);
	t->next = t;
	
	link x = t;
	
	// create cyclic link 
	for (int i = 2; i <= N; i++) {
		x = (x->next = new node(i, t));
	}
	
	while (x != x->next) {
		for (int i = 1; i < M; i++) {
			x = x->next;
		}
		x->next = x->next->next;
	}
	std::cout << x->item << std::endl;
}

int Examples::PostfixExpressionCalculation(const char* expression, int len) {
	Stack<int> save(len);

	for (int i = 0; i < len; i++) {
		if (expression[i] == '+') save.push(save.pop() + save.pop());
		if (expression[i] == '*') save.push(save.pop() * save.pop());

		if (expression[i] >= '0' && expression[i] <= '9') save.push((int)(expression[i] - '0'));
		/*while (expression[i] >= '0' && expression[i] <= '9') {
			save.push(a[i]);
		}*/
	}
	return save.pop();
}

void launchAllExamples() {
	////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Iosif task: " << std::endl;
	Examples::IosifTask(8, 9);
	////////////////////////////////////////////////////////////////////////////////////
	link testLink = new node(1, 0);
	testLink->next = testLink;
	std::cout << "Empty link: ";
	li::show(testLink);
	
	li::insert(testLink, new node(2, 0));
	testLink = li::next(testLink);
	li::insert(testLink, new node(3, 0));
	testLink = li::next(testLink);
	li::insert(testLink, new node(4, 0));
	testLink = li::next(testLink);
	li::insert(testLink, new node(5, 0));
	testLink = li::next(testLink);
	std::cout << std::endl << "Insert: ";
	li::show(testLink);
	
	li::deleteNode(testLink);
	std::cout << std::endl << "Delete testLink link: ";
	li::show(testLink);

	testLink = li::next(testLink);
	testLink = li::reverse(testLink);
	std::cout << std::endl << "reverse testLink link is performed.";
	////////////////////////////////////////////////////////////////////////////////////
	Stack<int> st(7);
	for (int i = 0; i < 5; i++) st.push(i);
	st.pop();
	st.pop();
	std::cout << std::endl << "Stack is checked";
	////////////////////////////////////////////////////////////////////////////////////
	int result = Examples::PostfixExpressionCalculation("598+46**7+*", 11);
	bool check = result == 2075;
	
	if (check) std::cout << "All data structures examples were launched!" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}