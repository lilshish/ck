#include <stdio.h>
#include <locale.h>
//#include <math.h>


enum Pred {ZAO = 3, OOO, IP, OOO_Rhaka}; // enum - ������������� ��� ������, ������������ n-��� ����������� ��������


struct Otrezok // struct - ����������� ��� ������, ��������� � ����, ��� ��������, ����� �������� ��������� ����� ������, ����� ����������������� � ������� ����������
{
    int x;
    int y;
};

union ADSL // union - �����������, ������ ���� ����� �����, ���� ����� � ��������� ������, �������� �������������� ��������
{
    int value;
    struct
    {
        unsigned DSL: 1;
        unsigned PPP: 1;
        unsigned Link: 1;
    };
};

int main()
{
    setlocale(LC_ALL, "Rus");

    enum Pred a = OOO;
    printf("%d\n\n", a);

    struct Otrezok tochka1;
    struct Otrezok tochka2;
    printf("���������� ����� �: ");
    scanf("%d, %d", &tochka1.x, &tochka1.y);
    printf("���������� ����� B: ");
    scanf("%d, %d", &tochka2.x, &tochka2.y);
    float len = sqrt(pow(tochka2.x - tochka1.x, 2) + pow(tochka2.y - tochka1.y, 2));

    printf("���������� ������� ������ (%d, %d)\n", tochka2.x - tochka1.x, tochka2.y - tochka1.y);
    printf("����� ������� ������(|AB|) = %.2f\n", len);



    puts("\n");

    union ADSL sys;
    printf("������� ����� � 16-� ��: ");
    scanf("%x", &sys.value);
    printf("DSL: %s\nPPP: %s\nLink: %s\n",
           sys.DSL ? "ON" : "OFF",
           sys.PPP ? "ON" : "OFF",
           sys.Link ? "ON" : "OFF");

    return 0;

}

