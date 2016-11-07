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

void launchAllExamples() {
	std::cout << "Iosif task: " << std::endl;
	Examples::IosifTask(8, 9);
	std::cout << "All data structures examples were launched!" << std::endl << std::endl;
}