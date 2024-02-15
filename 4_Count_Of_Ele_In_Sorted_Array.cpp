#include <iostream>

using namespace std;

// Function to find the first occurrence of x in a sorted array arr
int firstOcc(int arr[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    int first = -1; // Initialize first to -1
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
        {
            first = mid;   // Update first if x is found
            end = mid - 1; // Continue searching for first occurrence in the left half
        }
        else if (arr[mid] > x)
            end = mid - 1; // If x is smaller, search in the left half
        else
            start = mid + 1; // If x is larger, search in the right half
    }
    return first; // Return the index of the first occurrence of x
}

// Function to find the last occurrence of x in a sorted array arr
int lastOcc(int arr[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    int last = -1; // Initialize last to -1
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
        {
            last = mid;      // Update last if x is found
            start = mid + 1; // Continue searching for last occurrence in the right half
        }
        else if (arr[mid] > x)
            end = mid - 1; // If x is smaller, search in the left half
        else
            start = mid + 1; // If x is larger, search in the right half
    }
    return last; // Return the index of the last occurrence of x
}

// Function to count the occurrences of x in a sorted array arr
int count(int arr[], int n, int x)
{
    int i = firstOcc(arr, n, x); // Find the first occurrence of x
    int j = lastOcc(arr, n, x);  // Find the last occurrence of x
    if (i == -1 && j == -1)      // If x is not found in the array
        return 0;
    else
        return j - i + 1; // Return the count of occurrences of x
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5}; // Example sorted array
    int n = sizeof(arr) / sizeof(arr[0]);    // Calculate the size of the array
    int x = 3;                               // Element to be searched

    // Call the count function to count the occurrences of x
    int occurrence = count(arr, n, x);

    // Output the result
    cout << "Number of occurrences of " << x << " is: " << occurrence << endl;

    return 0;
}
