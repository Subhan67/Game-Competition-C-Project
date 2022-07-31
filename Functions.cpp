#include "Functions.h"

int Functions::getLength(char* arr) {
	int length = 0;
	for (int i = 0; arr[i] != '\0'; i++, length++);
	return length;
}

void Functions::copy(char* arr, char* arr2) {
	int length = getLength(arr2);
	for (int i = 0; i < length; i++) {
		arr[i] = arr2[i];
	}
	arr[length] = '\0';
}
