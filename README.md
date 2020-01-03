# API
This is a weather API application with C++ and Python.
Python File makes the API call, which returns a JSON File. It then writes the JSON to a JSON file, where C++ reads it, then displays it in the console.

I used Neil Lohmann's json.h file to read JSON files from C++. Here is the link to his GitHub: https://github.com/nlohmann/json

I used a free API from OpenWeatherAPI. Just sign up, and get your API Key! Here is the link: https://openweathermap.org/api

Please feel free to take a look! If you plan on using any code, just make sure to give me credit

*****************************************
****** INSTRUCTIONS TO RUN PROGRAM ******
*****************************************
1.	C++ Program, Main.cpp

a.	In line 98, where it starts, ‘system(…);’, you would need to enter in the directory of the .exe file of the python file (will show how to export python file into .exe).
  
b.	In line 164, you just need to change the directory of the weather.json file.
  
2.	Python File

  a.	I used PyCharm IDE to do this, as it has a built in terminal to export files as a .exe file.
  
  b.	Open the Weather API.py in PyCharm.
    
  c.	At the bottom, there is a button that says ‘Terminal’. Click it and enter, ‘pyinstaller Weather API.py’, then click enter. This will create a DIST folder within the folder/location of where the Weather API.py file is.
    
  d.	Open the DIST folder, then click ‘Weather API’, and at the bottom is the .exe file, named ‘Weather API’. Enter the directory for this .exe file to line 98 in the main.cpp file.
    
3.	Then run your program!
