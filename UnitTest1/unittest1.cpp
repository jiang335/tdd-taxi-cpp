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
			Assert::AreEqual(fabs(calcCostByKilpMetre(-1) - 0) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByKilpMetre(0) - 0) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByKilpMetre(1) - 6) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByKilpMetre(2) - 6) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByKilpMetre(4) - 7.6) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByKilpMetre(8) - 10.8) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByKilpMetre(10) - 13.2) < 0.001, true);
		}
		TEST_METHOD(Minutes)
		{
			Assert::AreEqual(fabs(calcCostByMinutes(-1) - 0.0) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByMinutes(0) - 0.0) < 0.001, true);
			Assert::AreEqual(fabs(calcCostByMinutes(2) - 0.5) < 0.001, true);
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
			Assert::AreEqual(procLineGDK(L"1����,�ȴ�0����").c_str(), L"�շ�6Ԫ");
			Assert::AreEqual(procLineGDK(L"3����,�ȴ�0����").c_str(), L"�շ�7Ԫ");
			Assert::AreEqual(procLineGDK(L"10����,�ȴ�0����").c_str(), L"�շ�13Ԫ");
			Assert::AreEqual(procLineGDK(L"2����,�ȴ�3����").c_str(), L"�շ�7Ԫ");
		}
	};
}
