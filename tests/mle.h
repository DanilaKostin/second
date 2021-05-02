#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(Mle, positive)
{
    text txt = create_text();

    txt->lines->push_back("first 0\n");

    txt->lines->push_back("second 1\n");

    txt->lines->push_back("third 2\n");

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    mle(txt, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);

    mle(txt, 2);
    EXPECT_EQ(txt->cursor->line_num, 2);

    testing::internal::CaptureStdout();

    show(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "first 0\nsecond 1\nthird 2|\n";

    EXPECT_EQ(standart, output);


    free(txt);
}

TEST(Mle, negative_over_mnogo)
{
    text txt = create_text();

    txt->lines->push_back("first 0\n");

    txt->lines->push_back("second 1\n");

    txt->lines->push_back("third 2\n");

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    mle(txt, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);


    testing::internal::CaptureStdout();

    show(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "|first 0\nsecond 1\nthird 2\n";

    EXPECT_EQ(standart, output);
    
    free(txt);
}
