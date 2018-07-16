#pragma once
#include <gtest/gtest.h> 
#include <gmock/gmock.h>
#pragma comment(lib,"gtest_maind.lib")   
#pragma comment(lib,"gtestd.lib") 
#pragma comment(lib,"gmock_main.lib")
#pragma comment(lib,"gmock.lib")
class Mock_Aircraft : public Aircraft{
	public:
		MOCK_CONST_METHOD0(GetSize, int());
		MOCK_CONST_METHOD0(GetDirection, Direction());
};

class Mock_Battleship : public Battleship {
	public:
		MOCK_CONST_METHOD0(GetSize, int());
		MOCK_CONST_METHOD0(GetDirection, Direction());
};

class Mock_Cruiser : public Cruiser {
	public:
		MOCK_CONST_METHOD0(GetSize, int());
		MOCK_CONST_METHOD0(GetDirection, Direction());
};

class Mock_Destroyer : public Destroyer {
	public:
		MOCK_CONST_METHOD0(GetSize, int());
		MOCK_CONST_METHOD0(GetDirection, Direction());
};
