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
    
}