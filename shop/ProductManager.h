#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H
#include "Laptop.h"
#include "Phone.h"
#include "Shirt.h"
#include "Sneakers.h"
#include "TShirt.h"
#include <vector>

class ProductManager {
private:
	std::vector<Product*> products;

	ProductManager() { }

	Product* getNewProduct();
public:
	static ProductManager& getInstance() {
		static ProductManager instance;
		return instance;
	}

	const int& getNumProducts() const { return products.size(); }
	Product* getProduct(const int& pos) const { return products[pos]; }

	void add();
	void change();
	void remove();
	void print() const;
};

#endif