#include "Book.hpp"
#include "utils.h"

Book::Book(void)
{
	page_number = 0;
	finished = true;
	current_page = 0;
	note = 0;
}

Book::Book(std::string &init_title, bool is_finished) : title(init_title), finished(is_finished)
{
	page_number = 0;
	current_page = 0;
	note = 0;
}

Book::Book(Book &other) : title(other.title), synopsis(other.synopsis), page_number(other.page_number), finished(other.finished), current_page(other.current_page), note(other.note)
{
}

Book &Book::operator=(Book &other)
{
	title = other.title;
	synopsis = other.synopsis;
	page_number = other.page_number;
	finished = other.finished;
	current_page = other.current_page;
	note = other.note;
}

Book::~Book()
{
}

void Book::get_info() const
{
	std::cout << "Title is: " << title << ".\n";
	std::cout << "Synopsis is: \n"
			  << synopsis << "\n";
	std::cout << "Page: " << current_page << "/" << page_number << ".\n";
	std::cout << "The book is" << (finished ? " " : " not ") << "finished.\n";
	std::cout << "The note is " << note / 20 << "/5." << std::endl;
}

/*
void	Book::set_info()
{

	unsigned	unsigned_buff;
		if (str_buff != "")
			title = str_buff;
		str_buff.clear();
		std::cin.clear();
		std::cout << "Please write the synopsis of the book" << std::endl;
		std::getline (std::cin, str_buff);
		if (str_buff != "")
			synopsis = str_buff;
		str_buff.clear();
		std::cin.clear();
		std::cout << "How many pages does the book have ?" << std::endl;
		std::cin >> unsigned_buff;
		if (unsigned_buff != 0)
			page_number = unsigned_buff;
		std::cout << "Have you finished this book ?" << std::endl;
		std::cin >> unsigned_buff;
		std::cin.clear();
		if (unsigned_buff != 0)
		{
			finished = unsigned_buff;
			current_page = page_number;
		}
		else
		{
			std::cout << "At which page are you ?" << std::endl;
			std::cin >> unsigned_buff;
			std::cin.clear();
			current_page = unsigned_buff;
		}
		unsigned_buff = 101;
		while (unsigned_buff > 100)
		{
			std::cout << "Please give it a note out of 100" << std::endl;
			std::cin >> unsigned_buff;
			std::cin.clear();
		}
		note = unsigned_buff;
}*/

void Book::input_title(void)
{
	std::string input_buff = "";
	while (input_buff == "")
	{
		std::cout << "Please write the title of the book" << std::endl;
		std::getline(std::cin, input_buff);
		input_buff = trim_spaces(input_buff, " \n \t");
		if (input_buff.size() >= 200)
		{
			std::cout << "Title is too big! Please use less than 200 chars" << std::endl;
			input_buff = "";
		}
	}
	if (std::cin.fail())
	{
		std::cerr << "Input of the book's title failed." << std::endl;
		exit(1);
	}
	title = input_buff;
}

void Book::input_synopsis(void)
{
	std::string input_buff = "";
	std::string synopsis_buff = "";
	while (synopsis_buff == "")
	{
		std::cout << "Please write the synopsis of the book (finish typing with EOF)" << std::endl;
		while (std::getline(std::cin, input_buff))
		{
			input_buff = trim_spaces(input_buff, " \n \t");
			synopsis_buff += input_buff + "\n";
		}
		if (!std::cin.eof() && std::cin.fail())
		{
			std::cerr << "Input of the book's title failed." << std::endl;
			exit(1);
		}
		std::cin.clear();
	}
	synopsis = synopsis_buff;
}

void Book::input_pages(void)
{
	const char *total_pages_msg = "Please input the number of pages this book has: ";
	std::string input_buff = "";
	unsigned int number_buff = 0;
	while (true)
	{
		std::cout << total_pages_msg;
		std::cin >> number_buff;
		if (std::cin.eof())
        {
			std::cin.clear();
            ignore_line();
            break;
        }
		else if (!std::cin.eof() && std::cin.peek() != '\n')
        {
			std::cin.clear();
            ignore_line();
            continue;
        }
		break;
	}
	if (!std::cin.eof() && std::cin.fail())
	{
		std::cerr << "Input of the book's title failed." << std::endl;
		exit(1);
	}
	std::cout << "number: " << number_buff;
}

/*
void input_finished(void)
{
}

void input_note(void)
{
}

void set_title(void)
{
}

void set_synopsis(void)
{
}

void set_pages(void)
{
}

void set_finished(void)
{
}

void set_note(void)
{
}

void get_title(void)
{
}

void get_synopsis(void)
{
}

void get_pages(void)
{
}

void get_finished(void)
{
}

void get_note(void){

}
*/
