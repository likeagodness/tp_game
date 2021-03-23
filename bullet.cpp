#include <iostream>	
#include <bullet.h>
#include <map.h>

bullet::bullet(const float x, const float y, const char owner, const int bdir) : present(false), b_x(x), b_y(y), b_dx(0), b_dy(0), owner(owner)
									//����������� ������������ - �������� � ���� ��������� ���������� ����, ����������� �������� � ����, ��� � ���������
									//������������� ���������� �� ����� �� ���������, ���������� ���������
{
	switch (owner) //���� ��������:
	{
	case 'p': //�����, �� 
		std::cout << "Player "; //������� � ������� ��������������� ���������
		break;
	case 'e': //����, ��
		std::cout << "Enemy "; //������� � ������� ��������������� ���������
		break;
	}
	std::cout << "launched bullet\n"; //������� ������� ���������
	BDIR b_dir(static_cast<BDIR>(bdir)); //����������� ���������� ����������-����������� � ��� ����������
	b_Texture.loadFromFile("Textures/bullet.png"); //��������� �������� �� ����� � ����� Textures bullet.png
	b_Sprite.setTexture(b_Texture); //������������� ��������
	b_Sprite.setPosition(x, y); //������������� ��������� ���� �� ���������� �����������
}

bullet::~bullet() //����������� �����������
{
	switch (owner) //���� ��������:
	{
	case 'p': //�����, ��
		std::cout << "Player's "; //������� � ������� ��������������� ���������
		break;
	case 'e': //����, ��
		std::cout << "Enemy's "; //������� � ������� ��������������� ���������
		break;
	}
	std::cout << "bullet destroyed\n"; //������� ������� ���������, ��� �������� �������� �������
}

void bullet::move(const sf::Int64 time) //����������� �������-����������� ����
{
	switch (b_dir) //���� ���� ����������:
	{
	case right: //������, ��
		b_dx = 0.3; //���������� ���������� �� x ����� 0.3
		b_dy = 0;
		break;

	case left: //�����, ��
		b_dx = -0.3; //���������� ���������� �� x ����� -0.3
		b_dy = 0;
		break;

	case up: //������, ��
		b_dx = 0;
		b_dy = 0.3; //���������� ���������� �� y ����� 0.3
		break;

	case down: //������, ��
		b_dx = 0;
		b_dy = -0.3; //���������� ���������� �� y ����� -0.3
		break;
	}

	b_x += b_dx * time; //��������� ���������� x
	b_y += b_dy * time; //��������� ���������� y
	b_Sprite.setPosition(b_x, b_y); //������������� ������ �� ����������� ����
}

void bullet::update(map& map, const sf::Int64 time, float x, const float y, const int dir) //����������� �������-���������� �������-���� �� ����� ���� �� �����
{
	if (present) //���� ������������
	{
		move(time); //����������
		map_interaction(map); //��������������� � ������
	}
	else //�����
	{
		switch (dir) //������������ �� ����������� �������������, ����������� ��� ��������, ������������� ����������� ����
		{
		case left:
			b_dir = left; 
			break;
		case right:
			b_dir = right;
			break;
		case down:
			b_dir = up;
			break;
		case up:
			b_dir = down;
			break;
		}

		switch (b_dir) //� ����������� �� ����������� ���� ������ � ��������� ����������
		{
		case right:
			b_x = x + 55;
			b_y = y + 25;
			break;

		case left:
			b_x = x + 10;
			b_y = y + 25;
			break;

		case up:
			b_x = x + 25;
			b_y = y + 55;
			break;

		case down:
			b_x = x + 25;
			b_y = y + 10;
			break;
		}
		b_Sprite.setPosition(b_x, b_y); //������������� ������ ���� �� � �����������
	}
}

void bullet::map_interaction(map& map) //����������� �������-�������������� ���� � ������
{
	for (int i = (b_y + 8) / 64; i < (b_y + 16 - 8) / 64; ++i) //�������� �� �������� ������� ���� ��������� 
		for (int j = (b_x + 8) / 64; j < (b_x + 16 - 8) / 64; ++j) //�������� �� �������� ������� ������� �� ���������
		//��������� ���������� +- 8, ��� ��� �� ���� ������ 64X64 ����� ������ ��������, ���� ��������� ������������
		{
			char tile = map.get_tile(i, j); //� ���������� tile ������� �������� ����� �����, �� ������� ��������� ������� ������� ����

			if (tile == '0' || tile == '1' || tile == '4') //���� ����������� � ����������� �������
			{
				map.break_wall(i, j); //����� ������
				present = false; //������� ����
			}

			if (tile == 'w' || tile == '2' || tile == '3')  //���� ����������� � ������������� �������
				present = false; //������ ������� ����
		}
}