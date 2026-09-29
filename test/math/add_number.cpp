


#include "cal_math.h"
#include <gtest/gtest.h>


#define TEST_NUMBER_DYNAMIE_ADD(val1,val2,val3) \
{                                               \
NumberDynamy a( val1 ), b( val2), c (val3);    \
EXPECT_EQ(a+b,c);                               \
}
TEST(Test_number_dynamie,test_add_1){
    TEST_NUMBER_DYNAMIE_ADD(2,3,5)
    TEST_NUMBER_DYNAMIE_ADD(1,-2,-1)
}
TEST(Test_number_dynamie,test_add_2){
    TEST_NUMBER_DYNAMIE_ADD(2.f,3,5.f)
    TEST_NUMBER_DYNAMIE_ADD(1.f,-2,-1.f)
}
