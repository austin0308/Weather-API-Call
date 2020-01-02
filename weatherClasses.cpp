//
//  weatherClasses.cpp
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

#include <stdio.h>
#include "weatherHeader.h"
#include <string>

using namespace std;

//mutators
void weatherInfo::setTemp(int *temp) {tempurature = temp;};
void weatherInfo::setTempHigh(int *high) {tempuratureHigh = high;}
void weatherInfo::setTempLow(int *low) {tempuratureLow = low;}
void weatherInfo::setHumidity(int *humid) {humidity = humid;}
void weatherInfo::setWindSpeed(int speed) {windSpeed = speed;}
void weatherInfo::setCloudCover(int *cloud) {cloudCover = cloud;}
void weatherInfo::setCity(string c) {city = c;};
void weatherInfo::setCountry(string usa) {country = usa;}
void weatherInfo::setDescription(string desc) {description = desc;}

//accessors
string weatherInfo::getMessages(int i) const {return weatherMessages[i];}
int weatherInfo::getTemp() const {return *tempurature;}
int weatherInfo::getTempHigh() const {return *tempuratureHigh;}
int weatherInfo::getTempLow() const {return *tempuratureLow;}
int weatherInfo::getHumidity() const {return *humidity;}
int weatherInfo::getWindSpeed() const {return windSpeed;}
int weatherInfo::getCloudCover() const {return *cloudCover;}
string weatherInfo::getCity() const {return city;}
string weatherInfo::getCountry() const {return country;}
string weatherInfo::getDescription() const {return description;}
