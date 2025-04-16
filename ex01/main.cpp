#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void test_contacts(void) {
	Contact wrong;
	Contact right("Ola", "Nordmann", "Ola with the moola", "+47 123 12 123", "is dirt poor");
	Contact copy(right);

	wrong.display_contact();
	std::cout << std::string("=").append(10, '=') << std::endl;
	right.display_contact();
	std::cout << std::string("=").append(10, '=') << std::endl;
	copy.display_contact();
	std::cout << std::string("=").append(10, '=') << std::endl;
	try {
		Contact error("Jan-Erik", "Filip Skaar", "Gamlefar", "Unknown", "");
		error.display_contact();
	} catch (std::exception& except) {
		std::cout << except.what() << std::endl;
	}
}

void test_phonebook(void) {
	PhoneBook yellowedpages;
	Contact ola("Ola", "Nordmann", "Ola with the moola", "+47 123 12 123", "is dirt poor");
	Contact jesper("Jesper", "Nordmann", "jepsi pepsi", "+47 123 12 123", "prefers coke");
	Contact per("Per", "Nordmann", "pære", "+47 123 12 123", "hates pears");
	Contact kåre("Kåre", "Nordmann", "store-K", "+47 123 12 123", "is actually quite small");
	Contact svein("Svein", "Nordmann", "svin", "+47 123 12 123", "has never been young");
	Contact kjartan("Kjartan", "Nordmann", "kjappa", "+47 123 12 123", "lost a leg in the war");
	Contact gustav("Gustav", "Nordmann", "hans majestet, kongen", "+47 123 12 123", "is an immortal king of the holy roman empire");
	Contact tomas("Tomas", "Nordmann", "toget", "+47 123 12 123", "hates trains");
	Contact berit("Berit", "Nordmann", "woman", "+47 123 12 123", "woman");

	yellowedpages.add(ola);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(jesper);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(per);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(kåre);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(svein);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(kjartan);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(gustav);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(tomas);
	std::cout << std::string("=").append(10, '=') << std::endl;
	yellowedpages.add(berit);

	yellowedpages.open();
}

Contact get_contact(void) {
	std::string forename;
	std::cout << "forename: ";
	std::getline(std::cin, forename);
	std::string surname;
	std::cout << "surname: ";
	std::getline(std::cin, surname);
	std::string nickname;
	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	std::string number;
	std::cout << "number: ";
	std::getline(std::cin, number);
	std::string secret;
	std::cout << "secret: ";
	std::getline(std::cin, secret);
	return Contact(forename, surname, nickname, number, secret);
}

int main(void) {
	bool proceed = true;
	PhoneBook yellowedpages;

	while (proceed) {
		std::string command;
		std::cout << "available commands are as follows: ADD, SEARCH, EXIT" << std::endl << "please enter your choice of command: ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			std::cout << "adding!" << std::endl;
			try { yellowedpages.add(get_contact()); } catch (std::exception& except) { std::cout << "invalid contact created" << std::endl; }
		} else if (command == "SEARCH") {
			std::cout << "searching!" << std::endl;
			yellowedpages.open();
			std::cout << "please choose an available entry: ";
			std::getline(std::cin, command);
			try { yellowedpages.search(std::stoi(command)).display_contact(); } catch (std::exception& except) { std::cout << "entry not found" << std::endl; }
		} else if (command == "EXIT") {
			std::cout << "exiting!" << std::endl;
			proceed = false;
		} else if (std::cin.eof()) { 
			std::cout << std::endl << "use the EXIT command next time..." << std::endl;
			proceed = false;
		}
	}
}
