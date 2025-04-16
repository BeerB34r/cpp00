#include "Contact.hpp"
#include <iostream>
#include <stdexcept>

Contact::Contact() {
	this->forename = "N/A";
	this->surname = "N/A";
	this->nickname = "N/A";
	this->number = "N/A";
	this->secret = "N/A";
}

Contact::Contact(std::string forename, std::string surname, std::string nickname, std::string number, std::string secret) {
	if (forename.empty() || surname.empty() || nickname.empty() || number.empty() || secret.empty()) {
		throw std::invalid_argument("Contacts require all fields to be non-empty");
	}
	this->forename = forename;
	this->surname = surname;
	this->nickname = nickname;
	this->number = number;
	this->secret = secret;
}

Contact::Contact(const Contact& other) {
	if (other.forename.empty() || other.surname.empty() || other.nickname.empty() || other.number.empty() || other.secret.empty()) {
		throw std::invalid_argument("Provided contact is invalid");
	}
	this->forename = other.forename;
	this->surname = other.surname;
	this->nickname = other.nickname;
	this->number = other.number;
	this->secret = other.secret;
}

void Contact::display_contact(void) {
	std::cout << forename << std::endl;
	std::cout << surname << std::endl;
	std::cout << nickname << std::endl;
	std::cout << number << std::endl;
	std::cout << secret << std::endl;
}


const std::string Contact::get_forename() {
	return forename;
}

const std::string Contact::get_surname() {
	return surname;
}

const std::string Contact::get_nickname() {
	return nickname;
}

const std::string Contact::get_number() {
	return number;
}

const std::string Contact::get_secret() {
	return secret;
}

Contact::~Contact() {
}
