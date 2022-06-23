#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct librarys
{
    int mainac, subac, price, day, month, year;
    char bookname[30], authorname[30], flag[10], stdname[30], id;
} s;
struct libraryr
{
    int mainac, subac, price, day, month, year;
    char bookname[30], authorname[30], flag[10], stdname[30], id;
} r;
struct sutdent
{
    int mainac, subac, stdid, day, month, year;
    char stdname[30], flag[10];
} std;

int add_book();
int display_book();
int author();
int title_specbook();
int no_books();
int acc_books();
int withdraw();
int ret_book();
int not_ret();
int choose;
int main()
{
    while (1)
    {
        printf("\n");
        printf("1.Add book information\n");
        printf("2.Display book information\n");
        printf("3.List of all books given author\n");
        printf("4.List the title of specified book\n");
        printf("5.List of count of the books in the library\n");
        printf("6.List the books in the order of accessio number\n");
        printf("7.Withdraw a book\n");
        printf("8.Return a book\n");
        printf("9.Student not return book\n");
        printf("choose any opion:");
        scanf("%d", &choose);
        printf("\n");
        switch (choose)
        {
        case 1:
            add_book();
            break;
        case 2:
            display_book();
            break;
        case 3:
            author();
            break;
        case 4:
            title_specbook();
            break;
        case 5:
            no_books();
            break;
        case 6:
            acc_books();
            break;
        case 7:
            withdraw();
            break;
        case 8:
            ret_book();
            break;
        case 9:
            not_ret();
            break;
        default:
            exit(1);
            break;
        }
    }
    return 0;
}
int add_book()
{
    FILE *fp, *bu;
    int alx = 0, count = 0, nobooks, count1 = 0;
    printf("Enter book name: ");
    scanf("%s", s.bookname);
    printf("Enter author name: ");
    scanf("%s", s.authorname);
    printf("Enter price: ");
    scanf("%d", &s.price);
    printf("Enter day: ");
    scanf("%d", &s.day);
    printf("Enter month: ");
    scanf("%d", &s.month);
    printf("Enter year: ");
    scanf("%d", &s.year);
    printf("Enter number of books:");
    scanf("%d", &nobooks);
    bu = fopen("backup.dat", "w");
    fclose(bu);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(s.bookname, r.bookname) == 0)
        {
            alx = 1;
            r.subac++;
            count++;
        }
    }
    fclose(fp);
    if (alx == 1)
    {
        s.subac = r.subac++;
        fp = fopen("library.dat", "r");
        bu = fopen("backup.dat", "w");
        while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
            fprintf(bu, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, r.flag);
        fclose(fp);
        fclose(bu);
        fp = fopen("library.dat", "w");
        bu = fopen("backup.dat", "r");
        while (fscanf(bu, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
        {
            if (strcmp(r.bookname, s.bookname) == 0)
            {
                fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, r.flag);
                r.subac++;
                count1++;
                if (count1 == count)
                    for (int i = 0; i < nobooks; i++, r.subac++)
                        fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, s.bookname, s.authorname, s.price, s.day, s.month, s.year, "Availabel");
            }
            else
                fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, r.flag);
        }
        fclose(fp);
        fclose(bu);
    }
    else
    {
        fp = fopen("library.dat", "r");
        printf("Hello world\n");
        while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
        {
            count++;
        }
        r.mainac++;
        r.subac = 1;
        fclose(fp);
        fp = fopen("library.dat", "a");
        for (int i = 0; i < nobooks; i++, r.subac++)
            fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, s.bookname, s.authorname, s.price, s.day, s.month, s.year, "Availabel");
        fclose(fp);
    }
    printf("\n");
    return 0;
}
int display_book()
{
    FILE *fp;
    printf("Enter book name:");
    scanf("%s", s.bookname);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(s.bookname, r.bookname) == 0)
        {
            printf("Accession number :%d.%d     bookname : %s   ", r.mainac, r.subac, r.bookname);
            printf("Author name : %s    ", r.authorname);
            printf("Price : %d    ", r.price);
            printf("Date : %d/%d/%d    ", r.day, r.month, r.year);
            printf("Book is : %s\n", r.flag);
        }
    }
    fclose(fp);
    printf("\n");
    return 0;
}
int author()
{
    FILE *fp;
    printf("Enter author name:");
    scanf("%s", s.authorname);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(s.authorname, r.authorname) == 0)
        {
            printf("Accession number :%d.%d     bookname : %s   ", r.mainac, r.subac, r.bookname);
            printf("Author name : %s    ", r.authorname);
            printf("Price : %d    ", r.price);
            printf("Date : %d/%d/%d    ", r.day, r.month, r.year);
            printf("Book is : %s\n", r.flag);
        }
    }
    fclose(fp);
    printf("\n");
    return 0;
}
int title_specbook()
{
    FILE *fp;
    int count = 0, i = 0, l;
    printf("Enter book name:");
    scanf("%s", s.bookname);
    l = strlen(s.bookname);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        count = 0;
        for (i = 0; i < l; i++)
        {
            if (s.bookname[i] == r.bookname[i])
                count++;
        }
        if (count >= 5)
        {
            printf("Accession number :%d.%d     bookname : %s   ", r.mainac, r.subac, r.bookname);
            printf("Author name : %s    ", r.authorname);
            printf("Price : %d    ", r.price);
            printf("Date : %d/%d/%d    ", r.day, r.month, r.year);
            printf("Book is : %s\n", r.flag);
        }
    }
    fclose(fp);
    printf("\n");
    return 0;
}
int no_books()
{
    FILE *fp;
    int count = 0;
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
        count++;
    printf("Total number of books: %d \n", count);
    fclose(fp);
    printf("\n");
    return 0;
}
int acc_books()
{
    FILE *fp;
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        printf("Accession number :%d.%d     bookname : %s   ", r.mainac, r.subac, r.bookname);
        printf("Author name : %s    ", r.authorname);
        printf("Price : %d    ", r.price);
        printf("Date : %d/%d/%d    ", r.day, r.month, r.year);
        printf("Book is : %s\n", r.flag);
    }
    fclose(fp);
}
int withdraw()
{
    FILE *fp, *bu;
    char conf[5], alx = 0;
    printf("Enter book name: ");
    scanf("%s", s.bookname);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(s.bookname, r.bookname) == 0)
        {
            printf("Accession number :%d.%d     bookname : %s   ", r.mainac, r.subac, r.bookname);
            printf("Author name : %s    ", r.authorname);
            printf("Price : %d    ", r.price);
            printf("Date : %d/%d/%d    ", r.day, r.month, r.year);
            printf("Book is : %s\n", r.flag);
        }
    }
    fclose(fp);
    printf("Enter book main accession number : ");
    scanf("%d", &s.mainac);
    printf("Enter book sub accession number : ");
    scanf("%d", &s.subac);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(s.bookname, r.bookname) == 0 && s.mainac == r.mainac && s.subac == r.subac)
        {
            printf("Accession number :%d.%d     bookname : %s   ", r.mainac, r.subac, r.bookname);
            printf("Author name : %s    ", r.authorname);
            printf("Price : %d    ", r.price);
            printf("Date : %d/%d/%d    ", r.day, r.month, r.year);
            printf("Book is : %s\n", r.flag);
            break;
        }
    }
    fclose(fp);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (s.mainac == r.mainac && s.subac == r.subac && strcmp(r.flag, "Issued") == 0)
        {
            alx = 1;
            printf("Book is not availabel\n");
            break;
        }
    }
    fclose(fp);
    if (alx == 0)
    {
        printf("Enter student name :");
        scanf("%s", std.stdname);
        printf("Enter student id :");
        scanf("%d", &std.stdid);
        printf("Enter day :");
        scanf("%d", &std.day);
        printf("Enter month :");
        scanf("%d", &std.month);
        printf("Enter year :");
        scanf("%d", &std.year);
        printf("Type yes to confirm :");
        scanf("%s", conf);
        if (strcmp(conf, "yes") == 0)
        {
            fp = fopen("library.dat", "r");
            bu = fopen("backup.dat", "w");
            while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
                fprintf(bu, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, r.flag);
            fclose(fp);
            fclose(bu);
            fp = fopen("library.dat", "w");
            bu = fopen("backup.dat", "r");
            while (fscanf(bu, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
            {
                if (s.mainac == r.mainac && s.subac == r.subac && strcmp(r.flag, "Availabel") == 0)
                {
                    fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, "Issued");
                }
                else
                    fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, r.flag);
            }
            fclose(fp);
            fclose(bu);
            if (alx == 0)
            {
                fp = fopen("std.dat", "a");
                fprintf(fp, "%d.%d %s %d %d/%d/%d %s\n", s.mainac, s.subac, std.stdname, std.stdid, std.day, std.month, std.year, "Withdraw");
                fclose(fp);
            }
        }
    }
    return 0;
}
int ret_book()
{
    FILE *fp, *st, *stbc, *bu;
    int ret = 0;
    struct libnew
    {
        int mainac, subac, price, day, month, year, stdid;
        char bookname[30], authorname[30], flag[10], stdname[30];
    } l;
    char stdname[30];
    int stdid, z = 0;
    printf("Enter student name :");
    scanf("%s", stdname);
    printf("Enter student id : ");
    scanf("%d", &stdid);
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(r.flag, "Issued") == 0)
        {
            st = fopen("std.dat", "r");
            while (fscanf(st, "%d.%d %s %d %d/%d/%d %s", &l.mainac, &l.subac, l.stdname, &l.stdid, &l.day, &l.month, &l.year, l.flag) != EOF)
            {
                if (r.mainac == l.mainac && r.subac == l.subac && strcmp(l.flag, "Withdraw") == 0)
                {
                    break;
                }
            }
            fclose(st);
            st = fopen("std.dat", "r");
            while (fscanf(st, "%d.%d %s %d %d/%d/%d %s", &std.mainac, &std.subac, std.stdname, &std.stdid, &std.day, &std.month, &std.year, std.flag) != EOF)
            {
                if (r.mainac == std.mainac && r.subac == std.subac && strcmp(std.stdname, l.stdname) == 0 && std.stdid == l.stdid && strcmp(std.flag, "Returned") == 0)
                {
                    break;
                }
            }
            fclose(st);
            printf("Accession number :%d.%d     bookname : %s   ", r.mainac, r.subac, r.bookname);
            printf("Author name : %s    ", r.authorname);
            printf("Price : %d    ", r.price);
            printf("Date : %d/%d/%d    ", r.day, r.month, r.year);
            printf("Book is : %s\n", r.flag);
            z = 1;
        }
    }
    fclose(fp);
    if (z == 0)
    {
        printf("Student does not issued any book\n");
        return 0;
    }
    if (z == 1)
    {
        printf("Enter main accession number of book : ");
        scanf("%d", &l.mainac);
        printf("Enter sub accession number of book : ");
        scanf("%d", &l.subac);
        st = fopen("std.dat", "a");
        fprintf(st, "%d.%d %s %d %d/%d/%d %s\n", std.mainac, std.subac, std.stdname, std.stdid, std.day, std.month, std.year, "Returned");
        fclose(st);
        fp = fopen("library.dat", "r");
        bu = fopen("backup.dat", "w");
        while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
            fprintf(bu, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, r.flag);
        fclose(fp);
        fclose(bu);
        bu = fopen("backup.dat", "r");
        fp = fopen("library.dat", "w");
        while (fscanf(bu, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
        {
            if (l.mainac == r.mainac && l.subac == r.subac && strcmp(r.flag, "Issued") == 0)
            {
                fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, "Availabel");
            }
            else
                fprintf(fp, "%d.%d %10s %10s %4d %d/%d/%d %s\n", r.mainac, r.subac, r.bookname, r.authorname, r.price, r.day, r.month, r.year, r.flag);
        }
        fclose(bu);
        fclose(fp);
    }
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(r.flag, "Issued") == 0)
        {
            st = fopen("std.dat", "r");
            while (fscanf(st, "%d.%d %s %d %d/%d/%d %s", &std.mainac, &std.subac, std.stdname, &std.stdid, &std.day, &std.month, &std.year, std.flag) != EOF)
                if (r.mainac == std.mainac && r.subac == std.subac && strcmp(stdname, std.stdname) == 0 && std.stdid == stdid)
                {
                    bu = fopen("std.dat", "r");
                    stbc = fopen("stdback.dat", "w");
                    while (fscanf(bu, "%d.%d %s %d %d/%d/%d %s", &l.mainac, &l.subac, l.stdname, &l.stdid, &l.day, &l.month, &l.year, l.flag) != EOF)
                    {
                        if (r.mainac == l.mainac && r.subac == l.subac)
                            fprintf(stbc, "%d.%d %s %d %d/%d/%d %s\n", l.mainac, l.subac, l.stdname, l.stdid, l.day, l.month, l.year, l.flag);
                    }
                    fclose(bu);
                    fclose(stbc);
                }
            fclose(st);
        }
    }
    fclose(fp);
    return 0;
}
int not_ret()
{
    FILE *fp, *st;
    int ret = 0;
    struct libnew
    {
        int mainac, subac, price, day, month, year, stdid;
        char bookname[30], authorname[30], flag[10], stdname[30];
    } l;
    fp = fopen("library.dat", "r");
    while (fscanf(fp, "%d.%d %s %s %d %d/%d/%d %s", &r.mainac, &r.subac, r.bookname, r.authorname, &r.price, &r.day, &r.month, &r.year, r.flag) != EOF)
    {
        if (strcmp(r.flag, "Issued") == 0)
        {
            st = fopen("std.dat", "r");
            while (fscanf(st, "%d.%d %s %d %d/%d/%d %s", &l.mainac, &l.subac, l.stdname, &l.stdid, &l.day, &l.month, &l.year, l.flag) != EOF)
            {
                if (r.mainac == l.mainac && r.subac == l.subac && strcmp(l.flag, "Withdraw") == 0)
                {
                    ret = 1;
                    break;
                }
            }
            fclose(st);
            st = fopen("std.dat", "r");
            while (fscanf(st, "%d.%d %s %d %d/%d/%d %s", &std.mainac, &std.subac, std.stdname, &std.stdid, &std.day, &std.month, &std.year, std.flag) != EOF)
            {
                if (r.mainac == std.mainac && r.subac == std.subac && strcmp(std.stdname, l.stdname) == 0 && std.stdid == l.stdid && strcmp(std.flag, "Returned") == 0)
                {
                    ret = 2;
                    break;
                }
            }
            fclose(st);
            printf("Student name : %s   Student id : %d\n", l.stdname, l.stdid);
        }
    }
    return 0;
}