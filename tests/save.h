#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(Save, positive)
{
    text start = create_text();
    start->lines->push_back("first 0\n");
    start->lines->push_back("second 1\n");
    start->lines->push_back("third 2\n");

    start->cursor->line_num = 0;
    start->cursor->position = 0;

    save(start, "testsave.txt");

    text final = create_text();
    load(final, "testsave.txt");

    EXPECT_EQ(start->lines->size(), final->lines->size());

    string* compare_1 = new string[start->lines->size()];
    string* compare_2 = new string[final->lines->size()];

    copy(start->lines->begin(), start->lines->end(), compare_1);
    copy(final->lines->begin(), final->lines->end(), compare_2);

    for(unsigned int i = 0; i < start->lines->size(); i++)
        EXPECT_STREQ(compare_1[i].c_str(), compare_2[i].c_str());

    free(start);
    free(final);
}


TEST(Save, negative_empty)
{
    text start = create_text();
    start->cursor->line_num = 0;
    start->cursor->position = 0;
    save(start, "save_fun.test.txt");

    text final = create_text();
    load(final, "save_fun.test.txt");

    EXPECT_EQ(start->lines->size(), final->lines->size());

    string* compare_1 = new string[start->lines->size()];
    string* compare_2 = new string[final->lines->size()];

    copy(start->lines->begin(), start->lines->end(), compare_1);
    copy(final->lines->begin(), final->lines->end(), compare_2);

    for(unsigned int i = 0; i < start->lines->size(); i++)
        EXPECT_STREQ(compare_1[i].c_str(), compare_2[i].c_str());

    free(start);
    free(final);
}
