#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    puts("");
    puts("1) Выделить из одной строки лексемы(кусочки), разделенные любым из множества "
         "символов(разделителей), входящих во вторую строку");


    char str[100];
    char str2[100];
    gets(str);
    gets(str2);
    char *pr = strtok(str, str2);
    while (pr != NULL)
    {
        printf("%s\n", pr);
        pr = strtok(NULL, str2);
    }

    char s1[100];
    char s2[100];

    puts("");
    puts ("2) Сравнение двух строк:");

    scanf("%s", s1);
    scanf("%s", s2);
    if (strcmp(s1, s2) == 0)
        puts("Строки одинаковые");
    else
        puts("Строки разные");


    puts("");
    puts("3) Копирование первых n символов одной строки в другую строку:");

    scanf("%s", s1);
    scanf("%s", s2);
    puts("Введите кол-во симоволов для копирования строки 2 в строку 1:");
    int n;
    scanf("%d", &n);
    printf("%s\n", strncpy (s1, s2, n));


    puts("");
    puts("4) Поиск в строке последнего вхождения символа:");

    scanf("%s", s1);
    puts("Символ: ");
    char ch;
    scanf("%hhd", &ch);
    char* found = strrchr(s1, ch);
    if (found == NULL)
        printf("Символа %c не найдено\n", ch);
    else
        printf("%d\n", *found);


    puts("");
    puts("5) Поиск в одной строке любого из множества символов, входящих во вторую строку:");

    scanf("%s", s1);
    scanf("%s", s2);
    if (strspn(s1, s2) == 0)
        puts("Не найдено ни одного символа");
    else
        printf("%d\n", strspn(s1, s2));



    return 0;
}
