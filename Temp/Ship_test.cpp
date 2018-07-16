/*
#include <gtest/gtest.h> 
#include <gmock/gmock.h>
#include "ship.hpp"

class ShipTest : public::testing::Test {
	protected:
		Ship *horizontalship;
		Ship *verticalship;
		Aircraft *aircraft;
		Battleship *battleship;
		Cruiser *cruiser;
		Destroyer *destroyer;

		virtual void SetUp() {
			horizontalship = new Ship(8, Direction::HORIZONTAL);
			verticalship = new Ship(1, Direction::VERTICAL);
			aircraft = new Aircraft(Direction::HORIZONTAL);
			battleship = new Battleship(Direction::VERTICAL);
			cruiser = new Cruiser(Direction::HORIZONTAL);
			destroyer = new Destroyer(Direction::VERTICAL);
		}

		virtual void TearDown() {
			delete horizontalship;
			delete verticalship;
			delete aircraft;
			delete battleship;
			delete cruiser;
			delete destroyer;
		}
};

TEST_F(ShipTest, IsRightSize) {
	EXPECT_EQ(horizontalship->GetSize(), 8);
	EXPECT_EQ(verticalship->GetSize(), 1);
	EXPECT_EQ(aircraft->GetSize(), 5);
	EXPECT_EQ(battleship->GetSize(), 4);
	EXPECT_EQ(cruiser->GetSize(), 3);
	EXPECT_EQ(destroyer->GetSize(), 2);
};

TEST_F(ShipTest, IsRightDirection) {
	EXPECT_EQ(horizontalship->GetDirection(), Direction::HORIZONTAL);
	EXPECT_EQ(verticalship->GetDirection(), Direction::VERTICAL);
	EXPECT_EQ(aircraft->GetDirection(), Direction::HORIZONTAL);
	EXPECT_EQ(battleship->GetDirection(), Direction::VERTICAL);
	EXPECT_EQ(cruiser->GetDirection(), Direction::HORIZONTAL);
	EXPECT_EQ(destroyer->GetDirection(), Direction::VERTICAL);
}
*/