/*
Задание 1. Многоквартирный дом

На вход программе поступают десять фамилий в формате строк.Это фамилии жильцов квартир 
с первой по десятую.Необходимо прочитать эти фамилии и записать в одномерный массив.Далее 
пользователь вводит три номера квартир.Необходимо вывести в консоль фамилию жильца, 
проживающего в этой квартире.Если пользователь введёт некорректный номер квартиры, 
необходимо сообщить ему об этом.
*/

#include <iostream>
#include <string>

int main()
{
	//init block
	std::string nameApartments[10];
	int numberAprtment;

	// Input data in string array
	std::cout << "Input data apartments." << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "Input name leaved " << ++i << " in apartment: ";
		i--;
		std::cin >> nameApartments[i];
	}

	//Get data from array
	std::cout << "Input number 3 apartments." << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "Input number apartment: ";
		std::cin >> numberAprtment;
		if (numberAprtment < 1 || numberAprtment > 10) {
			std::cout << "Incorrect number aprtment!" << std::endl;
			i--;
		}
		else {
			numberAprtment--;
			std::cout << "In apartment leaved " << nameApartments[numberAprtment] << std::endl;
		}
	}



}
