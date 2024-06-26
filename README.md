# Codam Rank 02

# push_swap

## Objectives
The Push Swap project focuses on developing a sorting algorithm in C, emphasizing the understanding of algorithmic complexity and the use of basic algorithms. Sorting algorithms play a fundamental role in a developer's journey, and comprehending their complexity is crucial, especially when facing job interviews and classic questions related to algorithms.

## Mandatory Part
### Rules
The project involves managing two stacks named 'a' and 'b'.

At the beginning:
Stack 'a' contains a random assortment of negative and/or positive numbers without duplicates.
Stack 'b' is initially empty.
The objective is to sort the numbers in ascending order within stack 'a'.

Operations available for sorting:
* sa: Swap the first 2 elements at the top of stack 'a'.
* sb: Swap the first 2 elements at the top of stack 'b'.
* ss: Simultaneously perform 'sa' and 'sb'.
* pa: Push the first element at the top of stack 'b' onto stack 'a'.
* pb: Push the first element at the top of stack 'a' onto stack 'b'.
* ra: Rotate all elements of stack 'a' upwards by 1.
* rb: Rotate all elements of stack 'b' upwards by 1.
* rr: Simultaneously perform 'ra' and 'rb'.
* rra: Rotate all elements of stack 'a' downwards by 1.
* rrb: Rotate all elements of stack 'b' downwards by 1.
* rrr: Simultaneously perform 'rra' and 'rrb'.

## Benchmark
To validate the project, certain sorts must be performed with a minimal number of operations:

For a minimalist validation (minimum grade of 80), sorting 100 random numbers should require fewer than 700 operations.
For maximal project validation and bonuses, sorting 500 random numbers should require no more than 5500 operations.
The project's performance is evaluated based on these benchmarks during assessment.
