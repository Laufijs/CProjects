#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sword.h"

Sword::Sword() : weight(2) , quality(1), critChance(1){} ;
Sword::Sword(int w, int q, int c){
    weight = (w >= 2 && w <= 5) ? w : (rand() % 4 + 2);
    quality = (q >= 1 && q <= 6) ? q : (rand() % 6 + 1);
    critChance = (c >= 1  && c <= 100) ? c : (rand() % 100 + 1) ;
    
}

int Sword::Damage(){
    int damage = weight * quality;
    int rng = rand() % 100 + 1 ;
    
    if(rng <= critChance){
    	damage *= 2 ; 
    	std::cout << "Critical Strike! "  ;
    }
    	WearAndTear();  
    	return damage ;
	
}

void Sword::WearAndTear(){
    if (quality > 1){
        quality--;
    }
}

void Sword::Sharpen(){
    if (quality + 2 > 6){
        quality = 6;
    } else {
        quality += 2;
    }
}
int Sword::getCritChance(){
	return critChance;
}
int Sword::getWeight(){
    return weight;
}

int Sword::getQuality(){
    return quality;
}

void Sword::getSwordInfo(){
    std::cout << "Sword weight: " << weight << "\nQuality: " << quality << "\nCrit Chance : " << critChance << std::endl;
}


