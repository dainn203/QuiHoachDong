#include <stdio.h>
#include <stdlib.h>

// Hàm tìm giá trị lớn nhất giữa hai số nguyên
int max(int a, int b) {
	return (a > b) ? a : b;
}

// Hàm giải bài toán Balo không giới hạn bằng quy hoạch động
int unboundedKnapsack(int W, int weights[], int values[], int n) {
	int *dp = (int *)malloc((W + 1) * sizeof(int));

	// Khởi tạo dp với giá trị 0
	for (int i = 0; i <= W; i++) {
		dp[i] = 0;
	}

	// Xây dựng bảng dp[] theo kiểu bottom-up
	for (int i = 0; i < n; i++) {
		for (int w = weights[i]; w <= W; w++) {
			dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
		}
	}

	int result = dp[W];
	free(dp);
	return result;
}

int main() {
	int values[] = { 60, 100, 140, 140 };
	int weights[] = { 10, 20, 30, 50 };
	int W = 50;
	int n = sizeof(values) / sizeof(values[0]);

	printf("Gia tri lon nhat co the dat duoc la: %d\n", unboundedKnapsack(W, weights, values, n));
	return 0;
}
