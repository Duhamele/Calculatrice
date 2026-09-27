

#include "cal_math.h"
#include <gtest/gtest.h>
TEST(Test_number_dynamie,test_add){
    NumberDynamy a(1),b(1),c(0),d(1.f);
    EXPECT_EQ(a,b);
    EXPECT_NE(a,c);
    EXPECT_EQ(a,d);

}

