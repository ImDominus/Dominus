#include "BattleShip_testcase.hpp"


std::tuple<std::string, Direction, Position> InsertShip(std::string name, std::string d, int x, int y) {
	Position shipposition;
	shipposition.x = x, shipposition.y = y;
	Direction shipdirection;
	if (d == "horizontal") {
		shipdirection = Direction::HORIZONTAL;
	}
	else if (d == "vertical") {
		shipdirection = Direction::VERTICAL;
	}
	return { name, shipdirection, shipposition };
}

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> LessThanFive() {
	std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase;
	// TestCase1
	std::vector<std::tuple<std::string, Direction, Position>> test1;
	test1.push_back(InsertShip("aircraft", "horizontal", 0, 0));
	test1.push_back(InsertShip("battleship", "horizontal", 1, 1));
	test1.push_back(InsertShip("cruiser", "horizontal", 2, 2));
	test1.push_back(InsertShip("destroyer", "horizontal", 3, 3));
	testcase.push_back(test1);
	// TestCase2
	std::vector<std::tuple<std::string, Direction, Position>> test2;
	testcase.push_back(test2);
	return testcase;
};

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> MoreThanFive() {
	std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase;
	// TestCase1
	std::vector<std::tuple<std::string, Direction, Position>> test1;
	test1.push_back(InsertShip("aircraft", "horizontal", 0, 0));
	test1.push_back(InsertShip("battleship", "horizontal", 0, 1));
	test1.push_back(InsertShip("cruiser", "horizontal", 0, 2));
	test1.push_back(InsertShip("destroyer", "horizontal", 0, 3));
	test1.push_back(InsertShip("battleship", "horizontal", 0, 4));
	test1.push_back(InsertShip("cruiser", "horizontal", 0, 5));
	testcase.push_back(test1);
	// TestCase2
	std::vector<std::tuple<std::string, Direction, Position>> test2;
	test2.push_back(InsertShip("battleship", "horizontal", 0, 0));
	test2.push_back(InsertShip("aircraft", "horizontal", 1, 3));
	test2.push_back(InsertShip("cruiser", "vertical", 2, 4));
	test2.push_back(InsertShip("destroyer", "horizontal", 3, 2));
	test2.push_back(InsertShip("aircraft", "horizontal", 4, 1));
	test2.push_back(InsertShip("cruiser", "vertical", 5, 4));
	test2.push_back(InsertShip("cruiser", "vertical", 3, 5));
	test2.push_back(InsertShip("destroyer", "horizontal", 6, 2));
	testcase.push_back(test2);
	return testcase;
};

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> WrongDistribution() {
	std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase;
	// TestCase1
	std::vector<std::tuple<std::string, Direction, Position>> test1;
	test1.push_back(InsertShip("aircraft", "horizontal", 0, 0));
	test1.push_back(InsertShip("battleship", "horizontal", 0, 1));
	test1.push_back(InsertShip("cruiser", "horizontal", 0, 2));
	test1.push_back(InsertShip("aircraft", "horizontal", 0, 3));
	test1.push_back(InsertShip("aircraft", "horizontal", 0, 4));
	testcase.push_back(test1);
	// TestCase2
	std::vector<std::tuple<std::string, Direction, Position>> test2;
	test2.push_back(InsertShip("cruiser", "horizontal", 0, 0));
	test2.push_back(InsertShip("cruiser", "horizontal", 0, 1));
	test2.push_back(InsertShip("battleship", "vertical", 3, 3));
	test2.push_back(InsertShip("aircraft", "horizontal", 4, 2));
	test2.push_back(InsertShip("aircraft", "horizontal", 4, 3));
	testcase.push_back(test2);
	return testcase;
};

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> OutRangeX() {
	std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase;
	// TestCase1, Big X
	std::vector<std::tuple<std::string, Direction, Position>> test1;
	test1.push_back(InsertShip("aircraft", "horizontal", 10, 0));
	test1.push_back(InsertShip("battleship", "horizontal", 0, 1));
	test1.push_back(InsertShip("cruiser", "horizontal", 0, 2));
	test1.push_back(InsertShip("destroyer", "horizontal", 0, 3));
	test1.push_back(InsertShip("aircraft", "horizontal", 0, 4));
	testcase.push_back(test1);
	// TestCase2, Big X + length
	std::vector<std::tuple<std::string, Direction, Position>> test2;
	test2.push_back(InsertShip("aircraft", "horizontal", 0, 0));
	test2.push_back(InsertShip("cruiser", "horizontal", 8, 8));
	test2.push_back(InsertShip("battleship", "horizontal", 0, 2));
	test2.push_back(InsertShip("aircraft", "horizontal", 0, 3));
	test2.push_back(InsertShip("destroyer", "horizontal", 0, 4));
	testcase.push_back(test2);
	// TestCase3 Small X
	std::vector<std::tuple<std::string, Direction, Position>> test3;
	test3.push_back(InsertShip("aircraft", "horizontal", 0, 0));
	test3.push_back(InsertShip("cruiser", "horizontal", -1, 1));
	test3.push_back(InsertShip("battleship", "horizontal", 0, 4));
	test3.push_back(InsertShip("aircraft", "horizontal", 1, 5));
	test3.push_back(InsertShip("destroyer", "horizontal", 4, 7));
	testcase.push_back(test3);
	return testcase;
};

