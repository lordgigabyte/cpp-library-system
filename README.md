# cpp-library-system

This is my second ever C++ project. I learned a lot more useful things programming this project, for example: Inheritance, custom exceptions, pointers, constructors, stringstream and a lot more about how the language itself works and things to look out for. 

## Features:
**Loan**
  - Lets the user loan a book of their choosing from the available books.
    - If a user tries to loan out a book with the same title as another one, the user will be asked to provide the ISBN number for the book they want to loan. 
  
**Return**
  - Lets the user return a book that they have loaned.

**Available books**
  - Lets the user see the books that are in the library's system.

**Exit**
  - Lets the user exit the program.

## Build & run:
This project was built and tested in Visual Studio.

1. Clone the repository.
2. Open "cpp-library-system.slnx" in Visual Studio.
3. Build and run (Ctrl+F5 or the green run button).
No external dependencies, just the C++ standard library is used.

## Why I made it:
This project was a way for me to learn more fundamentals of C++ and how they can be used. It was the perfect project for deepening my understanding of the language and its different functions. Things like inheritance and constructors are things I am familiar with from Java, but making this project gave me an even better understanding of them. One thing that this project showed me was pointers, which were completely new to me. There are a wide variety of uses for them and I am glad to have used them and learned about them in this project. 

## Example interaction:
```
Hello and welcome to the library! What would you like to do?
Loan
Return
Available books
Exit
Loan
What is the title of the book you would like to loan?
harry potter and the philosopher's stone
You loaned the book: harry potter and the philosopher's stone, successfully!

Hello and welcome to the library! What would you like to do?
Loan
Return
Available books
Exit
Available books

Harry Potter and the Philosopher's Stone, J.K. Rowling, Checked out

The Double, Fyodor Dostoyevsky, Available

The Double, Jose Saramago, Available

Harry Potter and the Goblet of Fire, J.K. Rowling, Available

A Tale of Two Cities, Charles Dickens, Available

Hello and welcome to the library! What would you like to do?
Loan
Return
Available books
Exit
```
## Example interaction for a book with a matching name
```
Hello and welcome to the library! What would you like to do?
Loan
Return
Available books
Exit
Loan
What is the title of the book you would like to loan?
the double
4424915358792, The Double, Fyodor Dostoyevsky
7216119766575, The Double, Jose Saramago

Can you specify which book you wanted to loan by entering the ISBN, please.
7216119766575
You loaned the book: the double by Jose Saramago, successfully!

Hello and welcome to the library! What would you like to do?
Loan
Return
Available books
Exit
```







