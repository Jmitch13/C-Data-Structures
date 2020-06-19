#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory
{
private:
    vector<GroceryItem> _inventory;
    float _taxRate;
public:
    GroceryInventory()
    {
        //initializes the tax to 0
        _taxRate = 0.00;
    }
    GroceryItem& getEntry(const string &Name)
    {
        vector<GroceryItem>::iterator x;
        //recieves the inventory list from grocery item
        for (x = _inventory.begin(); x != _inventory.end(); x++)
        {
            GroceryItem &res = *x;
            if(res.getName() == Name)
              return res;
        }
      
    }
    //Adds the entry
    void addEntry(const string &_name, const int &_quantity, const float &_price, const bool &_taxable)
    {
        //Adds a new inventory slot at the end of the vector
        _inventory.push_back(GroceryItem(_name,_quantity, _price, _taxable));
    }
    //Returns the taxRate if the item is taxable
    float getTaxRate() const
    {
        return _taxRate;
    }
    void setTaxRate(const float& taxrate)
    {
        //Used to retireve the object's taxrate hidden by the local variable _taxRate
        this -> _taxRate = taxrate;
    }
    //createList takes all the information from shipment.txt
    //to then calculate the revenue later
    void createListFromFile(const string& filename) {
        ifstream input_file(filename);
        if (input_file.is_open()) {
            cout << "Successfully opened file " << filename << endl;
            string name;
            int quantity;
            float unit_price;
            bool taxable;
            //Reads all 4 parts of a product from the file into the program
            while (input_file >> name >> quantity >> unit_price >> taxable) {
                addEntry(name, quantity, unit_price, taxable);
            }
            input_file.close();
        } else {
            throw invalid_argument("Could not open file " + filename);
        }
    }
    float calculateUnitRevenue() const
    {
        float utotal = 0.0;
        for(int i = 0; i < _inventory.size(); i++)
        {
            utotal += (_inventory[i].getUnitPrice() * _inventory[i].getQuantity());
            //UnitRevenue
        }
        return utotal;
    }
    //Takes all the items that are taxed and adds the tax of those items together
    float calculateTaxRevenue() const
    {
        float tax = 0.0;
        for(int i = 0; i< _inventory.size(); i++)
        {
            tax += (_inventory[i].getUnitPrice() * _inventory[i].getQuantity() * getTaxRate());
        }
        return tax;
    }
    float calculateTotalRevenue() const
    {
        float totalR = 0.0;
        //Runs a for loop to add all the items in the array
        for(int i=0; i <_inventory.size();i++)
        {
            //Get the total unit price by multiplying the quanitity by the amount
            totalR += _inventory[i].getQuantity() * _inventory[i].getUnitPrice();
        }
        //Returns the revenue
        return totalR;
    }

    GroceryItem& operator[](const int& item)
    {
        //Keeps returning items if as long as there are items in the shipment
        if(item < _inventory.size())
            return _inventory[item];
    }
};
