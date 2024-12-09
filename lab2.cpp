#include "lab2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

char* strtolower(char* str) {
    char *ptr = str;
    while (*ptr){ // Пока не конец строки
        if (*ptr >= 'A' && *ptr <= 'Z') {
            *ptr = *ptr + 32;
        }
        ptr++; // Переход к  следующему символу
    }
    return str; 
}

char* strtoupper(char* str) {
    char *ptr = str;
    while (*ptr) { 
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = *ptr - 32;
        }
        ptr++; 
    }
    return str; 
}

int strcmp_insensitive(const char* str1, const char* str2) {
    while (*str1 && *str2) {// Пока строки не закончились
        char ch1 = *str1;
        char ch2 = *str2;
        if (ch1 >= 'A' && ch1 <= 'Z'){ // Понижение регистра
            ch1 = ch1 + 32;
        }
        if (ch2 >= 'A' && ch2 <= 'Z'){
            ch2 = ch2 + 32;
        }
        if (ch1 != ch2){ // Сравнение
            return ch1 - ch2; 
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char* strreverse(char* str) {
    if (strlen(str) == 0){ // Проверка на пустую строку
        return str;
    }
    char *start = str;
    char *end = str;
    while (*end) {
        end++;
    }
    end = end - 1; // Указатель не на "\0"
    while (start < end){ // Меняем символы местами 
        char t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }
    return str; 
}


char* strtrim(char* str) {
    if (strlen(str) == 0) {
        return str;
    }
    char *start = str; 
    char *end = str;
    while (*start && (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r' || *start == '\v' || *start == '\f')){ // Поиск первого печатного символа 
        start++;
    }
    if (*start == '\0'){ // Если строка состоит из пробелов вернуть пустую строку
        *str = '\0';
        return str;
    }
    end = start;
    while (*end){  // Поиск последнего печатного символа
        end++;
    }
    end--;
    char *dst = str;
    while (start < end && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r' || *end == '\v' || *end == '\f')){ // Копирование строки между start и end
        *dst++ = *start++;
    }
    *dst = '\0';
    return str;
}

char* strrmchar(char* str, char symbol) {
    if (strlen(str) == 0){
        return str;
    }; 
    char *cht = str; // Указатель для чтения
    char *zap = str; // Указатель для записи
    while (*cht) {
        if (*cht != symbol){
            if (zap != cht){
                memmove(zap, cht, 1); // Перемещение символа на новую позицию
            }
            zap++;
        }
        cht++;
    }
    *zap = '\0';
    return str;
}

size_t strcountchar(const char *str, char symbol) {
    if (strlen(str) == 0){
        return 0;
    };
    size_t count = 0; // Счетчик символов
    const char *ptr = str;
    while ((ptr = strchr(ptr, symbol)) != NULL) {// Поиск симвоа в строке
        count++;
        ptr++;   
    }
    return count;
}

char* substr(const char* str, size_t pos, size_t count) {
    if (strlen(str) == 0){
        return 0;
    };
    size_t len = strlen(str);
    if (pos >= len) {
        return NULL;
    }
    size_t actual_count = count;
    if ((len - pos) < count) {
        size_t actual_count = len - pos;// Вычисляем реальную длину подстроки
    }
    char *result = (char*)malloc(actual_count + 1);
    if (!result) {
        return NULL;
    }// Проверка на успешное выделение памяти

    for (size_t i = 0; i < actual_count; i++) {// Копирование подстроки
        result[i] = str[pos + i];
    }

    result[actual_count] = '\0'; // Завершение строки
    return result;
}


int strfindlastof(const char* str, const char* symbols) {
    if (strlen(str) == 0) {
        return 0;
    }
    int last_index = -1; // Изначально индекс не найден
    for (int i = 0; str[i] != '\0'; i++) {
        const char *found = strchr(symbols, str[i]); // Поиск str[i] в symbols
        if (found) {
            last_index = i;
        }
    }
    return last_index;
}
    
int strispalindrome(const char* str) {
    if (strlen(str) == 0){
        return 0;
    }
    const char *left = str; // Указатель на начало строки
    const char *right = str;
    while (*right) {
        right++;
    }
    right--; // Смещение на последний символ
    while (left < right) {
        while (left < right && !isalnum(*left)) { // Пропуск непечатных символов и пробелов
            left++;
        }
        while (left < right && !isalnum(*right)) {
            right--;
        }
        if (tolower(*left) != tolower(*right)) {
            return 0; // Если символы не совпадают, это не палиндром
        }
        left++;
        right--;
    }
    return 1;
}

size_t strcountwords(const char* str) {
    if (strlen(str) == 0) {
        return 0;
    }
    size_t count = 0;  // Счетчик слов
    int in_word = 0;   // Флаг, указывающий, находимся ли мы внутри слова
    while (*str) {
        if (!isspace(*str)) { // Если текущий символ не пробельный и не в слове, начинало нового слово
            if (!in_word) {
                in_word = 1;
                count++;
            }
        }
        else { // Если текущий символ пробельный, завершение слова
            in_word = 0;
        }
        str++;
    }
    return count;
}

