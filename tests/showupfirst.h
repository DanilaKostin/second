#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include <iostream>
#include <sstream>

#include "common.h"
#include "text.h"
#include "_text.h"


TEST(Showupfirst, positive)
{

    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    txt->lines->push_back("line 0 position zero\n");

    txt->lines->push_back("line 1 position one\n");

    testing::internal::CaptureStdout();

    showupfirst(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "Line 0 Position Zero\nLine 1 Position One\n";

    EXPECT_EQ(standart, output);

    free(txt);
}

TEST(Showupfirst, negative_different_symbols)
{

    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    txt->lines->push_back("line_zero And f\n");

    txt->lines->push_back("_line_one\n");

    testing::internal::CaptureStdout();

    showupfirst(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "Line_zero And F\n_line_one\n";

    EXPECT_EQ(standart, output);

    free(txt);
}

TEST(Showupfirst, negative_no_lines)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();

    showupfirst(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_EQ(text.length(), 0);

    free(txt);
}
