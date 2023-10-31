#include <stdio.h>
#include <stdlib.h>

int Str_len(char *str)
{
    int i=0;
    for(i=0; str[i]; i++)
    {
        i++;
    }
    return i;
}
void string_scan(char *str, int maxSize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for(; str[i]!= '\n' && i<maxSize;)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i] = 0;
}

void string_copy(char str1[], char *str2)
{
    int i;
    for(i=0; str2[i]; i++)
    {
        str1[i] = str2[i];
    }
    str1[i] = 0;
}
typedef struct
{
    char bookTitle[100];
    char authorName[100];
    char status[50];
    int publicationYear;
    int numOfCopies;
    float price;
    int id;
} BOOK_T;
BOOK_T Library[100];
int index_of_book=0;
int numOfBooks=0;
int temp=0;
#define BOOKS_MAX   100
void Add_Book(int id)
{
    BOOK_T b;
    for(int i=0; i<index_of_book; i++)
    {
        if(id == Library[i].id)
        {
            Library[i].numOfCopies++;
            numOfBooks++;
            printf("The book is already available.\n");
            return;
        }
    }
    b.id = id;
    printf("Please Enter The Title of The book:\n");
    fflush(stdin);
    string_scan(b.bookTitle,100);

    printf("Please Enter The Author of The book:\n");
    fflush(stdin);
    string_scan(b.authorName,100);

    printf("Please Enter The status of The book:\n");
    fflush(stdin);
    string_scan(b.status,50);

    printf("Please Enter The publication year of The book:\n");
    fflush(stdin);
    scanf("%d",&b.publicationYear);

    printf("Please Enter The price of The book:\n");
    fflush(stdin);
    scanf("%f",&b.price);

    if(numOfBooks < BOOKS_MAX)
    {
        Library[index_of_book] = b;
        Library[index_of_book].numOfCopies = 1;
        index_of_book++;
        numOfBooks++;
    }
    system("cls");
}
void print_Book(int id)
{
    int i,flag=0;
    for(i=0; i<index_of_book; i++)
    {
        if(id == Library[i].id)
        {
            if(Str_len(Library[i].authorName) < 100)
            {
                printf("Author Name: %s\n",Library[i].authorName);
            }
            else
            {
                printf("Author Name is greater than 100 characters\n");
            }

            if(Str_len(Library[i].bookTitle) < 100)
            {
                printf("Book Title: %s\n",Library[i].bookTitle);
            }
            else
            {
                printf("Book Title is greater than 100 characters\n");
            }

            if(Str_len(Library[i].status) < 50)
            {
                printf("Status: %s\n",Library[i].status);
            }
            else
            {
                printf("Book status is greater than 50 characters\n");
            }

            printf("Publication Year: %d\n", Library[i].publicationYear);
            printf("Number of Copies: %d\n", Library[i].numOfCopies);
            printf("Price: %.1f\n", Library[i].price);
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Invalid Book.\n");
    }
}
void Book_Borrow(int id)
{
    int flag =0;
    for(int i=0; i<index_of_book; i++)
    {
        if(id == Library[i].id)
        {

            if(Library[i].numOfCopies >0)
            {
                Library[i].numOfCopies --;
                numOfBooks--;
                printf("Congrats, you have borrowed The book!\n");

                if(Library[i].numOfCopies == 0)
                {
                    strcpy(Library[i].status, "Borrowed ");
                }
            }
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("This Book is not valid.\n");
    }
}
void Book_buy(int id)
{
    int flag = 0;
    for(int i=0; i<index_of_book; i++)
    {
        if(id == Library[i].id)
        {
            printf("Enter number of books you want to buy:\n");
            scanf("%d",&temp);
            numOfBooks+=temp;
            if((numOfBooks) > BOOKS_MAX)
            {
                printf("Library is full.\n");
                return;
            }
            Library[i].numOfCopies+=numOfBooks;
            printf("Congrats, you have bought a new book!\n");
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("This Book is not valid.\n");
    }
}
void book_delete(int id)
{
    int index, flag=0;
    for(int i=0; i<index_of_book; i++)
    {
        if(id == Library[i].id)
        {
            index = i;
            for(i=index; i<index_of_book; i++)
            {
                Library[i] = Library[i+1];
            }
            string_copy(Library[i].authorName , "-1");
            string_copy(Library[i].bookTitle , "-1");
            string_copy(Library[i].status , "-1");
            Library[i].id = -1;
            Library[i].numOfCopies = -1;
            Library[i].publicationYear = -1;
            Library[i].price = -1;
            flag = 1;
            printf("The book is deleted.\n");
            break;
        }
    }
    if(flag == 0)
    {
        printf("There is no book to delete.\n");
    }
}
void Exit(void)
{
    exit(1);
}
int main()
{
    int choice,id;
    for(;;)
    {

        printf("=============================================\nPlease select one of the following options:  |\n%45s|\n1- Add Book.%-33s|\n2- Print Book.%-31s|\n3- Borrow Book.%-30s|\n\
4- Delete Book.%-30s|\n5- Buy Book.%-33s|\n6- Exit.%-36s|\n=============================================\n"," ", " ", " ", " ", " "," "," ", " ");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
        case 1:
            printf("Enter The ID of The Book:\n");
            scanf("%d",&id);
            Add_Book(id);
            break;
        case 2:
            if(index_of_book == 0)
            {
                printf("No Book Entered Library Yet.\n");
            }
            else
            {
                printf("Enter The ID of The Book:\n");
                scanf("%d",&id);
                print_Book(id);
            }
            break;
        case 3:
            if(index_of_book == 0)
            {
                printf("No Book Entered Library Yet to Borrow.\n");
            }
            else
            {
                printf("Enter The ID of The Book:\n");
                scanf("%d",&id);
                Book_Borrow(id);
            }
            break;
        case 4:
            printf("Enter The ID of The Book:\n");
            scanf("%d",&id);
            book_delete(id);
            break;

        case 5:
            if(index_of_book == 0)
            {
                printf("No Book Entered Library Yet to buy.\n");
            }
            else
            {
                printf("Enter The ID of The Book:\n");
                scanf("%d",&id);
                Book_buy(id);
            }
            break;

        case 6:
            Exit();

        }
    }

}
