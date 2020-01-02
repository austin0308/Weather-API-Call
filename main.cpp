//
//  main.cpp
//  Call Python File
//
//  Created by Austin Le on 10/17/19.
//  Email: le.austin2000@gmail.com
//  Copyright © 2019 Austin Le. All rights reserved.
//


/*
 I, Austin Le, do not claim to the header file, json.h, to be my work.
 I created the classes, weatherHeader.h, and the main but used Neils json
 library/header file to read the JSON file.
 Please see the legal information in the json.h.
*/


/*
    __ _____ _____ _____
 __|  |   __|     |   | |  JSON for Modern C++
|  |  |__   |  |  | | | |  version 3.7.0
|_____|_____|_____|_|___|  https://github.com/nlohmann/json

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2013-2019 Niels Lohmann <http://nlohmann.me>.

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "weatherHeader.h"
#include "json.h"


//This programs calls a python application, which makes an API call to get weather.
//The user enters in the zipcode, and it will display the current weather
//The python file makes the request, then rights the JSON to a JSON file.
//Then I have C++ read the JSON File and display it out.

//Here is the link to the API I used.
//https://openweathermap.org/current

using namespace std;

//function prototype
//reads the josn file and displays
//the current weather information.
int readAndDisplayJSON();
void getZip();

int main(int argc, const char * argv[]) {

    getZip();
    
    return 0;
}
void getZip()
{
    //creating an object of weather Info class
    weatherInfo messages;
    
    //string to hold user response
    string yesOrNo = "y";
    
    //while loop to continue asking the user
    //for a zip code to display weather information
    while (yesOrNo == "y" || yesOrNo == "Y" || yesOrNo == "Yes" || yesOrNo == "yes" || yesOrNo == "YES")
    {
        //try catch statement to catch
        //when the user enters in an invalid zip
        try
        {
            int i = 0;
            //may need to change directory to locate exe file
            //put in ' ' if the folder/any other type of file, name has spaces
            system("/Users/austinle/Documents/Python/Weather/dist/'Weather API'/'Weather API'");
            
            //this is the variable that holds
            //wahtever is returned from the readAndDisplay() function
            int temp = readAndDisplayJSON();
            
            //if statement to check the 'temp'
            //variable and displays the appropriate message
            if (temp < 30)
            {
                i = 0;
            }
            else if (temp < 50)
            {
                i = 1;
            }
            else if (temp < 60)
            {
                i = 2;
            }
            else if (temp < 70)
            {
                i = 3;
            }
            else if (temp < 80)
            {
                i = 4;
            }
            else if (temp < 90)
            {
                i = 5;
            }
            //sets messages with the variable
            // 'i'
            //gets the message and displays to user.
            cout << messages.getMessages(i) << endl;
        
        }
        //catches if there was an invalid zip entered
        catch (const exception &ex)
        {
            //tells the user that it was invalid
            cout << "\n\n***** Invalid Zip Code Entered. Please Try Again. *****\n" << endl;
        }
        
        //asks the user enter in another zip code
        //enter 'n' will break the loop and end the program
        cout << "\n\n\n\n\nWould You Like to Check Another City? [y]es or [n]o" << endl;
        cin >> yesOrNo;
    }
    
    //thanks the user for using the program
    cout << "\n\n\n\nThanks For Checking the Weather! Enjoy your day!\n" << endl;
}

int readAndDisplayJSON()
{
    using json = nlohmann::json;
    
    //creating an object of the class weather info
    weatherInfo weather;
    
    //creates a reader variable
    ifstream reader;
    
    //may need to change directory to read the json file.
    reader.open("/Users/austinle/Documents/C++/Adv. C++/Week 5/Call Python File/Call Python File/weather.json");
    
    if (reader.is_open())
    {
        //creates an object of json.h
        json getJson;
        
        //reads the file
        reader >> getJson;
        
        //variables to hold contents from json file
        int *temp = new int;
        int *tempHigh = new int;
        int *tempLow = new int;
        int windSpeed;
        int *humidity = new int;
        int *cloudCover = new int;
        
        
        //used to convert wind speed to MPH
        //defaults to meters per second
        const double windSpeedConversion = 2.237;
        string city, country, description;
        
        //getting/assigning the variables with the information
        //from the JSON file.
        *temp = getJson["main"]["temp"];
        *tempHigh = getJson["main"]["temp_max"];
        *tempLow = getJson["main"]["temp_min"];
        *humidity = getJson["main"]["humidity"];
        windSpeed = getJson["wind"]["speed"];
        *cloudCover = getJson["clouds"]["all"];
        city = getJson["name"];
        country = getJson["sys"]["country"];
        description = getJson["weather"][0]["description"];
                
        //makes the first letter of the
        //description capitalized.
        description[0] = toupper(description[0]);

        //capitalizes the first letter of every word
        //in the description.
        for (int i = 0; i < description.length(); i++)
        {
            char space = ' ';
            if (description[i] == space)
            {
                description[i + 1] = toupper(description[i + 1]);
            }
        }
        
        //converts tempurature to F.
        //defaults to Kelvin when making the
        //API call.
        *temp = ((*temp - 273.15) * 9 / 5) + 32;
        *tempHigh = ((*tempHigh - 273.15) * 9 / 5) + 32;
        *tempLow = ((*tempLow - 273.15) * 9 / 5) + 32;
        
        //converts to MPH, API defaults to meters per second
        windSpeed*=windSpeedConversion;
        
        //setting the objects with the
        //information
        weather.setTemp(temp);
        weather.setTempHigh(tempHigh);
        weather.setTempLow(tempLow);
        weather.setHumidity(humidity);
        weather.setCloudCover(cloudCover);
        weather.setWindSpeed(windSpeed);
        weather.setCity(city);
        weather.setCountry(country);
        weather.setDescription(description);
        
        //displaying the results for the weather
        cout << "\n\n\n\n\n\n\n\n*----------------------------*" << endl;
        cout << "| City: " << weather.getCity() << ", " << weather.getCountry() << endl;
        cout << "| Description: " << weather.getDescription() << endl;
        cout << "| Current Temperature: " << weather.getTemp() << "°F" << endl;
        cout << "| Max Temperature: " << weather.getTempHigh() << "°F" << endl;
        cout << "| Minimum Temperature: " << weather.getTempLow() << "°F" << endl;
        cout << "| Wind Speed: " << weather.getWindSpeed() << " MPH" << endl;
        cout << "| Humidity: " << weather.getHumidity() << "%" << endl;
        cout << "| Cloud Coverage: " << weather.getCloudCover() << "%" << endl;
        cout << "*----------------------------*" << endl;
        //closes reader
        reader.close();
        
        //deallocates pointers
        delete temp;
        delete tempHigh;
        delete tempLow;
        delete humidity;
        delete cloudCover;
    }
    else
    {
        //error message when the file cannot be found/read
        cout << "\nError Opening/Reading the File. Please Check Directory\n" << endl;;
    }
    
    //returns the high temp which will display the
    //appropriate message
    return weather.getTempHigh();
}
