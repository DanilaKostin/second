#include"_text.h"
#include "common.h"
#include "text.h"

void r1ne(const text txt){

    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }
    /* Если список изначально пуст, делать ничего не надо */
    if (txt->lines->size() == 0) {
        return;
    }

    for(list<string>::iterator it = txt->lines->begin(); it != txt->lines->end(); it++) {
        if(*it !="\n") {
            //it->erase();
            txt->lines->erase(it);
            break;
        }
    }
    if ((unsigned long)txt->cursor->line_num == txt->lines->size())
        txt->cursor->line_num -=1;


}

