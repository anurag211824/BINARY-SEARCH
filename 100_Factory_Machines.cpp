#include <bits/stdc++.h> // Include all standard C++ libraries
using namespace std;

// Function to calculate the total number of products that can be produced in given time
long long num_of_product(vector<long long> m, long long x)
{
    long long product = 0;
    long long n = m.size(); // Number of machines
    // Loop through each machine
    for (int i = 0; i < n; i++)
    {
        // Calculate the product produced by each machine in given time
        product += x / m[i];
    }
    return product; // Return total products produced
}

int main()
{
    long long n, t; // Number of machines and target number of products
    cout << "Enter the number of machines: ";
    cin >> n; // Input number of machines
    cout << "Enter the target number of products: ";
    cin >> t;               // Input target number of products
    vector<long long> m(n); // Vector to store production rate of each machine
    // Input production rate of each machine
    cout << "Enter the production rate of each machine:\n";
    for (long long i = 0; i < n; i++)
    {
        cout << "Machine " << i + 1 << ": ";
        cin >> m[i];
    }
    long long start = 1; // Start of binary search range
    // End of binary search range is set to the minimum production rate * target products
    long long end = *min_element(m.begin(), m.end()) * t;
    long long ans = 0; // Variable to store the result
    // Binary search loop
    while (start <= end)
    {
        long long mid = start + (end - start) / 2; // Calculate the mid point
        long long res = num_of_product(m, mid);    // Get total products produced in mid time
        if (res < t)
        {
            // If total products produced is less than target, adjust start
            start = mid + 1;
        }
        else
        {
            // If total products produced is greater than or equal to target, adjust end
            ans = mid; // Update answer to current mid
            end = mid - 1;
        }
    }
    cout << "Minimum time required to produce " << t << " products: " << ans << endl; // Output the answer

    return 0;
}
