#pragma once
#include <vector>
#include <string>
#include <tuple>
#include "ship.hpp"

class BattleShipServer {
	public:
		// To register new game board
		// args
		// - ships: Ship and it's position (length MUST be 5)
		// return
		// - true if input data is valid or false
		bool RegisterBoard(const std::vector < std::tuple< const Ship&, Position>>&ships) {
			return false;
		};
		// Start new game
		// args
		// - username: user name
		// return
		// - game id
		int Start(const std::string & username) {
			return -1;
		}
		// Attack
		// args
		// - id : unique game id
		// - pos : attack coordinate
		// return - one of below
		// - Miss
		// - Hit
		// - Aircraft Destroyed
		// - Battleship Destroyed
		// - Cruiser Destroyed
		// - Destroyer Destroyed
		// - Wrong position
		// - Wrong ID
		std::string Attack(int id, Position pos) {
			return "Wrong ID";
		}
		// Check whether the game is end
		// return
		// - true or false
		bool IsEnd(int id) const {
			return true;
		}
		// Get current attack count
		// args
		// - id : unique game id
		// return
		// - count of attack
		int GetAttackCount(int id) {
			return -1;
		}
	private:
		// BLACK BOX
};