#include<iostream>
#include<string>
#include<vector>
#include <regex>
#include <fstream>
#include <ostream>
#include"h1.h"
//#include"json/json.h"

void jsonout(int c, area a);

int main()
{
	ifstream ifile;     //说明输入文件流对象ifile    
	ofstream ofile;     //说明输出文件流对象ofile
	ifile.open("1.txt");
	ofile.open("2.txt");
	smatch result1, result2;
	regex pattern1("\\d{11}"), pattern2("(.*)省(.*)市(.*)区");
	string json;
	//Json::Value root;
	//Json::Value temp;
	vector<string> address, tel, name,all;
	vector<area> areas;
	string line,temp;
	int count=0;
	while (getline(ifile, line))
	{
		count++;
		all.push_back(line);
		cout << all[count-1]<<endl;
	}
	ofile <<'['<<endl;
	cout << '['<<endl;
	for (int i = 0; i < count; i++)
	{
		int count = 0, j = 0, len, pos;
		pos = all[i].find(',');
		name.push_back(all[i].substr(2, pos-2));
		address.push_back(all[i].substr(pos + 1));
		regex_search(address[i], result1, pattern1);
		tel.push_back(result1[0]);
		temp = regex_replace(address[i], pattern1, "");
		temp =temp.substr(0,temp.length() - 1);
		if (all[i][0] == '1')
		{
			areas.push_back(divide_address_5(temp));
			json = "{\"姓名\":\"" + name[i] + "\",\"手机\":\"" + tel[i] + "\",\"地址\":[\"" + areas[i].province + "\",\"" + areas[i].city + "\",\"" + areas[i].district + "\",\"" + areas[i].town + "\",\"" + areas[i].street + "\"]}";
			ofile<< json<<endl;
			cout << json<<endl;
		}
		else if (all[i][0] == '2')
		{
			areas.push_back(divide_address_7(temp));
			json = "{\"姓名\":\"" + name[i] + "\",\"手机\":\"" + tel[i] + "\",\"地址\":[\"" + areas[i].province + "\",\"" + areas[i].city + "\",\"" + areas[i].district + "\",\"" + areas[i].town + "\",\"" + areas[i].street + "\",\"" + areas[i].t1 + "\",\"" + areas[i].t2 + "\"]}";
			ofile << json << endl;
			cout << json << endl;
		}
		else
		{
			
			areas.push_back(divide_address_7(temp));
			json = "{\"姓名\":\"" + name[i] + "\",\"手机\":\"" + tel[i] + "\",\"地址\":[\"" + areas[i].province + "\",\"" + areas[i].city + "\",\"" + areas[i].district + "\",\"" + areas[i].town + "\",\"" + areas[i].street + "\",\"" + areas[i].t1 + "\",\"" + areas[i].t2 + "\"]}";
			ofile << json << endl;
			cout << json << endl;
		}
		
		//temp["姓名"] = name[i];
		//temp["手机"] = tel[i];
		//Json::Value dizhi;
		//dizhi.append(areas[i].province); dizhi.append(areas[i].city); dizhi.append(areas[i].district); dizhi.append(areas[i].town); dizhi.append( areas[i].street);
		//temp["地址"] = dizhi;
		//root.append(temp);
	
	
	}
	//ofile<< root.toStyledString();
	//cout << root.toStyledString();
	ofile << ']' ;
	cout << ']';
	ifile.close();
	ofile.close();
}
void jsonout(int c,area a)
{
	if (c == 5)
	{
		c=5;
	}
}