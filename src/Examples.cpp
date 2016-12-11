#include <iostream>
#include "Examples.h"
#include "DataStructure.h"
#include "Search.h"
#include "Graph.h"

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
	}
	return save.pop();
}

char* Examples::convertInfixToPostfix(const char* expression) {
	const int expressionSize = strlen(expression);
	Stack<char> save(expressionSize);
	Stack<char> result(expressionSize);

	for (int i = 0; i < expressionSize; i++) {
		if (expression[i] >= '0' && expression[i] <= '9') result.push((int)(expression[i] - '0'));
		if (expression[i] == '+' || expression[i] == '*') save.push(expression[i]);
		if (expression[i] == ')') result.push(save.pop());
	}

	const int resultStackSize = result.getSize();
	char* resultChar = new char[resultStackSize];
	for (int i = resultStackSize - 1; i >= 0 ; i--) {
		resultChar[i] = result.pop();
	}

	return resultChar;
}

void launchAllExamples() {
#if 0
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
	std::cout << std::endl << "Prefix calculation was performed.";
	
	char* resultConvert = Examples::convertInfixToPostfix("(5*(((9+8)*(4*6))+7))");
	std::cout << std::endl << "Prefix calculation was performed.";

	bool check = (result == 2075) && 
			     (strcmp("598+46**7+*", resultConvert));
	
	////////////////////////////////////////////////////////////////////////////////////
	llStack<int> stll;
	for (int i = 0; i < 5; i++) stll.push(i);
	stll.pop();
	stll.pop();
	std::cout << std::endl << "Stack based on linked list is checked";

	////////////////////////////////////////////////////////////////////////////////////
	Queue<int> q;
	for (int i = 0; i < 5; i++) q.put(i);
	q.get();
	q.get();
	std::cout << std::endl << "Queue is checked.";

	////////////////////////////////////////////////////////////////////////////////////
	QueueArray<int> q1(10);
	for (int i = 0; i < 5; i++) q1.put(i);
	q1.get();
	q1.get();
	std::cout << std::endl << "Queue based on array is checked.";

	////////////////////////////////////////////////////////////////////////////////////
	std::cout << std::endl << "Start binary tree traversal: ";
	BinaryTreeLink bTree = new BinaryTree(0, 0, 0);
	BinaryTree left = BinaryTree(1, 0, 0);
	BinaryTree right = BinaryTree(2, 0, 0);
	bTree->l = &left;
	bTree->r = &right;
	BinaryTree left1 = BinaryTree(3, 0, 0);
	BinaryTree right1 = BinaryTree(4, 0, 0);
	bTree->l->l = &left1;
	bTree->l->r = &right1;
	BinaryTree left2 = BinaryTree(5, 0, 0);
	BinaryTree right2 = BinaryTree(6, 0, 0);
	bTree->r->l = &left2;
	bTree->r->r = &right2;
	biTree::traverse(bTree);
	std::cout << std::endl << "Binary tree traversed";

	std::cout << std::endl << "Start binary tree traversal based on stack: ";
	biTree::traverseStack(bTree);
	std::cout << std::endl << "Binary tree traversed";

	std::cout << std::endl << "Start binary tree traversal based on queue (by levels): ";
	biTree::levelTraverseQueue(bTree);
	std::cout << std::endl << "Binary tree traversed";

	int biCount = biTree::count(bTree);
	int biHeight = biTree::height(bTree);

	check = check * (biCount == 7) * (biHeight == 2);

	////////////////////////////////////////////////////////////////////////////////////
	PriorityQueue<int> qP(10);
	qP.insert(12);
	qP.insert(2);
	qP.insert(15);
	qP.insert(8);
	qP.getMax();
	qP.getMax();
	qP.insert(3);
	std::cout << std::endl << "Priority queue based on array is checked.";

	////////////////////////////////////////////////////////////////////////////////////
	STdistributed<Item, Key> stdistributed(100);
	for (int i = 0; i < 100; i++) {
		Item v;
		v.rand();
		if ((stdistributed.search(v.key()).null())) stdistributed.insert(v);
	}
	int STdistributedCount = stdistributed.count();
	Item itemRemove;
	itemRemove.rand();
	stdistributed.remove(itemRemove);
	itemRemove.rand();
	stdistributed.remove(itemRemove);
	STdistributedCount = stdistributed.count();	
	std::cout << std::endl << "Distributed search: symbol table based on array is checked.";

	////////////////////////////////////////////////////////////////////////////////////
	STsequental<Item, Key> stseq(100);
	for (int i = 0; i < 100; i++) {
		Item v;
		v.rand();
		if ((stseq.search(v.key()).null())) stseq.insert(v);
	}
	int STseqCount = stseq.count();
	Item elementSearch = stseq.search(43);
	Item elementBinSearch = stseq.Bsearch(43);
	check *= (elementSearch.key() == elementBinSearch.key());
	std::cout << std::endl << "Sequental search: symbol table based on array is checked.";

	////////////////////////////////////////////////////////////////////////////////////
	STll<Item, Key> st_ll(100);
	for (int i = 0; i < 100; i++) {
		Item v;
		v.rand();
		if ((st_ll.search(v.key()).null())) st_ll.insert(v);
	}
	int st_llCount = st_ll.count();
	std::cout << std::endl << "Symbol table based on linked list is checked.";

	////////////////////////////////////////////////////////////////////////////////////
	BST<Item, Key> bst;
	for (int i = 0; i < 100; i++) {
		Item v;
		v.rand();
		if ((bst.search(v.key()).null())) bst.insert(v);
	}
	Item BSTsearchItem = bst.search(94);
	std::cout << std::endl << "Sorted BST: \n";
	bst.show();

	std::cout << std::endl << "BST: symbol table based on BST is checked. Insertion and search are successful.";
	Item v;
	v.rand();
	if ((bst.search(v.key()).null())) bst.insertV(v);
	std::cout << std::endl << "BST: symbol table based on BST is checked. Insertion to vertex is successful.";

	BST<Item, Key> bst2;
	for (int i = 0; i < 100; i++) {
		Item v;
		v.rand();
		if ((bst2.search(v.key()).null())) bst2.insert(v);
	}

	bst.join(bst2);
	std::cout << std::endl << "BST: symbol table based on BST is checked. Joining is successful.";

	////////////////////////////////////////////////////////////////////////////////////
	//SkipList<Item> skiplist(30);

	////////////////////////////////////////////////////////////////////////////////////
	HashTable<ItemHash, char> hashTable(10);
	for (int i = 0; i < 10; i++) {
		ItemHash v;
		v.rand();
		if ((hashTable.search(v.key()).null())) hashTable.insert(v);
	}
	std::cout << std::endl << "Hash-table insert and search is successfull. ";
#endif
	////////////////////////////////////////////////////////////////////////////////////
	DenseGraph G(10);
	for (int i = 0; i < 10; i++) {
		G.insert(Edge(i, 2));
	}

	SparseMultiGRAPH Gsp(10);
	for (int i = 0; i < 10; i++) {
		Gsp.insert(Edge(i, 2));
	}

	DenseGraph Grand(4);
	randG(Grand, 10);
	sPATH<DenseGraph> sPath = sPATH<DenseGraph>(Grand, 0, 3);
	bool path07 = sPath.exists();

	DenseGraph Grand1(5);
	randG(Grand1, 6);
	gPATH<DenseGraph> gPath = gPATH<DenseGraph>(Grand1, 0, 2, 4);
	bool path05 = sPath.exists();

#if 0
	////////////////////////////////////////////////////////////////////////////////////
	if (check) std::cout << std::endl << "All data structures examples were launched!" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
#endif
}