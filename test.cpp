#include "pch.h"
#include "../lab_5_for_unique/Functions.cpp"
TEST(UList, Ugetters) {
	UList a;
	EXPECT_EQ(a.getFirstEl(), 0);
	EXPECT_EQ(a.getLastEl(), 0);
	EXPECT_EQ(a.getNumOfEl(), 0);
	vector<double> test = { 5.7, 34, 0.4, 23.3, 5.4 };
	UList b(test);
	EXPECT_EQ(b.getFirstEl(), 5.7);
	EXPECT_EQ(b.getLastEl(), 5.4);
	EXPECT_EQ(b.getNumOfEl(), 5);
	a = b;
	EXPECT_EQ(a.getFirstEl(), 5.7);
	EXPECT_EQ(a.getLastEl(), 5.4);
	EXPECT_EQ(a.getNumOfEl(), 5);

}
TEST(UList, UfindValue) {
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> test1 = { 0.1 , 34, 0.4, 6.5, 5.6, 23.3, 38.4 };
	UList b(test);
	UList c(test1);
	EXPECT_EQ(a.findMax(), NULL);
	EXPECT_EQ(b.findMax(), 40.3);
	EXPECT_EQ(c.findMax(), 38.4);
	EXPECT_EQ(a.findMin(), NULL);
	EXPECT_EQ(b.findMin(), 0.1);
	EXPECT_EQ(c.findMin(), 0.1);
	EXPECT_EQ(a.findAVG(), NULL);
	EXPECT_NEAR(b.findAVG(), 19.62, 0.01);
	EXPECT_NEAR(c.findAVG(), 15.47, 0.01);
}
TEST(UList, Usorting) {
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 40.3, 34, 23.3, 0.4, 0.1 };
	vector<double> expected1_2 = { 0.1, 0.4, 23.3, 34, 40.3 };
	UList b(test);
	EXPECT_NO_THROW(a.choiceSort());
	EXPECT_NO_THROW(a.choiceSort());
	b.choiceSort();
	for (int i = 0; i < b.getNumOfEl(); i++)
	{
		EXPECT_EQ(b[i], expected1_1[i]);
	}
	b.bubbleSort();
	for (int i = 0; i < b.getNumOfEl(); i++)
	{
		EXPECT_EQ(b[i], expected1_2[i]);
	}

}

TEST(UList, Uskalyar)
{
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 0, 0, 0, 0, 0 };
	vector<double> expected1_2 = { 20.15, 17, 0.2, 11.65, 0.05 };
	vector<double> expected1_3 = { 4030, 3400, 40, 2330, 10 };
	UList b(test);
	a = b;
	b.skalyar(0);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_1[i], 0.01);
	}
	b = a;
	b.skalyar(0.5);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_2[i], 0.01);
	}
	b = a;
	b.skalyar(100);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_3[i], 0.01);
	}
}
TEST(operator, UplusAndMinus)
{
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 40.3, 34, 0.4, 23.3, 0.1, 5.3, 0.2 };
	vector<double> expected1_2 = { 40.3, 34, 0.4 };
	UList b(test);
	EXPECT_NO_THROW(a.operator-());
	EXPECT_NO_THROW(a.operator+(5.3));
	EXPECT_EQ(a[0], 5.3);
	a.operator+(4.3);
	a.operator-();
	a.operator-();
	EXPECT_NO_THROW(a.operator-());
	b.operator+(5.3);
	b.operator+(0.2);
	for (int i = 0; i < expected1_1.size(); i++) {
		EXPECT_EQ(b[i], expected1_1[i]);
	}
	b.operator-();
	b.operator-();
	b.operator-();
	b.operator-();
	for (int i = 0; i < expected1_2.size(); i++) {
		EXPECT_EQ(b[i], expected1_2[i]);
	}
}
TEST(operator, Uequal)
{
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> test1 = { 4.3, 5.6, 1.3 };
	UList b(test); UList c(test1);
	a = b;
	for (int i = 0; i < a.getNumOfEl(); i++) {
		EXPECT_EQ(b[i], a[i]);
	}
	b = c;
	a = move(c);
	for (int i = 0; i < a.getNumOfEl(); i++) {
		EXPECT_EQ(b[i], a[i]);
	}
	EXPECT_EQ(c.getNumOfEl(), 0);
	EXPECT_EQ(a[2], 1.3);
	EXPECT_TRUE(a[6]);
}
TEST(UList, Uoutput) {
	ostringstream out;
	UList a;
	out << a;
	EXPECT_EQ("\n", out.str());
	std::ostringstream out1;
	vector<double> test = { 40.3, 34, 0.4 };
	UList b(test);
	out1 << b;
	EXPECT_EQ("40.3 34 0.4 \n", out1.str());
}
TEST(UList, Uinput)
{
	UList test;
	istringstream input("3\n1.2\n3.4\n-5.6\n");
	input >> test;
	EXPECT_EQ(test.getNumOfEl(), 3);
	EXPECT_EQ(test[0], 1.2);
	EXPECT_EQ(test[1], 3.4);
	EXPECT_EQ(test[2], -5.6);
}
