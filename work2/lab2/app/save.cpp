#include <stdio.h>
#include <assert.h>
#include <string>
#include "common.h"
#include "text.h"

static void save_line(int index, char *contents, int cursor, void *data);


void save(text txt, string filename)
{
    FILE *f;

    if ((f = fopen(filename.c_str(), "w")) == NULL) {
        printf("Can't save to file %s\n", filename.c_str());
        return;
    }

    process_forward(txt, save_line, f);

    fclose(f);
}

static void save_line(int index, char *contents, int cursor, void *data)
{
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(cursor);

    FILE* f = (FILE*)data;
    fprintf(f, "%s", contents);

}
