// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;
// Function to return the maximum
// water that can be stored
int maxWatermethod1(int arr[], int n)
{
	// To store the maximum water
	// that can be stored
	int res = 0;
	// For every element of the array
	for (int i = 1; i < n-1; i++) {
		// Find the maximum element on its left
		int left = arr[i];
		for (int j=0; j<i; j++)
		left = max(left, arr[j]);
		// Find the maximum element on its right
		int right = arr[i];
		for (int j=i+1; j<n; j++)
		right = max(right, arr[j]);
	// Update the maximum water
	res = res + (min(left, right) - arr[i]);
	}
	return res;
}

int findWatermethod2(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
 
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}

int main()
{
	int arr[] = {3, 0, 2, 0, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout <<"method1 : "<<maxWatermethod1(arr, n)<<"\n";
	cout <<"method2 : "<<findWatermethod2(arr, n)<<"\n";
	return 0;
}
