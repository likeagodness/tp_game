#include <iostream>
#include <message.h>

message::message(const float x, const float y, const sf::String str): go_x(x), go_y(y) 
//����������� ������������, �������� � ��� ������� ���������� ��������� � ��������� ������ � ����������
{
	go_Font.loadFromFile("Font/sourcesans.ttf"); //��������� ����� �� ����� Font, ����� prstart.ttf
	go_Str.setFont(go_Font); //������������ ����� ������
	go_Str.setString(str); //������������� ������ ���������
	go_Str.setPosition(go_x, go_y); //������������� ���������� ���������
	go_Str.setCharacterSize(40); //������������� ������ ������
}

message::~message() //����������� �����������
{
	std::cout << "Game-related message destroyed\n"; //�������� �������� ������� ������ - ������ � �������
}