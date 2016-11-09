class Examples {
private:
	// linked list usage 
	static void IosifTask(int M, int N);

	// expression caclulation
	static int PostfixExpressionCalculation(const char* expression, int len);
	static char* convertInfixToPostfix(const char* expression);
public:
	friend void launchAllExamples();
};