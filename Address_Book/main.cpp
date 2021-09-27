#include <string>
#include <iostream>
#include <stdio.h>
#define MAX 1000
using namespace std;

struct Peoson
{
	string Name;
	int Sex;//性别：男=1 女=0
	string  Phone;
	string  Address;
};
struct Addressbooks
{
	struct Peoson peosonArray[MAX];
	int actualSize = 0;
};
//显示功能菜单//
void show_Menu()
{
	cout << "1、新增联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、查找联系人" << endl;
	cout << "4、清空通讯录" << endl;
	cout << "0、退出通讯录" << endl;
}
//新增联系人功能//
void new_Address(Addressbooks* user)
{
	system("cls");//窗口清屏
	if (user->actualSize >= MAX)
	{
		cout << "通讯录数据已满，无法添加" << endl;
	}
	else
	{
		string stemp;
		int sex;

		cout << "请输入姓名" << endl;
		cin >> stemp;
		user->peosonArray[user->actualSize].Name = stemp;
		system("cls");
		cout << "请输入性别" << endl;
		cout << "1、男 2、女" << endl;
	resex01:
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			user->peosonArray[user->actualSize].Sex = sex;
			system("cls");
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			goto resex01;
		}

		cout << "请输入电话号码" << endl;
		cin >> stemp;
		user->peosonArray[user->actualSize].Phone = stemp;
		system("cls");
		cout << "请输入地址" << endl;
		cin >> stemp;
		user->peosonArray[user->actualSize].Address = stemp;
		user->actualSize++;
		system("cls");
	}



}
//修改联系人信息
void change_Information(int chooseCount, Addressbooks* user)
{
	int chooseChange;
	string stemp;
	int sex;
		cout << "选择需要修改的信息"
		<< "1、姓名"
		<< "2、性别"
		<< "3、号码"
		<< "4、地址"
		<< endl;
	cin >> chooseChange;
	if (chooseChange <= 4 && chooseChange >= 1)
	{
		switch (chooseChange)
		{
		case 1:
			cout << "请输入需要修改的姓名" << endl;
			cin >> stemp;
			user->peosonArray[chooseCount - 1].Name = stemp;
			break;
		case 2:
			cout << "请输入需要修改的性别"
				<< "1、男         2、女"
				<< endl;
		resex02:
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				user->peosonArray[chooseCount - 1].Sex = sex;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				goto resex02;

			}

		case 3:
			cout << "请输入需要修改的号码" << endl;
			cin >> stemp;
			user->peosonArray[chooseCount - 1].Phone= stemp;
			break;

		case 4:
			cout << "请输入需要修改的地址" << endl;
			cin >> stemp;
			user->peosonArray[chooseCount - 1].Address = stemp;
			break;

		default:
			break;
		}

	}
	else cout << "输入错误，请重新输入" << endl;

}
//删除联系人
void delete_Peoson(int choosecount, Addressbooks* user)
{

		for (; choosecount <= user->actualSize; choosecount++)
		{
			user->peosonArray[choosecount - 1] = user->peosonArray[choosecount];
		}
		user->actualSize--;

}
//选择联系人进行查看，功能作用与查看联系人目录下
void choose_Peoson(int chooseCount, Addressbooks* user)
{
	int choosedeep;
	string sex;
	if (user->peosonArray[chooseCount - 1].Sex == 1)
	{
		sex = "男";
	}
	else sex = "女";
	cout
		<< "  联系人姓名：" << user->peosonArray[chooseCount - 1].Name
		<< "\n  联系人性别：" << sex
		<< "\n  联系人号码：" << user->peosonArray[chooseCount - 1].Phone
		<< "\n  联系人地址：" << user->peosonArray[chooseCount - 1].Address
		<< endl;
	cout << "\n0:返回    1:修改   2：删除" << endl;
rechoose:
	cin >> choosedeep;
	if (choosedeep >= 0 && choosedeep <= 2)
	{
		system("cls");
		switch (choosedeep)
		{
		case 0:break;
		case 1:change_Information(chooseCount, user); break;
		case 2:delete_Peoson(chooseCount,user); break;
		}
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		goto rechoose;
	}
}
//查看联系人目录
void dis_Addressbook(Addressbooks* user)
{
	int choose_count;
	system("cls");
	if (user->actualSize == 0)
	{
		cout << "***你没有朋友的吗？***" << endl;
	}
	else
	{
		cout << "共有" << user->actualSize << "位联系人" << endl;
		for (int i = 0, j = 1; i < user->actualSize; j++, i++)
		{

			cout << j << "、" << user->peosonArray[i].Name << endl;

		}
		cout << "\n数字选择       按0返回" << endl;
		cin >> choose_count;
		if (choose_count != 0)
		{
			system("cls");
			choose_Peoson(choose_count, user);

		}

	}

}

//主函数//
int main()
{
	Addressbooks user;
	int function_count;

	while (1) {
		show_Menu();
		scanf_s("%d", &function_count);
		switch (function_count)
		{
		case 1:new_Address(&user); break;
		case 2:dis_Addressbook(&user); break;
		case 3:break;//查找联系人
		case 4:break;//清空通讯录
		case 0:printf("欢迎下次使用");
			system("pause");
			return 0;
			break;
		default:printf("输入错误，请重新输入");
			break;
		}
	}
}