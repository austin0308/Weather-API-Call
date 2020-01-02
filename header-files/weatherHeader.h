//
//  weatherHeader.h
//  Call Python File
//
//  Created by Austin Le on 10/17/19.
//  Copyright © 2019 Austin Le. All rights reserved.
//
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

/*
 I, Austin Le, do not claim to the header file, json.h, to be my work.
 I created the classes and the main but used Neils json
 library/header file to read the JSON file.
 Please see the legal information in the json.h.
*/

#ifndef weatherHeader_h
#define weatherHeader_h

#include <string>

using namespace std;

class weatherInfo
{
    
private:
    int *tempurature, *tempuratureHigh, *tempuratureLow, *humidity, windSpeed, *cloudCover;
    
    string city, country, description, weatherMessages[6];

public:
    weatherInfo()
    {
        //Messages for cold weather to display to user.
        //for when the temp is less than 30
        weatherMessages[0] = "\nWow! It's going to be REALLY cold.\nMake sure to grab your hat, gloves, and coat!";
        //for when the temp is less than 50
        weatherMessages[1] = "\nGrab a coat! It's going to be cold!";
        //for when temp is less than 60
        weatherMessages[2] = "\nNot a bad idea to grab a light jacket!\nIt's going to be a little chilly.";
        
        //messages for warm weather to display to user
        //for when temp is less than 70
        weatherMessages[3] = "\nIt's going to be nice today!\nPerhaps grabbing a light jacket isn't a bad idea?";
        //for when the temp is less than 80
        weatherMessages[4] = "\nIt's going to be hot!\nWear something breathable!";
        //for when the temp is less than 90
        weatherMessages[5] = "\nMan! It's super hot today.\nStay hydrated and wear sunscreen!";

    }
    //mutators, to set values
    //sets weather information
    void setTemp(int *);
    void setTempHigh(int *);
    void setTempLow(int *);
    void setHumidity(int *);
    void setWindSpeed(int);
    void setCloudCover(int *);
    void setCity(string);
    void setCountry(string);
    void setDescription(string);
    
    
    //accessors to get values
    //gets weather information
    int getTemp() const;
    int getTempHigh() const;
    int getTempLow() const;
    int getHumidity() const;
    int getWindSpeed() const;
    int getCloudCover() const;
    string getCity() const;
    string getCountry() const;
    string getDescription() const;
    //gets messages
    string getMessages(int) const;
    
};

#endif /* weatherHeader_h */
