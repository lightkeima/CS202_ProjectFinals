#include <iostream>
#include <conio.h>
#include <thread>
#include "HeaderFile/game.h"
#include "HeaderFile/menu.h"
using namespace std;
Draw a;
int startScreen() {
	a.cursorPosition(20, 0);
	//a.changeFontSize(30);
	a.setTextColor(GREEN);
	cout << "========================================================================";
	a.cursorPosition(20, 1);
	cout << '"';
	a.setTextColor(PURPLE);
	cout << "  CCCC    A    RRRR    DDDD   OOOO  DDDD   GGGG   IIII NN   N  GGGG   ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 2);
	cout << '"';
	a.setTextColor(15);
	cout << " C       A A   R   R   D   D O    O D   D G        II  N N  N G       ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 3);
	cout << '"';
	a.setTextColor(BLUE);
	cout << " C      AAAAA  RRRR    D   D O    O D   D G   GGG  II  N   NN G   GGG ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 4);
	cout << '"';
	a.setTextColor(YELLOW);
	cout << "  CCCC A     A R   R   DDDD   OOOO  DDDD   GGGG   IIII N    N  GGGG   ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 5);
	cout << "========================================================================";
	a.drawDino(37, 9);
	a.drawHuman(64, 12);
	a.drawCar(41, 12,RIGHT);
	a.drawTruck(54, 12, RIGHT);
	a.drawBird(66, 7,LEFT);
	a.drawBird(68, 8, LEFT);
	a.setTextColor(GREEN);
	a.cursorPosition(20, 13);
	a.cursorPosition(20, 14);
	a.setTextColor(BLUE);
	cout << "#########################################################################";
	a.cursorPosition(20, 15);
	a.setTextColor(YELLOW);
	cout << "|Nguyen Truong Vinh Thuyen";
	a.cursorPosition(20, 16);
	cout << "|Nguyen Thi Kim Phuong";
	a.cursorPosition(20, 17);
	cout << "|Nguyen Hoang Tan";
	a.cursorPosition(20, 18);
	cout << "|Tran Trieu Thanh";
	vector<string> item;
	item.push_back("|New game|");
	item.push_back("|Load game|");
	item.push_back("|Setting|");
	item.push_back("|Exit|");
	Menu menu(item,49,7,WHITE,BLUE);
	return menu.runMenu();
}
int main() {
	system("color 07");
	a.FixConsoleWindow();
	a.ShowConsoleCursor(invisible);
	int check = startScreen();
	if (check == 3) exit(0);
	//system("pause");
	Player player("Test", 10);
	vector<mObject*> obj;
	obj.push_back(new Bird(RIGHT, 3));
	obj.push_back(new Dino(RIGHT, 15));
	obj.push_back(new Truck(RIGHT, 79));
	vector<mObject*> obj1;
	obj1.push_back(new Truck(LEFT, 30));
	obj1.push_back(new Car(LEFT, 50));
	obj1.push_back(new Bird(LEFT, 4));
	vector<mObject*> obj2;
	Lane lane0(obj2, RIGHT, 100, NULL);
	Lane lane(obj, RIGHT, 100, NULL);
	Lane lane1(obj1, LEFT, 200, NULL);
	Lane lane3(obj2, RIGHT, 100, &player);

	vector<Lane*> l;
	l.push_back(&lane0);
	l.push_back(&lane);
	l.push_back(&lane1);
	l.push_back(&lane);
	l.push_back(&lane1);
	l.push_back(&lane1);
	l.push_back(&lane3);
	vector<Level> level;
	level.push_back(l);
	Game game(&player, level, 0);
	game.playing(0);
	system("pause");
	return 0;
}