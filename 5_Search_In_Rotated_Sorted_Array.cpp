#include <iostream>

using namespace std;

// Function to find the index of the minimum element in a rotated sorted array
int minEleIndex(int A[], int l, int h)
{
    int start = l;
    int end = h;
    int n = h - l + 1;
    while (start <= end)
    {
        if (A[start] <= A[end])
            return start; // If the array is already sorted, return the start index
        int mid = (start + end) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (A[mid] <= A[prev] && A[mid] <= A[next])
            return mid; // If mid is the minimum element, return its index
        else if (A[mid] >= A[start])
            start = mid + 1; // If the left half is sorted, search in the right half
        else
            end = mid - 1; // If the right half is sorted, search in the left half
    }
}

// Function to perform binary search in a sorted array
int binary_search(int A[], int l, int h, int target)
{
    int low = l;
    int high = h;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == target)
            return mid; // If the target is found, return its index
        else if (A[mid] < target)
            low = mid + 1; // If the middle element is less than the target, search in the right half
        else
            high = mid - 1; // If the middle element is greater than the target, search in the left half
    }
    return -1; // If the target is not found, return -1
}

// Function to search for a key in a rotated sorted array
int search(int A[], int l, int h, int key)
{
    // Find the index of the minimum element
    int index = minEleIndex(A, l, h);
    // Perform binary search in the left and right halves separately
    int index1 = binary_search(A, l, index - 1, key);
    int index2 = binary_search(A, index, h, key);
    // Determine the final index of the key
    if (index1 == index2)
        return -1; // If the key is not found in both halves, return -1
    else if (index1 > index2)
        return index1; // If the key is found in the left half, return its index
    else
        return index2; // If the key is found in the right half, return its index
}

int main()
{
    int A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; // Example rotated sorted array
    int n = sizeof(A) / sizeof(A[0]);       // Calculate the size of the array
    int key = 3;                            // Key to be searched

    // Call the search function to find the index of the key
    int index = search(A, 0, n - 1, key);

    // Output the result
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
