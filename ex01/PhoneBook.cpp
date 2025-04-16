#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() {
}

PhoneBook::PhoneBook(const PhoneBook& other) {
	this->contacts = other.contacts;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add(const Contact& contact) {
	Contact temp = contact;

	for (auto it = contacts.begin(); it != contacts.end(); it++) {
		std::swap(*it, temp);
	}
}

void PhoneBook::open() {
	for (unsigned int i = 0; i < contacts.size(); i++) { entry(i); }
}

void PhoneBook::entry(unsigned int i) {
	std::string forename = contacts[i].get_forename();
	std::string surname = contacts[i].get_surname();
	std::string nickname = contacts[i].get_nickname();
	if (forename.size() > 10) { forename.insert(9, 1, '.').resize(10); }
	if (surname.size() > 10) { surname.insert(9, 1, '.').resize(10); }
	if (nickname.size() > 10) { nickname.insert(9, 1, '.').resize(10); }

	std::cout << std::right <<  std::setw(10) <<  i << "|";
	std::cout << std::setw(10) << std::setprecision(10) << forename << "|";
	std::cout << std::setw(10) << std::setprecision(10) << surname << "|";
	std::cout << std::setw(10) << std::setprecision(10) << nickname << std::endl;
}

Contact PhoneBook::search(int i) {
	return contacts[i];
}
