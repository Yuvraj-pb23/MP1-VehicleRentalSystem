#include"Application.h"
#include"Database_Templates.cpp"
#include<iostream>
#include<cstdio>
#include<cstdlib>

Application :: Application()
{
    try{
        this->db = new Database();

    }catch (Error e){
        cout<<e.getMessage();
        exit(EXIT_FAILURE);
    };
}
void Application :: gotoXY(int x,int y) const
{
    printf("%c[%d;%df",0x1B,y,x);
}

void Application::renderMenu()
{
    unsigned char choice = 1;
    while(true)
    {
        system("clear");
        gotoXY(25, 4);
        cout << "Select Any option from below";
        gotoXY(25, 5);
        cout << "!.Add new vehicle";
        gotoXY(25, 6);
        cout << "2. View vehicle details";
        gotoXY(25, 7);
        cout << "3. Edit vehicle details";
        gotoXY(25, 8);
        cout << "4. Add new user";
        gotoXY(25, 9);
        cout << "5. Add new trip";
        gotoXY(25, 10);
        cout << "6. View trip";
        gotoXY(25, 11);
        cout << "7. Start trip";
        gotoXY(25, 12);
        cout << "8. Complete trip";
        gotoXY(25, 13);
        cout << "9. Exit";

        gotoXY(30, 15);
        cout << "Enter your choice : ";

        gotoXY(50, 15);
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
       
        switch(choice)
        {
           case '1':
           this->renderAddNewVehicleMenu();
           break;
           case '2':
           this->renderViewVehicleMenu();
           break;
           case '3':
           this->renderEditVehicleMenu();
           break;
           case '4':
           this->renderAddNewUserMenu();
           break;
           case '5':
           this->renderAddNewTripMenu();
           break;
           case '6':
           this->renderViewTripMenu();
           break;
           case '7':
           this->renderStartTripMenu();
           break;
           case '8':
           this->renderCompleteTripMenu();
           break;
           case '9':
           this->clearMemory();
           system("clear");
           exit(EXIT_SUCCESS);
           break;
           default:
           this->clearMemory();
           system("clear");
           exit(EXIT_SUCCESS);
           break;
           
        }
        
    }
}

void Application :: renderAddNewVehicleMenu( ) const
{
  
}