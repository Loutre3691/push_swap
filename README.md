*This project has been created as partof the 42 curriculum by fde-chec, slaabid*

## DESCRIPTION

The goal of this project is to sort data on a stack, using a limited set of instructions and with the fewest possible actions. It involves applying various types of algorithms to choose the most appropriate and optimized solution for efficient data sorting.

Files :  
- main.c ------------> first files, argument handling
- disorder.c --------> files wiht a number between 0 and 1, this number us to know the state of disoorder, If the number is 0, it means everything is in order. and if they are in the worst possible order, the disorder is 1. In betwen, the stack is partly sorted.0
- indexing-----------> The file allows you to assign an index to each argument; the index corresponds to the argument's position in the program.
- parsing------------>It allows you to manage argument errors, whether there are duplicates or no arguments at all.
- sort---------------> Implements the sorting logic, with complex sort, medium sort, simple sort, and small sort. Depending on the result of the disorder, one will go into one of the sorts.
- makefile-----------> files to compile the program
- push_swap.h--------> file containing the declarations and library.
- operation----------> These are the rules that allow you to manage operations on the stack : 
#### -> sa : Swaps the first two elements in stack a
#### -> sb : Swaps the first two elements in stack b
#### -> ss : Performs sa and sb simultaneously
#### -> ra : Rotates all elements upwards so that the first element of a goes to the bottom of the stack
#### -> rb : Rotates all elements upwards so that the first element of b goes to the bottom of the stack
#### -> rr : Performs ra and rb simultaneously
#### -> rra : Rotates all elements downwards so that the last element of a goes to the top of the stack
#### -> rrb : Rotates all elements downwards so that the last element of b goes to the top of the stack
#### -> rrr : Performs rra and rrb simultaneously

## INSTRUCTION

git clone with the link intra 

cd push_swap

make

./push_swap [number list]

ARG="2 1 0"; ./push_swap $ARG | wc -l  

./push_swap $(shuf -i 1-100 -n 50) | wc -l  

## RESOURCES
To complete this project we used different tools, AI was able to help us understand some things that were blocking us, we also asked for advice from other students.

## CHOICE ALGO
simple : simple sort, selection sort.
medium : chunck sort, cut in slice to sort.
complex : Radix sorting ensures efficient sorting even with large datasets, making it a suitable approach for our project as the algorithm minimizes the number of operations by dividing the problem into smaller, more manageable parts.




