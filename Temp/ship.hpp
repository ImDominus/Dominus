#pragma once

enum class Direction {
	HORIZONTAL,
	VERTICAL
};

struct Position {
	int x;
	int y;
};

class Ship {
	public:
		virtual ~Ship() {};
		virtual int GetSize() const = 0;
		virtual Direction GetDirection() const = 0;
};

class Aircraft : public Ship {
	public:
		virtual ~Aircraft() {};
};

class Battleship : public Ship {
	public:
		virtual ~Battleship() {};
};

class Cruiser : public Ship {
	public:
		virtual ~Cruiser() {};
};

class Destroyer : public Ship {
	public:
		virtual ~Destroyer() {};
};