#pragma once

#include <string>
using namespace std;

class Webpage {
private:
    string url;
    time_t time;
public:
    //Default Constructer
    Webpage()
    {
        url = " ";
        time = 0;
    }
    //Copy Constructer
    Webpage(const string& webpageUrl, const time_t& timeVisited)
    {
        url = webpageUrl;
        time = timeVisited;
    }
    //Sets the URL
    void setUrl(const string& webpageUrl)
    {
        url = webpageUrl;
    }
    //Returns the URL that the user visited
    string getUrl()
    {
        return url;
    }
    //Sets the time
    void setTime(const double& timeVisited)
    {
        time = timeVisited;
    }
    //Returns the time at which the user visited the webpage
    time_t getTime()
    {
        return time;
    }
};
