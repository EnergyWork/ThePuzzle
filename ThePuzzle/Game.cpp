#include <iostream>
#include <algorithm> 
#include <iomanip>
using namespace std;

enum class Direction
{
	LEFT, RIGHT, TOP, BOTTOM
};

class Game
{
private:
	uint16_t field[4][4];
	uint16_t row, column;

	void fix()
	{
		// �������� ���-�� ��������
		uint32_t inversions = 0;
		for (uint16_t i = 0; i < 14; i++) // �� 14, ��� �� ��� ���������� ����� ��� ������ ���������
		{
			uint16_t tmp = field[i % 4][i / 4];
			for (uint16_t j = i + 1; j < 15; j++)
			{
				if (tmp > field[j % 4][j / 4])
					inversions++;
			}
		}
		// ���� ��������, �� ������� ���� ��������� ��������, ��� ������ �������� ��������
		if (inversions % 2 == 1)
		{
			swap(field[3][1], field[3][2]);
		}
	}
public:
	Game()
	{
		row = 3;
		column = 3;
		for (size_t i = 0; i < 4; i++)
			for (size_t j = 0; j < 4; j++)
				field[i][j] = 0;
	}
	~Game()
	{
		
	}

	void create_field()
	{
		// ����� ����� � �������� �������� ��� �� ����
		for (uint16_t num = 1; num <= 15; num++)
		{
			bool ok = false; // ���� ����, ��� ����� ������� ���������
			while (!ok)
			{
				uint16_t cell = rand() % 15; // ����� ������������ ��������� ������ �� 0 �� 14, ����� ������� ������ ���� ������ ��������� "������"
				if (field[cell % 4][cell / 4] == 0)
				{
					ok = true;
					field[cell % 4][cell / 4] = num;
				}
			}
		}
		fix();
	}
	bool is_solved()
	{
		for (uint16_t i = 0; i < 15; i++)
		{
			if (field[i % 4][i / 4] != i + 1)
				return false;
		}
		return true;
	}
	void move(Direction dir)
	{
		switch (dir)
		{
		case Direction::LEFT:
			if (column < 3)
			{
				field[row][column] = field[row][column + 1];
				field[row][column + 1] = 0;
				column += 1;
			}
			break;
		case Direction::RIGHT:
			if (column > 0)
			{
				field[row][column] = field[row][column - 1];
				field[row][column - 1] = 0;
				column -= 1;
			}
			break;
		case Direction::TOP:
			if (row < 3)
			{
				field[row][column] = field[row + 1][column];
				field[row + 1][column] = 0;
				row += 1;
			}
			break;
		case Direction::BOTTOM:
			if (row > 0)
			{
				field[row][column] = field[row - 1][column];
				field[row - 1][column] = 0;
				row -= 1;
			}
			break;
		}
	}
	void draw_field()
	{
		system("cls");
		for (uint16_t i = 0; i < 4; i++)
		{
			for (uint16_t j = 0; j < 4; j++)
			{
				if (field[i][j] == 0)
					cout << "  " << setw(3);
				else
					cout << field[i][j] << setw(3);
			}
			cout << endl;
		}
	}
};