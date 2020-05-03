#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>
#include <regex>

#include "calccost.h"

using namespace std;

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
	return wstrConvert.to_bytes(procLineGDK(wstrConvert.from_bytes(strLine)));
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
