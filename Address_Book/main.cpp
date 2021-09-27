#include <string>
#include <iostream>
#include <stdio.h>
#define MAX 1000
using namespace std;

struct Peoson
{
	string Name;
	int Sex;//�Ա���=1 Ů=0
	string  Phone;
	string  Address;
};
struct Addressbooks
{
	struct Peoson peosonArray[MAX];
	int actualSize = 0;
};
//��ʾ���ܲ˵�//
void show_Menu()
{
	cout << "1��������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��������ϵ��" << endl;
	cout << "4�����ͨѶ¼" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}
//������ϵ�˹���//
void new_Address(Addressbooks* user)
{
	system("cls");//��������
	if (user->actualSize >= MAX)
	{
		cout << "ͨѶ¼�����������޷����" << endl;
	}
	else
	{
		string stemp;
		int sex;

		cout << "����������" << endl;
		cin >> stemp;
		user->peosonArray[user->actualSize].Name = stemp;
		system("cls");
		cout << "�������Ա�" << endl;
		cout << "1���� 2��Ů" << endl;
	resex01:
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			user->peosonArray[user->actualSize].Sex = sex;
			system("cls");
		}
		else
		{
			cout << "�����������������" << endl;
			goto resex01;
		}

		cout << "������绰����" << endl;
		cin >> stemp;
		user->peosonArray[user->actualSize].Phone = stemp;
		system("cls");
		cout << "�������ַ" << endl;
		cin >> stemp;
		user->peosonArray[user->actualSize].Address = stemp;
		user->actualSize++;
		system("cls");
	}



}
//�޸���ϵ����Ϣ
void change_Information(int chooseCount, Addressbooks* user)
{
	int chooseChange;
	string stemp;
	int sex;
		cout << "ѡ����Ҫ�޸ĵ���Ϣ"
		<< "1������"
		<< "2���Ա�"
		<< "3������"
		<< "4����ַ"
		<< endl;
	cin >> chooseChange;
	if (chooseChange <= 4 && chooseChange >= 1)
	{
		switch (chooseChange)
		{
		case 1:
			cout << "��������Ҫ�޸ĵ�����" << endl;
			cin >> stemp;
			user->peosonArray[chooseCount - 1].Name = stemp;
			break;
		case 2:
			cout << "��������Ҫ�޸ĵ��Ա�"
				<< "1����         2��Ů"
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
				cout << "�����������������" << endl;
				goto resex02;

			}

		case 3:
			cout << "��������Ҫ�޸ĵĺ���" << endl;
			cin >> stemp;
			user->peosonArray[chooseCount - 1].Phone= stemp;
			break;

		case 4:
			cout << "��������Ҫ�޸ĵĵ�ַ" << endl;
			cin >> stemp;
			user->peosonArray[chooseCount - 1].Address = stemp;
			break;

		default:
			break;
		}

	}
	else cout << "�����������������" << endl;

}
//ɾ����ϵ��
void delete_Peoson(int choosecount, Addressbooks* user)
{

		for (; choosecount <= user->actualSize; choosecount++)
		{
			user->peosonArray[choosecount - 1] = user->peosonArray[choosecount];
		}
		user->actualSize--;

}
//ѡ����ϵ�˽��в鿴������������鿴��ϵ��Ŀ¼��
void choose_Peoson(int chooseCount, Addressbooks* user)
{
	int choosedeep;
	string sex;
	if (user->peosonArray[chooseCount - 1].Sex == 1)
	{
		sex = "��";
	}
	else sex = "Ů";
	cout
		<< "  ��ϵ��������" << user->peosonArray[chooseCount - 1].Name
		<< "\n  ��ϵ���Ա�" << sex
		<< "\n  ��ϵ�˺��룺" << user->peosonArray[chooseCount - 1].Phone
		<< "\n  ��ϵ�˵�ַ��" << user->peosonArray[chooseCount - 1].Address
		<< endl;
	cout << "\n0:����    1:�޸�   2��ɾ��" << endl;
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
		cout << "�����������������" << endl;
		goto rechoose;
	}
}
//�鿴��ϵ��Ŀ¼
void dis_Addressbook(Addressbooks* user)
{
	int choose_count;
	system("cls");
	if (user->actualSize == 0)
	{
		cout << "***��û�����ѵ���***" << endl;
	}
	else
	{
		cout << "����" << user->actualSize << "λ��ϵ��" << endl;
		for (int i = 0, j = 1; i < user->actualSize; j++, i++)
		{

			cout << j << "��" << user->peosonArray[i].Name << endl;

		}
		cout << "\n����ѡ��       ��0����" << endl;
		cin >> choose_count;
		if (choose_count != 0)
		{
			system("cls");
			choose_Peoson(choose_count, user);

		}

	}

}

//������//
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
		case 3:break;//������ϵ��
		case 4:break;//���ͨѶ¼
		case 0:printf("��ӭ�´�ʹ��");
			system("pause");
			return 0;
			break;
		default:printf("�����������������");
			break;
		}
	}
}