#include<iostream>
#include<string>
#include<vector>
#include <regex>
#include"h1.h"
#include"json/json.h"


int main()
{
	smatch result1, result2;
	regex pattern1("\\d{11}"), pattern2("(.*)省(.*)市(.*)区");

	Json::Value root;
	Json::Value temp;

	Json::FastWriter writer;
	string all[10], tel[10], name[10], address[10];
	area areas[10];
	for (int i = 0; i < 5; i++)
	{
		cin >> all[i];
	}
	for (int i = 0; i < 5; i++)
	{
		int count = 0, j = 0, len, pos;
		pos = all[i].find(',');
		name[i] = all[i].substr(0, pos);
		address[i] = all[i].substr(pos + 1);
		regex_search(address[i], result1, pattern1);
		tel[i] = result1[0];
		areas[i] = divide_address(regex_replace(address[i], pattern1, ""));
		temp["姓名"] = name[i];
		temp["手机"] = tel[i];
		Json::Value dizhi;
		dizhi.append(areas[i].province); dizhi.append(areas[i].city); dizhi.append(areas[i].district); dizhi.append(areas[i].town); dizhi.append( areas[i].street);
		temp["地址"] = dizhi;
		root.append(temp);
	}

	cout << root.toStyledString();
}
