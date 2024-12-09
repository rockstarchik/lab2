#include "lab2.h"


int main() {
	char str[] = "HELLO";
	printf("%s\n", strtolower(str));
	char str2[] = "hello";
	printf("%s\n", strtoupper(str));
	char str3[] = "hello";
	char str32[] = "HELLO";
	char str33[] = "!hello";
	printf("%d\n", strcmp_insensitive(str3, str32));
	printf("%d\n", strcmp_insensitive(str3, str33));
	char str4[] = "hello";
	printf("%s\n", strreverse(str4));
	char str5[] = " hello ";
	printf("%s\n", strtrim(str5));
	char str6[] = "hello";
	printf("%s\n", strrmchar(str6, 'o'));
	char str7[] = "hello";
	printf("%d\n", strcountchar(str7, 'l'));
	char str8[] = "hello";
	printf("%s\n", substr(str8, 0, 4));
	char str9[] = "hello";
	printf("%d\n", strfindlastof(str9, "abcde"));
	char str10[] = "Go hang a salami I'm a lasagna hog";
	printf("%d\n", strispalindrome(str10));
	char str11[] = "Was it a car or a cat I saw?";
	printf("%d\n", strcountwords(str11));
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова 