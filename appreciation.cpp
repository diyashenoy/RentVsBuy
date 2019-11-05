//
// Created by Diya Shenoy on 2019-10-16.
//

#include <iostream>

double appreciation(double& real_purchase_price, double& appreciation_rate)
{
    double current_value = real_purchase_price;
    double appreciation_per_month = appreciation_rate/12;

    for(int i=0 ; i<12; i++)
    {

            current_value = current_value + (appreciation_per_month*current_value);

    }

    return current_value;
}