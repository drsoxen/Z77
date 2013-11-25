//
//  main.cpp
//  Compressor
//
//  Created by Chris Ziraldo on 2013-11-21.
//  Copyright (c) 2013 Chris Ziraldo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
  std::map<std::string,std::pair<size_t, int> > mapOfFile;
  
  std::string fileContents = "the quick brown fox jumps over the lazy dog";
  
  for (int substringLength = 6; substringLength > 0; substringLength--)
  {
    for (int index = 0; index < fileContents.length()-substringLength; index++)
    {
      std::string substring = fileContents.substr(index,substringLength);
      
      size_t prevPos;
        
      size_t pos = fileContents.find(substring, index +1);
      
      int count = 0;
      
      while(pos != string::npos)
      {
        prevPos = pos;
          mapOfFile[substring] = std::pair<size_t,int>(prevPos,substringLength);
        pos = fileContents.find(substring,pos+1);
        count++;
      }
      pos = string::npos;
      prevPos = string::npos;
      count = 0;
      
    }
  }
  
  for (auto it = mapOfFile.begin(); it != mapOfFile.end(); it++)
  {
    cout << "Key:" << it->first;
    cout << "<" << it->second.first << "," << it->second.second << ">\n";
  }
  
  return 0;
}

