#include <iostream>

using namespace std;

struct lista_element
{
    int nr;
    struct lista_element* next;
};
class lista
{
    struct lista_element *l;
    public:
        //konstruktor pusta lista
        lista()
        {
            l=NULL;
        }
        //dodawanie do listy
        void dodawanieDoListy(int numer)
        {
            lista_element* p=new lista_element;
            p->nr=numer;
            p->next=NULL;
            if(l==NULL)
            {
                l=p;
            }
            else
            {
                lista_element* q=l;
                while(q->next!=NULL)
                {
                    q=q->next;
                }
                q->next=p;

            }
        }
        //usuwanie z listy
        int usunOstatniego()
        {
            if(l==NULL)
            {
                return -1;
            }
            if(l->next==NULL)
            {
                int numer=l->nr;
                delete l;
                l=NULL;
                return numer;
            }
            lista_element* q=l;
            while(q->next->next!=NULL)
            {
                q=q->next;
            }
            int numer=q->next->nr;
            delete q->next;
            q->next=NULL;
            return numer;
        }
        //wypisywanie listy
        void wypisz()
        {
            lista_element* q=l;
            while(q!=NULL)
            {
                cout<<q->nr<<" ";
            q=q->next;
            }
            cout<<endl;
        }
};
int main()
{
    lista l;
    l.dodawanieDoListy(6);
    l.dodawanieDoListy(7);
    l.dodawanieDoListy(12);
    l.dodawanieDoListy(34);
    l.wypisz();
    cout<<"Usunieta liczba z listy: "<<l.usunOstatniego()<<endl;
    l.wypisz();
    return 0;
}

//dodawanie do listy
//konstruktor pusta lista NULL
//usun_ostatniego z list
//-zwraca usuwana liczbe
//-usuwanie
//wypisz
//-przeglad i wypisuje
//l=new lista_element
//l=7
//l.nr=7;
//l.next=NULL
