
#include <gtest/gtest.h>
#include"../include/getFunctions.h"
#include"../include/beginBreathing.h"
#include"../include/logUser.h"
#include"../include/UserInfo.h"
#include"../include/Date.h"
#include"../include/Mood.h"


TEST(getFunctionsTest, validMoodCheck) {
    EXPECT_TRUE(isValidMood(1));
    EXPECT_FALSE(isValidMood(0));
}

TEST(getFunctionsTest, validCycleCheck) {
    EXPECT_TRUE(isValidCycle(3));
    EXPECT_FALSE(isValidCycle(20));
}

TEST(getFunctionsTest, validNameCheck) {
    EXPECT_TRUE(isValidName("karol"));
    EXPECT_FALSE(isValidName(""));
    EXPECT_FALSE(isValidName("thisismorethat35wordsidontwantthisinputtobevalidtoolong"));
}


int main(int argc,char**argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}