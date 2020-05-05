#include "ProductManager.h"
#include <iostream>
#include <iomanip>

void ProductManager::add() {
	Product* productToAdd = getNewProduct();
	if (productToAdd != nullptr) {
		products.push_back(productToAdd);
	}
}

Product* ProductManager::getNewProduct() {
	std::cout << "Enter type of product to add:\n";
	char* type = new char[20];
	std::cin >> type;
	Product* p;
	if (strcmp(type, "laptop") == 0) {
		p = new Laptop();
	}
	else if (strcmp(type, "phone") == 0) {
		p = new Phone();
	}
	else if (strcmp(type, "shirt") == 0) {
		p = new Shirt();
	}
	else if (strcmp(type, "sneakers") == 0) {
		p = new Sneakers();
	}
	else if (strcmp(type, "tshirt") == 0) {
		p = new TShirt();
	}
	else {
		std::cout << "Wrong type of product.\n" << std::endl;
		return nullptr;
	}
	std::cout << "Enter a new product:" << std::endl;
	std::cin >> *p;

	delete[] type;

	return p;
}

void ProductManager::change() {
	std::cout << "Enter number of product to change:";
	int pos;
	std::cin >> pos;
	if (0 <= pos && pos < products.getSize()) {
		Product* productToAdd = getNewProduct();
		if (productToAdd != nullptr) {
			products[pos] = productToAdd;
		}
	}
	else {
		std::cout << "Wrong number" << std::endl;
	}
}

void ProductManager::remove() {
	std::cout << "Enter number of product to remove:";
	int pos;
	std::cin >> pos;
	products.remove(pos);
}

void ProductManager::print() const {
	std::cout << products << "\n";
}