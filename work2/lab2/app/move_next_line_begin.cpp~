/**
 * move_next_line_begin.c -- перемещает курсор в начало следующей строки
 * реализация команды "mnlb"
 *
 * Copyright (c) 2020, Nikon Podgorny <podgorny@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Перемещает курсор в начало следующей строки
 * @param txt текст
 * @returns статус
 */
int move_next_line_begin(const text txt)
{
    if((unsigned int) txt->cursor->line_num != txt->lines->size() - 1) {
        txt->cursor->line_num++;
        txt->cursor->position = 0;
        return SUCCESS;
    } else {
        return FAILED_NO_LINE;
    }
}
