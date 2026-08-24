#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

class MultipleMatchesFound : public std::invalid_argument {

public:
	MultipleMatchesFound(const std::string& message)
		: std::invalid_argument(message) {}

};


class Book {

private:

	std::string title;
	std::string author;
	bool checkout_status = false;
	std::string ISBN;

public:

	Book(std::string title, std::string author, std::string ISBN) {

		this->title = title;
		this->author = author;
		this->ISBN = ISBN;

	}

	std::string getTitle() const {
		return title;
	}

	std::string getAuthor() const {
		return author;
	}

	bool getCheckoutStatus() const {
		return checkout_status;
	}

	std::string getISBN() const {
		return ISBN;
	}


	void checkOut() {

		if (checkout_status) {

			throw std::invalid_argument("Sorry book is loaned out at the moment! \n");
		}

		else {

			checkout_status = true;
		}

	}

	void returnBook() {

		if (checkout_status) {

			checkout_status = false;
		}

		else {

			throw std::invalid_argument("Cannot return a book that hasn't been loaned out. \n");
		}
	}
};

std::string toLower(std::string s) {

	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	return s;
}

class Library {

private:

	std::vector <Book> books;


	std::vector <Book*> findCandidates(std::string title) {

		std::vector <Book*> candidates;

		for (int i = 0; i < books.size(); i++) {

			if (toLower(books[i].getTitle()) == toLower(title)) {
				candidates.push_back(&books[i]);
			}
		}

		return candidates;
	}

	std::string candidateResults(std::vector <Book*> candidates) {

		std::stringstream candidate_string;

		for (Book* book : candidates) {
			candidate_string << book->getISBN() << ", " << book->getTitle() << ", " << book->getAuthor() << "\n";
		}

		std::string results = candidate_string.str();

		return results;
	}


public:

	Library() {

		books.push_back(Book{ "Harry Potter and the Philosopher's Stone", "J.K. Rowling", "9959591423341" });
		books.push_back(Book{ "The Double", "Fyodor Dostoyevsky", "4424915358792" });
		books.push_back(Book{ "The Double", "Jose Saramago", "7216119766575" });
		books.push_back(Book{ "Harry Potter and the Goblet of Fire", "J.K. Rowling", "1989052027347" });
		books.push_back(Book{ "A Tale of Two Cities", "Charles Dickens", "2932760580167" });

	}

	void loan(std::string title) {

		std::vector <Book*> candidates = findCandidates(title);

		if (candidates.empty()) {

			throw std::invalid_argument("Sorry, no book with that title found \n");
		}

		else if (candidates.size() > 1) {

			throw MultipleMatchesFound(candidateResults(candidates));
		}

		else {

			candidates[0]->checkOut();
		}
	}


	void giveBack(std::string title) {

		std::vector <Book*> candidates = findCandidates(title);

		if (candidates.empty()) {

			throw std::invalid_argument("Sorry, no book with that title found \n");
		}

		else if (candidates.size() > 1) {

			throw MultipleMatchesFound(candidateResults(candidates));
		}

		else {

			candidates[0]->returnBook();
		}

	}

	void loanWithISBN(std::string ISBN) {

		for (auto& book : books) {

			if (book.getISBN() == ISBN) {
				book.checkOut();

				return;
			}
		}

		throw std::invalid_argument ("Sorry, no book with matching ISBN found \n");
	}

	void returnWithISBN(std::string ISBN) {

		for (auto& book : books) {

			if (book.getISBN() == ISBN) {
				book.returnBook();
				
				return;
			}
		}

		throw std::invalid_argument("Sorry, no book with matching ISBN found \n");
	}
};

int main() {

	Library library;

	std::string response;
	std::vector <std::string> valid_response = {"Loan", "Return", "Exit"};


	while (true) {

		std::cout << "\nHello and welcome to the library! What would you like to do?\nLoan\nReturn\nExit \n";
		std::getline(std::cin, response);

		if (std::find(valid_response.begin(), valid_response.end(), response) == valid_response.end()) {

			std::cout << "Not a valid answer, make sure your answer is written properly \n";
			continue;

		}

		if (response == "Loan") {

			std::string book_title;
			std::string ISBN_num;

			std::cout << "What is the title of the book you would like to loan? \n";
			std::getline(std::cin, book_title);

			try {

				library.loan(book_title);
				std::cout << "You loaned the book: " << book_title << ", successfully! \n";
			}

			catch (const MultipleMatchesFound& ex) {

				std::cout << ex.what() << '\n';
				std::cout << "Can you specify which book you wanted to loan by entering the ISBN, please. \n";
				std::getline(std::cin, ISBN_num);

				try {

					library.loanWithISBN(ISBN_num);
					std::cout << "You loaned the book: " << book_title << ", successfully! \n";
				}

				catch (const std::invalid_argument& ex) {

					std::cout << ex.what() << '\n';
					continue;
				}
			}

			catch (const std::invalid_argument& ex) {

				std::cout << ex.what() << '\n';
				continue;
			}
		}

		if (response == "Return") {

			std::string book_title;
			std::string ISBN_num;

			std::cout << "What is the title of the book you would like to return? \n";
			std::getline(std::cin, book_title);

			try {

				library.giveBack(book_title);
				std::cout << "You returned the book: " << book_title << ", successfully! \n";
			}

			catch (const MultipleMatchesFound& ex) {

				std::cout << ex.what() << '\n';
				std::cout << "Can you specify which book you wanted to return by entering the ISBN, please. \n";
				std::getline(std::cin, ISBN_num);

				try {

					library.returnWithISBN(ISBN_num);
					std::cout << "You returned the book: " << book_title << ", successfully! \n";
				}

				catch (const std::invalid_argument& ex) {

					std::cout << ex.what() << '\n';
					continue;
				}
			}

			catch (const std::invalid_argument& ex) {

				std::cout << ex.what() << '\n';
				continue;
			}
		}

		if (response == "Exit") {
			break;
		}
	}

	return 0;
}