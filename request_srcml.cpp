/*
  @file request_srcml.cpp

  Implementation of request_srcml()
*/

#include <iostream>
#include "request_srcml.hpp"
#include "get_language_from_filename.hpp"

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request) {
    if(!request.option_filename.empty()){
      return request.option_filename;
    }

    // TODO: determine the proper filename from the request
    std::string filename;
    if(request.entry_filename == "data"){
      if(request.local_filename == "-") {
        return "";
      }
      return request.local_filename;
    }else {
      return request.entry_filename;
    }

    return filename;
}

// extracts the language to use from the request, and the filename
std::string request_language(const srcml_request& request, const std::string& filename) {
    if(!request.option_language.empty()){
      return request.option_language;
    }

    return get_language_from_filename(filename);
}

// generates srcML based on the request
bool generate_srcml(const srcml_request& request) {

	std::string filename = request_filename(request);

	std::string language = request_language(request, filename);
  if(request.option_language.empty() && language.empty()) {
    std::cerr << "Extension not supported\n";
    return false;
  }

	// srcML generation code that is not available yet
}
