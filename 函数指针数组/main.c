#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int my_add(int* a, int* b) {

	return *a + *b;
}

int my_sub(int* a, int* b) {
	return *a - *b;
}

int my_mul(int* a, int* b) {
	return *a * *b;
}

int my_div(int* a, int* b) {
	return *a / *b;
}

typedef int(*sizeyunsuan)(int*, int*);//����������

char* my_strcpy(char* dest, const char* str) {
	int flag = 1;
	while (flag) {
		*dest = *str;
		if ('\0' == *str) {
			flag = 0;
		}
	}
	return dest;
}

typedef char* (tostrcpy)(char*, const char*);
tostrcpy* point = my_strcpy;

tostrcpy* pointArr[4] = { my_strcpy };

int main(void) {
	int* arr[5];
	sizeyunsuan pa[4] = {my_add,my_sub,my_mul,my_div};//����ָ������
	
	//���������ͺͲ����б���ȫ��ͬ�ĺ��������������棬������������
	int i = 0;
	int a = 3, b = 6;
	for (; i < 4; i++) {
		printf("%d\n", pa[i](&a, &b));//����ָ�����ȷ�򿪷�ʽ

	}
	
	return 0;
}