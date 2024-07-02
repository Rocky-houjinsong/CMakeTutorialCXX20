#include <iostream>   //import <iostream>;
import airline_ticket;

using namespace std;

/*
	测试文件
*/

int main()
{
	AirlineTicket myTicket;    // 此处就是  使用模块中的 数据 
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);

	double cost{ myTicket.calculatePriceInDollars() };

	std::cout << "This ticket will cost $" << cost << std::endl;
}