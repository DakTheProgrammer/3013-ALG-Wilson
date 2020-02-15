///////////////////////////////////////////////////////////////////////////////
//
// Author:           Dakota Wilson
// Email:            dtw3200@live.com
// Label:            HW-4
// Title:            Assignment 7 - Heapify
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//      An array based min heap that is sorted whenever a item is inserted and
//  removed by using a bubble up and bubble down method. also allows the user to
//  "heapify" an array into a heap and is sorted with the bubble up method when
//  inserted.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * Class Heap
 * 
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : used to sort whenever a item is inserted
 *          Left        : used to check the index left of asked index
 *          OnHeap      : checks if index is in the heap or not
 *          Parent      : gets the index of the parent of the asked index
 *          Right       : used to check the index rigth of asked index
 *          Swap        : swaps 2 values in the heap based on there index
 *          /// Fix These:
 *          SinkDown    : used to sort the heap whenever a item is removed
 *          PickChild   : Picks the smallest child of its parents
 *          Heapify     : sorts a array into the heap by using bubble up to sort
 *      public:
 *          Insert      : places a item into the heap
 *          Print       : prints the values in the array heap
 *          Remove      : removes the root of the heap
 */
class Heap {
private:
    int size; // size of the array
    int *H;   // array pointer
    int end;  // 1 past last item in array

    /**
   * BubbleUp
   * 
   * @description: 
   *    This puts one value into its proper
   *    place in the heap.
   * 
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
    void BubbleUp(int index) {
        // check parent is not of beginning of array
        if (Parent(index) >= 1) {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {
        return 2 * index;
    }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     * 
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {
        return index < end;
    }

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     * 
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) {
        return index / 2;
    }

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) {
        return 2 * index + 1;
    }

    /**
     * Swap
     * 
     * @description: 
     *      Swaps to values in the heap
     * 
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
    }

    ////////////////////////////
    //Fix These Methods
    ////////////////////////////

    /**
     * Heapify
     * @description:
     *      takes in an array and inserts them into the heap. Is sorted
     *      by the bubble up method used in the insert method.
     * 
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     * 
     * @return            : void 
     */
    void Heapify(int* A, int s) {
        for(int i = 0; i < s; i++)
        {
            Insert(A[i]);
        }
    }

    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
    void SinkDown(int index) {
        int smallest = index;

		if (Left(index) < end && H[Left(index)] < H[index])
			smallest = Left(index);

		if (Right(index) < end && H[Right(index)] < H[smallest])
			smallest = Right(index);

		if (smallest != index) {
			Swap(index, smallest);
			SinkDown(smallest);
		}
    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) {
        if(Right(index) == end)
        {
            return H[Left(index)];          //if only 1 child
        }
        else if(Left(index) < end)
        {
            if(H[Left(index)] < H[Right(index)])
            {
                return H[Left(index)];      //left child smaller
            }
            else
            {
                return H[Right(index)];     //right child smaller
            }
        }
        else
        {
            return -999;                    //doesnt have any children :(
        }
    }
    

public:
    /**
   * Heap constructor
   */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
   * Heap constructor
   * 
   * @param  {int} s : heap size 
   */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }

    /**
   * Insert
   * 
   * @description:
   *        Add a value to the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void Insert(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
     * For test our heap !!!  
     */
    void Print() {
        for (int i = 1; i <= end - 1; i++) {
            cout << H[i];
            if (i < end - 1) {
                cout << "->";
            }
        }
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     * 
     * @return {int}  : top of heap
     */
    int Remove() {
        int temp = H[1];
        H[1] = H[--end];
        SinkDown(1);            //sinks down starting at position 1

        return temp;
    }

    
};

int main() {
    Heap H;

    H.Insert(17);
    H.Insert(11);

    for (int i = 1; i <= 10; i++) {
        H.Insert(i);
    }

    H.Print();
}