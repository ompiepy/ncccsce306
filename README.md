# Lab 5: Fruit Class File in C++
This file makes the API call and gets the data from [USDA FoodData Central](https://fdc.nal.usda.gov/fdc-app.html#/).

## Prerequsites
- libcurl
```
# To install in Linux
sudo apt-get install libcurl4-nss-dev
```
- Make (GNU Make)
> This should be installed by deafult in Linux. Verify using ```make -v```. This should give some output showing its version.

## Usage:
```
git clone -b lab5 https://github.com/ompiepy/ncccsce306.git
cd ncccsce306
make API_KEY="YOUR_API_KEY"
```
> Remember to replace YOUR_API_KEY with your API Key. You can get one from [here](https://www.ers.usda.gov/developer/data-apis/#apiForm).

## Output
![output](output.png)

## Project Idea
https://shorturl.at/cmsK6