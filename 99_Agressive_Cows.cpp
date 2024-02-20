#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Function to check if it's possible to place 'k' cows in stalls with minimum distance 'minD'
bool isCowplaced(vector<int> &stalls, int minD, int k)
{
    int n = stalls.size();
    int cow = 1;                // Initialize the number of cows placed to 1 (the first stall will always have a cow)
    int lastPlaced = stalls[0]; // Initialize the position of the last placed cow to the first stall

    // Iterate through the stalls starting from the second one
    for (int i = 1; i < n; i++)
    {
        // Check if the distance between the current stall and the last placed cow is greater than or equal to minD
        if ((stalls[i] - lastPlaced) >= minD)
        {
            cow++;                  // Place a cow
            lastPlaced = stalls[i]; // Update the position of the last placed cow
        }
    }

    // Return true if the number of cows placed is greater than or equal to 'k'
    return cow >= k;
}

// Function to find the maximum minimum distance between cows
int aggressiveCows(vector<int> &stalls, int k)
{
    // Sort the stalls in ascending order
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    int end = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int mx = 0;                          // Initialize the result to 0
    int start = 1;                       // Minimum possible distance

    // Binary search to find the maximum minimum distance
    while (start <= end)
    {
        int mid = start + ((end - start) / 2); // Calculate the middle distance

        // If it's possible to place 'k' cows with minimum distance 'mid', update 'mx' and search on the right half
        if (isCowplaced(stalls, mid, k))
        {
            mx = mid;        // Update the result to current middle distance
            start = mid + 1; // Search on the right half
        }
        else
        {
            end = mid - 1; // Search on the left half
        }
    }

    return mx; // Return the maximum minimum distance
}

int main()
{
    // Example usage:
    vector<int> stalls = {1, 2, 4, 8, 9}; // Example stall positions
    int k = 3;                            // Example number of cows

    // Call the aggressiveCows function and print the result
    cout << "Maximum minimum distance between cows: " << aggressiveCows(stalls, k) << endl;

    return 0;
}
