#include<stdio.h>
#include<conio.h>
#include<windows.h>
typedef struct book
{
char title[20];
char author[20];
int page;
float price;
}Book;
Book *book;
int count=0;
int size;
void addBook()
{
system("cls");
system("color 0c");
printf("\n********ADD NEW BOOK DETAIL********");
printf("\n enter book tittle:");
fflush(stdin);
gets(book[count].title);
printf("\n enter book author:");
fflush(stdin);
gets(book[count].author);
printf("\n enter book price:");
scanf("%f",&book[count].price);
printf("\n enter book page:");
scanf("%d",&book[count].page);
fflush(stdin);
count++;
}
void showallbook()
{
int i;
system("cls");
system("color 71");
printf("\n\n\t\t###############Book Details##############");
printf("\n\n\t\t-----------------------------------------");
printf("\n\t\tBOOK TITTLE\t\tBOOK AUTHOR\t\tBOOK PRICE\t\tBOOK PAGES");
printf("\n\t\t--------------------------------------------");
for(i=0;i<count;i++)
{
printf("\n%25s",book[i].title);
printf("%25s",book[i].author);
printf("%20f",book[i].price);
printf("%20d",book[i].page);
}
}
void searchBook()
{
char btitle[10];
int i;
printf("\nEnter book title to be search:");
gets(btitle);
for(i=0;i<count;i++)
{
if(stricmp(book[i].title,btitle)==0)
{
system("cls");
printf("\n\n\t\t###########BOOK DETAILS############");
printf("\n\n\t\tbook title :%s",book[i].title);
printf("\n\t\tbook author :%s",book[i].author);
printf("\n\t\tbook price :%f",book[i].price);
printf("\n\t\tbook page :%d\n",book[i].page);
}
}
}
void removebook()
{
char btitle[10];
int i,j;
Book *temp;
printf("\nEnter book title to be remove:");
gets(btitle);
for(i=0;i<count;i++)
{
if(stricmp(book[i].title,btitle)==0)
{
system("cls");
printf("\n\n\t\t ###########Remove Book Details###########");
printf("\n\n\t\tbook title :%s",book[i].title);
printf("\n\t\tbook author :%",book[i].author);
printf("\n\t\tbook priice :%f",book[i].price);
printf("\n\t\tbook pages :%d\n",book[i].page);
for(j=i;j<count-i;j++)
book=book+1;
count--;
return;
}
}
}
void updatebook()
{
char btitle[10];
int i,j;
Book temp;
printf("\nEnter book title to be remove :");
gets(btitle);
for(i=0;i<count;i++)
{
if(stricmp(book[i].title,btitle)==0)
{
system("cls");
printf("\n\n\t\t########## Book Details ###########");
printf("\n\n\t\tbook title :%s",book[i].title);
printf("\n\t\tbook author :%s",book[i].author);
printf("\n\t\tbook price :%f",book[i].price);
printf("\n\t\tbook pages ;%d\n",book[i].page);
printf("\n************Add new book details **********");
printf("\nEnter book title:");
gets(book[i].title);
printf("\nEnter book author :");
fflush(stdin);
gets(book[i].author);
printf("\nEnter book price :");
scanf("%f",&book[i].price);
printf("\nEnter book pages :");
scanf("%d",&book[i].page);
}
}
}
int login()
{
	char ch;
	int i,count=3;
	char password[]="admin123",pass[100];
	do{
		system("cls");
		printf("Tries Left! %d\n",count--);
		printf("Enter Admin Password:");
		i=0;
		ch = getch();
		while(ch!=13)
		{
			printf("*");
			pass[i++]=ch;
			ch = getch();
		}
		pass[i]='\0';
		if(strcmp(pass,password)==0)
			return 1;
	}while(count>0);
	return 0;
}
int main()
{
	int choice;
	if(!login()){
		printf("\nExiting....\n");
		return 0;
	}
	system("cls");
	printf("\n Enter the total no.of book you want add in library:");
	scanf("%d",&size);
	book=(Book*)malloc(sizeof(Book)*size);
	do
	{
		system("cls");
		printf("\n1. Add book\n2.show all book\n3.search book\n4.update book\n5.remove book");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: addBook();
			        break;
			case 2:showallbook();
		          	break;
			case 3:searchBook();
			        break;
			case 4:updatebook();
			       break;
			case 5:removebook();
			       break;
			case 6:
			       return 0;	   	           
		}
		getch();
	}	while(1);
    }
