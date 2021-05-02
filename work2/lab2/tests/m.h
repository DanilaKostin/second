#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(M, positive) //тестируем, чтобы были правильные данные и правильный вывод (зачем я это пишу, если будет документация?)
{
    text txt = create_text();

    txt->lines->push_back("first 0\n");

    txt->lines->push_back("second 1\n");

    txt->lines->push_back("third 2\n");

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;


    m(txt, 1, 3);
    EXPECT_EQ(txt->cursor->line_num, 1);
    EXPECT_EQ(txt->cursor->position, 3);

    testing::internal::CaptureStdout();

    show(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "first 0\nsec|ond 1\nthird 2\n";

    EXPECT_EQ(standart, output);


    free(txt);
}

TEST(M, negative_over_mnogo)//Что будет, если ввести номер строки или позицию больше возможного (пс. ничего не поменяется, это и проверяется)
{
    text txt = create_text();

    txt->lines->push_back("first 0\n");

    txt->lines->push_back("second 1\n");

    txt->lines->push_back("third 2\n");

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 100, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 100, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    testing::internal::CaptureStdout();

    show(txt);

    string output = testing::internal::GetCapturedStdout();
    string standart = "|first 0\nsecond 1\nthird 2\n";

    EXPECT_EQ(standart, output);

    free(txt);
}
