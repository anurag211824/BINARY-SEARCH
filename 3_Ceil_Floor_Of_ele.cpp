#include <iostream>
#include <vector>

using namespace std;
// Function to find the floor value of x in a sorted vector 'a'
int floor(vector<int> &a, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int Floor = -1; // Initialize Floor to -1
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == x)
            return a[mid]; // If x is found, return x
        else if (a[mid] > x)
            end = mid - 1; // If x is smaller, search in the left half
        else if (a[mid] <= x)
        {
            Floor = a[mid];  // Update Floor to the current value
            start = mid + 1; // Search in the right half for potentially larger Floor
        }
    }
    return Floor; // Return the floor value
}

// Function to find the ceil value of x in a sorted vector 'a'
int ceil(vector<int> &a, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int Ceil = -1; // Initialize Ceil to -1
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == x)
            return a[mid]; // If x is found, return x
        else if (a[mid] >= x)
        {
            Ceil = a[mid]; // Update Ceil to the current value
            end = mid - 1; // Search in the left half for potentially smaller Ceil
        }
        else if (a[mid] < x)
        {
            start = mid + 1; // If x is larger, search in the right half
        }
    }
    return Ceil; // Return the ceil value
}

// Function to get both the floor and ceil values of x in a sorted vector 'a'
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Call the floor and ceil functions to get the floor and ceil values respectively
    int u = ceil(a, n, x);
    int v = floor(a, n, x);
    // Create a pair with the floor and ceil values and return it
    pair<int, int> p = {v, u};
    return p;
}

int main()
{
    // Example sorted vector
    vector<int> arr = {1, 4, 6, 8, 10};
    int n = arr.size();
    int x = 5;

    // Call the getFloorAndCeil function
    pair<int, int> result = getFloorAndCeil(arr, n, x);

    // Output the floor and ceil values
    cout << "Floor of " << x << " is: " << result.first << endl;
    cout << "Ceil of " << x << " is: " << result.second << endl;

    return 0;
}
