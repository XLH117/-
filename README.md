ソースコード：

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
			cout << number++ << "." << a.name << "(" << a.price << "円," << a.calories << " kcal)\n";
		}
	}
	void takeOrder()
	{
		int orderNum;
		while (true)
		{
			cout << "番号を入力して注文してください(注文し終わったら0を入力してください)\n";
			cin >> orderNum;
			if (orderNum == 0) break;
			if(orderNum >= 1 && orderNum <= menu.size())
			{
				order.push_back(menu[orderNum - 1]);
			}
			else
			{
				cout << "無効な番号です。もう一回入力してください。\n";
			}
		}
	}
	void check()
	{
		int totalPrice = 0, totalCal = 0;
		cout << "\nあなたの注文：\n";
		for (const auto& a : order)
		{
			cout << "-" << a.name << "(" << a.price << "円," << a.calories << " kcal)\n";
			totalPrice += a.price;
			totalCal += a.calories;
		}
		cout << "\n合計金額：" << totalPrice << "円\n" << "合計カロリー：" << totalCal << "kcal\n";
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



/*
メニューのテキストファイル menu.txt に以下の内容を記入した：

オムライス 850 650
カレーライス 700 550
サラダ 400 120
スープ 300 90
*/
