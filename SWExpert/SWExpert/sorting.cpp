#include <iostream>
#include <algorithm>
using namespace std;

void bubble(int* a, const int n);
void selection(int* a, const int n);
void insertion(int* a, const int n);
void mergesort(int *a, int low, int high);
void merge(int* a, int low, int high, int mid);
void quicksort(int* a, int left, int right);
void quickSort(int arr[], int low, int high);

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
	//mergesort(arr, 0, 10-1);
	//quicksort(arr, 0, 9);
	quickSort(arr, 0, 9);

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

// 시간 복잡도 : 평균 - O(n log n), 최악 - O(n^2)
void quicksort(int* arr, int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];// 피봇은 어느걸로 잡든 상관없음
	int temp;
	do {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	/* recursion */
	if (left < j)
		quicksort(arr, left, j);

	if (i < right)
		quicksort(arr, i, right);
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1); // pivot의 인덱스
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}