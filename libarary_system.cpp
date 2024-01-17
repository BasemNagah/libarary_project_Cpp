#include<iostream>
using namespace std;

int last_book = 0 ;
int last_user = 0 ;

/////structs
    struct user
    {
        int user_id ;
        string user_name ;
        int borrow_books_size ;
        int borrow_books_id[100] ;

    };

    struct book
    {
        int book_id ;
        string book_name ;
        int quantity ;
        int borrow_users_size ;
        int users_borrowed[100] ;

    };

    book books[1000] ;
    user users[1000] ;

  //  functions
void add_book(void) ;
void search_prefix(void) ;
void add_user(void) ;
void print_users(void) ;
void user_borrow_book(void) ;
void print_users_borrowed_book(void) ;
void print_library(void) ;
void User_return_book(void) ;



int main() {

    string password = "pass123" ;
    string copy_pass ;
    int choice ;
    int logout_flag ;


    while(1)
    {
        cout<<"please Enter password : " ;
        cin>>copy_pass ;
        if(copy_pass == password)
        {
            logout_flag = 0 ;
            while(1)
            {
                cout<<"1) Add book\n" ; //done
                cout<<"2) Search books by prefix\n" ;//done
                cout<<"3) Print who borrowed books by name\n" ; // done
                cout<<"4) Print library by id\n" ; //done
                cout<<"5) Print library by name\n" ; // done
                cout<<"6) Add user\n" ; //done
                cout<<"7) User borrow book\n" ; //done
                cout<<"8) User return book\n" ;
                cout<<"9) Print users \n" ; //done
                cout<<"10) Logout \n" ; //done
                cout<<"Enter your menu choice [1-10] : " ;
                cin>>choice ;

                switch(choice)
                {
                case 1:
                    add_book() ;
                    break ;

                case 2:
                    search_prefix() ;
                    break ;

                case 3:
                    print_users_borrowed_book() ;
                    break ;

                case 4:
                    print_library() ;
                    break ;

                case 5:
                    print_library() ;
                    break ;

                case 6:
                    add_user();
                    break ;

                case 7:
                    user_borrow_book() ;
                    break ;

                case 8:
                    User_return_book() ;
                    break ;

                case 9:
                    print_users() ;
                    break ;

                case 10:
                    logout_flag = 1 ;
                    break ;

                default :
                    cout<<"Wrong choice please try again !\n" ;
                    break ;
                }

                if(logout_flag == 1)
                {
                    cout<<"Logout successfully !\n" ;
                    break ;
                }

            }



        }
        else
        {
            cout<<"Wrong password !\nPlease try again \n";
        }

    }



	return 0;
}


void add_book(void)
{
    books[last_book].book_id = last_book ;
    cout<<"id = "<<last_book ;
    cout<<"\nEnter book name : " ;
    cin>>books[last_book].book_name ;
    cout<<"Enter book quantity : " ;
    cin>>books[last_book].quantity ;
    cout<<"** Book with informations ( id:" <<books[last_book].book_id<<" name:"<<books[last_book].book_name
    <<" quantity:"<<books[last_book].quantity<<" ) added successfully **\n" ;
    last_book++ ;
}

void search_prefix(void)
{
    string prefix ;
    int prefix_size ;
    int prefix_flag = 0 ;

    cout<<"Enter book name prefix : " ;
    cin>>prefix ;
    prefix_size = prefix.size() ;
    for(int j=0 ;j<last_book ; j++)
    {
        prefix_flag = 0 ;
        for(int i=0 ; i<prefix_size; i++)
        {
            if( (books[j].book_name[i]) != prefix[i] )
            {
                prefix_flag = 1 ;
            }
        }

        if(prefix_flag == 0)
        {
            cout<<books[j].book_name<<"("<<books[j].quantity<<")\n" ;
        }
    }
}

void add_user(void)
{
    users[last_user].user_id = last_user ;
    cout<<"id : "<<last_user ;
    cout<<"\nEnter user name : " ;
    cin>>users[last_user].user_name ;
    cout<<"** "<<users[last_user].user_name<<" added successfully ! **\n" ;
    last_user++ ;
}

void print_users(void)
{
    for(int i=0 ;i<last_user ; i++)
    {
        cout<<"User "<<users[i].user_name<<" , id "<<users[i].user_id<<" , borrowed books ids : " ;
        for (int j=0 ; j<users[i].borrow_books_size ; j++)
        {
            cout<<users[i].borrow_books_id[i]<<" " ;
        }
        cout<<"\n" ;
    }
}

