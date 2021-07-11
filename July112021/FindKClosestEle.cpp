#include <bits/stdc++.h>
#include<math.h>

using namespace std;

int BinarySearch(vector<int> arr, int low, int high, int x)
{
	while (low <= high)
	{
		int m = low + (high - low) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			low = m + 1;

		// If x is smaller, ignore right half
		else
			high = m - 1;
	}

	// if we reach here, then element was
	// not present
	return low;
}

deque<int> FindKClosestElem(vector<int> &arr, int k, int x)
{
	deque<int> finalArray;
	int i = 0, j = 0;
	bool isITrue = true;
	bool isJTrue = true;
	int index = 0;

	int middle = BinarySearch(arr, 0, arr.size() - 1, x);

	if (binary_search(arr.begin(), arr.end(), x))
	{
		i = middle - 1;
		j = middle + 1;
		finalArray.push_back(x);
		index++;
	}

	else if(middle < 0){
		i = 0;
		j = 1;
	}

	else
	{
		i = middle;
		j = middle + 1;
	}

	for(int l = index ; l < k; l++)
	{
		cout << "i:" << i << endl;
		cout << "j:" << j << endl;
		if (j != arr.size()-1 && i != 0)
		{
			if ((abs(x - arr[i]) < abs(x - arr[j])) || ((abs(x - arr[i]) == abs(x - arr[j])) && i < j))
			{
				cout << "i1:" << arr[i] << endl;
				finalArray.push_front(arr[i]);
				i--;
			}
			else if ((abs(x - arr[i]) > abs(x - arr[j])) || ((abs(x - arr[i]) == abs(x - arr[j])) && i > j))
			{
				cout << "i2:" << arr[i] << endl;
				finalArray.push_back(arr[j]);
				j++;
			}
		}
		else if (j == arr.size()-1)
		{
			if (isITrue)
			{
				cout << "i3:" << arr[i] << endl;
				finalArray.push_back(arr[j]);
				isITrue = false;
			}

			else
			{
				cout << "i4:" << arr[i] << endl;
				finalArray.push_front(arr[i]);
				i--;
			}
		}

		else if (i == 0)
		{
			if (isJTrue)
			{
				cout << "i5:" << arr[i] << endl;
				finalArray.push_front(arr[i]);
				isJTrue = false;
			}

			else
			{
				cout << "i6:" << arr[i] << endl;
				finalArray.push_back(arr[j]);
				j++;
			}
		}
	}

	return finalArray;
}

int main()
{
	int x = -1, k = 4;
	vector<int> arr{1,2,3,4,5};
	deque<int> a = FindKClosestElem(arr, k, x);
	// cout << BinarySearch(arr, 0, arr.size() - 1, x);
	cout << a.size();
	for (int i = 0; i < a.size(); i++)
	{
		cout << "a: "<< a[i] << endl;
	}
	return 0;
}
