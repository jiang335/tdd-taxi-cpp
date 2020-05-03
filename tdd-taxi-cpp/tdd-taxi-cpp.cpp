#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>
#include <regex>

using namespace std;

double calcCostByKilpMetre(int kiloMetre)
{
	double result = 0;
	if (kiloMetre > 0) {
		result = 6;
		if (kiloMetre > 2) {
			result += 0.8 * (kiloMetre - 2);
			if (kiloMetre > 8)
				result += 0.8 * 0.5 * (kiloMetre - 8);
		}
	}
	return result;
}

double calcCostByMinutes(int minutes)
{
	double result = 0;
	if (minutes > 0) {
		result = 0.25 * minutes;
	}
	return result;
}

int calcCost(int kiloMetre, int minutes)
{
	return int(calcCostByKilpMetre(kiloMetre) + calcCostByMinutes(minutes) + 0.5);
}

wstring procLineGDK(wstring wstrLine)
{
	wregex pattern(L"(\\d{1,})公里,等待(\\d{1,})分钟");
	wcmatch results;
	if (regex_match(wstrLine.c_str(), results, pattern))
		return L"收费" + to_wstring(calcCost(stoi(results[1]), stoi(results[2]))) + L"元";
	return L"";
}

string procLineUTF8(const string strLine)
{
	wstring_convert<codecvt_utf8<wchar_t>> wstrConvert;
	wstring ret = procLineGDK(wstrConvert.from_bytes(strLine));
	return wstrConvert.to_bytes(ret);
}

void procFile(const char* fileName)
{
	ifstream inFile(fileName);
	ostringstream receipt;
	while (!inFile.eof()) {
		char strLine[256];
		inFile.getline(strLine, sizeof(strLine) / sizeof(strLine[0]));
		receipt << procLineUTF8(strLine) << "\n";
	}
	inFile.close();
}

void main(int argc, char* argv[])
{
	if (argc < 2)
		return;
	try {
		procFile(argv[1]);
	}
	catch (const exception err) {
		cerr << err.what() << endl;
	}
}
