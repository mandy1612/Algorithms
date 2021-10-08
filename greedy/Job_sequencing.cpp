// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
using namespace std;

// A structure to represent a job
struct Job
{
char id;	 // Job Id
int dead; // Deadline of job
int profit; // Profit if job is over before or on deadline
};

// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns minimum number of platforms required
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs in decreasing order of profit
	sort(arr, arr+n, comparison);

	int result[n]; // (Sequence of jobs)
	bool slot[n]; // free time slots

	// Initialize all slots
	for (int i=0; i<n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i=0; i<n; i++)
	{
	// Find a free slot for this job (Note that we start
	// from the last possible slot)
	for (int j=min(n, arr[i].dead)-1; j>=0; j--)
	{
		if (slot[j]==false)
		{
			result[j] = i; // Add this job to result
			slot[j] = true; // Make this slot occupied
			break;
		}
	}
	}

	// Print the result
	for (int i=0; i<n; i++)
	if (slot[i])
		cout << arr[result[i]].id << " ";
}

int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
				{'d', 1, 25}, {'e', 3, 15}};
	int n = 5;
	cout << "Maximum profit sequence of jobs \n";
	
	printJobScheduling(arr, n);
	return 0;
}
