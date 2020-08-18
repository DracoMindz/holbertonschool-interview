# 0x18 Merge Sort
Specilizations - Interview Preparation - Algorithms

Given a print_arry function for this project.

With projects written in C a header file is required.
No more than five functons are allowed per file.

### Task
 0. Merge Sort
___
Write a function that sorts a array of integers in
ascending order using the Merge Sort algorithm.
Prototype: void nerge_sort(int *array, size_t size)

For this project top-dpwn merge sort algorithm is
required.

Allowed: printf, malloc and free (once)
___

0-O
___
Write Big O notations of time complexity of the
Merge Sort:

in the best case
in the average case
in the worst case
___

Note:
```
Working with size_t in this instance proved to be a challenge. Kept getting errors having to do with type agreement. It became necessary to find a way to wor around the size_t and still get the correct result from the code.

Reading the main until you understand what the process is is important. Originally I included the
print_array function in the merge_sort file.  After reading the main and noting how the functions were called I realized it was better to have a separate file that included the print_array function. In the merge_sort file the print_array was not being used by any function. In the main it is called separately and without reference to the merge_sort file.
```