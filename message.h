#pragma once
#include <SFML/Graphics.hpp>

class message //����� ��������� � ��������� ����
{
private:
	float go_x, go_y; //���������� ��������� �� ������

	sf::Font go_Font; //�����
	sf::Text go_Str; //������ ������

public:
	message(const float x, const float y, const sf::String str); //���������� ������������ � �����������

	~message(); //���������� �����������

	void print(sf::RenderWindow &window) //������� ������ �� ����� ���������, � �������� ��������� ���������� ����� ������� 'window' ��� ������������� ��� ������ 'draw'
	{ 
		window.draw(go_Str); //�������������� �����
	}
};
