// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: fruit.cpp
// NCC CSCE 306 1 - OO Software Development
// Lab #5 - Fruit Class File in C++
// Description: This file defines the function required to print data, retrive the required date
// --------------------------------------------------------------------------------------

# include <iostream>
# include "fruit.h"
# include "json.hpp"
# include <string>

using json = nlohmann::json;

/**
 * Returns the information of food data
 * @param Fruit The class Fruit
 */
void Fruit::ToString(Fruit Fruit){std::cout << "Description of the food: " << Fruit.get_name() << "\n"
                  << Fruit.get_portion_label() <<": " << Fruit.get_portion_qty() << " " << Fruit.get_portion_unit() << "\n"
                  << Fruit.get_energy_label() <<": " << Fruit.get_energy() << " " << Fruit.get_energy_unit() << "\n"
                  << Fruit.get_protein_label() <<": " << Fruit.get_protein() << " " << Fruit.get_protein_unit() << "\n"
                  << Fruit.get_lipid_label() <<": " << Fruit.get_lipid() << " " << Fruit.get_lipid_unit() << "\n"
                  << Fruit.get_carbs_label() <<": " << Fruit.get_carbs() << " " << Fruit.get_carbs_unit() <<"\n\n";};

                  /**
 * Returns the food nutrient amount by matching the food nutrients from json data
 * @param data The JSON data to search
 * @param nutrientName the search parameter of the nutrient name
 */
double findNutrientAmount(const json& data, const std::string& nutrientName) {
    double amount = 0.0;
    for (const auto& nutrient : data["foodNutrients"]) {
        if (nutrient["nutrient"]["name"] == nutrientName) {
            amount = nutrient["amount"];
            break;
        }
    }
    return amount;
}

/**
 * Returns the food nutrient unit by matching the food nutrients from json data
 * @param data The JSON data to search
 * @param nutrientName the search parameter of the nutrient name
 */
std::string findNutrientUnit(const json& data, const std::string& nutrientName) {
    std::string unit = "";
    for (const auto& nutrient : data["foodNutrients"]) {
        if (nutrient["nutrient"]["name"] == nutrientName) {
            unit = nutrient["nutrient"]["unitName"];
            break;
        }
    }
    return unit;
}