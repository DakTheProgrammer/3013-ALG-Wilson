## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n2), O(log n), O(n!)**, order the algorithms from fastest to slowest.
    - **Answer**: O(1), O(n), O(log n), O(n log n), O(n<sup>2</sup>), O(n!)
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? 
    - **Answer**: 

- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
<ol>
    <li>Finding the max element in an unordered stack would require _____O(n)______ operations?
        <ul><li><br><b>Reason</b>: You would have to look through all elements possibly.</li></ul></li>
    <li>Finding the min element in an unordered queue would require _____O(n)______ operations?
        <ul><li><br><b>Reason</b>: You would have to look through all elements possibly.</li></ul></li>
    <li>Finding some element in some Binary Search Tree would require ___O(h)______ operations?
        <ul><li><br><b>Reason</b>: it could be a glorified linked list so you'd have to go through the hight of the tree possibly.</li></ul></li>
    <li>Finding some element in a balanced Binary Search Tree would require _____O(log n)______ operations?
        <ul><li><br><b>Reason</b>: Since it's balanced you could do a binary search.</li></ul></li>
    <li>Finding some element in an ordered linked list would require ____O(n)______ operations (worst case)?
        <ul><li><br><b>Reason</b>: </li></ul></li>
    <li>Finding some element in an ordered linked list would require ____O(n)______ operations (average case)?
        <ul><li><br><b>Reason</b>: </li></ul></li>
    <li>Finding some element in an unordered linked list would require __O(n)______ operations (worst case)?
        <ul><li><br><b>Reason</b>: </li></ul></li>
</ol>

8. For each of the following, count the number of operations where some_statement is executed based on the loops

```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
- **Answer**:
```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
- **Answer**:
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```
- **Answer**:
At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
    - **Answer**:
    - **Reason**:
2. You need to store undo/redo operations in a word processor.
    - **Answer**:
    - **Reason**:
3. You need to evaluate an expression (i.e., parse).
    - **Answer**:
    - **Reason**:
4. You need to store the friendship information on a social networking site. I.e., who is friends with who.
    - **Answer**:
    - **Reason**:
5. You need to store an image (1000 by 1000 pixels) as a bitmap.
    - **Answer**:
    - **Reason**:
6. To implement printer spooler so that jobs can be printed in the order of their arrival.
    - **Answer**:
    - **Reason**:
7. To implement back functionality in the internet browser.
    - **Answer**:
    - **Reason**:
8. To store the possible moves in a chess game.
    - **Answer**:
    - **Reason**:
9. To store a set of fixed key words which are referenced very frequently.
    - **Answer**:
    - **Reason**:
10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)
    - **Answer**:
    - **Reason**:
11. To store the genealogy information of biological species.
    - **Answer**:
    - **Reason**:
12. To store an alphabetized list of names in order to look up quickly.
    - **Answer**:
    - **Reason**: