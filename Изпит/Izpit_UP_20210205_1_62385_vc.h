#pragma once
//Kristina Dragomirova Goranova 62385

int* countletters(int arr1[], int arr2[], int N) {
	int counter_capital = 0, counter_small = 0;
	int* result = new int[2];
	int* new_arr = new int[N];
	for (int i = 0; i < N; i++) {
		new_arr[i] = arr1[i] + arr2[i];
	}
	for (int i = 0; i < N; i++) {
		if (new_arr[i] >= 65 && new_arr[i] <= 90) counter_capital++;
		if (new_arr[i] >= 97 && new_arr[i] <= 122) counter_small++;
	}
	result[0] = counter_capital;
	result[1] = counter_small;
	delete[] new_arr;
	return result;

}
char* revandreplace(char* str) {
	int length = 0;
	char temp;
	while (str[length] != '\0') {
		length++;
	}
	for (int i = 0; i < length / 2; i++) {
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
	for (int i = 0; i < length; i++) {
		
		if (str[i] == 101) str[i] -= 68;
		else if (str[i] == 69) str[i] -= 36;
		else if (str[i] == 89) str[i] -= 47;
		else if (str[i] == 121) str[i] -= 79;
		
	}
	return str;
}
bool CheckDate(char str[]) {
	int year = 0,length=0;
	bool digits = true;
	while (str[length] != '\0') {
		length++;
	}
	for (int i = 0; i < 4; i++) {
		if (!(str[i] >= '0' && str[i] <= '9')) { digits = false; break; }
	}
	bool visokosna = false;
	year = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
	if (year % 100 == 0) {
		if (year % 400 == 0) visokosna = true;
	}
	else if (year % 4 == 0) visokosna = true;

	if (str[4] == ' ' && str[5] == 'g' && str[6] == '.' && visokosna == true ) return true;
	else return false;
}