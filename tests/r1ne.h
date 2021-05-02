#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(R1ne, positive)
{
    text txt = create_text();

    txt->lines->push_back("first 0\n");

    txt->lines->push_back("second 1\n");

    txt->lines->push_back("third 2\n");

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    r1ne(txt);

    testing::internal::CaptureStdout();

    show(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "|second 1\nthird 2\n";

    EXPECT_EQ(standart, output);

    free(txt);
}

TEST(R1ne, negative_standart)
{
    text txt = create_text();

    txt->lines->push_back("\n");

    txt->lines->push_back("line 1\n");

    txt->lines->push_back("line 2\n");

    txt->cursor->line_num = 1;
    txt->cursor->position = 0;

    r1ne(txt);
    testing::internal::CaptureStdout();

    show(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "\n|line 2\n";

    EXPECT_EQ(standart, output);
    EXPECT_EQ(txt->cursor->line_num, 1);
    EXPECT_EQ(txt->cursor->position, 0);
    free(txt);
 }
TEST(R1ne, negative_cursor_test)
{

    text txt = create_text();

    txt->lines->push_back("\n");

    txt->lines->push_back("line 1\n");

    txt->cursor->line_num = 1;
    txt->cursor->position = 0;

    r1ne(txt);
    testing::internal::CaptureStdout();

    show(txt);

    string    output = testing::internal::GetCapturedStdout();
    string standart = "|\n";

    EXPECT_EQ(standart, output);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}
