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
    }

    {
    	srcml_request request = { "", "compress_file.something", "main.cpp", "" };
    	assert(request_filename(request) == "main.cpp");
    }

    {
      srcml_request request = { "", "mydata.cpp", "data", "" };
    	assert(request_filename(request) == "mydata.cpp");
    }

    {
      srcml_request request = { "option_filename.h", "local_filename.zip", "entry_filename.cpp", "" };
    	assert(request_filename(request) == "option_filename.h");
    }

    {
      srcml_request request = { "", "mydata.cpp", "", "" };
      assert(request_language(request, "mydata.cpp") == "C++");
    }

    {
      srcml_request request = { "", "mydata.cpp", "", "Ruby" };
      assert(request_language(request, "mydata.cpp") == "Ruby");
    }

    return 0;
}
