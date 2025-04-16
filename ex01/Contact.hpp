#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
public:
	Contact();
	Contact(std::string forename, std::string surname, std::string nickname, std::string number, std::string secret);
	Contact(const Contact&);
	virtual ~Contact();

	const std::string get_forename();
	const std::string get_surname();
	const std::string get_nickname();
	const std::string get_number();
	const std::string get_secret();
	void display_contact();
private:
	std::string forename;
	std::string surname;
	std::string nickname;
	std::string number;
	std::string secret;
protected:
};

#endif // CONTACT_HPP
