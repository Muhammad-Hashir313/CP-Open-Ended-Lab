#include<iostream>

using namespace std;

int main() {
	char choice;
	int fine = 1;
	string books[] = { "Book1", "Book2", "Book3" };

	char option;

	do
	{
		cout << "What do you want?\n";
		cout << "1. Available books\n";
		cout << "2. Borrow book\n";
		cout << "3. Return book\n";
		cout << "4. Exit\n";
		cin >> choice;

		int lengthOfArray = sizeof(books) / sizeof(string);

		if (choice == '1') {
			cout << "Books that are available are: \n";
			for (int i = 0; i < lengthOfArray; i++) {
				cout << "	" << books[i] << endl;
			}
		}
		else if (choice == '2') {
			string book;
			bool available = false;

			cout << "Enter the name of the book that you want to borrow: ";
			cin >> book;

			for (int i = 0; i < lengthOfArray; i++) {
				if (book == books[i]) {
					available = true;
					cout << "Book available, borrowed successfully.\n";
					cout << "WARNING!!!\n";
					cout << "You have maximum of 3 days to return the book or else fine will be $1 for each exceeding day\n";

					books[i] = " ";

					break;
				}
			}
			if (available == false) {
				cout << "Book not available";
			}
		}
		else if (choice == '3') {
			string book;
			int days, fine = 1;

			cout << "Enter the name of the book: ";
			cin >> book;

			for (int i = 0; i < lengthOfArray; i++)
			{
				if (book != books[i]) {
					if (books[i] == " ") {
						books[i] = book;
					}
					else {
						books[i + 1] = book;
					}

					cout << "How many days did you borrowed the book for: ";
					cin >> days;

					if (days > 3) {
						fine = (days - 3) * fine;
						cout << "your fine is " << fine << " as you were late in returning the borrowed book in time.\n";
						cout << "Returned successfully\n";
						break;
					}
					else {
						cout << "Returned successfully, no fine is charged" << endl;
					}
					break;
				}
			}
		}
		else if (choice == '4') {
			cout << "See you next time. Goodbye :)" << endl;
			break;
		}

	} while (true);
	

	system("pause");
	return 0;
}