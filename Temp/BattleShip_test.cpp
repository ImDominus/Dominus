#include "BattleShip_testcase.hpp"

using ::testing::AtLeast;
using ::testing::Return;

class BattleShipTest : public::testing::Test {
	private:
		void MakeOneShip(std::vector<std::tuple<const Ship&, Position>> &ships, 
			             std::tuple<std::string, Direction, Position> &ship) {
			std::string shipname = std::get<0>(ship);
			Direction shipdirection = std::get<1>(ship);
			Position shipposition = std::get<2>(ship);
			if (shipname == "aircraft") {
				Mock_Aircraft *aircraft = new Mock_Aircraft;
				EXPECT_CALL(*aircraft, GetSize()).Times(AtLeast(0)).WillRepeatedly(Return(5));
				EXPECT_CALL(*aircraft, GetDirection()).Times(AtLeast(0)).WillRepeatedly(Return(shipdirection));
				std::tuple<const Ship&, Position> ship_info = { *aircraft, shipposition };
				memory->push_back(aircraft);
				ships.push_back(ship_info);
			}
			else if (shipname == "battleship") {
				Mock_Battleship *battleship = new Mock_Battleship;
				EXPECT_CALL(*battleship, GetSize()).Times(AtLeast(0)).WillRepeatedly(Return(4));
				EXPECT_CALL(*battleship, GetDirection()).Times(AtLeast(0)).WillRepeatedly(Return(shipdirection));
				std::tuple<const Ship&, Position> ship_info = { *battleship, shipposition };
				memory->push_back(battleship);
				ships.push_back(ship_info);
			}
			else if (shipname == "cruiser") {
				Mock_Cruiser *cruiser = new Mock_Cruiser;
				EXPECT_CALL(*cruiser, GetSize()).Times(AtLeast(0)).WillRepeatedly(Return(3));
				EXPECT_CALL(*cruiser, GetDirection()).Times(AtLeast(0)).WillRepeatedly(Return(shipdirection));
				std::tuple<const Ship&, Position> ship_info = { *cruiser, shipposition };
				memory->push_back(cruiser);
				ships.push_back(ship_info);
			}
			else if (shipname == "destroyer") {
				Mock_Destroyer *destroyer = new Mock_Destroyer;
				EXPECT_CALL(*destroyer, GetSize()).Times(AtLeast(0)).WillRepeatedly(Return(2));
				EXPECT_CALL(*destroyer, GetDirection()).Times(AtLeast(0)).WillRepeatedly(Return(shipdirection));
				std::tuple<const Ship&, Position> ship_info = { *destroyer, shipposition };
				memory->push_back(destroyer);
				ships.push_back(ship_info);
			}
		}
	protected:
		std::vector<std::vector<std::tuple<const Ship&, Position>>> *boards;
		std::vector<Ship *> *memory;
		virtual void SetUp() {
			boards = new std::vector<std::vector<std::tuple<const Ship&, Position>>>;
			memory = new std::vector<Ship *>;
		}
		virtual void TearDown(){
			for (int i = 0; i < (*memory).size(); i++) {
				delete (*memory)[i];
			}
			delete boards;
			delete memory;
		}
		virtual void BuildTestCase(std::vector<std::vector<std::tuple<std::string, Direction, Position>>> testcase) {
			std::vector<std::tuple<const Ship&, Position>> ships;
			for (int i = 0; i < testcase.size(); i++) {
				for (int j = 0; j < testcase[i].size(); j++) {
					MakeOneShip(ships, testcase[i][j]);
				}
				(*boards).push_back(ships);
			}			
		}
};

void InvalidRegister(BattleShipServer &server, std::vector<std::tuple<const Ship&, Position>> &ships, std::string iterations) {
	EXPECT_FALSE(server.RegisterBoard(ships)) << "TEST CASE " + iterations + ": Register Failed";
	int id = server.Start("abc");
	EXPECT_EQ(id, -1) << "TEST CASE " + iterations + ": Start Failed";
	EXPECT_TRUE(server.IsEnd(id)) << "TEST CASE " + iterations + ": IsEnd Failed";
	EXPECT_EQ(server.GetAttackCount(id), -1) << "TEST CASE " + iterations + ": GetAttackCount Failed";
	srand(time(NULL));
	Position pos;
	pos.x = rand() % 10, pos.y = rand() % 10;
	EXPECT_EQ(server.Attack(id, pos), "Wrong ID");
}

void ValidRegister(BattleShipServer &server, std::vector<std::tuple<const Ship&, Position>> &ships, std::string iterations) {
	EXPECT_TRUE(server.RegisterBoard(ships)) << "TEST CASE " + iterations + ": Register Failed";
}

TEST_F(BattleShipTest, NoRegisterBoard) {
	BattleShipServer server;
	EXPECT_EQ(server.Start("abc"), -1) << "Start Failed";
	EXPECT_TRUE(server.IsEnd(-1)) << "IsEnd Failed";
}

