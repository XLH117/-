#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Menu
{
public:
	string name; int price; int calories;

	Menu(const string name, int price, int calories) : name(name), price(price), calories(calories) {}
};

class OrderSystem
{
public:
	vector<Menu> menu;
	vector<Menu> order;

	void loadMenu()
	{
		ifstream infile("menu.txt");
		string name;
		int price, calories;

		while (infile >> name >> price >> calories)
		{
			Menu s(name, price, calories);
			menu.push_back(s);
		}
	}

	void showMenu()
	{
		int number = 1;

		cout << "---Menu---\n";
		for (const auto& a : menu)
		{
			cout << number++ << "." << a.name << "(" << a.price << "��," << a.calories << " kcal)\n";
		}
	}

	void takeOrder()
	{
		int orderNum;

		while (true)
		{
			cout << "���Ť���������ע�Ĥ��Ƥ�������(ע�Ĥ��K��ä���0���������Ƥ�������)\n";
			cin >> orderNum;
			if (orderNum == 0) break;
			if (orderNum >= 1 && orderNum <= menu.size())
			{
				order.push_back(menu[orderNum - 1]);
			}
			else
			{
				cout << "�o���ʷ��ŤǤ����⤦һ���������Ƥ���������\n";
			}
		}
	}

	void check()
	{
		int totalPrice = 0, totalCal = 0;

		cout << "\n���ʤ���ע�ģ�\n";

		for (const auto& a : order)
		{
			cout << "-" << a.name << "(" << a.price << "��," << a.calories << " kcal)\n";

			totalPrice += a.price;
			totalCal += a.calories;
		}

		cout << "\n��Ӌ���~��" << totalPrice << "��\n" << "��Ӌ�����`��" << totalCal << "kcal\n";
	}
};

int main()
{
	OrderSystem s;
	s.loadMenu();
	s.showMenu();
	s.takeOrder();
	s.check();
	return 0;
}