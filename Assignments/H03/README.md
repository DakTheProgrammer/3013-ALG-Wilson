## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.
    - **Answer**: O(1), O(n), O(log n), O(n log n), O(n<sup>2</sup>), O(n!)
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? 
    - **Answer**: 40 seconds

----------------------------------------------------------------------------------------------------------------------------------

- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
<ol>
    <li>Finding the max element in an unordered stack would require _____O(n)______ operations?
        <ul><li><b>Reason</b>: You would have to look through all elements possibly.</li></ul></li>
    <li>Finding the min element in an unordered queue would require _____O(n)______ operations?
        <ul><li><b>Reason</b>: You would have to look through all elements possibly.</li></ul></li>
    <li>Finding some element in some Binary Search Tree would require ___O(h)______ operations?
        <ul><li><b>Reason</b>: it could be a glorified linked list so you'd have to go through the hight of the tree possibly.</li></ul></li>
    <li>Finding some element in a balanced Binary Search Tree would require _____O(log n)______ operations?
        <ul><li><b>Reason</b>: Since it's balanced you could do a binary search.</li></ul></li>
    <li>Finding some element in an ordered linked list would require ____O(n)______ operations (worst case)?
        <ul><li><b>Reason</b>: With a list it doesn't matter if it is ordered worse case you would need to look through all elements.</li></ul></li>
    <li>Finding some element in an ordered linked list would require ____O(n/2)______ operations (average case)?
        <ul><li><b>Reason: On average when searching throug the list most elements would be less then what you are searching for halfway throug the list.</b>: </li></ul></li>
    <li>Finding some element in an unordered linked list would require __O(n)______ operations (worst case)?
        <ul><li><b>Reason</b>: With a list it doesn't matter if it is ordered worse case you would need to look through all elements.</li></ul></li>
</ol>

----------------------------------------------------------------------------------------------------------------------------------

8. For each of the following, count the number of operations where some_statement is executed based on the loops

```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
- **Answer**: O(n<sup>2</sup>)
- **Reason**: This being due to both i and j run through n times cuasing it to just be n times n.
```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
- **Answer**: O(n<sup>2</sup>)
- **Reason**: This is due to the fact that you would be multiplying n from J and 1/2*n of I but you would need to take the constant of I's out and then multiply n by n or just n squared.
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```
- **Answer**: O(n log n)
- **Reason**: This being due to the J runing through log n times due to j*=2 and the I running through n times when multiplied together you get n log n

----------------------------------------------------------------------------------------------------------------------------------

- At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?

- **Answer**: 9
- **Reason**: 
    - logic - you would continue to cut the array in half until you get to a point when you half 3 giving you a single element which is your 8th time then if that isnt your number then there is a 9th comparison.
    - math - log(1023) = 9.99 meaning that you would only need to compare 9 times due to truncation.

----------------------------------------------------------------------------------------------------------------------------------

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
    - **Answer**: Linked list
    - **Reason**: So that things may be dynamicly alocated and you dont have to worry about space.
2. You need to store undo/redo operations in a word processor.
    - **Answer**: Stack
    - **Reason**: So that at any time when a word is deleted you can pop off the top and when somethings added you push to the top.
3. You need to evaluate an expression (i.e., parse).
    - **Answer**: Stack
    - **Reason**: So that it can be easily noted what is at the top so that you know when the expression is finished. (ex '[' meets ']' at top of stack)
4. You need to store the friendship information on a social networking site. I.e., who is friends with who.
    - **Answer**: Graph
    - **Reason**: Specificaly a relationship graph that has nodes to who is friends with who.
5. You need to store an image (1000 by 1000 pixels) as a bitmap.
    - **Answer**: Array
    - **Reason**: Easy acces to the colors held in each seprate pixel.
6. To implement printer spooler so that jobs can be printed in the order of their arrival.
    - **Answer**: Queue
    - **Reason**: this is due to the order of arival so that it can efficently be poped by such a factor.
7. To implement back functionality in the internet browser.
    - **Answer**:
    - **Reason**:
8. To store the possible moves in a chess game.
    - **Answer**:
    - **Reason**:
9. To store a set of fixed key words which are referenced very frequently.
    - **Answer**: Hash table
    - **Reason**: the fact that it is a fixed storage and can be accesed quickly.
10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)
    - **Answer**: Queue
    - **Reason**: a line of customers is a queue FIFO.
11. To store the genealogy information of biological species.
    - **Answer**: Tree
    - **Reason**: the fact that you are tracking ancestory and children is a dead givaway.
12. To store an alphabetized list of names in order to look up quickly.
    - **Answer**: Tree
    - **Reason**: Specifiacally a balanced binary search tree so that look up time is minimal based on there first char.