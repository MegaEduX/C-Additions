//
//  CSVParser.cpp
//
//  Class originally created to be used on a college programming project.
//  T3G12 - MIEIC 2012/2013 - FEUP
//
//  This class creates and parses CSV files.
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

#include "CSVParser.h"

#include "Additions.h"

CSVParser::CSVParser() {
    
}

CSVParser::CSVParser(std::string filePath) {
    _filePath = filePath;
}

CSVParser::~CSVParser() {
    
}

//
// parseCSV()
//
// Return Format:
// <vector> - representing a file
//  <vector> - representing a line
//   <string> - representing a cell
//

std::vector<std::vector<std::string>> CSVParser::parseCSV() {
    std::vector<std::vector<std::string>> returnVec;
    
    std::ifstream ifile (_filePath);
    
    std::string line;
    
    while (std::getline(ifile, line))
        returnVec.push_back(Additions::explode(",", line));
    
    _cachedResult = returnVec;
    
    return returnVec;
}

std::vector<std::string> CSVParser::tableHeader(bool reparse) {
    if (_cachedResult.size() == 0 || reparse)
        parseCSV();
    
    return _cachedResult[0];
}

std::vector<std::vector<std::string>> CSVParser::tableRows(bool reparse) {
    if (_cachedResult.size() == 0 || reparse)
        parseCSV();
    
    std::vector<std::vector<std::string>> returnVec;
    
    for (unsigned int i = 1; i < _cachedResult.size(); i++)
        returnVec.push_back(_cachedResult[i]);
    
    return returnVec;
}

std::string CSVParser::encodeCSV(std::vector<std::vector<std::string>> vecToEncode) {
    std::string returnStr;
    
    for (unsigned int i = 0; i < vecToEncode.size(); i++) {
        for (unsigned int j = 0; j < vecToEncode[i].size(); j++) {
            returnStr.append(vecToEncode[i][j]);
            
            if (j + 1 != vecToEncode[i].size())
                returnStr.append(","); // Do not append a , on EOL
        }
        
        if (i + 1 != vecToEncode.size())
            returnStr.append("\n"); // Do not append a \n on EOF
    }
    
    return returnStr;
}
