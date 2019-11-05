//
// Created by Diya Shenoy on 2019-10-16.
//

#include <iostream>

void get_buying_info(double& purchase_price, double& down_payment, double& term, double& rate, double& tax_rate, double& appreciation_rate)
{
    std::cout<<"==== Home Buying Information ===="<<std::endl;

    std::cout<<"Enter the purchase price of the home: ";
    std::cin>>purchase_price;

    std::cout<<"Enter your down payment: ";
    std::cin>>down_payment;

    if(down_payment != purchase_price)
    {
        std::cout<<"Enter the interest rate of your loan: ";
        std::cin>>rate;

        std::cout<<"Enter the term of your loan: ";
        std::cin>>term;
    }

    std::cout<<"Enter the property tax rate of the home: ";
    std::cin>>tax_rate;

    std::cout<<"Enter the rate at which you expect your home to appreciate each year: ";
    std::cin>>appreciation_rate;

}

void get_renting_info(double& rent, double& return_investment)
{
    std::cout<<"==== Renting Information ===="<<std::endl;
    std::cout<<"Enter your monthly rent payment: ";
    std::cin>>rent;

    std::cout<<"Enter your expected annual average rate of return on your investments: ";
    std::cin>>return_investment;
}
