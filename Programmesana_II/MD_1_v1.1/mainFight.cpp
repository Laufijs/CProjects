#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <thread>
#include <chrono>
#include "sword.h" 
#include "shield.h"
#include "character.h"

 bool Fight(Character& char1, Character& char2){
 	
	 int attackChar2 = char1.Attack() - char2.Defence();
	 int attackChar1 = char2.Attack() - char1.Defence() ;
	 
	 	if(attackChar2 > 0 ){
	 		std::cout << char1.getName() << " hits " ;
	 		char2.Hit(attackChar2) ;
	 		std::cout << " and "<<char2.getName()<<" is left with "<< char2.getLife() << " LIFEPOINTS." << std::endl ;
		}
		if(char2.getLife() >0 && attackChar1 > 0  ){
			std::cout << char2.getName() << " hits " ;
			char1.Hit(attackChar1) ;
			std::cout << " and "<<char1.getName()<<" is left with "<< char1.getLife() << " LIFEPOINTS." << std::endl ;
 		}
	 	std::cout << "----------------------------------------" <<std::endl ;

			if(char1.getLife() <= 0 ){
 	std::cout << char2.getName() << " is VICTORIOUS! While "<< char1.getName() << " travels to eternal halls of Valhala! " << std::endl;
 	std::cout << "----------------------------------------" <<std::endl ;
 	char1.Print() ;
 	std::cout << "----------------------------------------" <<std::endl ;
 	char2.Print() ;
 		return false ;
	}else if(char2.getLife() <= 0){
	std::cout << char1.getName() << " is VICTORIOUS! While "<< char2.getName() << " travels to eternal halls of Valhala! " << std::endl ;
	std::cout << "----------------------------------------" <<std::endl ;
	char1.Print() ;
 	std::cout << "----------------------------------------" <<std::endl ;
 	char2.Print() ;
		return false;
	}
				return char1.getLife() > 0 && char2.getLife() > 0 ;
}
void menu(){
	std::cout <<"----------------------------------------" << std :: endl ;
	std::cout << "MAIN MENU" <<std::endl ;
	std::cout << "1.Create new Character ;" <<std::endl ;
	std::cout << "2.Create new Opponent ;" <<std::endl ;
	std::cout << "3.Start the Fight ;" <<std::endl ;
	std::cout << "4.Start Auto Fight ;" <<std::endl ;
	std::cout << "5.Display menu ;" <<std::endl ;
	std::cout << "6.Exit Game ;" <<std::endl ;
	std::cout << "7.Reset both characters to Default"<<std::endl ;
	std::cout <<"----------------------------------------" << std :: endl ;
}
int skyNet(){
	return rand() % 2 + 1;
}
 int main(){
	srand(time(nullptr)); 
 	int option  ;
 	bool gameOn = true ;
 		std::string userName, userName2;
		int hp, str, sWeight, sQual, sCrit, shProt, shSize, hp2, str2, sWeight2, sQual2, sCrit2, shProt2, shSize2;
		
 	Character user("Default_User" , 99, 8 , 3, 4, 10, 10 , 4) ;
 	Character user2("SkyNet", 99, 7, 4, 4, 10, 8, 4) ;
	
	menu() ;

	while(gameOn){
	
	char key = getch()  ;
	option = key - '0' ;
	std::cout <<"Option Nr. : "<< option << std::endl ;
	std::cout << std::endl ;
	 	
	 
	switch(option){
		case 1: {
			std::cout << "Out of bound entries will be set to random."<< std::endl ;
			std::cout << "Enter your characters name : " ;
			std::cin >> userName ;
			
			std::cout << "Enter your life points (1-100) : " ;
			std::cin >> hp ;
			
			std::cout << "Enter your characters strength (1-10) : ";
			std::cin >> str ;
			
			std::cout << "Enter weight of the sword (2 -5) : " ;
			std::cin >> sWeight ;
			
			std::cout << "Enter quality of the sword (1 - 6) : " ;
			std::cin>>sQual ;
			
			std::cout << "Enter swords critical chance (1 - 100) : ";
			std::cin>>sCrit ;
			
			std::cout << "Enter shield protection rate (1 - 4) : " ;
			std::cin >> shProt ;
			
			std::cout << "Enter shield quality rate (0-4) : ";
			std::cin>>shSize ;
			
			user = Character(userName, hp, str, sWeight, sQual, sCrit, shProt, shSize) ;
			std::cout << "New character : " << user.getName() << " has been created!" << std::endl ;
			user.Print() ;
			menu() ;
			break;
		}
		case 2:{
			std::cout << "Out of bound entries will be set to random."<< std::endl ;
			std::cout << "Enter your characters name : " ;
			std::cin >> userName2 ;
			
			std::cout << "Enter your life points (1-100) : " ;
			std::cin >> hp2 ;
			
			std::cout << "Enter your characters strength (1-10) : ";
			std::cin >> str2 ;
			
			std::cout << "Enter weight of the sword (2 -5) : " ;
			std::cin >> sWeight2 ;
			
			std::cout << "Enter quality of the sword (1 - 6) : " ;
			std::cin>>sQual2 ;
			
			std::cout << "Enter swords critical chance (1 - 100) : ";
			std::cin>>sCrit2 ;
			
			std::cout << "Enter shield protection rate (1 - 4) : " ;
			std::cin >> shProt2 ;
			
			std::cout << "Enter shield quality rate (0-4) : ";
			std::cin>>shSize2 ;
			
			user2 = Character(userName2, hp2, str2, sWeight2, sQual2, sCrit2, shProt2, shSize2) ;
			std::cout << "New opponent : " << user2.getName() << " has been created!" << std::endl ;
			user2.Print() ;
			menu();
			break;
		}
		////////////////////////////////////////////////////////////////////////////////////////////
		case 3:{
			bool userFight = true ; 		

			if(user.getLife() == 0){
				std::cout << "Resetting " << user.getName() << " to default parameters" << std::endl ;
				user = Character ("Default_User" , 99, 8 , 3, 4, 10, 10 , 4) ;
			}else if(user2.getLife() == 0){
				std::cout << "Resetting " << user2.getName() << " to default parameters" << std::endl ;
 				user2 =	Character ("SkyNet", 99, 7, 4, 4, 10, 8, 4) ;
			}
			
		if(user.getLife() == 99 &&  user2.getLife() == 99  ){
 			std::cout << "Using default parameters." <<std::endl ;
 			std::cout<< std::endl ;
		 }
			while(userFight){ // user.getLife()>0 && user2.getLife() >0
 				std::cout << "Choose your action : " << std::endl ;
 				std::cout << "1.Attack your opponent;"<<std::endl ;
 				std::cout<<"2.Sharpen your sword ;"<<std::endl ;
 				std::cout << "3.Repair your shield ; " << std::endl ;
 				std::cout << "4.Surrender" << std::endl ;
 				std::cout << "----------------------------------------" << std::endl ;
 					
					int skyNetChoice = skyNet() ;
 					char x = getch() ;
 					int choice = x - '0' ;
 					switch(choice){
				 	case 1 :{
 						if(Fight(user, user2)){
 							std::cout << "You attack "<<user2.getName()<<"!"<<std::endl ;
						}
						 break ;
						}
					case  2:{
						std::cout <<user.getName() << " upgrades his weaponry. ATTACK+" << std::endl ;
						user.sharpenSword() ;
						break;
					}	
					case 3:{
						std::cout << user2.getName() << " fortifies his positions. DEFENCE+" << std::endl ;
						user.repairShield();
						break;
					}
					case 4 :{
						std::cout << "Fear strikes your heart and you run away!" << std::endl ;
						userFight = false ;
						skyNetChoice = 4 ;
						break;
					}
					default : {
						std::cout << "Use choices from 1 to 3!" << std::endl ;
						break;
					}
			}
					if(!gameOn){
				break ;
			}
			switch(skyNetChoice){
				case 1 :{
					std::cout << user2.getName() <<" attacks you! " << std::endl ;
					Fight(user2, user) ;
					break;
				}
				case 2 :{
					std::cout <<user2.getName() << " upgrades his weaponry. ATTACK+" << std::endl ;
					user2.sharpenSword() ;
					break;
				}
				case 3 : {
					std::cout << user2.getName() << " fortifies his positions. DEFENCE+" << std::endl ;
					user2.repairShield() ;
					break;
				case 4 : {
					std::cout << user2.getName() << "Laughs, as you flee!" << std::endl ;
					break;
				}		
		}
	}			
}
						userFight = false ;
					std::cout << "Returning to menu..." << std::endl ;
				menu();
    		break;	
		}
		////////////////////////////////////////////////////////////////////////////////////////////
		case 4:{
		std::cout << "Auto fight ON!" << std::endl;
   		std::cout << std::endl;

   		while(true) { // user.getLife() > 0 && user2.getLife() > 0
    
    		if(user.getLife() == 0){
				std::cout << "Resetting " << user.getName() << " to default parameters" << std::endl ;
				user = Character("Default_User" , 99, 8 , 3, 4, 10, 10 , 4) ;
				break;
			}else if(user2.getLife() == 0){
				std::cout << "Resetting " << user2.getName() << " to default parameters" << std::endl ;
 				user2 = Character("SkyNet", 99, 7, 4, 4, 10, 8, 4) ;
 				break;
			}
			
        int skyNetChoiceUser = skyNet(); 
   	     	switch (skyNetChoiceUser) {
            case 1:{
                std::cout << user.getName() <<" attacks!" << std::endl;
                Fight(user, user2);
                break;
            }
            case 2:{
                std::cout << user.getName() << " sharpens their sword." << std::endl;
                user.sharpenSword();
                break;
            }
            case 3: {
                std::cout << user.getName() << " repairs their shield." << std::endl;
                user.repairShield();
                break;
            }
        }
        int skyNetChoiceOpponent = skyNet();  
        	switch (skyNetChoiceOpponent) {
            case 1:{
                std::cout << user2.getName() << " attacks!" << std::endl;
                Fight(user2, user);
                break;
            }
            case 2:{
                std::cout << user2.getName() << " sharpens their sword." << std::endl;
                user2.sharpenSword();
                break;
            }
            case 3: {
                std::cout << user2.getName() << " repairs their shield." << std::endl;
                user2.repairShield();
                break;
            }
        }
        
		std::cout << user.getName() << ": " << user.getLife() << " life points." << std::endl;
        std::cout << user2.getName() << ": " << user2.getLife() << " life points." << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(2)); // https://stackoverflow.com/questions/21521282/basic-timer-with-stdthread-and-stdchrono
    		
		}
					std::cout << "Returning to menu..." << std::endl ;
				menu();
    		break;	
	}
		case 5:{
			menu() ;
			break;
		}
		case 6:{
			std::cout << "Exiting game..." ;
			gameOn = false ;
			break;
		}
		case 7:{
			std::cout << "Resetting both characters" << std::endl ;
			 	Character user("Default_User" , 99, 8 , 3, 4, 10, 10 , 4) ;
 				Character user2("SkyNet", 99, 7, 4, 4, 10, 8, 4) ;
			break;
		}
		default :{
			std::cout << "Please use number from 1 to 6 only!" <<std::endl ;
			break;
		}
	} 
}	

return 0;
}
