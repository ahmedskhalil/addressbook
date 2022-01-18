//
// AddressBook
// Add, remove and
// list enties in alphabetical order
// Author: Ahmed Khalil
// Date: 18.01.2021
//

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

enum class SortBy_ {FIRST_NAME, LAST_NAME};

class PhoneBook {
public:
  PhoneBook() {};
  
  void addEntry(std::string first_name, std::string last_name, std::string phone_number) {
    if (!first_name.empty() || !last_name.empty() || !phone_number.empty()) {
      phonebook_.push_back({ first_name, last_name, phone_number});
    } else {
      std::cout << ">> WARNING: not storing any values, please provide at least a first name, "
                << "a last name or a phone number.\n";
    }
  }
  
  void deleteEntry(std::string first_name, std::string last_name) {
    auto it = phonebook_.begin();
    while (it != phonebook_.end())
    {
      if ((*it).at(0) == first_name || (*it).at(1) == first_name)
      {
        std::cout << ">> Removing : " << (*it).at(0) << " "
                  << (*it).at(1) << std::endl << std::endl;
        phonebook_.erase(it++);
      }
      ++it;
    }
  }
  
  void findEntry(std::string first_name, std::string last_name) {
    auto it = phonebook_.begin();
    while (it != phonebook_.end())
    {
      auto first_last_name = (*it).at(0) + " " + (*it).at(1);
      toLowerCase_(first_last_name);
      toLowerCase_(first_name);
      toLowerCase_(last_name);
      std::size_t found = first_last_name.rfind(first_name);
      if (found!=std::string::npos) {
        std::cout << ">> Found : " << (*it).at(0) << " "
                  << (*it).at(1) << std::endl << std::endl;
      }
      ++it;
    }
  }
  
  void showPhoneBookEntries()
  {
    for (auto it = phonebook_.begin(); it != phonebook_.end(); ++it)
    {
      std::cout << " " << (!(*it).at(0).empty() ? (*it).at(0) : "...")
                << " " << (!(*it).at(1).empty() ? (*it).at(1) : "...") << " - "
                << (*it).at(2) << std::endl;
    }
    std::cout << std::endl;
  }
  
  void showSortedPhoneBookEntries(SortBy_ sorted_by)
  {
    if (sorted_by == SortBy_::FIRST_NAME) {
      phonebook_.sort(compareFirstName_);
      std::cout<< "Phone book entries sorted by first name : " << std::endl;
    } else if (sorted_by == SortBy_::LAST_NAME) {
      phonebook_.sort(compareLastName_);
      std::cout<< "Phone book entries sorted by last name : " << std::endl;
    }
    showPhoneBookEntries();
  }
  
private:
  std::list<std::vector<std::string>> phonebook_;
  
  static void toLowerCase_(std::string& str)
  {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });
  }
  
  static bool compareFirstName_(const std::vector<std::string>& first, const std::vector<std::string>& second)
  {
    unsigned int i = 0;
    auto str_1 = first.at(0);
    auto str_2 = second.at(0);
    toLowerCase_(str_1);
    toLowerCase_(str_2);
      
    while ((i<str_1.length()) && (i<str_2.length()))
    {
      if ((str_1.at(i))<(str_2.at(i))) return true;
      else if ((str_1.at(i))>(str_2.at(i))) return false;
      ++i;
    }
    return (str_1.length() < str_2.length());
  }
  
  static bool compareLastName_ (const std::vector<std::string>& first, const std::vector<std::string>& second)
  {
    unsigned int i = 0;
    auto str_1 = first.at(1);
    auto str_2 = second.at(1);
    toLowerCase_(str_1);
    toLowerCase_(str_2);
    while ((i<str_1.length()) && (i<str_2.length()))
    {
      if ((str_1.at(i))<(str_2.at(i))) return true;
      else if ((str_1.at(i))>(str_2.at(i))) return false;
      ++i;
    }
    return (str_1.length() < str_2.length());
  }
};
