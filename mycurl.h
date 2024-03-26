// --------------------------------------------------------------------
// Author: Om Sharma
// Adapted from: libcurl. See https://curl.se/libcurl/ for more details
// File Name: mycurl.h
// NCC CSCE 306 1 - OO Software Development
// Lab #5 - Fruit Class File in C++
// Description: This header file defines curl to get make the HTTP Request
// --------------------------------------------------------------------

#include <iostream>
#include <curl/curl.h> //libcurl library

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
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

/**
 * @brief Function to perform a HTTP GET request using libcurl.
 *
 * This function initiates a HTTP GET request using libcurl library to the
 * specified URL.
 *
 * @param URL The URL to send the HTTP GET request to.
 */
void myCurl(std::string URL);