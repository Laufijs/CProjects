/*
 * Program Name: simple math ;
 * Author: [Laufy] ;
 * Date: [04/11/2024] ;
 * Description: Simple practice for math equations. ;
 * Copyright (c) [2024] [Laufy] ;
 * Note: Feel free to modify / share this code as long as credit is given to the original author. ;
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

void math(const std::string& userActionYes, const std::string& userActionNo) ;
		
		std::string answer ;
		std::string userActionYes = "yes" ;
		std::string userActionNo = "no" ;
		
int main(){
		
		
			std::cout << "Are you ready to solve some simple math equations? yes/no : " ;
			std::getline(std::cin, answer) ;
				
		if(answer == userActionYes){
			math(userActionYes, userActionNo) ;
		}else{
			std::cout << "Thanks for playing! " ;
		}
	return 0 ;
}
	
void math(const std::string& userActionYes, const std::string& userActionNo){
		time_t t ;
		srand((unsigned) time(&t)) ;
		
	while(true){
			int userAnswer;
			int correctAnswer ;
			int randomNumb1 = -10 + rand() % 21 ;
			int	randomNumb2 = -10 + rand() % 21 ;
			int x = 1 + rand() % 4 ;
			
			if(x == 4 ){
				while( randomNumb2 == 0 || randomNumb1 % randomNumb2 != 0){	
					randomNumb1 = -10 + rand() % 21 ;
					randomNumb2 = -10 + rand() % 21 ;
				}
			}
			
			std::cout << " Solve the following equation : " ;
			switch(x){
				case 1 :
				std::cout << randomNumb1  << " + " << randomNumb2 << " = ";
				correctAnswer = randomNumb1 + randomNumb2 ;
				break ;
					case 2 :
					std::cout << randomNumb1 << " - " << randomNumb2 << " = ";
					correctAnswer = randomNumb1 - randomNumb2 ;
					break;
						case 3 :
						std::cout << randomNumb1 << " * " << randomNumb2 << " = ";
						correctAnswer = randomNumb1 * randomNumb2 ;
						break;
							case 4 :
							std::cout << randomNumb1 << " / " << randomNumb2 << " = ";
							correctAnswer = randomNumb1 / randomNumb2 ;
							break;
		}
		
		std::cin >> userAnswer ;
		
		if(userAnswer == correctAnswer){
			std::cout << "Correct!" ;
		} else {
			std::cout << " Wrong, the correct anwer is : " << correctAnswer << std::endl ;
		}
		
			std::cout << " Do you wish to play again? yes / no : " ;
			std::cin >> answer ;
			
			if(answer == userActionYes){
				std::cout << "Good luck! " ;
			} else if (answer == userActionNo){
				std::cout << "Thanks for playing!" ;
				break;
		}
	}
}
	

	
