
///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            P01
// Title:            Assignment 4 - Resizing the Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Resizeable stack that when the stack goes to half size it will shrink by
//		half. Also will increas by 175% when it is full to prevent overflow. The
//		program reads in a file of even and odd numbers when a even number is
//		it is pushed and when a odd is read the top number is popped off the
//		stack.
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
	int timesResized; // times stack resized
	int MaxSize;	  // the max size the stack reaches

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
	 *		also checks if it needs to be resized
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
	 *      Adds an item to top of stack and checks 
	 *		if resize is needed
	 *
	 * Params:
	 *      [int] : item to be added
	 *
	 * Returns:
	 *      [bool] ; success = true
	 */
	bool Push(int x)
	{
		A[++top] = x;
		CheckResize();
		return true;
	}

	/**
	 * Public void: ContainerGrow
	 *
	 * Description:
	 *      Resizes the container for the stack by 1.75 
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
		int newSize = size * 1.75;			// 175% size of original
		int* B = new int[newSize];			// allocate new memory

		for (int i = 0; i < size; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;							// delete old array

		size = newSize;						// save new size

		A = B;								// reset array pointer

		if (MaxSize < newSize)
		{
			MaxSize = size;					// checks if maxsize needs 
											// increase
		}
	}

	/**
	 * Public void: ContainerShrink
	 *
	 * Description:
	 *      Resizes the container for the stack by .5
	 *      its capacity
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
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

	/**
	 * Public void: CheckResize
	 *
	 * Description:
	 *      checks if the stack needs to be resized
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void CheckResize()
	{
		if (Full())
		{
			ContainerGrow();			//shrinks
			timesResized++;				//increments times resized
		}
		else if (top < (size / 2) && size > 10)
		{
			ContainerShrink();			//grows
			timesResized++;				//increments times resized
		}
	}

	/**
	 * Public void: getSize
	 *
	 * Description:
	 *      gets the size of the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	int getSize()
	{
		return size;
	}

	/**
	 * Public void: getTimesResized
	 *
	 * Description:
	 *      gets the times the stack was resized
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	int getTimesResized()
	{
		return timesResized;
	}

	/**
	 * Public void: getMaxSize
	 *
	 * Description:
	 *      gets the max size of the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	int getMaxSize()
	{
		return MaxSize;
	}

	/**
	 * Public void: getMaxSize
	 *
	 * Description:
	 *      gets the top of the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	int getTop()
	{
		return top;
	}
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{
	ArrayStack stack;				//stack for resizing
	ifstream infile;				//infile for input
	ofstream outfile;				//outfile for output
	infile.open("nums_test.dat");
	outfile.open("output.txt");

	int num;						//num to put into stack or to read a pop

	while (!infile.eof())
	{
		infile >> num;
		if (num % 2 == 0)			//pushes evens
		{
			stack.Push(num);
		}
		else						//pops when odd is read
		{
			stack.Pop();
		}
	}
	
	

	outfile << "################################################################\n";
	outfile << "\tAssignment 4 - Resizing the Stack\n";
	outfile << "\tCMPS 3013\n";
	outfile << "\tDakota Wilson\n\n";
	outfile << "\tMax Stack Size: " << stack.getMaxSize() << "\n";
	outfile << "\tEnd Stack Size: " << stack.getSize() << "\n";
	outfile << "\tStack Resized:  " << stack.getTimesResized() << " Times\n\n";
	outfile << "################################################################\n";
}