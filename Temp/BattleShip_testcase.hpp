#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <time.h>
#include <gtest/gtest.h> 
#include <gmock/gmock.h>
#include "server.hpp"
#include "mocking_object.hpp"

#pragma comment(lib,"gtest_maind.lib")   
#pragma comment(lib,"gtestd.lib") 
#pragma comment(lib,"gmock_main.lib")
#pragma comment(lib,"gmock.lib")
std::tuple<std::string, Direction, Position> InsertShip(std::string name, std::string d, int x, int y);

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> LessThanFive();

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> MoreThanFive();

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> WrongDistribution();

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> OutRangeX();

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> OutRangeY();

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> SharePosition();

std::vector<std::vector<std::tuple<std::string, Direction, Position>>> ValidShip();

void AttackAction(BattleShipServer &server, std::string testname, int id1, int &id1_count, int id2, int &id2_count);