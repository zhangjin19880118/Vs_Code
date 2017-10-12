#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(int arr[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		int temp = arr[i];
		int j = i - 1;
		for (; j >= 0&&temp<arr[j]; --j)
				arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

void print_sort(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[] = { 1, 6, 3, 2, 8, 3 };
	int n = sizeof(arr) / 4;
	
	sort(arr, n);
	print_sort(arr,n);
	sort(arr, n);

	printf("\n");
	system("pause");
	return 0;
}
