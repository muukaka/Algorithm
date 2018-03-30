#include <iostream>
using namespace std;

void bubble(int* arr, const int n);
void selection(int* arr, const int n);
void insertion(int* arr, const int n);
void mergesort(int *a, int low, int high);
void merge(int *a, int low, int high, int mid);
void quicksort();

int main()
{
	int arr[10] = { 9, 5, 6, 4, 3, 2, 0, 7, 1, 8 };
	// 초기값
	cout << "input :" << endl;
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	//bubble(arr, 10);
	//selection(arr, 10);
	//insertion(arr, 10);
	mergesort(arr, 0, 10-1);

	// 출력
	cout << "output :" << endl;
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

// 시간 복잡도 : O(n^2)
void bubble(int* arr, const int n)
{
	int i, j;
	int a[10];

	// 초기화
	for (i = 0; i < n; i++)
		a[i] = arr[i];

	// 정렬
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j+1]);

	// 출력
	cout << "bubble : " << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// 시간 복잡도 : O(n^2)
void selection(int* arr, const int n)
{
	int i, j;
	int a[10];
	// 초기화
	for (i = 0; i < n; i++)
		a[i] = arr[i];

	// 정렬
	for (i = 0; i < n-1; i++)
	{
		int index = i;
		for (j = i+1; j < n; j++)
			if (a[j] < a[index])
				index = j;
		swap(a[i], a[index]);
	}

	// 출력
	cout << "selection : " << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// 시간 복잡도 : O(n^2), bubble, selection 보다는 빠름
void insertion(int* arr, const int n)
{
	int i, j;
	int a[10];
	// 초기화
	for (i = 0; i < n; i++)
		a[i] = arr[i];

	// 정렬
	for (i = 1; i < n; i++)
	{
		int temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
				a[j + 1] = a[j];
		a[j+1] = temp;
	}
	/* // sample code
	for (i = 1; i < n; i++)
	{
		remember = data[(j = i)];
		while (--j >= 0 && remember < data[j]) {
			data[j + 1] = data[j];
			data[j] = remember;
		}
	}
	*/

	// 출력
	cout << "insertion : " << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// 시간 복잡도 : O(n log n)
// A function to merge the two half into a sorted data.
void merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[10]; //temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}

// A function to split array into two parts.
void mergesort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two half.
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);

		// Merge them to get sorted output.
		merge(a, low, high, mid);
	}
}
void quicksort();