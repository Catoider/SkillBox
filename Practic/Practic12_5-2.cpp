/*
Задание 2. Сортировка
	Пользователь вводит в консоль 15 дробных чисел. Необходимо 
	прочитать их и вывести в консоль в порядке от большего к 
	меньшему. По возможности используйте минимум дополнительной 
	памяти и проходов по массиву.

	Ввод: 1.2 2.3 1.11 3.4 5.5 5.4 5.3 5.1 1.5 1.25 5.41 5.31 5.11 1.51 1.251 
	Вывод: 5.5 5.41 5.4 5.31 5.3 5.11 5.1 3.4 2.3 1.51 1.5 1.251 1.25 1.2 1.11
*/

#include <iostream>
#include <string>

/******************************************************************
*	Строит двоичное дерево от максимального значения к меньшему
*******************************************************************/
void heapify(double arr[], int sizeArray, int currentIndex) {
	//	arr:	массив с которым производится работа
	//	sizeArray:	размер массива
	//	currentIndex:	текущий индекс
	
	int largeIndex = currentIndex;
	int leftChild = 2 * currentIndex + 1;
	int rightChild = 2 * currentIndex + 2;
	
	//	Находит максимальный индекс и сохраняет его в память 
	//	leftChild/rightChild < sizeArray || Выход за пределы массива
	//	arr[leftChild] > arr[largeIndex] || Сравниваем значения
	if (leftChild < sizeArray && arr[leftChild] > arr[largeIndex])
		largeIndex = leftChild;	

	if (rightChild < sizeArray && arr[rightChild] > arr[largeIndex])
		largeIndex = rightChild;

	//	Делаем больший элемент корневым и повторяем пока больший 
	//	элемент не станет корневым в куче
	if (largeIndex != currentIndex) {
		std::swap(arr[currentIndex], arr[largeIndex]);
		heapify(arr, sizeArray, largeIndex);
	}
}

/******************************************************************
*	Пирамидальная сортировка(Куча, Двоичное дерево)
*******************************************************************/
void heapSort(double arr[], int sizeArray) {
	//	arr:	массив с которым производится работа
	//	sizeArray:	размер массива
	
	//	Строим двоичное дерево
	for (int i = sizeArray / 2 - 1; i >= 0; i--)
		heapify(arr, sizeArray, i);

	//	 Сортируем массив от меньшего к большему
	for (int i = sizeArray - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);	//Больший элемент в конец
		heapify(arr, i, 0);			//Сортируем
	}
}

/******************************************************************
*	Выводим массив в консоль
*******************************************************************/
void printArray(double arr[], int sizeArray, bool revers = false)
{
	//	arr:	массив с которым производится работа
	//	sizeArray:	размер массива
	//	revers:	режим работы (true - в обратном порядке)

	if(revers)
		for (int i = sizeArray-1; i >= 0; i--)
			std::cout << arr[i] << " ";
	else
		for (int i = 0; i < sizeArray; i++)
			std::cout << arr[i] << " ";
	std::cout << "\n";
}

int main()
{
	double arrDouble[15];
	double input = 0;
	int numbers = 0;

	std::cout << "Input count numbes: ";
	std::cin >> numbers;
	std::cout << "Input " << numbers << " double numbers: " << std::endl;
	
	for (int i = 0; i < numbers; i++) {
		std::cin >> input;
		arrDouble[i] = input;
	}
	
	heapSort(arrDouble, numbers);
	printArray(arrDouble, numbers, true);
}