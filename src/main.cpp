#include <Library.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

    Library lib("Minha lib", "Teste");
    Book *book = new Book("Teste","Luis", 2000, 100);

    lib.AddNewBook(*book);
    
    string s = lib.ListAllBooks();
    cout << s << endl;

    return 0;
}