TEST_F(BattleShipTest, RegisterBoard_LessThanFive) {
	BattleShipServer server;
	auto lessthanfive = LessThanFive();
	BuildTestCase(lessthanfive);
	for (int i = 0; i < boards->size(); i++) {
		std::string iterations = std::to_string(i + 1);
		InvalidRegister(server, (*boards)[i], iterations);
	}
}

TEST_F(BattleShipTest, RegisterBoard_MoreThanFive) {
	BattleShipServer server;
	auto morethanfive = MoreThanFive();
	BuildTestCase(morethanfive);
	for (int i = 0; i < boards->size(); i++) {
		std::string iterations = std::to_string(i + 1);
		InvalidRegister(server, (*boards)[i], iterations);
	}
}

TEST_F(BattleShipTest, RegisterBoard_WrongDistribution) {
	BattleShipServer server;
	auto wrongdistribution = WrongDistribution();
	BuildTestCase(wrongdistribution);
	for (int i = 0; i < boards->size(); i++) {
		std::string iterations = std::to_string(i + 1);
		InvalidRegister(server, (*boards)[i], iterations);
	}
}

TEST_F(BattleShipTest, RegisterBoard_OutRangeX) {
	BattleShipServer server;
	auto outrangex = OutRangeX();
	BuildTestCase(outrangex);
	for (int i = 0; i < boards->size(); i++) {
		std::string iterations = std::to_string(i + 1);
		InvalidRegister(server, (*boards)[i], iterations);
	}
}

TEST_F(BattleShipTest, RegisterBoard_OutRangeY) {
	BattleShipServer server;
	auto outrangey = OutRangeY();
	BuildTestCase(outrangey);
	for (int i = 0; i < boards->size(); i++) {
		std::string iterations = std::to_string(i + 1);
		InvalidRegister(server, (*boards)[i], iterations);
	}
}

TEST_F(BattleShipTest, RegisterBoard_SharePosition) {
	BattleShipServer server;
	auto shareposition = SharePosition();
	BuildTestCase(shareposition);
	for (int i = 0; i < boards->size(); i++) {
		std::string iterations = std::to_string(i + 1);
		InvalidRegister(server, (*boards)[i], iterations);
	}
}

TEST_F(BattleShipTest, RegisterBoard_ValidShip) {
	BattleShipServer server;
	auto validship = ValidShip();
	BuildTestCase(validship);
	for (int i = 0; i < boards->size(); i++) {
		std::string iterations = std::to_string(i + 1);
		ValidRegister(server, (*boards)[i], iterations);
	}
	int id_a1 = server.Start("abc");
	int id_a2 = server.Start("abc");
	int id_b1 = server.Start("def");
	int id_invalid = server.Start("ghi");

	EXPECT_EQ(id_a1, id_a2) << "Same username must return same ID";
	EXPECT_NE(id_a1, id_b1) << "Diffrent username must return diffrent ID";;
	EXPECT_NE(id_a1, -1) << "Board search Failed";
	EXPECT_NE(id_b1, -1) << "Board search Failed";
	EXPECT_FALSE(server.IsEnd(id_a1)) << "Valid ID, IsEnd Failed";
	EXPECT_FALSE(server.IsEnd(id_b1)) << "Valid ID, IsEnd Failed";
	EXPECT_EQ(server.GetAttackCount(id_a1), 0) << "Valid ID, GetAttackCount Failed";
	EXPECT_EQ(server.GetAttackCount(id_b1), 0) << "Valid ID, GetAttackCount Failed";

	EXPECT_EQ(id_invalid, -1) << "Not enough boards, So must be return -1";
	EXPECT_TRUE(server.IsEnd(id_invalid)) << "Invalid ID, IsEnd Failed";
	EXPECT_EQ(server.GetAttackCount(id_invalid), -1) << "Invalid ID, GetAttackCount Failed";
}


TEST_F(BattleShipTest, AttackTest) {
	srand(time(NULL));
	BattleShipServer server;
	auto validship = ValidShip();
	BuildTestCase(validship);
	// TEST only 1 boards
	server.RegisterBoard((*boards)[0]);
	int id1 = server.Start("abc");
	int id1_count = 0;
	int id2 = -1;
	int id2_count = -1;
	//ASSERT_NE(id1, -1) << "Id must be Valid";
	EXPECT_EQ(server.GetAttackCount(id1), id1_count);
	int invalidid = rand();
	while (invalidid == id1) invalidid = rand();
	AttackAction(server, "attacktestcase1.csv", id1, id1_count, id2, id2_count);

	// TEST 2 boards
	server.RegisterBoard((*boards)[1]);
	id2 = server.Start("def");
	id2_count = 0;
	//ASSERT_NE(id2, -1) << "id must be Valid";
	//ASSERT_NE(id1, id2) << "must be diffrent id";
	EXPECT_EQ(id2_count, 0);
	while ((invalidid == id1) || (invalidid == id2)) invalidid = rand();
	AttackAction(server, "attacktestcase2.csv", id1, id1_count, id2, id2_count);

	EXPECT_TRUE(server.IsEnd(id1)) << "game was finished";
	EXPECT_TRUE(server.IsEnd(id2)) << "game was finished";
}