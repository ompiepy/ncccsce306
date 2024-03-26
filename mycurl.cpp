// --------------------------------------------------------------------
// Author: Om Sharma
// Adapted from: libcurl. See https://curl.se/libcurl/ for more details
// File Name: mycurl.CPP
// NCC CSCE 306 1 - OO Software Development
// Lab #5 - Fruit Class File in C++
// Description: This file implements curl to get make the HTTP Request
// --------------------------------------------------------------------

# include <iostream>
# include <curl/curl.h> //libcurl library
# include <fstream> // File input output
# include "mycurl.h"

/**
 * @brief Callback function for writing data received by libcurl.
 *
 * This function is used as a callback by libcurl to handle received data. It is
 * typically used in conjunction with CURLOPT_WRITEFUNCTION option to specify
 * a function pointer to this callback.
 *
 * @param contents A pointer to the received data buffer.
 * @param size The size of each data element.
 * @param nmemb The number of data elements.
 * @param userp A pointer to user data (optional).
 * @return The total number of bytes handled. Should return the size multiplied
 *         by nmemb, unless an error occurs, in which case it should return 0.
 */
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/**
 * @brief Function to perform an HTTP GET request using libcurl and save the response to a JSON file.
 *
 * This function initiates an HTTP GET request using libcurl library to the specified URL.
 * It captures the response data and saves it to a JSON file named "response.json".
 *
 * @param URL The URL to send the HTTP GET request to.
 */
void myCurl(std::string URL){
  const char *cStyleURL = URL.c_str();
  CURL * curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    // Set the URL for the request
    curl_easy_setopt(curl, CURLOPT_URL, cStyleURL);

    // Response data will be stored in this string
    std::string response_data;
    
    // Set write callback function to capture response data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
    
    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }
    else {
        // Write response data to a JSON file
        std::ofstream outFile("response.json");
        if (outFile.is_open()) {
            outFile << response_data;
            outFile.close();
            std::cout << "Response saved to response.json" << std::endl;
        }
        else {
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    }

    // Clean up curl
    curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Curl initialization failed." << std::endl;
    }
  }