#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <array>

class PhoneBook
{
public:
	PhoneBook();
	PhoneBook(const PhoneBook&);
	virtual ~PhoneBook();

	void add(const Contact&);
	void open();
	void entry(unsigned int);
	Contact search(int);
private:
	std::array<Contact, 8> contacts;
protected:
};

#endif // PHONEBOOK_HPP
