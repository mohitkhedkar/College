#include <stdio.h>
#include <math.h>
#include <omp.h>

void main()
{
    int sep[20], array[20], key, i, j, n, left, right, size, interval, index, break_value = 0, tid;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    printf("Enter the elements of array in ascending order\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the key to be searched\n");
    scanf("%d", &key);
    printf("Enter the value of n for n-ary search algorithm\n");
    scanf("%d", &n);

    left = 0;
    right = size - 1;

    if (key >= array[left] && key <= array[right])
    {
        while (left != right)
        {
            // (start) code to find seperators
            printf("left=%d, right=%d, size=%d\n", left, right, size);
            if (size <= n)
            {
#pragma omp parallel for num_threads(size)
                for (i = 0; i < size; i++)
                {
                    sep[i] = left + i;
                    tid = omp_get_thread_num();
                    printf("Thread %d allocated sep[%d]=%d\n", tid, i, sep[i]);
                }
            }

            else
            {
                sep[0] = left;
                interval = ceil((float)size / (float)n);

#pragma omp parallel for num_threads(n - 1)
                for (i = 1; i <= n - 1; i++)
                {
                    sep[i] = left + interval * i - 1;
                    tid = omp_get_thread_num();
                    printf("Thread %d allocated sep[%d]=%d\n", tid, i, sep[i]);
                }

                sep[n] = right;
            }
            // (end) Code to find seperators

            // (start) Code for comparison

            for (i = 0; i <= n; i++)
            {
                if (key == array[sep[i]])
                {
                    index = sep[i];
                    printf("Element found at position %d\n", index + 1);
                    break_value = 1;
                    break;
                }
                if (key < array[sep[i]])
                {
                    right = sep[i];
                    if (i != 0)
                        left = 1 + sep[i - 1];
                    size = right - left + 1;
                    break;
                }
            }

            // (end) Code for comparison

            if (break_value == 1)
                break;
        } //End of 'while' loop
    }     //End of 'if'

    if (left == right || !(key >= array[left] && key <= array[right]))
        printf("Element does not present in the list\n");

} //End of main()

// For compilation : gcc - fopenmp nary - search.c - lm
// (Note: -fopenmp is used to use "OpenMP" library while -lm is used to use "math.h").

// To run:
// ./a.out