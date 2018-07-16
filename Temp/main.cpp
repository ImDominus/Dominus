#include <gtest/gtest.h>
#include <gmock/gmock.h>
#pragma comment(lib,"gtest_maind.lib")   
#pragma comment(lib,"gtestd.lib") 
#pragma comment(lib,"gmock_main.lib")
#pragma comment(lib,"gmock.lib")

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}