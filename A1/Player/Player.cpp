

#include "Player.h"
#include "Orders.h" //keep it for now, should be placed in the header file, but dont know why vs cannot detect it
#include <vector>
#include <iostream>
#include <algorithm>

using std::floor;
using std::cout;
using std::vector;
using std::sort;

Player::Player()
{
}


Player::Player(std::vector<Territory>& territories, Hand cards) {
    _territories = territories;
    _cards = cards;
}


//return territories that player owns
std::vector<Territory> Player::toDefend() {
    return _territories;

}

//return arbitrary list of territories to attack (As per A1 instructions)
std::vector<Territory> Player::toAttack() {
    return arbitraryTerritoriesToAttack;
}


//issue the order depending on what the player wants
void Player::issueOrder(int orderType) {

    switch (orderType) {
    case 1: {
        Deploy* deploy = new Deploy();
        _playerOrderList.addOrders(deploy);
        std::cout << "Troops deployed!\n";
        break;
    }

    case 2: {
        Advance* advance = new Advance();
        _playerOrderList.addOrders(advance);
        std::cout << "Troops advanced!\n";
        break;
    }

    case 3: {
        Bomb* bomb = new Bomb();
        _playerOrderList.addOrders(bomb);
        std::cout << "Bombed!\n";
        break;
    }


    case 4: {
        Blockade* blockade = new Blockade();
        _playerOrderList.addOrders(blockade);
        std::cout << "Blockade!\n";
        break;
    }

    case 5: {
        Airlift* airlift = new Airlift();
        _playerOrderList.addOrders(airlift);
        std::cout << "Calling Airlift!\n";
        break;
    }


    case 6: {
        Negotiate* negotiate = new Negotiate();
        _playerOrderList.addOrders(negotiate);
        std::cout << "Negotiating...";
        break;
    }

    }
}


void Player::printPlayerOrders() {

}

//Added


//Reinforcement phase
void reinforcementPhase(Map &map)
{

}

// to check if the player has all the territories of a continent
bool Player::getAllTerritories(Continent &continent)
{

    vector<string> continentTerr;
    vector<string> playerTerr;
    bool playerHaveAllTerritoriesOfTheContinent = false;
    //get all territories of the continent from the input
    for (int i = 0; continent.getTerritories().size(); i++) 
    {  
        for (int j = 0; j < continent.getTerritories()[i]->adjList.size(); j++)
        {
            string territoryName = continent.getTerritories()[i]->adjList[j].territory->getName();
            continentTerr.push_back(territoryName);
        }
    }
    //get all territories of the continent from the input

    //get all territories the player has
    for (int i = 0; _territories.size(); i++)
    {
        playerTerr.push_back(_territories[i].getName());
    }
    //get all territories the player has

    //compare
    if (isSubset(continentTerr, playerTerr))
    {
        playerHaveAllTerritoriesOfTheContinent = true;
    }
    else
    {
        playerHaveAllTerritoriesOfTheContinent = false;
    }
    //compare

    return playerHaveAllTerritoriesOfTheContinent;
    
}
// to check if the player has all the territories of a continent

bool isSubset(vector<string> A, vector<string> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return std::includes(A.begin(), A.end(), B.begin(), B.end());
}

int Player::distributeArmies(Territory& territory)
{
    int nbOfArmies = territory.getArmies();
    int ArmiesToDistribute = nbOfArmies/3; //even if it cant be distributed by 3, using integer will only gget the digit number.
    
    return ArmiesToDistribute;
}
//Reinforcement phase


//Orders issuing phase
void Player::issueOrdersPhase()
{
    
}

void Player::beforeAttack(Territory& territory)
{
    arbitraryTerritoriesToAttack.push_back(territory);
}

void Player::beforeDefend(Territory& territory)
{
    _territories.push_back(territory);
}

//Orders issuing phase


//Added
