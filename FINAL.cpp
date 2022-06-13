#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

void board (char [3][3],char [11],char [11]);
void menu  (char [3][3],char&,char [11],char [11]);
void Input (char [3][3],char&);
void TogglePlayer(char&);
char Checkmate   (char [3][3]);
void game (char [3][3],char&,char [11],char [11]);
void resetboard(char [3][3]);
void AI (char[3][3],char&,char[11],char[11]);
void PCInput (char[3][3],char&);

int main()
{

    char Jugador = 'X' ;
    char Nombre   [11];
    char Nombre_2 [11];
    char numeros [3][3]={{'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'}};


    menu (numeros,Jugador,Nombre,Nombre_2);                                          
    return 0;
}


void board (char numeros[3][3],char Nombre [11],char Nombre_2 [11])
{
    int i,j;
    int filas=3,columnas=3;

    system("cls");

    cout << "\t\t\t\tTic Tac Toe\n\n\n";
    cout << "\t      JUGADOR 1: " << Nombre <<" (X)  -  JUAGDOR 2: "<< Nombre_2 <<" (O)" << endl << endl << endl << endl;

    for(i=0;i<columnas;i++)               
    {
        cout<<"\t\t\t       ";cout<<"  "; 
        for(j=0;j<filas;j++) 
        {   
            cout<<numeros[i][j]; 
            if(j<filas-1)        
            {
                cout<<" | ";     
            }
        }
        cout<<endl;                                                                    

    if(i<filas-1)
        {
            for (int lines=0;lines<1;lines++ )                                         
            {
                cout<<"\t\t\t\t--- --- ---";                                          
            }
            cout<<endl;
        }

    }
    return;
}

//Menu
void menu (char numeros[3][3],char& Jugador,char Nombre [11],char Nombre_2 [11])
{
    int opcion,Opcion2;
    char continuar = 'Y';

    resetboard(numeros);                                                               

    cout << "\t\t\t\tTic Tac Toe\n\n\n";
    cout << "\t\t       Jugador 1 (X)  -  Jugador 2 (O)" << endl << endl;
    cout << "\n\n\n1)Empezar juego nuevo\n2)Ayuda\n3)Salir";
    cout << "\n\n\nOpcion: ";cin>>opcion;

    if (opcion==1)                                                                      
    {   
        system("cls");  
        cout << "Elija el numero para iniciar\n\n";
        cout << "1. JUGADOR vs JUGADOR\n2. JUGADOR vs IA\n\nOpCion: ";cin>>Opcion2;
        if(Opcion2==1)
        {
            game (numeros,Jugador,Nombre,Nombre_2);
        }
        else if (Opcion2==2)
        {
            AI (numeros,Jugador,Nombre,Nombre_2);
        }
    }
    else if (opcion==2)                                                                 
    {
        system("cls");  
        cout<<"\n\nINSTRUCCIONES:\n\n"
            <<"\tEste juego es para dos jugadores, X y O, que se turnan para marcar los\nespacios en una cuadrícula de 3x3."
            <<"El jugador que logre colocar tres de sus marcas \nen una fila horizontal, vertical o diagonal gana el juego."
            <<"\n\nEn este juego, la primera persona en jugar es X y la segunda es O.\n\nEspero que las instrucciones hayan sido útiles, ¡diviértete! \2";
        system("Pause>Null");
        system("cls");
        menu (numeros,Jugador,Nombre,Nombre_2);
    }
    else if (opcion==3)                                                                
    {
        cout<<"\n\nGracias por su tiempo, hasta la próxima!\n\n";
        system("Pause>Null");
    }                                                                               
else if ((opcion!=1)||(opcion!=2)||(opcion!=3))                                        
    {
        cout<<"\n\nEl número ingresado es incorrecto, intente nuevamente";
        system("Pause>Null");
        system("cls");
        menu (numeros,Jugador,Nombre,Nombre_2);
    }
    return;
}