std::vector<std::vector<std::tuple<std::string, Direction, Position>>>OutRangeY() {
	std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase;
	// TestCase1 Big Y
	std::vector<std::tuple<std::string, Direction, Position>> test1;
	test1.push_back(InsertShip("aircraft", "vertical", 0, 10));
	test1.push_back(InsertShip("destroyer", "vertical", 1, 0));
	test1.push_back(InsertShip("aircraft", "vertical", 2, 0));
	test1.push_back(InsertShip("battleship", "vertical", 3, 4));
	test1.push_back(InsertShip("cruiser", "vertical", 7, 2));
	testcase.push_back(test1);
	// TestCase2 Big Y + length
	std::vector<std::tuple<std::string, Direction, Position>> test2;
	test2.push_back(InsertShip("aircraft", "vertical", 0, 9));
	test2.push_back(InsertShip("destroyer", "vertical", 1, 0));
	test2.push_back(InsertShip("aircraft", "vertical", 2, 0));
	test2.push_back(InsertShip("battleship", "vertical", 3, 4));
	test2.push_back(InsertShip("cruiser", "vertical", 7, 2));
	testcase.push_back(test2);
	// TestCase3 Small Y
	std::vector<std::tuple<std::string, Direction, Position>> test3;
	test3.push_back(InsertShip("aircraft", "vertical", -1, 0));
	test3.push_back(InsertShip("destroyer", "vertical", 1, 0));
	test3.push_back(InsertShip("aircraft", "vertical", 2, 0));
	test3.push_back(InsertShip("battleship", "vertical", 3, 4));
	test3.push_back(InsertShip("cruiser", "vertical", 7, 2));
	testcase.push_back(test3);
	return testcase;
};

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> SharePosition() {
	std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase;
	// TestCase1
	std::vector<std::tuple<std::string, Direction, Position>> test1;
	test1.push_back(InsertShip("aircraft", "vertical", 0, 0));
	test1.push_back(InsertShip("destroyer", "horizontal", 0, 1));
	test1.push_back(InsertShip("aircraft", "vertical", 3, 0));
	test1.push_back(InsertShip("battleship", "vertical", 6, 5));
	test1.push_back(InsertShip("cruiser", "vertical", 7, 2));
	testcase.push_back(test1);
	// TestCase2
	std::vector<std::tuple<std::string, Direction, Position>> test2;
	test2.push_back(InsertShip("aircraft", "horizontal", 1, 1));
	test2.push_back(InsertShip("destroyer", "vertical", 2, 3));
	test2.push_back(InsertShip("aircraft", "vertical", 0, 5));
	test2.push_back(InsertShip("battleship", "vertical", 3, 5));
	test2.push_back(InsertShip("cruiser", "vertical", 4, 0));
	testcase.push_back(test2);
	return testcase;
};

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> ValidShip() {
	std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase;
	// TestCase1
	std::vector<std::tuple<std::string, Direction, Position>> test1;
	test1.push_back(InsertShip("aircraft", "vertical", 0, 0));
	test1.push_back(InsertShip("destroyer", "horizontal", 1, 0));
	test1.push_back(InsertShip("aircraft", "vertical", 3, 0));
	test1.push_back(InsertShip("battleship", "vertical", 6, 5));
	test1.push_back(InsertShip("cruiser", "vertical", 7, 2));
	testcase.push_back(test1);
	// TestCase2
	std::vector<std::tuple<std::string, Direction, Position>> test2;
	test2.push_back(InsertShip("aircraft", "horizontal", 1, 1));
	test2.push_back(InsertShip("destroyer", "vertical", 2, 3));
	test2.push_back(InsertShip("destroyer", "horizontal", 0, 5));
	test2.push_back(InsertShip("battleship", "vertical", 3, 5));
	test2.push_back(InsertShip("cruiser", "vertical", 6, 5));
	testcase.push_back(test2);
	return testcase;
};

void AttackAction(BattleShipServer &server, std::string testname, int id1, int &id1_count, int id2, int &id2_count) {
	int id;
	int *id_count;
	std::string temp;
	std::string ids, xs, ys, result, failedtest, increasecount;
	std::ifstream testcase("./TestCase/" + testname);
	while (testcase.is_open() && !testcase.eof()) {
		std::stringstream action;
		std::getline(testcase, temp);
		if (temp.size() == 0) break; // CSV Last Line
		action.str(temp);
		action >> ids >> xs >> ys >> result >> failedtest >> increasecount;
		if (std::stoi(ids) == 1) {
			id = id1;
			id_count = &id1_count;
		}
		else {
			id = id2;
			id_count = &id2_count;
		}
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '_') result[i] = ' ';
		}
		*id_count += std::stoi(increasecount);
		Position pos;
		pos.x = std::stoi(xs), pos.y = std::stoi(ys);
		EXPECT_EQ(server.Attack(id, pos), result) << failedtest;
		EXPECT_EQ(server.GetAttackCount(id), *id_count) << "Incorrect count";
	}
}