#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int test_strlen();
int test_strcpy();
int test_string();
int str_swap(char str1, char str2);


int main()
{
	//printf("Hello World!\n");
	//test_strlen();
	//test_strcpy();
	test_string();

	return 0; 
}

#define SIZE 32
int test_strcpy()
{
	char str1[SIZE] = "";
	char str2[SIZE] = "";

	printf("�� ���ڿ� �Է� : ");
	scanf_s("%s %s", str1, SIZE, str2, SIZE);
	printf("%s %s�� �ԷµǾ����ϴ�.\n", str1, str2);

	char temp[SIZE] = "";
	
	str_swap(str1, str2, SIZE);
	printf("%s %s�� ��ȯ�Ǿ�����?.", str1, str2);
	
	return 0;
}
//��ȯ�� �� ���ڿ� ������ ���� ��ȯ
 
int str_swap(char *str1 , char *str2, int size)
{
	int result = 0;
	if (size <= 0 || str1 == NULL || str2 == NULL)
	{
		return 0;
	}





	char* temp = NULL;
	//void * malloc(int size);
	temp = (char*)malloc(sizeof(char) * size);
	// char temp[SIZE]; 


	if (temp == NULL) {
		return 0;
	}

	//strncpy(temp, str1, size);
	//strncpy(str1, str2, size);
	//strncpy(str2, temp, size);


	strcpy_s(temp, size, str1);
	strcpy_s(str1, size, str2);
	strcpy_s(str2, size, temp);

	result = strlen(str1) + strlen(str2);
	free(temp);

	return result;
}

int test_strlen()
{
	char str1[] = "hello";
	char name[] = "��ȣ��";


	size_t len = strlen(str1);
	
	//printf("%s �� ���� : %d\n", str1, strlen(str1));
	printf("%s �� ���� : %d\n", str1, len);


	len = strlen("�ȳ��ϼ���");

	printf("%s �� ���� : %d\n", name, strlen(name));

	len = strlen("");
	printf("%s �� ���� : %d\n", "", strlen(" "));
} 

#define SIZE 128
int test_string()
{
	char in_str[SIZE] = "";
	char out_str[SIZE] = "";
	char* pcontext = NULL;


	char mycontact[] = "C:\\Users\\User\\Download\\mycontact.txt";

	FILE* mc = fopen(mycontact, "r");

	fgets(in_str, sizeof(in_str), mycontact);


	printf("Enter string: ");
	gets_s(in_str, sizeof(in_str));
	puts(in_str);
	
	char* p_token = strtok_s(in_str, "|", &pcontext);
	if(p_token != NULL) puts(p_token);

	p_token = strtok_s(NULL, "|", &pcontext);
	if(p_token != NULL) puts(p_token);
	
	p_token = strtok(NULL, "|", &pcontext);
	if(p_token != NULL) puts(p_token);
	

	return 0;
}