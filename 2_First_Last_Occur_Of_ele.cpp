#include <iostream>
#include <vector>

using namespace std;

// Function to search for the range of target in a sorted vector
vector<int> searchRange(vector<int> &nums, int target)
{
    // Initialize variables to store starting and ending indices
    int start1 = 0;
    int end1 = nums.size() - 1;
    int starting = -1;
    int ending = -1;

    // Binary search for the starting index of target
    while (start1 <= end1)
    {
        int mid = start1 + (end1 - start1) / 2;
        if (nums[mid] == target)
        {
            // Update starting index and search in the left half
            starting = mid;
            end1 = mid - 1;
        }
        else if (nums[mid] > target)
        {
            // Target is in the left half
            end1 = mid - 1;
        }
        else
        {
            // Target is in the right half
            start1 = mid + 1;
        }
    }

    // Reset variables for binary search on the right half for ending index
    int start2 = 0;
    int end2 = nums.size() - 1;

    // Binary search for the ending index of target
    while (start2 <= end2)
    {
        int mid = start2 + (end2 - start2) / 2;
        if (nums[mid] == target)
        {
            // Update ending index and search in the right half
            ending = mid;
            start2 = mid + 1;
        }
        else if (nums[mid] > target)
        {
            // Target is in the left half
            end2 = mid - 1;
        }
        else
        {
            // Target is in the right half
            start2 = mid + 1;
        }
    }

    // Return the range of indices
    return {starting, ending};
}

int main()
{
    // Example usage
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);

    cout << "Range of target " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
