
#include <gtest/gtest.h>
#include <stdexcept>
#include"../include/User.h"
#include"../include/Date.h"
#include"../include/Utils.h"

TEST(getFunctionsTest, invalidMoodCheck_Exceptions) {
    EXPECT_THROW(isValidMood(-23), std::out_of_range);
    EXPECT_THROW(isValidMood(6), std::out_of_range);
}
TEST(getFunctionsTest, validMoodCheck_Exceptions) {
    EXPECT_TRUE(isValidMood(1));
    EXPECT_TRUE(isValidMood(4));
}
TEST(getFunctionsTest, invalidCycle_Exceptions) {
    EXPECT_THROW(isValidCycle(-23), std::out_of_range);
    EXPECT_THROW(isValidCycle(0), std::out_of_range);
}

TEST(getFunctionsTest, validCycleCheck) {
    EXPECT_TRUE(isValidCycle(3));
    EXPECT_TRUE(isValidCycle(1));
}

TEST(getFunctionsTest, invalidNameCheck_Exceptions) {
    EXPECT_THROW(isValidName("thisismorethat35wordsidontwantthisinputtobevalidtoolong"),std::invalid_argument);
}
TEST(getFunctionsTest, validNameCheck) {
    EXPECT_TRUE(isValidName("Karol"));
}

int main(int argc,char**argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}