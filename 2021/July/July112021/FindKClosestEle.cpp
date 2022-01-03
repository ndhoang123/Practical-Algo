#include <bits/stdc++.h>
#include <math.h>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
	int high, mid, low;
	low = 0;
	high = arr.size() - 1;

	while (high >= low)
	{
		mid = (low + high) / 2;
		(arr[mid] > x) ? high = mid - 1 : low = mid + 1;
	}

	//compare the closest elements and store them in deque
	deque<int> dq;
	int i = high;
	int j = low;

	while (k--)
	{
		if (i < 0)
			dq.push_back(arr[j++]);
		else if (j >= arr.size())
			dq.push_front(arr[i--]);
		else if (abs(arr[i] - x) <= abs(arr[j] - x))
			dq.push_front(arr[i--]);
		else
			dq.push_back(arr[j++]);
	}

	//copy the deque to vector array and return the array
	vector<int> result(dq.begin(), dq.end());
	return result;
}

int main()
{
	int x = -1, k = 4;
	vector<int> arr{1, 2, 3, 4, 5};
	vector<int> a = findClosestElements(arr, k, x);
	// cout << BinarySearch(arr, 0, arr.size() - 1, x);
	cout << a.size();
	for (int i = 0; i < a.size(); i++)
	{
		cout << "a: " << a[i] << endl;
	}
	return 0;
}
