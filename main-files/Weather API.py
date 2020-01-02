import requests
import json

# This Weather API Call program was
# created by Austin Le on 10/5/2019
# Email: le.austin2000@gmail.com

# First half of API URL
apiCall = "https://api.openweathermap.org/data/2.5/weather?zip="
# My API Key
apiKey = ",us&appid=e679c963c847aaf2fea95221eee2ec65"

# Asks for User Zip code
zipcode = input("\nPlease Enter Zip Code: ")

# puts the API URL together
apiURL = apiCall + str(zipcode) + apiKey

# makes the call, getting the JSON file
requestCall = requests.get(apiURL).json()

# may need to change directory to write to json file
# please scroll down to follow the instructions to export it as an exe file
# this opens the json file to write to
output = open('/Users/austinle/Documents/C++/Adv. C++/Week 5/Call Python File/Call Python File/weather.json', 'w')

# deletes existing contents within the json file
output.truncate()
# puts new json contents into file
json.dump(requestCall, output)

# don't forget to change the directory for the json file on line 30!
# (I did this in PyCharm IDE) Open the Python file in PyCharm, at the bottom is a buttom to open
# Terminal. Click that then enter "pyinstaller 'Weather API.py' > click enter
# if you still have issues, here is a link to a YouTube video: https://www.youtube.com/watch?v=OZSZHmWSOeM

# Once it is converted to exe, that will create a couple of folders within the source folder the script is in.
# It is in the folder named "dist".
# Then you need to change the directory within C++ for the " system("...") " statement to
# call the python exe file.



