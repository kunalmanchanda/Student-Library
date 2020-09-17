#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

string bname;
string auth;
float prc;
int no_of_cpy;
char stats;
int edt;

class book
{
    private:
        struct node
        {
            string book_name;
            string author;
            float price;
            int no_of_copies;
            char status;
            int edition;
            node *next;
        };
        node *head;
        node *tail;

    public:
        book()
        {
            head=NULL;
            tail=NULL;
        }
        void add_node()
        {
            node *temp=new node;
            temp->book_name=bname;
            temp->author=auth;
            temp->price=prc;
            temp->no_of_copies=no_of_cpy;
            temp->status=stats;
            temp->edition=edt;
            temp->next=NULL;

            if(head==NULL)
            {
                head=temp;
                tail=temp;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }

        }
        void read_book()
        {
            ifstream myfile("book.txt", ios::in);

            if(myfile.is_open())
            {
                myfile>>bname>>auth>>prc>>no_of_cpy>>stats>>edt;

                while (!myfile.eof())
                {
                    if(myfile.good())
                    {
                        add_node();
                        myfile>>bname>>auth>>prc>>no_of_cpy>>stats>>edt;
                    }
                }
                myfile.close();
            }

            else
            {
                cout << "Unable to open file";
            }
        }

        void add_new_book()
        {
            cout<<"\nENTER THE NAME OF BOOK : ";
            fflush(stdin);
            getline(cin,bname);
            cout<<"\nENTER THE AUTHOR OF BOOK : ";
            fflush(stdin);
            getline(cin,auth);
            cout<<"\nENTER THE PRICE OF BOOK : ";
            cin>>prc;
            cout<<"\nENTER NO OF COPIES OF BOOK : ";
            cin>>no_of_cpy;
            cout<<"\nENTER THE EDITION OF BOOK : ";
            cin>>edt;

            //EXCEPTION HANDLING
            try
            {
                if (no_of_cpy > 0)
                    throw no_of_cpy;
                else
                    throw 'no_of_cpy';
                } catch (int ex)
                {
                    stats='Y';
                } catch (char ex)
                {
                    stats='N';
                }

            /*
            if(no_of_cpy>0)
            {
                stats='Y';
            }
            else
            {
                stats='N';
            }
            */

            replace( bname.begin(), bname.end(), ' ', '_');
            replace( auth.begin(), auth.end(), ' ', '_');

            for(int i=0;i<bname.length();i++)
            {
                if(bname[i]<='z' && bname[i]>='a')
                {
                    bname[i]-=32;
                }
            }

            for(int i=0;i<auth.length();i++)
            {
                if(auth[i]<='z' && auth[i]>='a')
                {
                    auth[i]-=32;
                }
            }

            add_node();
        }

