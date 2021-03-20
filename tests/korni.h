#ifndef KORNI_H
#define KORNI_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
#include "myfunc.h"
}

TEST(korniTest, usuall_diskr_zero) {
    ASSERT_EQ(f(1, 2, 1), -1);

}
TEST(korniTest, nokoren) {
    ASSERT_EQ(f(1, 2, 100), INFINITY);
}

TEST(korniTest, twokoren) {
    double d[2] = {0, 1};
    ASSERT_EQ(f(1,-1, 0), *d);
}
TEST(korniTestNegative, x2empty) {
    ASSERT_EQ(f(0, 1, 1), -1);

}

TEST(korniTestNegative, xempty) {
    double d[2] = {-1, 1};
    ASSERT_EQ(f(5, 0, -5), *d);

}

TEST(korniTestNegative, x2andx1empty) {
    ASSERT_EQ(f(0, 0, 1), INFINITY);

}
#endif // KORNI_H
