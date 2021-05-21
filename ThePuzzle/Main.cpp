#include <iostream>
#include <conio.h>
#include <time.h>
#include "Game.cpp"

int main()
{
	srand(time(NULL));
	char key;
	Game* puzzle = new Game();
	puzzle->create_field();
	puzzle->draw_field();
	while (!puzzle->is_solved())
	{
		key = _getch();
		switch (key)
		{
		case 56:
			puzzle->move(Direction::TOP); 
			break;
		case 50:
			puzzle->move(Direction::BOTTOM);
			break;
		case 54:
			puzzle->move(Direction::RIGHT);
			break;
		case 52:
			puzzle->move(Direction::LEFT);
			break;
		case 27:
			return 0;
		}
		puzzle->draw_field();
	}
	cout << "Пазл собран!" << endl;
	system("pause");
}