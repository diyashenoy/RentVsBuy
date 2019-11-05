//
// Created by Diya Shenoy on 2019-10-16.
//

#include <iostream>

double home_transportation()
{
    double miles, per_mile_cost;
    double choice, cost;
    std::cout<<"==== Commute from home ===="<<std::endl;

    std::cout<<"Enter how many miles from work your home is: ";
    std::cin>>miles;
    std::cout<<"How will you be getting to work from your home?"<<std::endl;
    std::cout<<"Enter 1 for driving."<<std::endl;
    std::cout<<"Enter 2 for public transit."<<std::endl;
    std::cout<<"Enter 3 for biking, walking, etc."<<std::endl;
    std::cout<<"Enter your choice: ";
    std::cin>>choice;

    if(choice == 1) //driving
    {
        std::cout<<"Enter how much it costs to drive your car per mile: ";
        std::cin>>per_mile_cost;

        cost = miles*per_mile_cost*2*261;
    }

    else if(choice == 2) //public transport
    {
        std::cout<<"Enter your monthly public transit costs: ";
        std::cin>>cost;
        cost = cost*12;
    }

    else //self
    {
        cost = 0;
    }

    return cost;
}

double rent_transportation()
{
    double miles, per_mile_cost;
    double choice,cost;
    std::cout<<"==== Commute from apartment ===="<<std::endl;

    std::cout<<"Enter how many miles from work your apartment is: ";
    std::cin>>miles;
    std::cout<<"How will you be getting to work from your apartment?"<<std::endl;
    std::cout<<"Enter 1 for driving."<<std::endl;
    std::cout<<"Enter 2 for public transit."<<std::endl;
    std::cout<<"Enter 3 for biking, walking, etc."<<std::endl;
    std::cout<<"Enter your choice: ";
    std::cin>>choice;

    if(choice == 1) //driving
    {
        std::cout<<"Enter how much it costs to drive your car per mile: ";
        std::cin>>per_mile_cost;

        cost = (per_mile_cost*2)*261;
    }

    else if(choice == 2) //public transport
    {
        std::cout<<"Enter your monthly public transit costs: ";
        std::cin>>cost;
        cost = cost*12;
    }

    else //self
    {
        cost = 0;
    }

    return cost;
}
