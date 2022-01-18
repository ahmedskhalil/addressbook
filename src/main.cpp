//
// AddressBook
// Driver/Testing code
// Author: Ahmed Khalil
// Date: 18.01.2021
//

#include <memory>
#include "AddressBook.hpp"

int main(int, char**) {

  auto phonebook = std::make_unique<PhoneBook>();
  
  phonebook->addEntry("Margaret", "Davis",  "1134683349");
  phonebook->addEntry("Jennifer", "Robert", "1134688001");
  phonebook->addEntry("Dorothy",  "Edward", "1134688049");
  phonebook->addEntry("Betty",    "Ronald", "1134688056");
  phonebook->addEntry("Carol",    "George", "113432845649");
  phonebook->addEntry("Linda",    "Joseph", "1134688064");
  phonebook->addEntry("Martin",   "",       "");
  phonebook->addEntry("",         "Flare",  "");
  phonebook->addEntry("",         "",       "");
  
  phonebook->showPhoneBookEntries();
  
  phonebook->showSortedPhoneBookEntries(SortBy_::FIRST_NAME);
  phonebook->showSortedPhoneBookEntries(SortBy_::LAST_NAME);
  
  phonebook->deleteEntry("Betty", "");
  phonebook->showPhoneBookEntries();
  
  std::cout << ">> Searching for 'AROL'\n";
  phonebook->findEntry("AROL", "");
  
  std::cout << ">> Searching for 'waRd'\n";
  phonebook->findEntry("waRd", "");
  
  std::cout << ">> Searching for 'or'\n";
  phonebook->findEntry("or", "");
  
  return 0;
}
