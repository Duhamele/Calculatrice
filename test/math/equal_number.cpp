

#include "cal_math.h"
#include <gtest/gtest.h>
TEST(Test_number_dynamie,test_equa_1){
    NumberDynamy a(1),b(1),c(0),d(1.f);
    EXPECT_EQ(a,b);
    EXPECT_NE(a,c);
    EXPECT_EQ(a,d);
}
TEST(Test_number_dynamie,test_equa_2){
    NumberDynamy a(2.f),b(2),c(-2.f),d(-2);
    EXPECT_EQ(a,b);
    EXPECT_EQ(c,d);
    EXPECT_NE(a,c);
}

