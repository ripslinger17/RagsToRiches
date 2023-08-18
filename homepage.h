//
// Created by Smit Patel on 06/08/23.
//

#ifndef FINANCE_GAME_HOMEPAGE_H
#define FINANCE_GAME_HOMEPAGE_H
#include <iostream>
#include <random>
#include <cmath>
#include <string>
#include "balance.h"

void fixDeposit(){
    std::cout << "\033[37m" << "Current balance: " << balance << std::endl;
    std::cout << "\033[33m" << "How many you have to deposit for the Fix Deposit?" << std::endl;
    while(true){
        std::cin >> input;
        if (input > balance || input < 5000){
            std::cout << "\033[34m" << "Invalid Input" << std::endl;
        } else{
            break;
        }
    }
    temp1 = input + (input * 6.8 * 1/100);
    temp1 = temp1 - input;
    balance += temp1;
    std::cout << "\032[31m" << "Updated balance: " << balance << std::endl;
}

void crypto(){
    int timePeriod, pv;
    double RR, random_number;
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<int> distribution(-100, 100);
    random_number = distribution(gen);

    RR = random_number / 100;

    while (true)
    {
        std::cout << "\033[33m" << "Enter Portfolio Value: ";
        std::cin >> input;
        if (input > balance || input < 5000)
        {
            std::cout << "\033[34m" << "Invalid Input" << std::endl;
        }
        else
        {
            break;
        }
    }
    std::cout << "\033[33m" << "Enter The Number of Months ";
    while (true)
    {
        std::cin >> timePeriod;
        if (timePeriod < 1 || timePeriod > 6)
        {
            std::cout << "\033[34m" << "Incorrect Input! Please Enter Correct Input" << std::endl;
        }
        else
        {
            break;
        }
    }
    RR = 1 + RR;
    pv = input * std::pow(RR, timePeriod);
    std::cout << "\033[33m" << "Portfolio Value: " << pv << std::endl;
    if (RR > 0)
    {
        pv = pv - input;
        balance += pv;
        std::cout << "\033[32m" << "Updated balance: " << balance << std::endl;
    }
    else
    {
        pv = input - pv;
        balance -= pv;
        std::cout << "\033[32m" << "Updated balance: " << balance << std::endl;
    }
}
void gambling()
{
    std::random_device cfn;
    std::mt19937 gen(cfn()); // Mersenne Twister engine
    std::uniform_int_distribution<int> distribution(1, 2);
    coinFlipNumber = distribution(gen);

    std::random_device rdn;
    std::mt19937 gen1(rdn()); // Mersenne Twister engine
    std::uniform_int_distribution<int> distribution1(1, 6);
    rollDiceNumber = distribution1(gen1);

    std::cout << "\033[37m" << "What do you want to play?" << std::endl;
    std::cout << "\033[33m" << "1. Coin Flip\n2. Roll the dice" << std::endl;

    while (true)
    {
        std::cin >> temp1;
        if (temp1 < 1 || temp1 > 2)
        {
            std::cout << "\033[34m" << "Invalid Input Please Select again!" << std::endl;
        }
        else
        {
            break;
        }
    }
    switch (temp1)
    {
        case 1:
            std::cout << "\033[37m" << "Welcome to Coin Flip Gambling " << "\033[33m" << "Enter the amount of Money you want to gamble!" << std::endl;
            while (true)
            {
                std::cin >> input;
                if (input < 50 || input > 2000)
                {
                    std::cout << "\033[34m" << "Invalid Input Please Enter Again!" << std::endl;
                }
                else
                {
                    break;
                }
            }
            std::cout << "\033[37m" << "It is a 2 sided fair coin with fancy name for each side choose your side" << "\033[33m" << "\n1. Destiny Emblem\n2. Fate Insignia" << std::endl;
            while (true)
            {
                std::cin >> temp2;
                if (temp2 < 1 || temp2 > 2)
                {
                    std::cout << "\033[34m" << "Invalid Input Please Enter Again!" << std::endl;
                }
                else
                {
                    break;
                }
            }
            if (temp2 == coinFlipNumber)
            {
                balance -= input;
                input *= 1.5;
                balance += input;
                std::cout << "\033[37m" << "Congratulations! You won! " << "\033[32m" <<"Your Current Updated Balance: " << balance << std::endl;
            }
            else
            {
                balance -= input;
                std::cout << "\033[37m" << "You loss!" << "\033[32m" << "Your Current Updated Balance: " << balance << std::endl;
            }
            break;

        case 2:
            std::cout << "\033[37m" << "Welcome to Dice Gambling" << std::endl;
            std::cout << "\033[33m" << "Enter the amount of Money you want to gamble!" << std::endl;
            while (true)
            {
                std::cin >> input;
                if (input < 125 || input > 5000)
                {
                    std::cout << "\033[34m" << "Invalid Input Please Enter Again!" << std::endl;
                }
                else
                {
                    break;
                }
            }
            std::cout << "\033[37m" << "It is a 6 sided fair die with fancy name for every side choose your side" << "\033[33m" << "\n1. Quantum Glyph\n2. Celestial Rune\n3. Ethereal Mark\n4. Cosmic Token\n5. Eon Crest\n6. Astral Sigil" << std::endl;
            while (true)
            {
                std::cin >> temp2;
                if (temp2 < 1 || temp2 > 6)
                {
                    std::cout << "\033[34m" << "Invalid Input Please Enter Again!" << std::endl;
                }
                else
                {
                    break;
                }
            }
            if (temp2 == rollDiceNumber)
            {
                balance -= input;
                input *= 5;
                balance += input;
                std::cout << "\033[37m" << "Congratulations! You won! " << "\033[32m" <<"Your Current Updated Balance: " << balance << std::endl;
            }
            else
            {
                balance -= input;
                std::cout << "\033[37m" << "You loss! " << "\033[32m" << "Your Current Updated Balance: " << balance << std::endl;
            }
    }
}

void check(){
    if (balance >= 1000000){
        std::cout << "\033[37m" << "Congratulations!" << "\033[32m" << "You completed the game with " << balance << std::endl;
        exit(0);
    }
    else{
        std::cout << "\033[31m" << "No you aren't there yet! Keep grinding!!" << std::endl;
    }
}

void quit()
{
    std::cout << "\033[31m" << "Are you sure you want to quit?\n" << "\033[33m" << "You are just shy of " << (temp1 = 1000000 - balance) << " from completeing the game\n" << "\033[33m" << "Press 1. Continue the game\n2.Quit the Game" << std::endl;
    while (true)
    {
        std::cin >> temp1;
        switch (temp1)
        {
            case 1:
                break;
            case 2:
                exit(0);

            default:
                std::cout << "\033[34m" << "Invalid Input Please Enter Correct Input" << std::endl;
                break;
        }
        break;
    }
}

void displayHomepage(){
    int choice1;
    while(true){
        std::cout << "\033[37m" << "Your current balance: " << balance << std::endl;
        std::cout << "\033[33m" << "Choose a activity to perform\n1. Fix Deposit\n2.Cryptocurrency\n3.Gambling\n4.Check For Win\n5.Exit" << std::endl;
        std::cin >> choice1;
        switch (choice1) {
            case 1:
                fixDeposit();
                break;
            case 2:
                crypto();
                break;
            case 3:
                gambling();
                break;
            case 4:
                check();
                break;
            case 5:
                quit();
                break;
            default:
                std::cout << "\033[34m" << "Please enter a valid choice" << std::endl;
                break;
        }
    }
}

#endif //FINANCE_GAME_HOMEPAGE_H