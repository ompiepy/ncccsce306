// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: main.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab #5 - Fruit Class File in C++
// Description: This file makes the API call and gets the data from USDA FoodData Central
// (https://fdc.nal.usda.gov/fdc-app.html#/)
// --------------------------------------------------------------------------------------

# include <iostream> // Standard Console Input Output
# include <fstream> // Strandard File Input Output
# include "fruit.h" // Definition of fruit data and functions
# include "mycurl.h" // Implementation of libcurl: See https://curl.se/libcurl/ for more details
# include "json.hpp" // Implementation of nlohmann/json.hpp: See https://github.com/nlohmann/json for more details
# include <string> // Standard String Library

using json = nlohmann::json; // Defining scope for nlohmann namesapce

int main(int argc,char** argv){
    //Apple
    std::string url_apple = "https://api.nal.usda.gov/fdc/v1/food/1750339?api_key=";
    url_apple = url_apple.append(argv[1]); //Appends API Key passed from terminal
    myCurl(url_apple); //Generates the JSON response in file response.json
    
    std::ifstream ifs_apple("response.json"); // Reads JSON data from response.json
    json data; // JSON object
    ifs_apple >> data; // Writes from buffer to JSON data

    // Calls Fruit constructor
    Fruit apple(data["description"], "Portion size", 100, "grams", "Energy (Atwater General Factors)", findNutrientAmount(data, "Energy (Atwater General Factors)"), findNutrientUnit(data, "Energy (Atwater General Factors)"),
            "Protein", findNutrientAmount(data,"Protein"), findNutrientUnit(data,"Protein"),
            "Total lipid (fat)", findNutrientAmount(data,"Total lipid (fat)"), findNutrientUnit(data,"Total lipid (fat)"),
            "Carbohydrates", findNutrientAmount(data,"Carbohydrate, by summation"), findNutrientUnit(data,"Carbohydrate, by summation"));
    // Displays fruit information
    apple.ToString(apple);
    ifs_apple.close(); //Destrys buffer

    //kiwi
    std::string url_kiwi = "https://api.nal.usda.gov/fdc/v1/food/2344734?api_key=";
    url_kiwi = url_kiwi.append(argv[1]); //Appends API Key passed from terminal
    myCurl(url_kiwi); //Generates the JSON response in file response.json
    
    std::ifstream ifs_kiwi("response.json");
    ifs_kiwi >> data;
    ifs_apple.close(); //Destrys buffer

    Fruit kiwi(data["description"], "Portion size", 100, "grams", "Energy", findNutrientAmount(data, "Energy"), findNutrientUnit(data, "Energy"),
            "Protein", findNutrientAmount(data,"Protein"), findNutrientUnit(data,"Protein"),
            "Total lipid (fat)", findNutrientAmount(data,"Total lipid (fat)"), findNutrientUnit(data,"Total lipid (fat)"),
            "Carbohydrates", findNutrientAmount(data,"Carbohydrate, by difference"), findNutrientUnit(data,"Carbohydrate, by difference"));
    kiwi.ToString(kiwi);

    
    //banana
    std::string url_banana = "https://api.nal.usda.gov/fdc/v1/food/1105073?api_key=";
    url_banana = url_banana.append(argv[1]); //Appends API Key passed from terminal

    myCurl(url_banana); //Generates the JSON response in file response.json
    std::ifstream ifs_banana("response.json");
    ifs_banana >> data;
    ifs_apple.close(); //Destrys buffer

    Fruit banana(data["description"], "Portion size", 100, "grams", "Energy", findNutrientAmount(data, "Energy"), findNutrientUnit(data, "Energy"),
            "Protein", findNutrientAmount(data,"Protein"), findNutrientUnit(data,"Protein"),
            "Total lipid (fat)", findNutrientAmount(data,"Total lipid (fat)"), findNutrientUnit(data,"Total lipid (fat)"),
            "Carbohydrates", findNutrientAmount(data,"Carbohydrate, by difference"), findNutrientUnit(data,"Carbohydrate, by difference"));
    banana.ToString(banana);

    //orange
    std::string url_orange = "https://api.nal.usda.gov/fdc/v1/food/746771?api_key=";
    url_orange = url_orange.append(argv[1]); //Appends API Key passed from terminal

    myCurl(url_orange); //Generates the JSON response in file response.json
    std::ifstream ifs_orange("response.json");
    ifs_orange >> data;
    ifs_apple.close(); //Destrys buffer

    Fruit orange(data["description"], "Portion size", 100, "grams", "Energy", findNutrientAmount(data, "Energy"), findNutrientUnit(data, "Energy"),
            "Protein", findNutrientAmount(data,"Protein"), findNutrientUnit(data,"Protein"),
            "Total lipid (fat)", findNutrientAmount(data,"Total lipid (fat)"), findNutrientUnit(data,"Total lipid (fat)"),
            "Carbohydrates", findNutrientAmount(data,"Carbohydrate, by difference"), findNutrientUnit(data,"Carbohydrate, by difference"));
    orange.ToString(orange);

    //grape
    std::string url_grape = "https://api.nal.usda.gov/fdc/v1/food/2346413?api_key=";
    url_grape = url_grape.append(argv[1]); //Appends API Key passed from terminal

    myCurl(url_grape); //Generates the JSON response in file response.json
    std::ifstream ifs_grape("response.json");
    ifs_grape >> data;
    ifs_apple.close(); //Destrys buffer

    Fruit grape(data["description"], "Portion size", 100, "grams", "Energy (Atwater General Factors)", findNutrientAmount(data, "Energy (Atwater General Factors)"), findNutrientUnit(data, "Energy (Atwater General Factors)"),
            "Protein", findNutrientAmount(data,"Protein"), findNutrientUnit(data,"Protein"),
            "Total lipid (fat)", findNutrientAmount(data,"Total lipid (fat)"), findNutrientUnit(data,"Total lipid (fat)"),
            "Carbohydrates", findNutrientAmount(data,"Carbohydrate, by difference"), findNutrientUnit(data,"Carbohydrate, by difference"));
    grape.ToString(grape);

    // Nutritional Analysis
    // Create a vector of cruits and insert the fruit objects
    std::vector<Fruit> fruits;
    fruits.push_back(apple);
    fruits.push_back(kiwi);
    fruits.push_back(banana);
    fruits.push_back(orange);
    fruits.push_back(grape);

    // Call the custom function to find the fruit with the highest energy
    Fruit max_energy_fruit = findHighestEnergy(fruits);

    // Output the fruit with the highest energy
    std::cout << "The fruit with the highest energy is: " << max_energy_fruit.get_name()
              << " (" << max_energy_fruit.get_energy() << " calories)" << std::endl;
    
    // Call the custom function to find the fruit with the highest protein
    Fruit max_protein_fruit = findHighestProtein(fruits);

    // Output the fruit with the highest protein
    std::cout << "The fruit with the highest protein is: " << max_protein_fruit.get_name()
              << " (" << max_protein_fruit.get_protein() << " calories)" << std::endl;
    
    // Call the custom function to find the fruit with the highest lipid
    Fruit max_lipid_fruit = findHighestLipid(fruits);

    // Output the fruit with the highest lipid
    std::cout << "The fruit with the highest lipid is: " << max_lipid_fruit.get_name()
              << " (" << max_lipid_fruit.get_lipid() << " calories)" << std::endl;
    
    // Call the custom function to find the fruit with the highest carbs
    Fruit max_carbs_fruit = findHighestCarbs(fruits);

    // Output the fruit with the highest carbs
    std::cout << "The fruit with the highest carbs is: " << max_carbs_fruit.get_name()
              << " (" << max_carbs_fruit.get_carbs() << " calories)" << std::endl;
    
    // Displaying in Descending Order
    DisplayAccordingToCarbs(fruits);
    DisplayAccordingToEnergy(fruits);
    DisplayAccordingToLipid(fruits);
    DisplayAccordingToProtein(fruits);

    // Call the custom function to find most nutritious fruit
    Fruit most_nutritious_fruit = findMostNutritiousFruit(fruits);

    // Output the most nutritious fruit
    std::cout << "\nThe most nutritious fruit is: " << most_nutritious_fruit.get_name()
                  << " (" << calculateScore(most_nutritious_fruit) << " points)" << std::endl;

    return 0;
}