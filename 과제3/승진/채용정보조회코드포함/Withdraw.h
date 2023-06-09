#pragma once
#include <iostream>

class DataBase;
class WithdrawUI;

class Withdraw
{
public:
	Withdraw();
	Withdraw(DataBase* dataBase);

	WithdrawUI* GetWithdrawUI() { return withdrawUI; }

	std::string TryWithdraw();

private:
	DataBase* dataBase;
	WithdrawUI* withdrawUI;
};