void user_borrow_book(void)
{
    string user_name ;
    int user_index ,book_index ;
    int validation_flag = 0 ;
    string book_name ;
    cout<<"Enter user name : " ;
    cin>>user_name ;
    cout<<"Enter book name : " ;
    cin>>book_name ;
    for(int i=0 ; i<last_user ; i++)
    {
        if(user_name == users[i].user_name)
        {
            user_index = i ;
            validation_flag  = 2 ;
        }
    }

    for(int i=0 ; i<last_book ; i++)
    {
        if(book_name == books[i].book_name)
        {
            book_index = i ;
            validation_flag  += 4 ;
        }
    }


    switch(validation_flag)
    {
    case 0:
        cout<<"Wrong user name and book name !\n";
        break;

    case 2:
        cout<<"Wrong book name !\n";
        break;

    case 4 :
        cout<<"Wrong user name !\n";
        break;

    case 6 :
        books[book_index].users_borrowed[books[book_index].borrow_users_size]  = users[user_index].user_id ;
        books[book_index].borrow_users_size++ ;

        users[user_index].borrow_books_id[users[user_index].borrow_books_size] = books[book_index].book_id ;
        users[user_index].borrow_books_size++ ;
        cout<<"Done successfully !\n";
        break ;

    }

}

void print_users_borrowed_book(void)
{
    string local_book_name ;
    cout<<"please enter book name : " ;
    cin>>local_book_name ;

    for(int i=0 ;i<last_book ; i++)
    {
        if(books[i].book_name == local_book_name)
        {
            for(int j=0 ;j<books[i].borrow_users_size ; j++)
            {
                for(int k=0 ; k<last_user ; k++)
                {
                    if(books[i].users_borrowed[j] == users[k].user_id)
                    {
                        cout<<users[k].user_name<<"\n" ;
                    }
                }
            }
        }
    }

}


void print_library(void)
{
    for(int i=0 ;i<last_book ; i++)
    {
        cout<<"id = "<<books[i].book_id<<"  name = "<<books[i].book_name<<"  total_quantity = "
        <<books[i].quantity<<"  total_borrowed = "<<books[i].borrow_users_size<<"\n" ;
    }
}


void User_return_book(void)
{
    string user_name ;
    int user_index ,book_index ;
    int validation_flag = 0 ;
    string book_name ;
    cout<<"Enter user name : " ;
    cin>>user_name ;
    cout<<"Enter book name : " ;
    cin>>book_name ;
    for(int i=0 ; i<last_user ; i++)
    {
        if(user_name == users[i].user_name)
        {
            user_index = i ;
            validation_flag  = 2 ;
        }
    }

    for(int i=0 ; i<last_book ; i++)
    {
        if(book_name == books[i].book_name)
        {
            book_index = i ;
            validation_flag  += 4 ;
        }
    }


    switch(validation_flag)
    {
    case 0:
        cout<<"Wrong user name and book name !\n";
        break;

    case 2:
        cout<<"Wrong book name !\n";
        break;

    case 4 :
        cout<<"Wrong user name !\n";
        break;

    case 6 :
        for(int i=0 ;i<books[book_index].borrow_users_size ;  i++ )
        {
            if(books[book_index].users_borrowed[i] == users[user_index].user_id)
            {
                for(int j=i ;j<books[book_index].borrow_users_size ; j++)
                {
                    books[book_index].users_borrowed[j] = books[book_index].users_borrowed[j+1] ;
                }
                books[book_index].borrow_users_size-- ;
                break ;
            }
        }

        users[user_index].borrow_books_id[users[user_index].borrow_books_size] = books[book_index].book_id ;



        for(int i=0 ;i<users[user_index].borrow_books_size ;  i++ )
        {
            if(users[user_index].borrow_books_id[i] == books[book_index].book_id)
            {
                for(int j=i ;j<users[user_index].borrow_books_size  ; j++)
                {
                    users[user_index].borrow_books_id[j] = users[user_index].borrow_books_id[j+1] ;
                }
                users[user_index].borrow_books_size-- ;
                break ;
            }
        }

        cout<<"returned successfully !\n";
        break ;

    }

}
