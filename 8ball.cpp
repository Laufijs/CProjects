/*
 * Program Name: 8ball ;
 * Author: [Laufy] ;
 * Date: [29/10/2024] ;
 * Description: ask a question and get different answer every time ;
 * Copyright (c) [2024] [Laufy] ;
 * Note: Feel free to modify / share this code as long as credit is given to the original author. ;
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
	time_t t;
	srand((unsigned) time(&t)) ;
	
	
		std::string x ;
		int y ;		
		std :: cout << "When you're ready, enter your question, when you are done, type exit." << std::endl ;
		
	while(true){
		std::cout << "Enter your question : " ;
		std::getline(std::cin, x) ;
		
		if(x == "exit"){
			break ;
			}
				
		y = 1 + rand() % (19-1+1) ;
		
	switch(y){
		case 1:
		std::cout<<"It is certain!" << std::endl;
		break  ;
			case 2 :
			std::cout<<	"It is decidedly so." << std::endl;
			break;
				case 3 : 
				std::cout<<"Without a doubt!" << std::endl;
				break;
					case 4 :
					std::cout << "You may rely on it." << std::endl;
					break;
						case 5:
						std::cout << "As I see it, yes."<< std::endl;
						break;
							case 6:
							std::cout << "Most likely!"<< std::endl	 ;
							break ;
								case 7:
								std::cout << "Outlook good!" << std::endl;
								break ;
									case 8:
									std::cout << "Yes!" << std::endl;
									break ;
										case 9:
										std::cout << "Signs point to yes." << std::endl;
										break ;
											case 10:
											std::cout << "Reply hazy try again." << std::endl;
											break ;
												case 11:
												std::cout << "Ask again later." << std::endl;
												break ;
													case 12:
													std::cout << "Better not tell you now." << std::endl;
													break ;
														case 13:
														std::cout << "Cannot predict now." << std::endl;
														break ;
															case 14:
															std::cout << "Concentrate and ask again." << std::endl;
															break ;
																case 15:
																std::cout << "Don't count on it." << std::endl;
																break ;
																	case 16:
																	std::cout << "My reply is no." << std::endl;
																	break ;
																		case 17:
																		std::cout << "My sources say no." << std::endl;
																		break ;
																			case 18:
																			std::cout << "Outlook not so good." << std::endl;
																			break ;
																				case 19:
																				std::cout << "Very doubtful." << std::endl;
																				break ;																		
																					default :
																					std::cout << "Ask different question" << std::endl;
																					break;
								}
}
std::cout << "Well Played!" << std::endl ;
return 0 ;
}
















