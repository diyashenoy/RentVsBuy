//
// Created by Diya Shenoy on 2019-10-15.
//

#include <iostream>
#include <fstream>
#include <ostream>
#include <cmath>
#include <iomanip>
#include "RentVsBuy.h"
#include "get_info.h"
#include "transportation.h"
#include "mortgage.h"
#include "appreciation.h"
#include "tax.h"
#include "remaining_loan.h"
#include "investment.h"


void RunRentVsBuy()
{
    std::ofstream outFile("RentVsBuy.csv"); 
    outFile << std::setprecision(0) << std::fixed;
    {
        double purchase_price, down_payment, rate, tax_rate, appreciation_rate;
        double inflation_rate;
        double loan_amount;
        double term, current_year=0;
        double years, mortgage=0, buying_transportation, home_maintenance=0, real_home_value,  renting_transportation; //final values
        double real_tax,home_cost;
        double real_purchase_price, current_value, tax, real_mortgage,remaining_loan;
        double monthly_mortgage, loan_rate, home_value_at_year_end, home_value_nominal;
        double monthly_rent, return_investment, year_rent=0, rent_cost=0;
        double home_investment, rent_investment, investment_home_cost, investment_rent_cost, home_dif, rent_dif;
        double home_profit,home_gross,rent_gross,hgminusrg, real_home_investment, real_rent_investment;
        double inv_year_rent, inv_buying_transportation, inv_maintenance, inv_renting_transportation;

        get_buying_info(purchase_price, down_payment, term, rate, tax_rate, appreciation_rate);
        real_purchase_price = purchase_price;
        loan_amount = purchase_price - down_payment;

        buying_transportation = home_transportation();
        get_renting_info(monthly_rent, return_investment);
        renting_transportation = rent_transportation();

        std::cout<<"Enter the expected average yearly inflation rate: ";
        std::cin>>inflation_rate;

        std::cout<<"Enter how many years in the future you want to look: ";
        std::cin>>years;

        remaining_loan = loan_amount; // to start the loop with some value


        loan_rate = rate;
        rent_investment = down_payment;
        home_investment = 0;

        inv_maintenance = (0.01*purchase_price);
        inv_year_rent = monthly_rent*12;
        inv_buying_transportation = buying_transportation;
        inv_renting_transportation = renting_transportation;


        outFile<<"Year,Mortgage,Taxes(real),Home Transportation(real),Home Maintenance(real),Home Costs Total(real),Home Value(real),Home Investments Total(real),Home Profits(real),Home Gross(real),Rent(real),Rent Transportation(real), Rent Costs Total (real),Rent Investments Total(real),Rent Gross(real),Home Gross - Rent Gross(real),Better Option"<<std::endl;
        for(int i=0;i<years;i++) //to calculate for the number of years into the future
        {
            //calculates the year
            current_year++;
            outFile << current_year<<",";

            //calculates mortgage
            if(i<term)
            {
                mortgage = mortgage_calculator(loan_amount, term, rate);
                outFile<<mortgage<<",";

            }
            else
            {
                mortgage = 0;
                outFile<<mortgage<<",";
            }

            //calculates taxes
            if(i==0)
            {
                current_value = real_purchase_price;
            }

            else
            {
                current_value = appreciation(real_purchase_price, appreciation_rate);
                real_purchase_price = current_value;
            }

            tax = calc_tax(tax_rate, current_value);
            real_tax = pow((1+inflation_rate),(-i)) * (tax); //to convert from nominal to real
            outFile<<real_tax<<",";

            //calculates home transportation
            outFile<<buying_transportation<<",";

            //calculates maintenance
            home_maintenance = 0.01*purchase_price;
            outFile<<home_maintenance<<",";

            //calculates home costs
            real_mortgage = pow((1+inflation_rate),(-i)) * (mortgage); //to convert from nominal to real

            home_cost = home_cost + real_mortgage + real_tax + buying_transportation +home_maintenance;
            outFile<<home_cost<<",";

            //calculates home value
            monthly_mortgage = mortgage/12;
            home_value_at_year_end = appreciation(real_purchase_price, appreciation_rate);
            remaining_loan = loan_calc(monthly_mortgage,remaining_loan, loan_rate);
            home_value_nominal = home_value_at_year_end - remaining_loan;
            real_home_value = pow((1+inflation_rate),(-i)) * (home_value_nominal);
            outFile<<real_home_value<<",";


            //calculates rent
            year_rent = monthly_rent*12;


            //calculates rent transportation;


            //calculates rent cost
            rent_cost = rent_cost + year_rent + renting_transportation;


            //investment calculation
//            real_buying_transportation = pow((1+inflation_rate),(-i)) * (buying_transportation);
//            real_renting_transportation = pow((1+inflation_rate),(-i)) * (renting_transportation);
//            real_home_maintenance = pow((1+inflation_rate),(-i)) * (home_maintenance);
//            real_year_rent = pow((1+inflation_rate),(-i)) * (year_rent);
//            investment_home_cost = mortgage + tax + real_buying_transportation + real_home_maintenance;
//            investment_rent_cost = real_year_rent + real_renting_transportation;

//            real_investment_home_cost = pow((1+inflation_rate),(-i)) * (investment_home_cost);
//            real_investment_rent_cost = pow((1+inflation_rate),(-i)) * (investment_rent_cost);

            investment_rent_cost = inv_year_rent + inv_renting_transportation;
            investment_home_cost = mortgage + tax + inv_buying_transportation + inv_maintenance;

            home_dif = (investment_rent_cost - investment_home_cost)/12;
            rent_dif = (investment_home_cost - investment_rent_cost)/12;

            for(int j=0; j<12; j++)
            {
                if (home_dif > 0)
                {
                    home_investment = home_investment + home_dif;
                }
                else
                    {
                    rent_investment = rent_investment + rent_dif;
                }

                home_investment  = home_investment + (home_investment * (return_investment / 12));
                rent_investment = rent_investment + (rent_investment * (return_investment / 12));
            }

            real_rent_investment = pow((1+inflation_rate),(-i)) * (rent_investment);
            real_home_investment = pow((1+inflation_rate),(-i)) * (home_investment);

            //home profits calculation
            home_profit = real_home_value + real_home_investment;

            //home gross calculation
            home_gross = home_profit - home_cost;

            //rent gross calculation
            rent_gross = real_rent_investment - rent_cost;

            //home gross - rent gross calculation
            hgminusrg = home_gross - rent_gross;

            //printing the outputs in order

            outFile<<real_home_investment<<",";
            outFile<<home_profit<<",";
            outFile<<home_gross<<",";

            outFile<<year_rent<<",";
            outFile<<renting_transportation<<",";
            outFile<<rent_cost<<",";


            outFile<<real_rent_investment<<",";
            outFile<<rent_gross<<",";
            outFile<<hgminusrg<<",";

            //better option calculation
            if (hgminusrg > 1)
            {
                outFile<<"Owning";
            }
            else
            {
                outFile<<"Renting";
            }


            inv_buying_transportation = inv_buying_transportation + (inflation_rate*inv_buying_transportation);
            inv_maintenance = inv_maintenance + (inflation_rate*inv_maintenance);
            inv_renting_transportation = inv_renting_transportation + (inflation_rate*inv_renting_transportation);
            inv_year_rent = inv_year_rent + (inflation_rate*inv_year_rent);


            outFile<<std::endl;
        }
    }

}




