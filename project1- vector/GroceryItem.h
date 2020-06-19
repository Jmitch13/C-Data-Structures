#pragma once
#include <string>
using namespace std;

class GroceryItem {
private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;
public:
    //default constructer
    GroceryItem()
    {
        _name = " ";
        _quantity = 0;
        _unitPrice = 0.99;
        _taxable = false;
    }
    //Constructer
    GroceryItem(const string& n, const int& q, const float& u, const bool& t)
    {
        _name = n;
        _quantity = q;
        _unitPrice = u;
        _taxable = t;
    }
    void setName(const string& n)
    {
        _name = n;
    }
    //returns the name of the item
    string getName() const
    {
        return _name;
    }
    void setQuantity(const int& q)
    {
        _quantity = q;
    }
    //returns the quantity value
    int getQuantity() const
    {
        return _quantity;
    }
    void setUnitPrice(const float& u)
    {
        _unitPrice = u;
    }
    //returns the unit price
    float getUnitPrice() const
    {
        return _unitPrice;
    }
    void setTaxable(const bool& t)
    {
        _taxable = t;
    }
    //Returns whether the item is taxable or not
    bool isTaxable() const
    {
        return _taxable;
    }
};


