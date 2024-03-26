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
# include <algorithm> // Standard Library to implement various sorting and data manupulation function
# include <vector> // Standard Library for vector operations and vector data management

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

// Custom function to find the fruit with the highest energy
Fruit findHighestEnergy(const std::vector<Fruit>& fruits) {
    // Initialize max_energy_fruit with the first fruit in the vector
    Fruit max_energy_fruit = fruits[0];

    // Iterate through the vector to find the fruit with the highest energy
    for (Fruit fruit : fruits) {
        if (fruit.get_energy() > max_energy_fruit.get_energy()) {
            max_energy_fruit = fruit;
        }
    }

    return max_energy_fruit;
}

// Custom function to find the fruit with the highest protein
Fruit findHighestProtein(const std::vector<Fruit>& fruits){
    Fruit max_protein_fruit = fruits[0];

    // Iterate through the vector to find the fruit with the highest protein
    for (Fruit fruit : fruits) {
        if (fruit.get_protein() > max_protein_fruit.get_protein()) {
            max_protein_fruit = fruit;
        }
    }

    return max_protein_fruit;
}

// Custom function to find the fruit with the highest lipid
Fruit findHighestLipid(const std::vector<Fruit>& fruits){
    Fruit max_lipid_fruit = fruits[0];

    // Iterate through the vector to find the fruit with the highest lipid
    for (Fruit fruit : fruits) {
        if (fruit.get_lipid() > max_lipid_fruit.get_lipid()) {
            max_lipid_fruit = fruit;
        }
    }

    return max_lipid_fruit;
}

// Custom function to find the fruit with the highest carbs
Fruit findHighestCarbs(const std::vector<Fruit>& fruits){
    Fruit max_carbs_fruit = fruits[0];

    // Iterate through the vector to find the fruit with the highest carbs
    for (Fruit fruit : fruits) {
        if (fruit.get_carbs() > max_carbs_fruit.get_carbs()) {
            max_carbs_fruit = fruit;
        }
    }

    return max_carbs_fruit;
}

// Sort Fruits according to the Descending order of energy
void DisplayAccordingToEnergy(const std::vector<Fruit>& fruits) {
    std::vector<Fruit> sortedFruits = fruits; // Create a copy of the input vector

    // Selection sort to sort the fruits vector based on energy values
    for (size_t i = 0; i < sortedFruits.size() - 1; ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < sortedFruits.size(); ++j) {
            if (sortedFruits[j].get_energy() > sortedFruits[maxIndex].get_energy()) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            // Manually swap elements
            Fruit temp = sortedFruits[i];
            sortedFruits[i] = sortedFruits[maxIndex];
            sortedFruits[maxIndex] = temp;
        }
    }

    std::cout << "\nDisplaying Fruits in Descending Order of Energy\n";
    std::cout << "\nEnergy\t\tName\n";
    // Display individual values of sorted fruits using iteration
    for (size_t i = 0; i < 5; ++i) {
        printf("%.4f\t\t%s\n", sortedFruits[i].get_energy(), sortedFruits[i].get_name().c_str());
    }
    std::cout << std::endl;
}

// Sort Fruits according to the Descending order of protein
void DisplayAccordingToProtein(const std::vector<Fruit>& fruits) {
    std::vector<Fruit> sortedFruits = fruits; // Create a copy of the input vector

    // Selection sort to sort the fruits vector based on protein values
    for (size_t i = 0; i < sortedFruits.size() - 1; ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < sortedFruits.size(); ++j) {
            if (sortedFruits[j].get_protein() > sortedFruits[maxIndex].get_protein()) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            // Manually swap elements
            Fruit temp = sortedFruits[i];
            sortedFruits[i] = sortedFruits[maxIndex];
            sortedFruits[maxIndex] = temp;
        }
    }

    std::cout << "\nDisplaying Fruits in Descending Order of Protein\n";
    std::cout << "\nProtein\t\tName\n";
    // Display individual values of sorted fruits using iteration
    for (size_t i = 0; i < 5; ++i) {
        printf("%.4f\t\t%s\n", sortedFruits[i].get_protein(), sortedFruits[i].get_name().c_str());
    }
    std::cout << std::endl;
}

