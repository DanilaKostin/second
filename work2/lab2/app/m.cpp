#include "_text.h"

int m(const text txt, int line_n, int pos_in_line)
{
    if (line_n < 0) {
        printf("Пишите неотрицательные числа");
        return 0;
    }

    if (line_n > (int) txt->lines->size() - 1) {
        printf("Нет такой строки");
        return 0;
    }

    if (pos_in_line < 0) {
        printf("Пишите неотрицательные числа");
        return 0;
    }

    list<string>::iterator it = txt->lines->begin();
    advance(it, line_n);

    if ((unsigned int) pos_in_line > it->size() - 1) {
        printf("Нет такой позиции");
        return 0;
    }

    txt->cursor->line_num = line_n;

    txt->cursor->position = pos_in_line;

    return 0;
}
