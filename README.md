# libarary_project_Cpp
# Library Management System

Welcome to the Library Management System! This simple C++ program allows you to manage a library by adding books, users, and tracking book borrowings.

## How to Use

1. **Login:**
    - Enter the password to access the library management system.

2. **Main Menu:**
    - Choose from the following options by entering the corresponding number:
        - 1. Add a book
        - 2. Search books by prefix
        - 3. Print users who borrowed books by name
        - 4. Print library by id
        - 5. Print library by name
        - 6. Add user
        - 7. User borrow book
        - 8. User return book
        - 9. Print users
        - 10. Logout

## Functionality

### 1. Add a Book
   - Adds a new book to the library with a unique ID, name, and quantity.

### 2. Search Books by Prefix
   - Searches for books in the library based on a user-entered prefix.

### 3. Print Users Who Borrowed Books by Name
   - Prints the users who have borrowed a specific book.

### 4. Print Library by ID
   - Prints the details of all books in the library, sorted by ID.

### 5. Print Library by Name
   - Prints the details of all books in the library, sorted by name.

### 6. Add User
   - Adds a new user to the system with a unique ID and name.

### 7. User Borrow Book
   - Allows a user to borrow a book by entering their name and the book's name.

### 8. User Return Book
   - Allows a user to return a book by entering their name and the book's name.

### 9. Print Users
   - Prints the details of all registered users, including the books they have borrowed.

### 10. Logout
   - Logs out of the system.

## Notes
- The default password is "pass123".
- ID and quantity are automatically assigned to books and users.
- User IDs and book IDs are used for book borrowings.

## Important Functions
- `add_book`: Adds a new book to the library.
- `search_prefix`: Searches for books based on a prefix.
- `add_user`: Adds a new user to the system.
- `user_borrow_book`: Allows a user to borrow a book.
- `User_return_book`: Allows a user to return a book.
- `print_users`: Prints the details of all registered users.
- `print_users_borrowed_book`: Prints users who have borrowed a specific book.
- `print_library`: Prints the details of all books in the library.

Feel free to explore and manage your library efficiently with this program!