// Sort Fruits according to the Descending order of lipid
void DisplayAccordingToLipid(const std::vector<Fruit>& fruits) {
    std::vector<Fruit> sortedFruits = fruits; // Create a copy of the input vector

    // Selection sort to sort the fruits vector based on lipid values
    for (size_t i = 0; i < sortedFruits.size() - 1; ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < sortedFruits.size(); ++j) {
            if (sortedFruits[j].get_lipid() > sortedFruits[maxIndex].get_lipid()) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            // Manually swap elements
            Fruit temp = sortedFruits[i];
            sortedFruits[i] = sortedFruits[maxIndex];
            sortedFruits[maxIndex] = temp;
        }
    }

    std::cout << "\nDisplaying Fruits in Descending Order of Lipid\n";
    std::cout << "\nLipid\t\tName\n";
    // Display individual values of sorted fruits using iteration
    for (size_t i = 0; i < 5; ++i) {
        printf("%.4f\t\t%s\n", sortedFruits[i].get_lipid(), sortedFruits[i].get_name().c_str());
    }
    std::cout << std::endl;
}

// Sort Fruits according to the Descending order of carbs
void DisplayAccordingToCarbs(const std::vector<Fruit>& fruits) {
    std::vector<Fruit> sortedFruits = fruits; // Create a copy of the input vector

    // Selection sort to sort the fruits vector based on carbohydrate values
    for (size_t i = 0; i < sortedFruits.size() - 1; ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < sortedFruits.size(); ++j) {
            if (sortedFruits[j].get_carbs() > sortedFruits[maxIndex].get_carbs()) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            // Manually swap elements
            Fruit temp = sortedFruits[i];
            sortedFruits[i] = sortedFruits[maxIndex];
            sortedFruits[maxIndex] = temp;
        }
    }

    std::cout << "\nDisplaying Fruits in Descending Order of Carbs\n";
    std::cout << "\nCarbs\t\tName\n";
    // Display individual values of sorted fruits using iteration
    for (size_t i = 0; i < 5; ++i) {
        printf("%.4f\t\t%s\n", sortedFruits[i].get_carbs(), sortedFruits[i].get_name().c_str());
    }
    std::cout << std::endl;
}

//Find nutrionally rich fruit
// Define a function to calculate the score of a fruit
double calculateScore(Fruit fruit) {
    const double energyWeight = 0.30;
    const double proteinWeight = 0.20;
    const double fatWeight = 0.30;
    const double carbWeight = 0.50;

    return (fruit.get_energy() * energyWeight) + (fruit.get_protein() * proteinWeight) + (fruit.get_lipid() * fatWeight) + (fruit.get_carbs() * carbWeight);
}

// Define a function to sort according to the score
Fruit findMostNutritiousFruit(const std::vector<Fruit>& fruits) {
    // Initialize the most nutritious fruit with the first fruit in the vector
    Fruit mostNutritiousFruit = fruits[0];
    double maxScore = calculateScore(mostNutritiousFruit);

    std::cout << "Calulating the most nutritious fruit\n\n";
    std::cout << "The different weight assigned are Energy: 30%, Protein: 20%, ";
    std::cout << "Fat: 30%, Carbohydrates: 50%.\n";
    std::cout << "Source: \"Dietary Guidelines for Americans 2020-2025\" published \n";
    std::cout << "by the U.S. Department of Health and Human Services and the U.S. ";
    std::cout << "Department of Agriculture.\n\n";

    // Iterate through the vector to find the most nutritious fruit
    for (Fruit fruit : fruits) {
        double score = calculateScore(fruit);
        std::cout << "Fruit: " << std::setw(40) << std::left << fruit.get_name() << " Score: " <<  score << std::endl;
        if (score > maxScore) {
            maxScore = score;
            mostNutritiousFruit = fruit;
        }
    }
    // Display the frit in descending order of the score
    return mostNutritiousFruit;
}
