#include <stdio.h>
#include <stdbool.h>

static int flip_1e1(int x) {
	int ones = x % 10;
	int tenths = x / 10;
	return ((ones * 10) + tenths);
}

static int flip_1e2(int x) {
	int ones = x % 10;
	int tenths = (x % 100) / 10;
	int hundredths = x / 100;
	return ((ones * 100) + (tenths * 10) + hundredths);
}

static bool is_palindrome(int x) {
	int start = flip_1e2(x % 1000);
	int end = (x / 1000);
	if (start == end) {
		return true;
	}
	return false;
}

int main() {
	for (int i = 600; i < 999; i++) {
		for (int j = 600; j < 999; j++) {
				if (is_palindrome(i * j))
					printf("%i * %i = %i\n", i, j, i * j);
		}
	}
}

