#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;
class BrowserHistory {
private:
    list<Webpage> navHistory;
    list<Webpage>::iterator navPos;
    list<Webpage> sitesVisited;
    int numSites;
public:
    //Empty list constructer
    BrowserHistory()
    {
        navPos = navHistory.begin();
        navPos = sitesVisited.begin();
        numSites = 0;
    }
    //Adds element to back of list. Similar to List Append
    void visitSite(const Webpage &newSite)
    {
        //Checks to see if the time is greater than the previous element
        //If it is then it will delete it
        while(navPos -> getTime() < navHistory.back().getTime())
        {
            navHistory.pop_back();
            numSites--;
        }
        sitesVisited.push_back(newSite);
        navHistory.push_back(newSite);
        navPos++;
    }
    //Use iterator to go back
    string back()
    {
        //Use error check to see if the user can actaully go back
        if(navHistory.size() > 1)
        {
            //Decrement to simulate a back button
            --navPos;
        }
        else
        {
            navPos = navHistory.begin();
        }
        return navPos -> getUrl();
    }
    //use iterator to go forward
    string forward()
    {
        //Use error to check if forward can still be used
        if(navHistory.size() > sitesVisited.size())
        {
            throw std::logic_error("No further URL");
        }
        else
        {
            //Increment to go forward
            navPos++;
        }
        return navPos -> getUrl();
    }
    //Reads the information from the file name
    void readHistory(string fileName)
    {
        string temp;
        int newTime;
        Webpage newSite;
        ifstream inFile(fileName.c_str());
        while(inFile >> temp) {
            if(temp == "new") {
                inFile >> temp >> newTime;
                newSite = Webpage(temp, time_t(newTime));
                visitSite(newSite);
            } else if(temp == "back") {
                back();
            } else if(temp == "forward") {
                forward();
            } else {
                throw std::logic_error("invalid command");
            }
        }
    }
    //Gets the URL
    string getUrl()
    {
        //Checks to make sure the URL isn't empty
        if(!sitesVisited.empty())
        {
            return navPos -> getUrl();
        }
        else
        {
            //If the URl list is empty an error will occur
            throw logic_error("There is no URL");
        }
    }
    //Returns the size of NavSize list
    size_t getNavSize()
    {
        return navHistory.size();
    }
    //Returns the sites visited
    list<Webpage> getSitesVisited()
    {
        return sitesVisited;
    }
    
};
