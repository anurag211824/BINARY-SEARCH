#include <iostream>
#include <vector>

using namespace std;

// Binary search function
int search(vector<int> &nums, int target)
{
    int start = 0;             // Initialize the starting index of the search range
    int end = nums.size() - 1; // Initialize the ending index of the search range
    int ans = -1;              // Initialize the variable to store the result

    // Binary search algorithm
    while (start <= end)
    {
        int mid = (start + end) / 2; // Calculate the middle index of the current search range
        if (nums[mid] == target)     // If the middle element is equal to the target, return its index
            return mid;
        else if (nums[mid] > target) // If the middle element is greater than the target, update the end index
            end = mid - 1;
        else // If the middle element is less than the target, update the start index
            start = mid + 1;
    }

    return ans; // Return -1 if the target is not found
}

int main()
{
    // Test case
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Initialize the array for testing
    int target = 6;                                     // Define the target value to search for

    // Call the binary search function
    int index = search(nums, target);

    // Display the result
    if (index != -1) // If the target is found, print its index
        cout << "Target " << target << " found at index " << index << endl;
    else // If the target is not found, print a message indicating so
        cout << "Target " << target << " not found in the array." << endl;

    return 0; // Return 0 to indicate successful completion of the program
}