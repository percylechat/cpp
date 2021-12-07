
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

//https://www.cplusplus.com/reference/ctime/strftime/
void	Account::_displayTimestamp( void )
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"[%Y%m%d_%H%M%S]",timeinfo);
    std::cout << buffer;
    // std::cout << "[19920104_091532]" ;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    //[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
    std::cout << " accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex;
    std::cout << ";amount:" << Account::_amount;
    std::cout << ";deposits:" << Account::_nbDeposits;
    std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
    // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
}

void	Account::makeDeposit( int deposit )
{
    //[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex;
    std::cout << ";p_amount:" << Account::_amount;
    std::cout << ";deposit:" << deposit;
    Account::_amount += deposit;
    Account::_nbDeposits += 1;
    std::cout << ";amount:" << Account::_amount;
    std::cout << ";nb_deposits:" << Account::_nbDeposits << std::endl;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    //[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
    _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex;
    std::cout << ";p_amount:" << Account::_amount << ";withdrawal:";
    if (withdrawal > Account::_amount)
    {
        std::cout << "refused" << std::endl;
        return (1);
    }
    else
    {
        std::cout << withdrawal;
        Account::_amount -= withdrawal;
        Account::_nbWithdrawals += 1;
        std::cout << ";amount:" << Account::_amount;
        std::cout << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals += 1;
    }
    return (0);
}

Account::Account( int initial_deposit )
{
    //[19920104_091532] index:0;amount:42;created
    _displayTimestamp();
    Account::_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    std::cout << " index:" << Account::_accountIndex;
    Account::_amount = initial_deposit;
    std::cout << ";amount:" << Account::_amount << ";created" << std::endl;
    Account::_totalNbDeposits = 0;
    Account::_totalNbWithdrawals = 0;
    Account::_nbWithdrawals = 0;
    Account::_nbDeposits = 0;
}

Account::~Account( void )
{
     _displayTimestamp();
    std::cout << " index:" << Account::_accountIndex;
    std::cout << ";amount:" << Account::_amount << ";closed" << std::endl;
}