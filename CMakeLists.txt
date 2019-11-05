cmake_minimum_required(VERSION 3.13)
project(RentVsBuy)

set(CMAKE_CXX_STANDARD 14)

add_executable(RentVsBuy main.cpp
                RentVsBuy.cpp RentVsBuy.cpp
                get_info.cpp get_info.h
                transportation.cpp transportation.h
                mortgage.cpp mortgage.h
                appreciation.cpp appreciation.h
                tax.cpp tax.h
                remaining_loan.cpp remaining_loan.h
                investment.cpp investment.h)

target_link_libraries(RentVsBuy PRIVATE m)