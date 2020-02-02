
///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Label:            L01
// Title:            Lecture 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
	int* A;           // pointer to array of int's
	int size;         // current max stack size
	int top;          // top of stack 
	int timesResized; 
	int MaxSize;

public:
	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor no params
	 *
	 * Params:
	 *     - None
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack() {
		size = 10;
		A = new int[size];
		top = -1;
		timesResized = 0;
		MaxSize = size;
	}

	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor size param
	 *
	 * Params:
	 *     - int size
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack(int s) {
		size = 10;
		A = new int[s];
		top = -1;
		timesResized = 0;
		MaxSize = size;
	}

	/**
	 * Public bool: Empty
	 *
	 * Description:
	 *      Stack empty?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = empty
	 */
	bool Empty() {
		return (top <= -1);
	}

	/**
	 * Public bool: Full
	 *
	 * Description:
	 *      Stack full?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = full
	 */
	bool Full() {
		return (top >= size - 1);
	}

	/**
	 * Public int: Peek
	 *
	 * Description:
	 *      Returns top value without altering the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Peek() {
		if (!Empty()) {
			return A[top];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public int: Pop
	 *
	 * Description:
	 *      Returns top value and removes it from stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Pop() {
		if (!Empty()) {
			CheckResize();
			return A[top--];
		}

		

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public void: Print
	 *
	 * Description:
	 *      Prints stack to standard out
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void Print() {
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}

	/**
	 * Public bool: Push
	 *
	 * Description:
	 *      Adds an item to top of stack
	 *
	 * Params:
	 *      [int] : item to be added
	 *
	 * Returns:
	 *      [bool] ; success = true
	 */
	bool Push(int x)
	{
		CheckResize();

		A[++top] = x;
		return true;
	}

	/**
	 * Public void: Resize
	 *
	 * Description:
	 *      Resizes the container for the stack by doubling
	 *      its capacity
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void ContainerGrow()
	{
		int newSize = size * 1.75;				// double size of original
		int* B = new int[newSize];			// allocate new memory

		for (int i = 0; i < size; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;							// delete old array

		size = newSize;						// save new size

		A = B;								// reset array pointer

		if (MaxSize < newSize)
		{
			MaxSize = size;
		}
	}

	void ContainerShrink()
	{
		int newSize = size / 2;				// halves size of original
		int* B = new int[newSize];			// allocate new memory

		for (int i = 0; i <= top; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;							// delete old array

		size = newSize;						// save new size

		A = B;								// reset array pointer
	}

	void CheckResize()
	{
		if (Full())
		{
			ContainerGrow();
			timesResized++;
			//cout << "Increasing ";
		}
		else if (top < (size / 4) && size > 10)
		{
			ContainerShrink();
			timesResized++;
			//cout << "Decreasing ";
		}
	}

	int getSize()
	{
		return size;
	}

	int getTimesResized()
	{
		return timesResized;
	}

	int getMaxSize()
	{
		return MaxSize;
	}

	int getTop()
	{
		return top;
	}
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{
	ArrayStack stack;
	ifstream infile;
	infile.open("nums.dat");
	ofstream outfile;
	outfile.open("Trace.txt");

	int num;

	while (!infile.eof())
	{
		infile >> num;
		if (num % 2 == 0)
		{
			stack.Push(num);
		}
		else
		{
			stack.Pop();
		}
		outfile << "top:" << stack.getTop() << " Size: " << stack.getSize() << '\n';
	}
	
	

	cout << "################################################################\n";
	cout << "\tAssignment 4 - Resizing the Stack\n";
	cout << "\tCMPS 3013\n";
	cout << "\tDakota Wilson\n\n";
	cout << "\tMax Stack Size: " << stack.getMaxSize() << "\n";
	cout << "\tEnd Stack Size: " << stack.getSize() <<"\n";
	cout << "\tStack Resized:  " << stack.getTimesResized() << " Times\n\n";
	cout << "################################################################\n";
}