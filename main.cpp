#include "GUIFactory.h"         //Se incluye codigo del archivo especificado.

void Aplication(const GUIFactory& f, int opc)       //Funcion Application.
{
    if (opc == 1)           //Opcion para Windows
    {
        const WinFactory* producto = f.CrearControlW();
        std::cout <<"\n"<< producto->Draw() << "\n";
        delete producto;
    }else if(opc == 2)          //Opcion para Mac
    {
        const MacFactory* producto = f.CrearControlM();
        std::cout <<"\n"<< producto->Draw() << "\n";
        delete producto;
    }else if(opc == 3)          //Opcion para Linux
    {
        const LinuxFactory* producto = f.CrearControlL();
        std::cout <<"\n"<< producto->Draw() << "\n";
        delete producto;
    }
}

int main()      //Funcion Principal.
{
    std::cout << "Cliente: Windows ";
    Button* f1 = new Button();
    Aplication(*f1, 1); // 1 - Windows
    delete f1;
    std::cout << std::endl;
    std::cout << "Cliente: Mac ";
    Button* f2 = new Button();
    Aplication(*f2, 2); // 2 - Mac
    delete f2;

    //////Para Linux///////
    std::cout << std::endl;
    std::cout << "Cliente: Linux ";
    Button* f3 = new Button();
    Aplication(*f3, 3); // 3 - Linux
    delete f3;
    return 0;
}
