#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

#include <string>

#define SUCCESS 0
#define FAILED_NO_LINE 1

using namespace std;

typedef struct _list *text;

typedef struct _crsr *cursor;


text create_text();


void append_line(text txt, string contents);

void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

void remove_all(text txt);

int m(text txt, int line_num, int cursor_pos);

int mle(const text txt, int line_n);

void r1ne(const text txt);

void save(text txt, string filename);

#endif
