#include <stdio.h>

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d: %d\n", arr[i], i + 1);
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swaps[n]; // Array to store the number of swaps for each element
    for (i = 0; i < n; i++)
        swaps[i] = 0; // Initialize swaps array with 0

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Increment swap count for swapped elements
                swaps[j]++;
                swaps[j + 1]++;
            }
        }
    }

    int total_swaps = 0;
    for (i = 0; i < n; i++) {
        total_swaps += swaps[i];
    }
    

    // Print the number of swaps for each element
    for (i = 0; i < n; i++)
        printf("%d: %d\n", arr[i], swaps[i]);


    total_swaps /= 2; // Dividing by 2 as each swap involves two elements

    // Print the total number of swaps
    printf(" %d\n", total_swaps);
}




void selectionSort(int arr[], int n)
{
    int i, j, min_indx, temp;
    int swaps[n]; // Array to store the number of swaps for each element
    int total_swaps = 0; // Variable to store the total number of swaps
    for (i = 0; i < n; i++)
        swaps[i] = 0; // Initialize swaps array with 0

    // Moving boundary of unsorted subarray, using index
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_indx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_indx])
                min_indx = j;

        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[min_indx];
        arr[min_indx] = temp;

        // Increment swap count for swapped elements
        if (min_indx != i) {
            swaps[min_indx]++;
            swaps[i]++;
        }

        // Increment total swap count
        total_swaps++;
    }

    // Print the number of swaps for each element
    for (i = 0; i < n; i++)
        printf("%d: %d\n", arr[i], swaps[i]);

    // Calculate total swaps and divide by 2
    int total_avg_swaps = 0;
    for (i = 0; i < n; i++)
        total_avg_swaps += swaps[i];
    total_avg_swaps /= 2;

    printf("%d\n", total_avg_swaps);
}


int main()
{
    int n = 9;

    // Bubble arrays
    int B_array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int B_array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Selection arrays
    int S_array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int S_array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("Bubble Sort on array1:\n");
    bubbleSort(B_array1, n);
    printf("\nBubble Sort on array2:\n");
    bubbleSort(B_array2, n);

   
   printf("\nSelection Sort on array1:\n");
    selectionSort(S_array1, n);
    printf("\nSelection Sort on array2:\n");
    selectionSort(S_array2, n);
   

    return 0;
}
