/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

	// all filenames and languages empty
    {
    	srcml_request request = { "", "", "", "" };
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
    }

    // Rule 1
    {
    	srcml_request request = { "", "compress_file.something", "main.cpp", "" };
    	assert(request_filename(request) == "main.cpp");
    }

    // Rule 2
    {
      srcml_request request = { "", "mydata.cpp", "data", "" };
    	assert(request_filename(request) == "mydata.cpp");
    }

    // Rule 3
    {
      srcml_request request = { "option_filename.h", "local_filename.zip", "entry_filename.cpp", "" };
    	assert(request_filename(request) == "option_filename.h");
    }

    // Rule 4
    {
      srcml_request request = { "", "mydata.cpp", "", "" };
      assert(request_language(request, "mydata.cpp") == "C++");
    }

    // Rule 5
    {
      srcml_request request = { "", "mydata.cpp", "", "Ruby" };
      assert(request_language(request, "mydata.cpp") == "Ruby");
    }

    // Rule 6
    {
      srcml_request request = { "", "-", "data", "" };
      assert(request_filename(request) == "");
    }

    // 1st error handling
    {
      srcml_request request = {"", "myfile.something", "", "" };
      assert(generate_srcml(request) == false);
    }

    // 2nd error handling
    {
      srcml_request request = {"", "-", "", "" };
      assert(generate_srcml(request) == false);
    }

    return 0;
}
