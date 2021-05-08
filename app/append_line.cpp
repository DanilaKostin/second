#include "_text.h"

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(const text txt, string contents)
{
    txt->lines->push_back(contents);
    txt->cursor->position = (unsigned int)contents.size();
    txt->cursor->line_num = (unsigned int)txt->lines->size() - 1;
}
