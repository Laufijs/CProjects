#include <iostream>
#include "shield.h"

Shield::Shield() : size(0) , protection(1){};
Shield::Shield(int s, int p){
	size = (s >= 0 && s <= 4) ? s : rand() % 4 + 1 ;
	protection = (p >= 1 && p <= 4) ? p : rand() % 4 + 1 ;
}

int Shield::block(){
	int def =  size*protection ;
	destruction();
	return def ;
}
void Shield::destruction(){
	if(size > 0){
		size-- ;
	}
}
void Shield::repair(){
	if(size + 2 > 4){
		size = 4 ;
	}else{
		size += 2 ;
	}
}
int Shield::getProtection(){
	return protection ;
}
int Shield::getSize(){
	return size ;
}
void Shield::getShieldInfo(){
	std::cout << "Shield size : " << size << "\nShield protection : " << protection << std::endl ;
}