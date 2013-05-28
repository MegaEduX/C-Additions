//
//  Additions.h
//
//  Class originally created to be used on a college programming project.
//  T3G12 - MIEIC 2012/2013 - FEUP
//
//  This namespace contains portable, useful functions.
//

/*
 
 This is free and unencumbered software released into the public domain.
 
 Anyone is free to copy, modify, publish, use, compile, sell, or
 distribute this software, either in source code form or as a compiled
 binary, for any purpose, commercial or non-commercial, and by any
 means.
 
 In jurisdictions that recognize copyright laws, the author or authors
 of this software dedicate any and all copyright interest in the
 software to the public domain. We make this dedication for the benefit
 of the public at large and to the detriment of our heirs and
 successors. We intend this dedication to be an overt act of
 relinquishment in perpetuity of all present and future rights to this
 software under copyright law.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 */

#ifndef AdditionsHeader
#define AdditionsHeader

#include <iostream>
#include <sstream>
#include <fstream>
#include <cerrno>
#include <vector>

#ifndef WIN32
int _getch();	// This is not an ISO function, so it's not available on POSIX-systems. Our solution? Let's make our own!
#endif

static const std::string esc = "__\\esc_key_pressed\\__";	// I seriously doubt that anyone will type this into a field.

namespace Additions {
    std::vector<std::string> explode(const std::string &delimiter, const std::string &str);
    
    std::string get_file_contents(const char *filename);
    
    std::string getline();
    
    bool checkForOnlyNumeric(std::string str);
    
    bool gotESC(std::string str);
    
    void clearConsole();
    
    void waitForReturn();
}

#endif
