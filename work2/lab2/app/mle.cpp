#include"_text.h"
int mle(const text txt, int line_n)
{
    if (line_n < 0) {
        printf("Не берём отриц.чисел \n");
        return 0;
    }

    if (line_n > (int) txt->lines->size() - 1) {
        printf("Нет такой позиции: %d\n", (int) txt->lines->size() - 1);
        return 0;
    }

    list<string>::iterator it = txt->lines->begin();
    advance(it, line_n);

    txt->cursor->line_num = line_n;

    txt->cursor->position = it->size()-1;

    return 0;
}
