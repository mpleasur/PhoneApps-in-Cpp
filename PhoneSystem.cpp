// ITP 365 Spring 2019
// HW2 – itpPhone
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac
//
// PhoneSystem.cpp
// Implements PhoneSystem class
//

#include "PhoneSystem.h"
#include <fstream>
#include "error.h"
#include <iostream>

// Function: Constructor
// Purpose: Constructs two maps --
//          (1) area codes -> locations
//              (loaded from areacodes.txt)
//          (2) phone numbers -> contacts
//              (loaded from contacts.txt)
// Input: None
// Output: None
PhoneSystem::PhoneSystem()
{
	// TODO: Implement
    // TODO: Implement
    std::string areaText;
    std::string contactText;
    
    areaText = "areacodes.txt";
    contactText = "contacts.txt";
    
    std::ifstream dataFile(areaText);
    std::ifstream dataFile2(contactText);
    
    //makes sure file is open
    if (!dataFile.is_open()){
        //if this code is run
        //if file didn't open succesfully
        error("File didn't open!");
        
    }
    if (!dataFile2.is_open()){
        //if this code is run
        //if file didn't open succesfully
        error("File didn't open!");
        
    }
    
    //loads file data
    while (!dataFile.eof()){
        std::string line;
        //get a line from the file
        std::getline(dataFile, line);
        //set an index at where the , is
        unsigned long index = line.find("|");
        
        //check to see if a | was found, it is isn't found than skip that line
        if (index != std::string::npos){
            //set the key to the string before the ,
            std::string key = line.substr(0,index);
            //set the value to the string after the ,
            std::string value = line.substr(index+1);
            //add the key and coresponding value
            areaCode[key] = value;
        }
        
//        for (std::string string : areaCode){
//            std::cout << string << std::endl;
//        }
//        std::cout << " " << std::endl;
        
    }
    
    
    //exact same as above but different file
    while (!dataFile2.eof()){
        std::string line;
        //get a line from the file
        std::getline(dataFile2, line);
        //set an index at where the , is
        unsigned long index = line.find("|");
        
        //check to see if a | was found, it is isn't found than skip that line
        if (index != std::string::npos){
            //set the key to the string before the ,
            std::string key = line.substr(0,index);
            //set the value to the string after the ,
            std::string value = line.substr(index+1);
            //add the key and coresponding value
            phoneNum[key] = value;
        }
        
//        for (std::string string : phoneNum){
//            std::cout << string << std::endl;
//        }
//        std::cout << " " << std::endl;
        
    }
    
    
}

// Function: addDigit
// Purpose: Called when the user adds a digit
//          to the current phone number
// Input: Digit to add (to the end of the number)
// Output: None
void PhoneSystem::addDigit(char digit)
{
    //checks the length of the phone and decides to add a hyphen or not
    if (currentPhone.length() == 12){
        //nothing
        currentPhone = currentPhone;
    }
    else if (currentPhone.length() < 3){
        currentPhone = currentPhone + digit;
    }
    else if (currentPhone.length() == 3){
        currentPhone = currentPhone + "-" + digit;
    }
    else if ((currentPhone.length() < 7) && (currentPhone.size() > 3) ){
        currentPhone = currentPhone + digit;
    }
    else if (currentPhone.length() == 7){
        currentPhone = currentPhone + "-" + digit;
    }
    else if(currentPhone.length() >7){
        currentPhone = currentPhone + digit;
    }
}

// Function: backspace
// Purpose: Removes the rightmost digit from the number
// Input: None
// Output: None
void PhoneSystem::backspace()
{
    // TODO: Implement
    //checks the size of the phone number to decide if it needs to delete a hyphen and digit
    if (currentPhone.size() > 8){
        currentPhone.pop_back();
    }
    else if ((currentPhone.size() < 8) && (currentPhone.size() > 4)){
        currentPhone.pop_back();
        currentPhone.pop_back();
    }
    
    else if ((currentPhone.size() < 4) && (currentPhone.size() > 0)){
        currentPhone.pop_back();
        currentPhone.pop_back();
    }
}

// Function: getNumber
// Purpose: Returns the current number the user has dialed
// Input: None
// Output: Current number user has dialed
std::string PhoneSystem::getNumber()
{
	// TODO: Implement
	return currentPhone; ; // FIX TO RETURN CORRECT VALUE
}

// Function: lookupNumber
// Purpose: Looks up the current number in the two maps:
//          (1) First checks if this number is a contact
//          (2) Otherwise, checks if the first three digits
//              are a known area code
// Input: None
// Output: Returns a string that contains either:
//         (a) The name of the contact
//         (b) The location of the area code
//         (c) "UNKNOWN" if it's neither a contact nor
//             contains a valid area code
std::string PhoneSystem::lookupNumber()
{
    //std::string firstThree;
   
    //checks if the area code is known
    if (currentPhone.length() >= 3){
        //std::cout << currentPhone.substr(0,3) << std::endl;
        if (areaCode.containsKey(currentPhone.substr(0,3))){
            //std::cout << "The number" << currentPhone << "has an area code from" << areaCode[currentPhone.substr(0,3)]<< std::endl;
            //return areaCode[firstThree];
            return areaCode[currentPhone.substr(0,3)];
        }
    }
    //checks if the phone number is know via lookking for the key in the map
    else if (phoneNum.containsKey(currentPhone)){
        //if the code is there then print out value
        return phoneNum[currentPhone];
       // std::cout << "The number" << currentPhone << "belongs to" << phoneNum[currentPhone] << std::endl;
        
    }
    else{
        return "UNKNOWN";
    }
    
   
    
    
    
    return "UNKNOWN";
}
