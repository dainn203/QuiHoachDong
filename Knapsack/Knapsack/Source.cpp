#include <stdio.h>
#include <stdlib.h>

// Hàm tìm giá trị lớn nhất giữa hai số nguyên
int max(int a, int b) {
	return (a > b) ? a : b;
}

// Hàm giải bài toán Balo 0/1 bằng quy hoạch động
int knapsack(int W, int weights[], int values[], int n) {
	int i, w;
	// Cấp phát động bảng K
	int **K = (int **)malloc((n + 1) * sizeof(int *));
	for (i = 0; i <= n; i++) {
		K[i] = (int *)malloc((W + 1) * sizeof(int));
	}

	// Xây dựng bảng K[][] theo kiểu bottom-up
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				K[i][w] = 0;
			}
			else if (weights[i - 1] <= w) {
				K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
			}
			else {
				K[i][w] = K[i - 1][w];
			}
		}
	}

	int result = K[n][W];

	// Giải phóng bộ nhớ của bảng K
	for (i = 0; i <= n; i++) {
		free(K[i]);
	}
	free(K);

	return result;
}

int main() {
	int values[] = { 60, 100, 120 };
	int weights[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(values) / sizeof(values[0]);

	printf("Gia tri lon nhat co the dat duoc la: %d\n", knapsack(W, weights, values, n));
	return 0;
}
