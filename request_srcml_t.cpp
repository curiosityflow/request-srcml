/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

	// all filenames and languages empty
    {
    	srcml_request request = { "", "", "", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");


        srcml_request request = { "", "mydata.cpp", "data", ""};
    	assert(request_filename(request) == "mydata.cpp");

    }

    return 0;
}
