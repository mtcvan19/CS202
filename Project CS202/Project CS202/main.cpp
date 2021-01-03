#include "CGame.h"
#include <Windows.h>

bool IS_RUNNING = true;
char MOVING;
CGame game;
int level = 5;

void exitGame(thread* t)
{
	system("cls");
	IS_RUNNING = false;
	t->join();
}

void ThreadFunc1()
{
	//while (1)
	//{
	GotoXY(0, 2);
	cout << "MOVING thread = " << MOVING << endl;
		game.startGame(level, MOVING);
		//system("pause");
	//}
}


int main()
{
	Menu(game);
	thread t1(ThreadFunc1);
	//int temp;
	char temp;
	while (1)
	{
		//if (_kbhit()) {
			//temp = toupper(_getch());
			temp = _getch();
			if (game.getPeople().isDead())
			{
				if (temp == 27)
				{
					game.exitGame(t1.native_handle());
					return 0;
				}
				else if (temp == 'P' || temp == 'p')
				{
					game.pauseGame(t1.native_handle());
				}
				else
				{
					MOVING = temp;
					GotoXY(20, 0);
					cout << "MOVING resume = " << MOVING << endl;
					//system("pause");
					game.resumeGame(t1.native_handle());
					MOVING = temp; //Cập nhật bước di chuyển
					GotoXY(50, 0);
					cout << "MOVING resume 2 = " << MOVING << endl;
				}
			}
			else
			{
				if (temp == 'Y' || temp == 'y')
					game.startGame(level, ' ');
				else
				{
					game.exitGame(t1.native_handle());
					return 0;
				}
			}
		//}
	}

	/*
	thread t1(ThreadFunc1);
	while (1)
	{
		int temp = toupper(getch());
		if (temp == 27)
		{
			exitGame(&t1);
			return 0;
		}
	}
	*/

	/*
	thread key(&CGame::checkKeyBoard, CGame());
	//thread process(Menu);
	Menu();
	key.join();
	//process.join();
	system("pause");
	*/

	/*
	time_t t = time(0);
	tm* Check = localtime(&t);
	cout << Check->tm_sec << endl;
	for (int i = 0; i < 2; ++i) {
		Sleep(2000);
	}
	t = time(0);
	Check = localtime(&t);
	cout << Check->tm_sec << endl;
	*/



	return 0;
}
       