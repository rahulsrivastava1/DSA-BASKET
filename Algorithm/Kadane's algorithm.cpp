// Time Complexity: O(N)
// Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int Max_Far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (Max_Far < max_ending_here)
			Max_Far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return Max_Far;
}

// Driver Code
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
