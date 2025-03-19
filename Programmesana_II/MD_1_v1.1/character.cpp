#include <iostream>
#include <string>
#include "character.h"
#include "sword.h"
#include "shield.h"

Character::Character(std::string n, int L, int s, int w, int q, int c,int p, int x ){
	name = n;
	life = (L > 0 && L <= 100) ? L : (rand() % 100 + 1) ;
	strength = (s >= 1 && s <= 10) ? s : (rand() % 10 + 1) ;
	sw = Sword(w, q,c) ;
	sh = Shield(x, p);
	
	for(int i = 0 ;i < 10 ; i++){
		path[i] = ' ' ;
	}
}

std::string Character::getName(){
	return name;
}
bool Character::Hit(int x){
	std::cout << name << " for "<<x << " damage";
	life -= x ;
	if(life <= 0){
		life = 0 ;
		return false ;
	}else{
		return true ;
	}
}
int Character::Attack(){
	int totalDamage =  strength + sw.Damage() ;
//	std::cout << name << " hits " << totalDamage <<" of damage."<<std::endl;
	return totalDamage ;
}

int Character::Defence(){
	int totalDef = (strength/2) + sh.block() ;
//	std::cout << name << " deflects " << totalDef << " of damage."<<std::endl ;
	return totalDef ;
}
int Character::getLife(){
	return life ;
}
void Character::Print(){
	std::cout << "Character : " << name << std::endl ;
	if(life >0){
		std::cout << "Life : " << life << std::endl ;
	}else{
		std::cout << name << " travels to eternals halls of Valhalla" << std::endl ;
	}
	std::cout<<"Path : " ; 
	for(char x : path){
		if(x != ' '){
			std::cout << x << " " ;
		}
	}
		std::cout << std::endl ;
		sw.getSwordInfo() ;
		sh.getShieldInfo() ;
}

Character::~Character(){
	if(this->life <= 0){
	std::cout << "Game over for : "<< this ->getName() <<"."<< std::endl ;
	}
}

void Character::repairShield(){
	sh.repair() ;
//	std::cout << "Shield is looking fabulous!" << std::endl ;
	sh.getShieldInfo() ;
	std::cout << "----------------------------------------" << std::endl ;
}
void Character::sharpenSword(){
	sw.Sharpen();
//	std::cout << "Ready to slice and dice!" << std::endl ;
	sw.getSwordInfo() ;
	std::cout << "----------------------------------------" << std::endl ;
	
}
