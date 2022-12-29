/*string.h to work on strings and stdlib.h for involving memory allocation*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*declare all variables which store book informations using structure 'books'*/
struct books
{
    char booktitle[50],bookauthor[30];
    float bookprice;
    int copies;

}b[1000];
/*main function*/
main()
{
     int a,i=0,count=0,found=0;
     char test[50];
/*recalling functions to use for operations*/
     void showMenuOptions();
     void searchBook();
     void showBooks();
     void addBook();
     void showNumberOfBooks();
 /*To show welcome message and menu options*/
     showWelcomeMessage();
     showMenuOptions();


     while (a!=6)
    {

        printf ("\n\n Enter your choice: ");
        scanf  ("%d", &a); /*Taking option to perform certain operations*/
        switch(a)
        {
        case 1:

            showMenuOptions(); /*shows Menu options*/
            break;
        case 2: /*shows all books in system if any registered*/

            if (count == 0)
                printf ("\n No available books");
            else
                printf ("\n List of books:\n");
            for (i=0;i<count;i++)
            {
                printf ("\n");
                showBooks(i);
            }
            break;
        case 3: /*adds books in the system*/

            addBook(i);
            i = i+1;
            count++;
            break;
        case 4: /*take title as input to search available book*/

            printf ("\n Enter book title to search: ");
            fflush(stdin);
            scanf ("%[^\n]%*c",test);
            printf ("\n");
            for (i=0;i<count;i++)
            {
                if (strcasecmp(test, b[i].booktitle) == 0)
                    {
                        searchBook(i);
                        printf ("\n");
                        found = 1;
                        printf ("\n A book has been found!!!");
                    }
            }
            if (found == 0)
            {
                printf (" Book not found");
            }

            break;
        case 5: /*shows number of books in system*/

            showNumberOfBooks(count);
            break;
        case 6:

            showGoodbyeMessage(); /*shows goodbye message*/
            break;

        default: /*if user inputs any invalid options*/

            printf ("\nPlease enter a valid option from above.");
            break;

        }
    }
    return 0;
}
void showMenuOptions() /*function to show menu options*/
{
    printf ("\n\n\n Please select a menu option number:\n");
    printf (" 1) Display this menu.\n");
    printf (" 2) Show all available books.\n");
    printf (" 3) Add a book to the book shop.\n");
    printf (" 4) Search a book by title.\n");
    printf (" 5) Display the total number of books.\n");
    printf (" 6) Exit from this book system.\n");
}
void searchBook(int i) /*function to search book from system*/
{

    printf (" Book title: %s", b[i].booktitle);
    printf ("\n Book author: %s", b[i].bookauthor);
    printf ("\n Book price: %.2f", b[i].bookprice);
    printf ("\n Book copies: %d", b[i].copies);
}
void showGoodbyeMessage() /*function to show goodbye message*/
{
    printf ("\n ***********************************************\n\n");
    printf (" Thanks for using Simple Book Management System.\n\n");
    printf (" ***********************************************\n\n");
}
void showBooks(int i) /*function to show books*/
{

    printf (" Book title: %s\n", b[i].booktitle);
    printf (" Book author: %s\n", b[i].bookauthor);
    printf (" Book price: %.2f\n", b[i].bookprice);
    printf (" Book copies: %d\n", b[i].copies);
}
void addBook(int i) /*function to add books*/
{

    printf ("\n Enter book title: ");
    fflush(stdin);
    gets(b[i].booktitle);
    printf (" Enter book author: ");
    fflush(stdin);
    gets(b[i].bookauthor);
    printf (" Enter book price: ");
    scanf  ("%f", &b[i].bookprice);
    printf (" Enter number of copies: ");
    scanf  ("%d", &b[i].copies);
}
void showNumberOfBooks(int count) /*function to show number of books*/
{

    printf ("\n Total number of books in the shop: %d", count);
}
void showWelcomeMessage() /*function to show welcome message*/
{
     printf (" *****************************************\n\n");
     printf (" Welcome to Simple Book Management System.\n\n");
     printf (" *****************************************");
}
