#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    puts("");
    puts("1) �������� �� ����� ������ �������(�������), ����������� ����� �� ��������� "
         "��������(������������), �������� �� ������ ������");


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
    puts ("2) ��������� ���� �����:");

    scanf("%s", s1);
    scanf("%s", s2);
    if (strcmp(s1, s2) == 0)
        puts("������ ����������");
    else
        puts("������ ������");


    puts("");
    puts("3) ����������� ������ n �������� ����� ������ � ������ ������:");

    scanf("%s", s1);
    scanf("%s", s2);
    puts("������� ���-�� ��������� ��� ����������� ������ 2 � ������ 1:");
    int n;
    scanf("%d", &n);
    printf("%s\n", strncpy (s1, s2, n));


    puts("");
    puts("4) ����� � ������ ���������� ��������� �������:");

    scanf("%s", s1);
    puts("������: ");
    char ch;
    scanf("%hhd", &ch);
    char* found = strrchr(s1, ch);
    if (found == NULL)
        printf("������� %c �� �������\n", ch);
    else
        printf("%d\n", *found);


    puts("");
    puts("5) ����� � ����� ������ ������ �� ��������� ��������, �������� �� ������ ������:");

    scanf("%s", s1);
    scanf("%s", s2);
    if (strspn(s1, s2) == 0)
        puts("�� ������� �� ������ �������");
    else
        printf("%d\n", strspn(s1, s2));



    return 0;
}
