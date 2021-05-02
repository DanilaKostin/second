#include <iostream>
#include <string.h>
#include "common.h"
#include "text.h"
#include"_text.h"
#include "common.h"

static void show_upper(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран в обратном порядке
 * пропуская нечётные строки
 */
void showupfirst(text txt)
{
    process_forward(txt, show_upper, NULL);
}

static void show_upper(int index, char *contents, int cursor, void *data)
{

    assert(contents != NULL);

    UNUSED(data);
    UNUSED(cursor);
    UNUSED(index);

    printf("%c", toupper(contents[0]));
    unsigned long i = 1;
    while (i != strlen(contents)-1)
    {
        if (contents[i-1] == ' ')
            printf("%c", toupper(contents[i]));
        else
        printf("%c", contents[i]);
        i++;
    }
    if (contents[strlen(contents)-1] == ' ')
        printf("%c", toupper(contents[strlen(contents)]));
    else printf("%c", contents[i]);
}
