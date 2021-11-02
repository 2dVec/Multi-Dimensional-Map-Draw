// Paint a Drawing
// Created by Paul Harman
// 02/11 - 2021
// Move with Arrow keys UP, DOWN, LEFT, RIGHT

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

class Map
{
private:
	std::vector<std::vector<char>> map{};
	int Sizeof_Map{};
	int Drawn_Characters{};
public:
	Map(int xy)
	{
		map.resize(xy, std::vector<char>(xy, ' '));
	}
	const int Sizeof_Characters()
	{
		return Drawn_Characters;
	}
	const int Get_Sizeof()
	{
		return Sizeof_Map;
	}
	const void Sizeof()
	{
		for (int y = 0; y < map.size(); y++)
		{
			for (int x = 0; x < map.size(); x++)
			{
			}
			Sizeof_Map++;
		}
	}
	void Display_Map();
	const void Show_Player(float xy, float xa)
	{
		map[xy][xa] = '#';
	}
	const void Erase_Before(float xy, float xa)
	{
		map[xy][xa] = '.';
		Drawn_Characters++;
	}
};

void Map::Display_Map()
{
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map.size(); x++)
		{
			std::cout << map[y][x];
		}
		std::cout << '\n';
	}
}

class Entity
{
public:
	float X, Y;

	bool move(Map& map)
	{
		if (GetAsyncKeyState(0x28))
		{
			if (Y == map.Get_Sizeof() - 1)
			{
				return false;
			}
			else
			{
				map.Erase_Before(Y, X);
				Y++;
			}
			return true;
		}
		if (GetAsyncKeyState(0x26))
		{
			if (Y == 0)
			{
				return false;
			}
			else
			{
				map.Erase_Before(Y, X);
				Y--;
			}
			return true;
		}
		if (GetAsyncKeyState(0x27))
		{
			if (X == map.Get_Sizeof() - 1)
			{
				return false;
			}
			else
			{
				map.Erase_Before(Y, X);
				X++;
			}
			return true;
		}
		if (GetAsyncKeyState(0x25))
		{
			if (X == 0)
			{
				return false;
			}
			else
			{
				map.Erase_Before(Y, X);
				X--;
			}
			return true;
		}
	}
	~Entity() {};
};

class Player : public Entity
{
public:
	const float Get_Player_PositionX() { return X; }
	const float Get_Player_PositionY() { return Y; }
	void Set_Start(float xa, float xy)
	{
		X = xa;
		Y = xy;
	}
};

int main()
{
	Map map = Map(10); // Set map size
	map.Sizeof();
	Player player;
	player.Set_Start(0, 0); //Start point of player

	while (true)
	{
		system("cls"); // Buffer screen
		map.Show_Player(player.Get_Player_PositionY(), player.Get_Player_PositionX());
		player.move(map);
		map.Display_Map();
		std::cout
			<< "\t\t\tX: " << player.Get_Player_PositionX() << '\n'
			<< "\t\t\tY: " << player.Get_Player_PositionY() << '\n'
			<< "\t\t\tCharacters drawn: " << map.Sizeof_Characters() << '\n'
			<< "\t\t\tSizeof Map: " << map.Get_Sizeof() << '\n';
	}

	return 0;
}
