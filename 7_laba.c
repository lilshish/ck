#include <stdio.h>
#include <locale.h>
//#include <math.h>


enum Pred {ZAO = 3, OOO, IP, OOO_Rhaka}; // enum - перечисляемый тип данных, ограниченный n-ным количеством констант


struct Otrezok // struct - композитный тип данных, вмещающий в себя, без сокрытия, набор значений различных типов данных, можно взаимодействовать с помощью указателей
{
    int x;
    int y;
};

union ADSL // union - объединение, хранит либо целое число, либо число с плавающей точкой, является разновидностью структры
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
    printf("Координаты точки А: ");
    scanf("%d, %d", &tochka1.x, &tochka1.y);
    printf("Координаты точки B: ");
    scanf("%d, %d", &tochka2.x, &tochka2.y);
    float len = sqrt(pow(tochka2.x - tochka1.x, 2) + pow(tochka2.y - tochka1.y, 2));

    printf("Координаты отрезка прямой (%d, %d)\n", tochka2.x - tochka1.x, tochka2.y - tochka1.y);
    printf("Длина отрезка прямой(|AB|) = %.2f\n", len);



    puts("\n");

    union ADSL sys;
    printf("Введите число в 16-й СС: ");
    scanf("%x", &sys.value);
    printf("DSL: %s\nPPP: %s\nLink: %s\n",
           sys.DSL ? "ON" : "OFF",
           sys.PPP ? "ON" : "OFF",
           sys.Link ? "ON" : "OFF");

    return 0;

}

