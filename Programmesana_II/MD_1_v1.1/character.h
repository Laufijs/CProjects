#pragma once
#include <string>
#include "shield.h"
#include "sword.h"

class Character{
	public:
		Character(std::string n, int l, int s, int w, int q, int p, int c, int x) ;
		bool Hit(int) ;
		int Attack() ;
		int Defence() ;
		int getLife() ;
		void Go(char) ;
		void Print() ;
		~Character() ;
		std::string getName();
		void repairShield() ;
		void sharpenSword() ;

	private:
		std::string name ;
		int life ;
		int strength ;
		char path[10] ;
		Sword sw ;
		Shield sh ;
	
};