// --------------------------------------------------------------------------------------
// Author: Om Sharma
// File Name: fruit.h
// NCC CSCE 306 1 - OO Software Development
// Lab #5 - Fruit Class File in C++
// Description: This file declares the data members and function required for fruit.cpp
// --------------------------------------------------------------------------------------

# include <iostream>
# include "json.hpp" // Implementation of nlohmann/json.hpp: See https://github.com/nlohmann/json for more details
# include <string>

using json = nlohmann::json; // Defining scope for nlohmann namesapce

#ifndef FRUIT_H
#define FRUIT_H

class Fruit{
    private:
      // Data member declaration
      //Food Name (string)  [ example: string, "Tomatoes, raw" ]
      std::string name;
      //  > Portion Label [ example: string, "Portion size"]
      std::string portion_label;
      //> Portion Quantity [ example: int, 100 ]
      float portion_qty;
      //> Portion Measurement Unit [ example: string, "grams" ]
      std::string portion_unit;
      //> Energy Label [ example: string, "Energy (calories) "]
      std::string energy_label;
      //> Energy Quantity [ example: float, 18 ]
      float energy;
      //> Energy Measurement Unit [ example: string, "grams" ]
      std::string energy_unit;
      //> Protein Label [ example: string, "Protein"]
      std::string protein_label;
      //> Protein Quantity [ example: float, .88 ]
      float protein;
      //> Protein Measurement Unit [ example: string, "grams" ]
      std::string protein_unit;
      ///> Lipids Label [ example: string, "Lipids (fat)"]
      std::string lipid_label;
      //> Lipids Quantity [ example: float, .2 ]
      float lipid;
      //>/ Lipid Measurement Unit [ example: string, "grams" ]
      std::string lipid_unit;
      //> Carbs Label [ example: string, "Carbohydrates (all)"]
      std::string carbs_label;
      //> Carbs Quantity [ example: float, 3.89 ]
      float carbs;
      //> Carbs Measurement Unit [ example: string, "grams" ] (total:15)
      std::string carbs_unit;


      public:
      //Getters
      std::string get_name(){return name;}
      std::string get_portion_label(){return portion_label;}
      float get_portion_qty(){return portion_qty;}
      std::string get_portion_unit(){return portion_unit;}
      std::string get_energy_label(){return energy_label;}
      float get_energy(){return energy;}
      std::string get_energy_unit(){return energy_unit;}
      std::string get_protein_label(){return protein_label;}
      float get_protein(){return protein;}
      std::string get_protein_unit(){return protein_unit;}
      std::string get_lipid_label(){return lipid_label;}
      float get_lipid(){return lipid;}
      std::string get_lipid_unit(){return lipid_unit;}
      std::string get_carbs_label(){return carbs_label;}
      float get_carbs(){return carbs;}
      std::string get_carbs_unit(){return carbs_unit;}
      
      //Setters
      void set_name(const std::string& name){Fruit::name=name;}
      void set_portion_label(const std::string& portion_label){Fruit::portion_label=portion_label;}
      void set_portion_qty(const float portion_qty){Fruit::portion_qty=portion_qty;}
      void set_portion_unit(const std::string& portion_unit){Fruit::portion_unit=portion_unit;}
      void set_energy_label(const std::string& energy_label){Fruit::energy_label=energy_label;}
      void set_energy(const float energy){Fruit::energy=energy;}
      void set_energy_unit(const std::string& energy_unit){Fruit::energy_unit=energy_unit;}
      void set_protein_label(const std::string& portion_unit){Fruit::protein_label=portion_unit;}
      void set_protein(const float protein){Fruit::protein=protein;}
      void set_protein_unit(const std::string& protein_unit){Fruit::protein_unit=protein_unit;}
      void set_lipid_label(const std::string& lipid_label){Fruit::lipid_label=lipid_label;}
      void set_lipid(const float lipid){Fruit::lipid=lipid;}
      void set_lipid_unit(const std::string& lipid_unit){Fruit::lipid_unit=lipid_unit;}
      void set_carbs_label(const std::string& carbs_label){Fruit::carbs_label=carbs_label;}
      void set_carbs(const float carbs){Fruit::carbs=carbs;}
      void set_carbs_unit(const std::string& carbs_unit){Fruit::carbs_unit=carbs_unit;}

      //ToString Method
      void ToString(Fruit);

      // Constructor
      Fruit(std::string a, std::string b, float c, std::string d , std::string e, float f, std::string g, std::string h, float i, std::string j, std::string k, float l, std::string m,std::string n, float o, std::string p ):
      name(a),portion_label(b),portion_qty(c),portion_unit(d),
      energy_label(e), energy(f), energy_unit(g),
      protein_label(h), protein(i), protein_unit(j),
      lipid_label(k),lipid(l), lipid_unit(m),
      carbs_label(n), carbs(o), carbs_unit(p){};
};

double findNutrientAmount(const json& data, const std::string& nutrientName);
std::string findNutrientUnit(const json& data, const std::string& nutrientName);

#endif