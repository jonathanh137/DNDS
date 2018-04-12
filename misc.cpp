#include "misc.h"

int dRoll(int N, int S) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += (rand() % S + 1);
	}
	return result;
}
int statrolls() {
	int rolls[3] = { 0 };
	int temp;
	int sum;
	int i;
	for (i = 1; i < 5; i++) {
		temp = dRoll(1, 6);
		for (int j = 0; j < i && j < 3; j++) {
			if (rolls[j] == 0) {
				rolls[j] = temp;
				break;
			}
			if (temp > rolls[j]) {
				sum = rolls[j];
				rolls[j] = temp;
				temp = sum;
			}
		}
	}
	sum = 0;
	for (i = 0; i < 3; i++) {
		sum += rolls[i];
	}
	return sum;
}
int compare(const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}
int intValid(int upBound) {
	int selector;
	while ((std::cout << "-> " && !(cin >> selector)) || (selector < 1) || (selector >= upBound) || cin.peek() != '\n')
	{
		std::cout << "Please enter a corresponding number" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return selector;
}