//Entrada de Datos por Parte de los Usuarios
void Input(char numeros[3][3], char& Player)
{
    int NumField;

    cout << "\n\nIt's " << Player << " Turn. " <<"Presione el Número del Campo: ";cin >> NumField; 
    //Campo de Tiro
    if (NumField == 1)
    {
        if (numeros[0][0] == '1')
            numeros[0][0] = Player;
        else
        {
            cout << "\nEl campo ya está en uso ¡Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 2)
    {
        if (numeros[0][1] == '2')
            numeros[0][1] = Player;
        else
        {
            cout << "\nEl campo ya está en uso ¡Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 3)
    {
        if (numeros[0][2] == '3')
            numeros[0][2] = Player;
        else
        {
            cout << "\nEl campo ya está en uso Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 4)
    {
        if (numeros[1][0] == '4')
            numeros[1][0] = Player;
        else
        {
            cout << "\nEl campo ya está en uso Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 5)
    {
        if (numeros[1][1] == '5')
            numeros[1][1] = Player;
        else
        {
            cout << "\nEl campo ya está en uso Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 6)
    {
        if (numeros[1][2] == '6')
            numeros[1][2] = Player;
        else
        {
            cout << "\nEl campo ya está en uso Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 7)
    {
        if (numeros[2][0] == '7')
            numeros[2][0] = Player;
        else
        {
            cout << "\nEl campo ya está en uso Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 8)
    {
        if (numeros[2][1] == '8')
            numeros[2][1] = Player;
        else
        {
            cout << "\nEl campo ya está en uso Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else if (NumField == 9)
    {
        if (numeros[2][2] == '9')
            numeros[2][2] = Player;
        else
        {
            cout << "\nEl campo ya está en uso Inténtalo de nuevo!" << endl;
            Input(numeros,Player);
        }
    }
    else 
    {
        cout << "\nEl número ingresado está fuera de rango" << endl;
        Input(numeros,Player);
    }
    return;
}

//Cambio de Turno
void TogglePlayer(char& Player)
{
    if (Player == 'X')                                                                          
        {
            Player = 'O';
        }
    else                                                                                        
        {
            Player = 'X';
        }
    return;
}

//Funcion que Dicta al GANADOR
char Checkmate(char numeros[3][3])
{
    //Player 1
     if (numeros[0][0] == 'X' && numeros[0][1] == 'X' && numeros[0][2] == 'X')
        return 'X';
     if (numeros[1][0] == 'X' && numeros[1][1] == 'X' && numeros[1][2] == 'X')
        return 'X';
     if (numeros[2][0] == 'X' && numeros[2][1] == 'X' && numeros[2][2] == 'X')
        return 'X';

     if (numeros[0][0] == 'X' && numeros[1][0] == 'X' && numeros[2][0] == 'X')
        return 'X';
     if (numeros[0][1] == 'X' && numeros[1][1] == 'X' && numeros[2][1] == 'X')
        return 'X';
     if (numeros[0][2] == 'X' && numeros[1][2] == 'X' && numeros[2][2] == 'X')
        return 'X';

     if (numeros[0][0] == 'X' && numeros[1][1] == 'X' && numeros[2][2] == 'X')
        return 'X';
     if (numeros[2][0] == 'X' && numeros[1][1] == 'X' && numeros[0][2] == 'X')
        return 'X';

    //Player 2
     if (numeros[0][0] == 'O' && numeros[0][1] == 'O' && numeros[0][2] == 'O')
        return 'O';
     if (numeros[1][0] == 'O' && numeros[1][1] == 'O' && numeros[1][2] == 'O')
        return 'O';
     if (numeros[2][0] == 'O' && numeros[2][1] == 'O' && numeros[2][2] == 'O')
        return 'O';

     if (numeros[0][0] == 'O' && numeros[1][0] == 'O' && numeros[2][0] == 'O')
        return 'O';
     if (numeros[0][1] == 'O' && numeros[1][1] == 'O' && numeros[2][1] == 'O')
        return 'O';
     if (numeros[0][2] == 'O' && numeros[1][2] == 'O' && numeros[2][2] == 'O')
        return 'O';

     if (numeros[0][0] == 'O' && numeros[1][1] == 'O' && numeros[2][2] == 'O')
        return 'O';
     if (numeros[2][0] == 'O' && numeros[1][1] == 'O' && numeros[0][2] == 'O')
        return 'O';


else if (numeros[0][0] != '1' && numeros[0][1] != '2' && numeros[0][2] != '3' && numeros[1][0] != '4' &&
         numeros[1][1] != '5' && numeros[1][2] != '6' && numeros[2][0] != '7' && numeros[2][1] != '8' && numeros[2][2] != '9')
        return 'D';
}

 
void game (char numeros[3][3],char& Player,char Nombre [11],char Nombre_2 [11])
{
    char continuar = 'Y';

    system("cls");
    cout << "Por favor ingrese identificadores:\n"
         << "Sugerencia: solo se permite un máximo de 10 caracteres\n";
    cout << "\nJugador 1 (Nombre / Inicial): ";cin>>Nombre;                                          
    cout << "\nJugador 2 (Nombre / Inicial): ";cin>>Nombre_2;                                        
    board (numeros,Nombre,Nombre_2);

    while(true)                                                                                 
        {
            Input(numeros,Player);
            board (numeros,Nombre,Nombre_2);

        if (Checkmate(numeros) =='X')
            {
                cout << "\nX gana!" << endl;break;
            }
        else if (Checkmate(numeros) =='O')
            {
                cout << "\nO gana!" << endl;break;
            }
        else if (Checkmate(numeros) == 'D')
            {
                cout << "\nEs un empate!" << endl;break;
            }   
                TogglePlayer(Player);       
        }
    cout<<"\n\n\nDo You Want to Return to the Start Menu?: ";cin>>continuar;                    

    if((continuar=='y')||(continuar=='Y'))
            {
                system("cls");
                menu (numeros,Player,Nombre,Nombre_2);
            }
    return;
}


void resetboard(char numeros[3][3])
{   
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            numeros[0][0]='1';
            numeros[0][1]='2';
            numeros[0][2]='3';
            numeros[1][0]='4';
            numeros[1][1]='5';
            numeros[1][2]='6';
            numeros[2][0]='7';
            numeros[2][1]='8';
            numeros[2][2]='9';
        }   
    }
    return;     
}


void AI (char numeros[3][3],char& Player,char Nombre[11],char Nombre_2[11])
{
    char continuar = 'Y';
    Nombre_2 = "Computer(AI)";
    system("cls");
    cout << "Por favor ingrese identificadores:\n"
         << "Sugerencia: solo se permite un máximo de 10 caracteres\n";
    cout << "\nJugador 1 (Nombre / Inicial): ";cin>>Nombre;                                          
    cout << "\nJugador 2 (Nombre / Inicial): " << Nombre_2;                                          
    board (numeros,Nombre,Nombre_2);

    while(true)                                                                                 
        {
            Input(numeros,Player);
            board (numeros,Nombre,Nombre_2);
            TogglePlayer(Player); 

        if (Checkmate(numeros) =='X')
            {
                cout << "\nX victorias!" << endl;break;
            }
        else if (Checkmate(numeros) =='O')
            {
                cout << "\nO victorias!" << endl;break;
            }
        else if (Checkmate(numeros) == 'D')
            {
                cout << "\nEs un empate!" << endl;break;
            }   

            PCInput (numeros,Player);
            board (numeros,Nombre,Nombre_2);
            TogglePlayer(Player);

        if (Checkmate(numeros) =='X')
            {
                cout << "\nX victorias!" << endl;break;
            }
        else if (Checkmate(numeros) =='O')
            {
                cout << "\nO victorias!" << endl;break;
            }
        else if (Checkmate(numeros) == 'D')
            {
                cout << "\nEs un empate!" << endl;break;
            }  

        }
    cout<<"\n\n\n¿Quiere volver al menú de inicio?: ";cin>>continuar;                    

    if((continuar=='y')||(continuar=='Y'))
            {
                TogglePlayer(Player);
                system("cls");
                menu (numeros,Player,Nombre,Nombre_2);
            }
    return;
}


void PCInput (char numeros[3][3],char& Player)
{
    srand(time(0));
    int NumField = rand()%9+1;

    cout << "\n\nIt's " << Player << " Turn. "; 
    Sleep(2500);

    if (NumField == 1)
    {
        if (numeros[0][0] == '1')
            numeros[0][0] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 2)
    {
        if (numeros[0][1] == '2')
            numeros[0][1] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 3)
    {
        if (numeros[0][2] == '3')
            numeros[0][2] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 4)
    {
        if (numeros[1][0] == '4')
            numeros[1][0] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 5)
    {
        if (numeros[1][1] == '5')
            numeros[1][1] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 6)
    {
        if (numeros[1][2] == '6')
            numeros[1][2] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 7)
    {
        if (numeros[2][0] == '7')
            numeros[2][0] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 8)
    {
        if (numeros[2][1] == '8')
            numeros[2][1] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else if (NumField == 9)
    {
        if (numeros[2][2] == '9')
            numeros[2][2] = Player;
        else
        {
            PCInput(numeros,Player);
        }
    }
    else 
    {
        cout << "\nEl número ingresado está fuera de rango" << endl;
        PCInput(numeros,Player);
    }
    return;
}

