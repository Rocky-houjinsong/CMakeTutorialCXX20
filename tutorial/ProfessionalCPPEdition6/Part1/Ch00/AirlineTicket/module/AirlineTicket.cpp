#pragma once
module airline_ticket;

using namespace std;
/*
	模块定义文件
*/
#pragma region 构造函数 && 析构函数

AirlineTicket::AirlineTicket()
	: m_passengerName{ "Unknown Passenger" }
	, m_numberOfMiles{ 0 }
	, m_hasEliteSuperRewardsStatus{ false }
{

}

AirlineTicket::~AirlineTicket()
{
	// Nothing to do in terms of cleanup
}
#pragma endregion


#pragma region getter && setter 

double AirlineTicket::calculatePriceInDollars()
{
	if (hasEliteSuperRewardsStatus())
	{
		//Elite Super Rewards  customers fly for free!
		return 0;
	}

	return getNumberOfMiles() * 0.1;
}

string AirlineTicket::getPassengerName()
{
	return m_passengerName;
}

void AirlineTicket::setPassengerName(string name)
{
	m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles()
{
	return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
	m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus()
{
	return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
	m_hasEliteSuperRewardsStatus = status;
}

#pragma endregion