        void display_all_book()
        {
            node *temp=head;
            int i=1;
            while(temp!=NULL)
            {
                cout<<"\nBOOK_NO : "<<i<<"\n";
                cout<<"\nBOOK_NAME : "<<temp->book_name<<"\n"<<"AUTHOR_NAME : "<<temp->author<<"\n"<<"PRICE : "<<temp->price<<"\n"<<"STATUS : "<<temp->status<<"\n"<<"NUMBER_OF_COPIES : "<<temp->no_of_copies<<"\n"<<"EDITION : "<<temp->edition<<"\n\n";
                temp=temp->next;
                i++;
            }
        }
        int book_rstatus()
        {
            cout<<"\nENTER THE NAME OF THE BOOK TO BE ISSUED\n";
            fflush(stdin);
            getline(cin,bname);
            replace( bname.begin(), bname.end(), ' ', '_');

            for(int i=0;i<bname.length();i++)
            {
                if(bname[i]<='z' && bname[i]>='a')
                {
                    bname[i]-=32;
                }
            }
            node *temp=head;
            while(temp!=NULL)
            {
                if(temp->book_name.compare(bname)==0)
                {
                    cout<<"\nBOOK_NAME : "<<temp->book_name<<"\n"<<"AUTHOR_NAME : "<<temp->author<<"\n"<<"PRICE : "<<temp->price<<"\n"<<"STATUS : "<<temp->status<<"\n"<<"NUMBER_OF_COPIES : "<<temp->no_of_copies<<"\n"<<"EDITION : "<<temp->edition<<"\n\n";
                    cout<<"\nBOOK FOUND!!!!!\n";
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n BOOK NOT FOUND!! \n";
                return 0;
            }
            if(temp->status=='Y')
            {
                temp->no_of_copies=temp->no_of_copies-1;
                cout<<"\n no of final copies: " <<temp->no_of_copies<<"\n";

                if(temp->no_of_copies==0)
                {
                     temp->status='N';
                }
                ofstream myfile("issuedbook.txt",ios::out | ios::app);
                if(myfile.is_open())
                {
                    myfile<<temp->book_name<<" "<<temp->author<<" "<<temp->price<<" "<<"1"<<" "<<temp->status<<" "<<temp->edition<<"\n";
                    myfile.close();
                }
                else
                {
                    cout << "Unable to open file\n";
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int book_status()
        {
            cout<<"\nENTER THE NAME OF THE BOOK TO BE ISSUED\n";
            fflush(stdin);
            getline(cin,bname);
            replace( bname.begin(), bname.end(), ' ', '_');

            for(int i=0;i<bname.length();i++)
            {
                if(bname[i]<='z' && bname[i]>='a')
                {
                    bname[i]-=32;
                }
            }
            node *temp=head;
            while(temp!=NULL)
            {
                if(temp->book_name.compare(bname)==0)
                {
                    cout<<"\nBOOK_NAME : "<<temp->book_name<<"\n"<<"AUTHOR_NAME : "<<temp->author<<"\n"<<"PRICE : "<<temp->price<<"\n"<<"STATUS : "<<temp->status<<"\n"<<"NUMBER_OF_COPIES : "<<temp->no_of_copies<<"\n"<<"EDITION : "<<temp->edition<<"\n\n";
                    cout<<"\nBOOK FOUND!!!!!\n";
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n BOOK NOT FOUND!! \n";
                return 0;
            }
            if(temp->status=='Y')
            {
                temp->no_of_copies=temp->no_of_copies-1;
                cout<<"\n no of final copies: " <<temp->no_of_copies<<"\n";

                if(temp->no_of_copies==0)
                {
                     temp->status='N';
                }
                ofstream myfile("issuedbook.txt",ios::out | ios::app);
                if(myfile.is_open())
                {
                    myfile<<temp->book_name<<" "<<temp->author<<" "<<temp->price<<" "<<"1"<<" "<<temp->status<<" "<<temp->edition<<"\n";
                    myfile.close();
                }
                else
                {
                    cout << "Unable to open file\n";
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }

        void update_book_details()
        {
            int ch;
            cout<<"UPDATE BOOK\n";
            cout<<"OPTIONS ARE:\n\n";
            cout<<"1...UPDATE BY BOOK NAME\n";
            cout<<"2...UPDATE BY AUTHOR NAME\n";
            cout<<"\t\tWANT TO UPDATE THE BOOK BY AUTHOR NAME OR BOOK NAME";
            cout<<"ENTER YOUR OPTION\n";
            cin>>ch;
            if(ch==1)
            {
                update_by_name();
            }
            else
            {
                update_by_auth();
            }
        }

        void update_by_name()
        {
            char s;
            float p;
            int n;
            int e;
            cout<<"ENTER THE NEW STATUS OF BOOK\n";
            cin>>s;
            if(s<='z' && s>='a')
                {
                    s-=32;
                }
            cout<<"ENTER THE NEW PRICE OF BOOK\n";
            cin>>p;
            cout<<"ENTER THE NEW NO OF COPIES OF BOOK\n";
            cin>>n;
            cout<<"ENTER THE NEW EDITION OF BOOK\n";
            cin>>e;
            update_book_name(s,p,n,e);
        }

        void update_by_auth()
        {

            char s;
            float p;
            int n;
            int e;
            cout<<"ENTER THE NEW STATUS OF BOOK\n";
            cin>>s;
            if(s<='z' && s>='a')
                {
                    s-=32;
                }

            cout<<"ENTER THE NEW PRICE OF BOOK\n";
            cin>>p;
            cout<<"ENTER THE NEW NO OF COPIES OF BOOK\n";
            cin>>n;
            cout<<"ENTER THE NEW EDITION OF BOOK\n";
            cin>>e;
            update_book_auth(s,p,n,e);
        }

        void update_book_name(char s,float p,int n,int e)
        {
            cout<<"ENTER THE NAME OF BOOK TO BE UPDATED\n\n";
            fflush(stdin);
            getline(cin,bname);
            replace( bname.begin(), bname.end(), ' ', '_');

            for(int i=0;i<bname.length();i++)
            {
                if(bname[i]<='z' && bname[i]>='a')
                {
                    bname[i]-=32;
                }
            }
            node *temp=head;
            while(temp!=NULL)
            {
                if(temp->book_name.compare(bname)==0)
                {
                    temp->status=s;
                    temp->edition=e;
                    temp->no_of_copies=n;
                    temp->price=p;
                    break;
                }
                else
                    {
                        temp=temp->next;
                    }
            }
            if(temp==NULL)
            {
                cout<<"\n BOOK NOT FOUND!! \n";
            }
        }
        void update_book_auth(char s,float p,int n,int e)
        {
            cout<<"ENTER THE AUTHOR OF BOOK TO BE UPDATED\n";
            fflush(stdin);
            getline(cin,auth);
            replace( auth.begin(), auth.end(), ' ', '_');

            for(int i=0;i<auth.length();i++)
            {
                if(auth[i]<='z' && auth[i]>='a')
                {
                    auth[i]-=32;
                }
            }
            node *temp=head;
            while(temp!=NULL)
            {
                if(temp->author==auth)
                {
                    temp->status=s;
                    temp->edition=e;
                    temp->no_of_copies=n;
                    temp->price=p;
                    break;
                }
                else
                    {
                        temp=temp->next;
                    }
            }
            if(temp==NULL)
            {
                cout<<"\n BOOK NOT FOUND!! \n";
            }
        }

        void search_book()
        {
            int ch;
            cout<<"CHOICES ARE:\n\n";
            cout<<"1...DISPLAY BY BOOK NAME\n";
            cout<<"2...DISPLAY BY AUTHOR NAME\n";
            cout<<"\t\tDISPLAY BY BOOK_NAME OR AUTHOR_NAME\n";
            cout<<"ENTER YOUR CHIOCE\n";
            cin>>ch;
            if(ch==1)
            {
                display_by_name();
            }
            else
            {
                display_by_auth();
            }
        }

        void display_by_name()
        {
            cout<<"ENTER THE NAME OF BOOK TO BE UPDATED\n";
            fflush(stdin);
            getline(cin,bname);
            replace( bname.begin(), bname.end(), ' ', '_');

            for(int i=0;i<bname.length();i++)
            {
                if(bname[i]<='z' && bname[i]>='a')
                {
                    bname[i]-=32;
                }
            }
            node *temp=head;
            while(temp!=NULL)
            {
                if(temp->book_name.compare(bname)==0)
                {
                    cout<<"\nBOOK_NAME : "<<temp->book_name<<"\n"<<"AUTHOR_NAME : "<<temp->author<<"\n"<<"PRICE : "<<temp->price<<"\n"<<"STATUS : "<<temp->status<<"\n"<<"NUMBER_OF_COPIES : "<<temp->no_of_copies<<"\n"<<"EDITION : "<<temp->edition<<"\n\n";
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n BOOK NOT FOUND!! \n";
            }
        }

        void display_by_auth()
        {
            cout<<"ENTER THE AUTHOR OF BOOK TO BE DISPLAYED\n";
            fflush(stdin);
            getline(cin,auth);
            replace( auth.begin(), auth.end(), ' ', '_');

            for(int i=0;i<auth.length();i++)
            {
                if(auth[i]<='z' && auth[i]>='a')
                {
                    auth[i]-=32;
                }
            }
            node *temp=head;
            while(temp!=NULL)
            {
                if(temp->author==auth)
                {
                    cout<<"BOOK_NAME : "<<temp->book_name<<"\n"<<"AUTHOR_NAME : "<<temp->author<<"\n"<<"PRICE : "<<temp->price<<"\n"<<"STATUS : "<<temp->status<<"\n"<<"NUMBER_OF_COPIES : "<<temp->no_of_copies<<"\n"<<"EDITION : "<<temp->edition<<"\n\n";
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n BOOK NOT FOUND!! \n";
            }
        }

        void write_book()
        {
            ofstream myfile("book.txt",ios::out | ios::trunc);

            if(myfile.is_open())
            {
                node *temp=head;

                while (temp!=NULL)
                {
                    myfile<<temp->book_name<<" "<<temp->author<<" "<<temp->price<<" "<<temp->no_of_copies<<" "<<temp->status<<" "<<temp->edition<<"\n";
                    temp=temp->next;
                }
                myfile.close();
            }

            else
            {
                cout << "Unable to open file\n";
            }

        }
                                                    //`QUICK SORT IN LL
        node *getTail(node *cur)
        {
            while (cur != NULL && cur->next != NULL)
                cur = cur->next;
            return cur;
        }

        node *partition(node *head1, node *end,node **newHead, node **newEnd)
        {
            node *pivot = end;
            node *prev = NULL, *cur = head1, *tail = pivot;

            while (cur != pivot)
            {
                if (cur->book_name < pivot->book_name)
                {
                    if ((*newHead) == NULL)
                        (*newHead) = cur;

                        prev = cur;
                        cur = cur->next;
                }
                else
                    {
                        if (prev)
                            prev->next = cur->next;

                        node *tmp = cur->next;
                        cur->next = NULL;
                        tail->next = cur;
                        tail = cur;
                        cur = tmp;
                    }
            }

            if ((*newHead) == NULL)
                (*newHead) = pivot;

            (*newEnd) = tail;

        return pivot;
        }

        node *Recur(node *head1, node *end)
        {
            if (!head1 || head1 == end)
                return head1;

            node *newHead = NULL, *newEnd = NULL;
            node *pivot = partition(head1, end, &newHead, &newEnd);

            if (newHead != pivot)
            {
                node *tmp = newHead;

                while (tmp->next != pivot)
                    tmp = tmp->next;
                tmp->next = NULL;

                newHead = Recur(newHead, tmp);
                tmp = getTail(newHead);
                tmp->next =  pivot;
            }

            pivot->next = Recur(pivot->next, newEnd);
            return newHead;
        }

        void Sort_book()
        {
            head = Recur(head, getTail(head));
        }

        ~book()
        {
            cout<<"ALLOCATING MEMORY!!";
            node *p;
            node *n;

            p = head;

            while (p != NULL)
                {
                    n = p->next;
                    delete p;
                    p = n;
                }
        }
};

static int max_no_of_book_issued=7;

int enrol;
string fname;
string lname;
string eid;
int yr_admin;
int no_isued;

class student
{
private:
      struct snode
        {
            int enrolment_no;
            string first_name;
            string last_name;
            string email_id;
            int yr_of_admin;
            int no_of_book_isued;
            snode *next;
        };
        snode *head;
        snode *tail;
public:
    student()
        {
            head=NULL;
            tail=NULL;
        }
        void add_snode()
        {
            snode *temp=new snode;
            temp->enrolment_no=enrol;
            temp->first_name=fname;
            temp->last_name=lname ;
            temp->email_id=eid;
            temp->yr_of_admin=yr_admin;
            temp->no_of_book_isued=no_isued;
            temp->next=NULL;

            if(head==NULL)
            {
                head=temp;
                tail=temp;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }

        }
        void read_student()
        {
            ifstream file("student.txt", ios::in);

            if(file.is_open())
            {
                file>>enrol>>fname>>lname>>eid>>yr_admin>>no_isued;

                while (!file.eof())
                {
                    if(file.good())
                    {
                        add_snode();
                        file>>enrol>>fname>>lname>>eid>>yr_admin>>no_isued;
                    }
                }
                file.close();
            }

            else
            {
                cout << "Unable to open file";
            }
        }

        void add_new_student()
        {
            cout<<"\nENTER THE ENROLMENT NUMBER OF STUDENT : ";
            cin>>enrol;
            cout<<"\nENTER THE FIRST NAME OF STUDENT : ";
            fflush(stdin);
            getline(cin,fname);
            cout<<"\nENTER THE LAST NAME OF STUDENT : ";
            fflush(stdin);
            getline(cin,lname);
            cout<<"\nENTER EMAIL_ID OF STUDENT : ";
            fflush(stdin);
            getline(cin,eid);
            cout<<"\nENTER YEAR OF ADMISSION OF STUDENT : ";
            cin>>yr_admin;
            cout<<"\nENTER NUMBER OF BOOK ISSUED: ";
            cin>>no_isued;

            for(int i=0;i<fname.length();i++)
            {
                if(fname[i]<='z' && fname[i]>='a')
                {
                    fname[i]-=32;
                }
            }

            for(int i=0;i<lname.length();i++)
            {
                if(lname[i]<='z' && lname[i]>='a')
                {
                    lname[i]-=32;
                }
            }

            add_snode();
        }
        int verify()
        {
            cout<<"\nENTER THE ENROLLMENT OF STUDENT :\n";
            cin>>enrol;
            snode *temp=head;
            while(temp!=NULL)
            {
                if(temp->enrolment_no==enrol)
                {
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n STUDENT NOT FOUND!! \n";
                return 0;
            }
            return 1;
        }
        int return_book_status()
        {
            cout<<"\nENTER YOUR DETAILS FIRST...\n";
            p:
            cout<<"\nENTER THE FIRST NAME OF STUDENT :\n";
            fflush(stdin);
            getline(cin,fname);
            cout<<"\nENTER THE LAST NAME OF STUDENT :\n";
            fflush(stdin);
            getline(cin,lname);

            for(int i=0;i<fname.length();i++)
            {
                if(fname[i]<='z' && fname[i]>='a')
                {
                    fname[i]-=32;
                }
            }

            for(int i=0;i<lname.length();i++)
            {
                if(lname[i]<='z' && lname[i]>='a')
                {
                    lname[i]-=32;
                }
            }
            snode *temp=head;
            while(temp!=NULL)
            {
                if((temp->first_name.compare(fname)==0)&&(temp->last_name.compare(lname)==0))
                {
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n STUDENT CREDENTIALS NOT FOUND!! \n";
                cout<<"\nARE YOU REGISTERED?\n";
                char ch;
                cin>>ch;
                if(ch=='y'||ch=='Y')
                {
                    goto p;
                }
                else
                    cout<<"\n FIRST BE IN DATABASE\n";
                return 0;
            }
            else
            {
                book b;
                b.read_book();
                int check=b.book_rstatus();

                if(check==1)
                {
                    cout<<"\nBOOK returned\n";
                    temp->no_of_book_isued-=1;
                    cout<<"\tNO OF BOOKs ISSUED: \t"<<temp->no_of_book_isued;
                    b.write_book();
                    return 1;
                }
                else
                {
                    cout<<"UNABLE TO RETURN BOOK \n";
                    return 0;
                }
            }
        }

        int book_issued_status()
        {
            cout<<"\nENTER YOUR DETAILS FIRST...\n";
            p:
            cout<<"\nENTER THE FIRST NAME OF STUDENT :\n";
            fflush(stdin);
            getline(cin,fname);
            cout<<"\nENTER THE LAST NAME OF STUDENT :\n";
            fflush(stdin);
            getline(cin,lname);

            for(int i=0;i<fname.length();i++)
            {
                if(fname[i]<='z' && fname[i]>='a')
                {
                    fname[i]-=32;
                }
            }

            for(int i=0;i<lname.length();i++)
            {
                if(lname[i]<='z' && lname[i]>='a')
                {
                    lname[i]-=32;
                }
            }
            snode *temp=head;
            while(temp!=NULL)
            {
                if((temp->first_name.compare(fname)==0)&&(temp->last_name.compare(lname)==0))
                {
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n STUDENT CREDENTIALS NOT FOUND!! \n";
                cout<<"\nARE YOU REGISTERED?\n";
                char ch;
                cin>>ch;
                if(ch=='y'||ch=='Y')
                {
                    goto p;
                }
                else
                    cout<<"\nPLEASE FIRST REGISTER TO ISSUE BOOKS OR CHECK YOUR CREDENTIALS\n";
                return 0;
            }
            if(temp->no_of_book_isued<max_no_of_book_issued)
            {
                book b;
                b.read_book();
                int check=b.book_status();

                if(check==1)
                {
                    cout<<"\nBOOK ISSUED\n";
                    temp->no_of_book_isued+=1;
                    cout<<"\tNO OF BOOKs ISSUED: \t"<<temp->no_of_book_isued;

                    return 1;
                }
                else
                {
                    cout<<"BOOK NOT AVAILABLE";
                }
            }
            else
            {
                cout<<"\nMAXIMUM BOOKS ALREADY ISSUED PLEASE RETURN PREVIOUSLY ISSUED BOOKS\n";
                return 0;
            }
        }

        void display_all_students()
        {
            snode *temp=head;
            int i=1;
            while(temp!=NULL)
            {
                cout<<"STUDENT_NO_IN_DATA : "<<i<<"\n";
                cout<<"STUDENT_ENROLMENT_NO : "<<temp->enrolment_no<<"\n";
                cout<<"STUDENT_FIRST_NAME : "<<temp->first_name<<"\n";
                cout<<"STUDENT_LAST_NAME : "<<temp->last_name<<"\n";
                cout<<"EMAIL_ID : "<<temp->email_id<<"\n";
                cout<<"ADDMISSION_YEAR : "<<temp->yr_of_admin<<"\n";
                cout<<"NO_OF_BOOK_ISSUED : "<<temp->no_of_book_isued<<"\n\n";
                temp=temp->next;
                i++;
            }
        }

        void update_student()
        {
            int ch;
            cout<<"UPDATE STUDENT\n\n";
            cout<<"OPTIONS ARE:\n\n";
            cout<<"1...UPDATE BY STUDENT NAME\n";
            cout<<"2...UPDATE BY STUDENT ENROLLMENT NUMBER\n";
            cout<<"\t\tWANT TO UPDATE THE STUDENT BY  NAME OR ENROLLMENT\n";
            cout<<"ENTER YOUR OPTION\n";
            cin>>ch;
            if(ch==1)
            {
                update_by_sname();
            }
            else
            {
                update_by_enrol();
            }
        }

        void update_by_sname()
        {
            int enrl;
            string Eid;
            int yr_adm;
            int isu;
            cout<<"\nENTER THE NEW ENROLMENT NUMBER OF STUDENT : ";
            cin>>enrl;
            cout<<"\nENTER NEW EMAIL_ID OF STUDENT : ";
            fflush(stdin);
            getline(cin,Eid);
            cout<<"\nENTER NEW YEAR OF ADMISSION OF STUDENT : ";
            cin>>yr_adm;
            cout<<"\nENTER NEW NUMBER OF BOOK ISSUED: ";
            cin>>isu;

            update_student_name(enrl,Eid,yr_adm,isu);
        }

        void update_by_enrol()
        {
            string fnam;
            string lnam;
            string Eid;
            int yr_adm;
            int isu;
            cout<<"\nENTER THE NEW FIRST NAME OF STUDENT : ";
            fflush(stdin);
            getline(cin,fnam);
            cout<<"\nENTER THE NEW LAST NAME OF STUDENT : ";
            fflush(stdin);
            getline(cin,lnam);
            cout<<"\nENTER NEW EMAIL_ID OF STUDENT : ";
            fflush(stdin);
            getline(cin,Eid);
            cout<<"\nENTER NEW YEAR OF ADMISSION OF STUDENT : ";
            cin>>yr_adm;
            cout<<"\nENTER NEW NUMBER OF BOOK ISSUED: ";
            cin>>isu;

            for(int i=0;i<fnam.length();i++)
            {
                if(fnam[i]<='z' && fnam[i]>='a')
                {
                    fnam[i]-=32;
                }
            }

            for(int i=0;i<lnam.length();i++)
            {
                if(lnam[i]<='z' && lnam[i]>='a')
                {
                    lnam[i]-=32;
                }
            }
            update_student_enrol(fnam,lnam,Eid,yr_adm,isu);
        }

        void update_student_name(int enrl,string Eid,int yr_adm,int isu)
        {
            cout<<"ENTER THE FIRST NAME OF STUDENT TO BE UPDATED\n\n";
            fflush(stdin);
            getline(cin,fname);
            cout<<"\nENTER THE LAST NAME OF STUDENT TO BE UPDATED:\n\n ";
            fflush(stdin);
            getline(cin,lname);

            for(int i=0;i<fname.length();i++)
            {
                if(fname[i]<='z' && fname[i]>='a')
                {
                    fname[i]-=32;
                }
            }

            for(int i=0;i<lname.length();i++)
            {
                if(lname[i]<='z' && lname[i]>='a')
                {
                    lname[i]-=32;
                }
            }
            snode *temp=head;
            while(temp!=NULL)
            {
                if((temp->first_name.compare(fname)==0)&&(temp->last_name.compare(lname)==0))
                {
                    temp->enrolment_no=enrl;
                    temp->email_id=Eid;
                    temp->yr_of_admin=yr_adm;
                    temp->no_of_book_isued=isu;
            break;
                }
                else
                    {
                        temp=temp->next;
                    }
            }
            if(temp==NULL)
            {
                cout<<"\n STUDENT CREDENTIALS NOT FOUND!! \n";
            }
        }
        void update_student_enrol(string fnam,string lnam,string Eid,int yr_adm,int isu)
        {
            cout<<"ENTER THE ENROLMENT NUMBER OF THE STUDENT TO BE UPDATED\n";
            cin>>enrol;

            snode *temp=head;
            while(temp!=NULL)
            {
                if(temp->enrolment_no==enrol)
                {
                    temp->first_name=fnam;
                    temp->last_name=lnam ;
                    temp->email_id=Eid;
                    temp->yr_of_admin=yr_adm;
                    temp->no_of_book_isued=isu;
                    break;
                }
                else
                    {
                        temp=temp->next;
                    }
            }
            if(temp==NULL)
            {
                cout<<"\n STUDENT NOT FOUND!! \n";
            }
        }

        void display_student()
        {
            int ch;
            cout<<"CHOICES ARE:\n\n";
            cout<<"1...DISPLAY BY STUDENT_NAME\n";
            cout<<"2...DISPLAY BY ENROLMENT_NUMBER\n";
            cout<<"\t\tDISPLAY BY STUDENT_NAME OR ENROLMENT_NUMBER\n";
            cout<<"ENTER YOUR CHIOCE\n";
            cin>>ch;
            if(ch==1)
            {
                display_by_sname();
            }
            else
            {
                display_by_enrol();
            }
        }

        void display_by_sname()
        {
            cout<<"ENTER THE FIRST NAME OF STUDENT TO BE DISPLAYED\n";
            fflush(stdin);
            getline(cin,fname);
            cout<<"ENTER THE LAST NAME OF STUDENT TO BE DISPLAYED\n";
            fflush(stdin);
            getline(cin,lname);

            for(int i=0;i<fname.length();i++)
            {
                if(fname[i]<='z' && fname[i]>='a')
                {
                    fname[i]-=32;
                }
            }
            for(int i=0;i<lname.length();i++)
            {
                if(lname[i]<='z' && lname[i]>='a')
                {
                    lname[i]-=32;
                }
            }

            snode *temp=head;

            while(temp!=NULL)
            {
                if((temp->first_name.compare(fname)==0)&&(temp->first_name.compare(fname)==0))
                {
                    cout<<"STUDENT_ENROLMENT_NO : "<<temp->enrolment_no<<"\n";
                    cout<<"STUDENT_FIRST_NAME : "<<temp->first_name<<"\n";
                    cout<<"STUDENT_LAST_NAME : "<<temp->last_name<<"\n";
                    cout<<"EMAIL_ID : "<<temp->email_id<<"\n";
                    cout<<"ADDMISSION_YEAR : "<<temp->yr_of_admin<<"\n";
                    cout<<"NO_OF_BOOK_ISSUED : "<<temp->no_of_book_isued<<"\n\n";
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n STUDENT  NOT FOUND!! \n";
            }
        }
        void display_by_enrol()
        {
            cout<<"ENTER THE ENROLMENT NUMBER OF THE STUDENT TO BE DISPLAYED\n";
            cin>>enrol;

            snode *temp=head;
            while(temp!=NULL)
            {
                if(temp->enrolment_no==enrol)
                {
                    cout<<"STUDENT_ENROLMENT_NO : "<<temp->enrolment_no<<"\n";
                    cout<<"STUDENT_FIRST_NAME : "<<temp->first_name<<"\n";
                    cout<<"STUDENT_LAST_NAME : "<<temp->last_name<<"\n";
                    cout<<"EMAIL_ID : "<<temp->email_id<<"\n";
                    cout<<"ADDMISSION_YEAR : "<<temp->yr_of_admin<<"\n";
                    cout<<"NO_OF_BOOK_ISSUED : "<<temp->no_of_book_isued<<"\n\n";
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp==NULL)
            {
                cout<<"\n STUDENT NOT FOUND!! \n";
            }
        }

        void write_student()
        {
            ofstream myfile("student.txt",ios::out | ios::trunc);

            if(myfile.is_open())
            {
                snode *temp=head;

                while (temp!=NULL)
                {
                    myfile<<temp->enrolment_no<<" "<<temp->first_name<<" "<<temp->last_name<<" "<<temp->email_id<<" "<<temp->yr_of_admin<<" "<<temp->no_of_book_isued<<"\n";
                    temp=temp->next;
                }
                myfile.close();
            }

            else
            {
                cout << "Unable to open file";
            }

        }

        snode *getTail(snode *cur)
        {
            while (cur != NULL && cur->next != NULL)
                cur = cur->next;
            return cur;
        }

        snode *partition(snode *head1, snode *end,snode **newHead, snode **newEnd)
        {
            snode *pivot = end;
            snode *prev = NULL, *cur = head1, *tail = pivot;

            while (cur != pivot)
            {
                if (cur->enrolment_no < pivot->enrolment_no)
                {
                    if ((*newHead) == NULL)
                        (*newHead) = cur;

                        prev = cur;
                        cur = cur->next;
                }
                else
                    {
                        if (prev)
                            prev->next = cur->next;

                        snode *tmp = cur->next;
                        cur->next = NULL;
                        tail->next = cur;
                        tail = cur;
                        cur = tmp;
                    }
            }

            if ((*newHead) == NULL)
                (*newHead) = pivot;

            (*newEnd) = tail;

        return pivot;
        }

        snode *quickRecur(snode *head1, snode *end)
        {
            if (!head1 || head1 == end)
                return head1;

            snode *newHead = NULL, *newEnd = NULL;
            snode *pivot = partition(head1, end, &newHead, &newEnd);

            if (newHead != pivot)
            {
                snode *tmp = newHead;

                while (tmp->next != pivot)
                    tmp = tmp->next;
                tmp->next = NULL;

                newHead = quickRecur(newHead, tmp);
                tmp = getTail(newHead);
                tmp->next =  pivot;
            }

            pivot->next = quickRecur(pivot->next, newEnd);
            return newHead;
        }

        void sort_student()
        {
            head = quickRecur(head, getTail(head));
        }

        ~student()
        {
            cout<<"ALLOCATING MEMORY!!";
            snode *p;
            snode *n;

            p = head;

            while (p != NULL)
                {
                    n = p->next;
                    delete p;
                    p = n;
                }
        }
};

//ADMIN CLASS
string aname;
int admn_id;

class admin
{
private:
    struct anode
    {
        int admin_id;
        string admin_name;
        anode *next;
    };
    anode *head;
    anode *tail;
    student s;
public:
    admin()
    {
        head=tail=NULL;
    }
    void add_anode()
    {
        anode *temp=new anode;
        temp->admin_name=aname;
        temp->admin_id=admn_id;
        temp->next=NULL;

            if(head==NULL)
            {
                head=temp;
                tail=temp;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }

        }
        void read_admin()
        {
            ifstream myfile("admin.txt", ios::in);

            if(myfile.is_open())
            {
                myfile>>admn_id>>aname;

                while (!myfile.eof())
                {
                    if(myfile.good())
                    {
                        add_anode();
                        myfile>>admn_id>>aname;
                    }
                }
                myfile.close();
            }

            else
            {
                cout << "Unable to open file";
            }
        }

        void enter_new_admin()
        {
            cout<<"\nENTER ADMIN ID : ";
            cin>>admn_id;
            cout<<"\nENTER THE AUTHOR OF BOOK : ";
            fflush(stdin);
            getline(cin,aname);

            replace( aname.begin(), aname.end(), ' ', '_');

            for(int i=0;i<aname.length();i++)
            {
                if(aname[i]<='z' && aname[i]>='a')
                {
                    aname[i]-=32;
                }
            }
            add_anode();
        }

        bool verify_member()
        {
            s.read_student();
            int c;
            c=s.verify();
            if(c==1)
                return true;
            else
                return false;
        }

        void return_book()
        {
            s.read_student();
            cout<<"\nRETURNBOOK\n";
            int status=s.return_book_status();
            if(status ==1)
            {
                cout<<"\nSUCCESFULLY RETURNED\n";
                s.write_student();
            }
            else
            {
                cout<<"\nUNABLE TO RETURN BOOK\n";
            }
        }


        void issue_book()
        {
            s.read_student();
            cout<<"\nISSUE BOOKS\n";
            int status;
            status=s.book_issued_status();
            if(status==1)
            {
                cout<<"\nSUCCESFULLY ISSUED\n";
                s.write_student();
            }
            else
            {
                cout<<"\nUNABLE TO ISSUE BOOK\n";
            }
        }

        void display_all_admin()
        {
            anode *temp=head;
            int i=1;
            while(temp!=NULL)
            {
                cout<<"ADMIN : "<<i<<"\n";
                cout<<"ADMIN_ID : "<<temp->admin_id<<"\n"<<"ADMIN NAME : "<<temp->admin_name<<"\n\n";
                temp=temp->next;
                i++;
            }
        }

        anode *getTail(anode *cur)
        {
            while (cur != NULL && cur->next != NULL)
                cur = cur->next;
            return cur;
        }

        anode *partition(anode *head1, anode *end,anode **newHead, anode **newEnd)
        {
            anode *pivot = end;
            anode *prev = NULL, *cur = head1, *tail = pivot;

            while (cur != pivot)
            {
                if (cur->admin_id < pivot->admin_id)
                {
                    if ((*newHead) == NULL)
                        (*newHead) = cur;

                        prev = cur;
                        cur = cur->next;
                }
                else
                    {
                        if (prev)
                            prev->next = cur->next;

                        anode *tmp = cur->next;
                        cur->next = NULL;
                        tail->next = cur;
                        tail = cur;
                        cur = tmp;
                    }
            }

            if ((*newHead) == NULL)
                (*newHead) = pivot;

            (*newEnd) = tail;

        return pivot;
        }

        anode *quickSortRecur(anode *head1, anode *end)
        {
            if (!head1 || head1 == end)
                return head1;

            anode *newHead = NULL, *newEnd = NULL;
            anode *pivot = partition(head1, end, &newHead, &newEnd);

            if (newHead != pivot)
            {
                anode *tmp = newHead;

                while (tmp->next != pivot)
                    tmp = tmp->next;
                tmp->next = NULL;

                newHead = quickSortRecur(newHead, tmp);
                tmp = getTail(newHead);
                tmp->next =  pivot;
            }

            pivot->next = quickSortRecur(pivot->next, newEnd);
            return newHead;
        }

        void sort_admin()
        {
            head = quickSortRecur(head, getTail(head));
        }

        ~admin()
        {
            cout<<"ALLOCATING MEMORY FREE!!";
            anode *p;
            anode *n;

            p = head;

            while (p != NULL)
                {
                    n = p->next;
                    delete p;
                    p = n;
                }
        }

        void write_admin()
        {
            ofstream myfile("admin.txt",ios::out | ios::trunc);

            if(myfile.is_open())
            {
                anode *temp=head;

                while (temp!=NULL)
                {
                    myfile<<temp->admin_id<<" "<<temp->admin_name<<"\n";
                    temp=temp->next;
                }
                myfile.close();
            }

            else
            {
                cout << "Unable to open file";
            }

        }

};

class main_menu
{
private:
    book bobj;
    student sobj;
    admin aobj;

public:
    main_menu()
    {
        bobj.read_book();
        sobj.read_student();
        aobj.read_admin();
    }

    void showtime()
    {
        while(1)
        {
            cout<<"\n\t\t\t\t\t DATA STRUCTURES MINI PROJECT\n\n";
    	cout<<"**********************************************************************************************************************\n";
    	cout<<"***********************************************************************************************************************\n";
    	cout<<"***********************************************************************************************************************\n";
    	cout<<"***********************************************************************************************************************\n";

    	cout<<"\n\n";

    	come_again:


    	    cout<<"0...EXIT\n";
    	    cout<<"1...DISPLAY ALL BOOKS\n";
    	    cout<<"2...ADD NEW BOOKS\n";
    	    cout<<"3...SEARCH BOOKS\n";
    	    cout<<"4...SORT BOOKS \n";
    	    cout<<"5...DISPLAY ALL STUDENTS\n";
    	    cout<<"6...UPDATE BOOK DETAILS \n";
    	    cout<<"7...UPDATE NEW STUDENT\n";
    	    cout<<"8...ADD NEW STUDENT\n";
    	    cout<<"9...SORT STUDENT\n";
    	    cout<<"10..SEARCH STUDENT \n";
    	    cout<<"11..SORT ADMIN \n";
    	    cout<<"12..ADD NEW ADMIN \n";
    	    cout<<"13..DISPLAY ALL ADMINS \n";
    	    cout<<"14..ISSUE BOOKS \n";
    	    cout<<"15..VERIFY STUDENT\n";
    	    cout<<"16..RETURN BOOKS\n";
    	    cout<<"17.. \n";
    	    cout<<"18.. \n";

    	    cout<<"\tENTER YOUR CHIOCE\n";
    	    int ch;
    	    cin>>ch;
    	    system("cls");

    	    switch(ch)
    	    {
            case 0:
                //EXIT
		    	printf("PROGRAM TERMINATED SUCCESSFULLY !!!\n");
		    	printf("\nPRESS ANY KEY TO CONTINUE...\n");
		    	exit(1);
		    	break;

	    	case 1:
	    	    //DISPLAY ALL BOOKS
	    	    bobj.display_all_book();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
                getch();
                system("cls");
		    	goto come_again;
		    	break;

	    	case 2:
	    	    //ADD NEW BOOKS
	    	    bobj.add_new_book();
                bobj.write_book();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
                getch();
		    	system("cls");
		    	goto come_again;
		    	break;

	    	case 3:
	    	    //SEARCH BOOKS
	    	    bobj.search_book();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
	    	    goto come_again;
		    	break;

		    case 4:
		        //SORT BOOKS
		        bobj.Sort_book();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
                getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 5:
		        //DISPLAY ALL STUDENTS
		        sobj.display_all_students();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
                goto come_again;
		    	break;

		    case 6:
		        //UPDATE BOOK DETAILS
		        bobj.update_book_details();
                bobj.write_book();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 7:
		        //UPDATE NEW STUDENT
		        sobj.update_student();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 8:
		        //ADD NEW STUDENT
		        sobj.add_new_student();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 9:
		        //SORT STUDENT
		        sobj.sort_student();
		        sobj.write_student();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 10:
		        //SEARCH STUDENT
		        sobj.display_student();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 11:
		        //SORT ADMIN
		        aobj.sort_admin();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 12:
		        //ADD NEW ADMIN
		        aobj.enter_new_admin();
		        aobj.write_admin();
                printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		        goto come_again;
		    	break;

		    case 13:
		        //DISPLAY ALL ADMINS
		        aobj.display_all_admin();
		        printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		    	goto come_again;
		    	break;

		    case 14:
		        //ISSUE BOOKS
		        aobj.issue_book();
		        bobj.write_book();
		        sobj.write_student();
		    	printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		    	goto come_again;
		    	break;

		    case 15:
		        //VERIFY STUDENT
		        cout<<"VERIFY STUDENT: "<<aobj.verify_member()<<"\n";
		    	printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		    	goto come_again;
		    	break;

            case 16:
		        //RETURN BOOKS
		        aobj.return_book();
		        bobj.write_book();
		        sobj.write_student();
		    	printf("\n\nPRESS ANY KEY TO CONTINUE !!!\n");
		    	getch();
		    	system("cls");
		    	goto come_again;
		    	break;
		    default:
			    break;
            }
	    }
    }

    ~main_menu()
    {
        bobj.write_book();
        sobj.write_student();
        aobj.write_admin();
    }
};

int main()
{
    system("cls");
    system("color E3");
    main_menu m;
    m.showtime();

    return 0;
}




















