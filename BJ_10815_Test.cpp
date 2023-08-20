// BJ_10815_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// N(1 ≤ N ≤ 500,000)
// M(1 ≤ M ≤ 500,000)
#include <stdio.h>
#include <stdlib.h>

//int src_arr[10] = {};
//int sorted_arr[10] = {};
//int dst_arr[10] = {};

void merge(int* input_arr, int* sorted_arr, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while ((i <= mid) && (j <= right)) {
		if (input_arr[i] <= input_arr[j]) {
			sorted_arr[k] = input_arr[i];
			i++;
		}
		else {
			sorted_arr[k] = input_arr[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int l = j; l <= right; l++) {
			sorted_arr[k] = input_arr[l];
			k++;
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			sorted_arr[k] = input_arr[l];
			k++;
		}
	}

	for (int i = left; i <= right; i++){
		input_arr[i] = sorted_arr[i];
	}
}

void merge_sort(int* input_arr, int* sorted_arr, int left, int right) {
	int mid = 0;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(input_arr, sorted_arr, left, mid);
		merge_sort(input_arr, sorted_arr, mid +1, right);
		merge(input_arr, sorted_arr, left, mid, right);
	}
}

void bin_search(int* p_dst_int, int* src_in_arr, int left, int right) {
	int i, j;
	int find_status = 0;
	int mid;
	i = left;
	j = right;

	while (i <= j) {
		mid = (i + j) / 2;

		if (p_dst_int[0] < src_in_arr[mid]) {
			j = mid - 1;
		}
		else if(p_dst_int[0] > src_in_arr[mid]) {
			i = mid + 1;
		}
		else {
			p_dst_int[0] = 1;
			find_status = 1;
			break;
		}
	}

	if (find_status != 1) {
		p_dst_int[0] = 0;
	}

}

int main()
{
	int src_test_no;
	int dst_test_no;
	scanf("%d", &src_test_no);

	int* p_src_arr = (int*)malloc(sizeof(int) * src_test_no);
	int* p_sort_arr = (int*)malloc(sizeof(int) * src_test_no);
	for (int i = 0; i < src_test_no; i++) { 
		scanf("%d", &p_src_arr[i]);
	}
	
	scanf("%d", &dst_test_no);
	int* p_dst_arr = (int*)malloc(sizeof(int) * dst_test_no);
	for (int i = 0; i < dst_test_no; i++) {
		scanf("%d", &p_dst_arr[i]);
	}

	//sort src
	merge_sort(p_src_arr, p_sort_arr, 0, src_test_no - 1);

	//compare dst
	for (int i = 0; i < dst_test_no; i++) {
		bin_search(&p_dst_arr[i], p_src_arr, 0, src_test_no - 1);
	}
	
	for (int i = 0; i < dst_test_no; i++) {
		printf("%d ", p_dst_arr[i]);
	}

}
 