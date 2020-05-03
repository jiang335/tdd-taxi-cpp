#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

extern double calcCostByKilpMetre(int kiloMetre);
extern double calcCostByMinutes(int minutes);
extern int calcCost(int kiloMetre, int minutes);
extern wstring procLineGDK(wstring wstrLine);

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(KilpMetre)
		{
			Assert::AreEqual(calcCostByKilpMetre(-1), 0.0);
			Assert::AreEqual(calcCostByKilpMetre(0), 0.0);
			Assert::AreEqual(calcCostByKilpMetre(1), 6.0);
			Assert::AreEqual(calcCostByKilpMetre(2), 6.0);
			Assert::AreEqual(calcCostByKilpMetre(4), 7.6);
			Assert::AreEqual(calcCostByKilpMetre(8), 10.8);
			Assert::AreEqual(calcCostByKilpMetre(10), 13.2);
		}
		TEST_METHOD(Minutes)
		{
			Assert::AreEqual(calcCostByMinutes(-1), 0.0);
			Assert::AreEqual(calcCostByMinutes(0), 0.0);
			Assert::AreEqual(calcCostByMinutes(2), 0.5);
		}
		TEST_METHOD(Cost)
		{
			Assert::AreEqual(calcCost(1, 0), 6);
			Assert::AreEqual(calcCost(3, 0), 7);
			Assert::AreEqual(calcCost(10, 0), 13);
			Assert::AreEqual(calcCost(2, 3), 7);
		}
		TEST_METHOD(Line)
		{
			Assert::AreEqual(procLineGDK(L"1公里,等待0分钟").c_str(), L"收费6元");
			Assert::AreEqual(procLineGDK(L"3公里,等待0分钟").c_str(), L"收费7元");
			Assert::AreEqual(procLineGDK(L"10公里,等待0分钟").c_str(), L"收费13元");
			Assert::AreEqual(procLineGDK(L"2公里,等待3分钟").c_str(), L"收费7元");
		}
	};
}
