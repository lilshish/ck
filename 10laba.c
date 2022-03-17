#include <stdio.h>
#include <stdlib.h>

int NOD(int fElemnt, int sElemnt);
int NOK(int fElemnt, int sElemnt);
void delete_symbol(char* p);
void delete_spaces(char* str);


int main()
{
    char str[1000];
    gets(str);
    delete_spaces(str);
    printf("%s\n", str);

    int fElemnt, sElemnt;
    scanf("%d %d", &fElemnt, &sElemnt);
    printf("NOD = %d\n", NOD(fElemnt, sElemnt));
    printf("NOK = %d\n", NOK(fElemnt, sElemnt));


}

int NOD(int fElemnt, int sElemnt)
{
    int nod;
    if (fElemnt == sElemnt)
        return fElemnt;
    int div = fElemnt - sElemnt;
    if (div < 0)
    {
        div = -div;
        div = NOD(fElemnt, div);
    }
    else
    {
        div = NOD(sElemnt, div);
    }
    return div;
}

int NOK(int fElemnt, int sElemnt)
{
    int nok = (fElemnt * sElemnt) / NOD(fElemnt, sElemnt);
    return nok;
}

void delete_symbol(char* p) {
    for (int i = 0; p[i] != '\0'; i++) {
        p[i] = p[i + 1];
    }
}

void delete_spaces(char* str) {
    while (*str != '\0') {
        if (*str == ' ' && *(str + 1) == ' ') {
            delete_symbol(str + 1);
            delete_spaces(str);
            return;
        }
        else if ((*str == '(' || *str == '[' || *str == '{' || *str == '"') && *(str + 1) == ' ') {
            delete_symbol(str + 1);
            delete_spaces(str);
            return;
        }
        str++;
    }
}



