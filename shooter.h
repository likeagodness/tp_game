#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <bullet.h>

class map; //класс карты, подключаем дл€ функции взаимодействи€ с картой

class shooter  //класс стрелка, предок классов игроков и противников
{
protected:
	float t_dx, t_dy, t_Speed, t_CurrentFrame; //приращение координаты по иксу и игреку, скорость движени€ стрелка, его нынешний фрейм

	sf::String t_File; //файл с текстурой стрелка
	sf::Texture t_Texture; //текстура стрелка

public:
	shooter(const float x, const float y, const sf::String file); //объ€вление конструктора с параметрами - координатами стрелка и его текстурой

	virtual ~shooter(); //объ€вление виртуального деструктора - потому что предок

	float t_x, t_y; //координаты стрелка
	bool life; //булевска€ переменна€, отвечающа€ за то, убит ли стрелок, или нет

	enum TDIR //перечисление направлений движени€ стрелка
	{ 
		left = 0, 
		right = 1, 
		up = 2, 
		down = 3
	} t_dir;

	sf::Sprite t_Sprite; //спрайт стрелка

	void animate(const sf::Int64 time); //объ€вление функции с анимацией стрелка, в качестве аргумента врем€ игры

	void collapse(); //объ€вление функции-уничтожени€ стрелка

	virtual void move(const sf::Int64 time) //виртуальна€ функци€ перемещени€ стрелка, переопределитс€ у потомков
	{

	}
	
	void map_interaction(map& map); //объ€вление функции-взаимодействи€ стрелка с картой
};