/*
Asignacion 6: Figuras en 3d
Juan F. Torré García
801-24-9424
CCOM3033-002
Profa.Lillian Gonzalez
30 de marzo del 2025
*/
#include <iostream>
#include <iomanip> 
using namespace std;

//Prototipos de funciones "overload" para calcular volumen 

double volumen(double radio);                                // Esfera
double volumen(double radio, double altura);                 // Cilindro
double volumen(double largo, double ancho, double alto);     // Prisma rectangular


//Prototipos de funciones "overload" para calcular el area de la superficie 

double areaSuperficie(double radio);                                // Esfera
double areaSuperficie(double radio, double altura);                 // Cilindro
double areaSuperficie(double largo, double ancho, double alto);     // Prisma rectangular


int main() 
{
    cout << "Este programa calcula el volumen y el area de la superficie de tres figuras.\n\n";

    //Menu para seleccionar figura
    cout << "Escoja una figura:\n"
         << "  a. Cilindro\n"
         << "  b. Esfera\n"
         << "  c. Prisma rectangular\n"
         << "Seleccion: ";

    char figura; //Declarar variable para almacenar la opcion escogida
    cin >> figura;

   
    //Validacion de input para la seleccion de la figura
    //Mientras input entrado por el usuario no sea 'a', 'b' o 'c' se seguira pidiendo el input
    while (figura != 'a' && figura != 'A' && figura != 'b' && figura != 'B' && figura != 'c' && figura != 'C') 
    {
        cout << "*OPCION INVALIDA* Por favor escoja entre 'a', 'b' o 'c': ";
        cin >> figura;
    }

    //Menu para escoger  entre calcular volumen o area de superficie
    cout << "\nEscoja que quiere calcular:\n"
         << "  a. Volumen\n"
         << "  b. Area de la superficie\n"
         << "Seleccion: ";
    
    char opcion; //Declarar variable para almacenar la opcion escogida
    cin >> opcion;

    //Validacion para la seleccion entre volumen o area de la superficie 
    while (opcion != 'a' && opcion != 'b') 
    {
        cout << "Opcion invalida. Por favor escoja entre 'a' o 'b': ";
        cin >> opcion;
    }

    //Inicializar variable para almacenar el resultado
    double resultado = 0.0;

    //Dependiendo de la figura que el usuario escoja, se piden los inputs y se valida que estos que no sean negativos
    //Luego se llama la funcion correspondiente de volumen o area de la superficie
    switch (figura) 
    {
    
    //Caso A: Cilindro

        case 'a': 
        case 'A':
        {
            cout << "\nCILINDRO \n";
            
            //Declarar las variables para radio y altura
            double r, h;

            //Ciclo do-while para validar que el radio no sea un valor negativo 
            //Siempre que el radio sea un número negativo, se desplegara un mensaje de error y se volvera a pedir el valor hasta que sea válido
            do 
            {
                cout << "Entre el radio (no puede ser negativo): ";
                cin >> r;

                //Se despliega el mensaje de error si el radio es negativo 
                if (r < 0) 
                {
                    cout << "El valor no puede ser negativo. Intente de nuevo.\n";
                }
                
            }   
            while (r < 0);

            //Siempre que la altura sea un numero negativo, se desplegara un mensaje de error y se volvera a pedir el valor hasta que sea valido 
            do 
            {
                cout << "Entre la altura (no puede ser negativa): ";
                cin >> h;

                //Se despliega mesnsaje de error si la altura es negativa
                if (h < 0) 
                {
                    cout << "El valor no puede ser negativo. Intente de nuevo.\n";
                }
                
            }

            while (h < 0);
            
        
            //Llamar la funcion correspondiente segun la opcion que halla escogido el usuario
            //Si la opcion es 'a', se calcula el volumen; Si no, se calcula el área de la superficie 
            if (opcion == 'a'|| opcion == 'A') 
            {
                //Llamar la funcion para calcular volumen
                resultado = volumen(r, h); 

                //Desplegar resultado redondeado a 2 lugares decimales
                cout << "\nEl volumen del cilindro es: "
                    << fixed << setprecision(2)  << resultado << endl;//set precision y fixed para poder redondear a 2 lugares decimales
            }
            
            else 
            {
                //LLamar la funcion para  calcular el area de la superficie
                resultado = areaSuperficie(r, h);
                
                //Desplegar resultado redondeado a 2 lugares decimales
                cout << "\nEl area de la superficie del cilindro es: "
                    << fixed << setprecision(2) << resultado << endl;//set precision y fixed para poder redondear a 2 lugares decimales
            }
            break;
        }

        //Caso B: Esfera

        
        case 'b': 
        case 'B':
        {
        
            cout << "\nESFERA \n";
            
            //Declarar la variable para almacenar el radio 
            double r;

            //Ciclo do-while para validar que el radio no sea un valor negativo
            //Mientras el radio sea negativo se pedira el input de nuevo 
            do 
            {
                cout << "Entre el radio (no puede ser negativo): ";
                cin >> r;

                //Se desplegara un mensaje de error mientras el radio sea negativo 
                if (r < 0) 
                {
                    cout << "El valor no puede ser negativo. Intente de nuevo.\n";
                }
            }

            while (r < 0);

            //Llamar la funcion correspondiente segun la opcion que halla escogido el usuario
            //Si la opcion es 'a', se calcula el volumen; Si no, se calcula el área de la superficie
            if (opcion == 'a' || opcion == 'A') 
            {
                //Llamar la funcion para calcualar volumen 
                resultado = volumen(r); 


                cout << "\nEl volumen de la esfera es: "
                    << fixed << setprecision(2) << resultado << endl;
            } 
            
            else 
            {
                //Llamar la funcion para calcular el area de la superficie 
                resultado = areaSuperficie(r);

                //Desplegar resultado redondeado a 2 lugares decimales 
                cout << "\nEl area de la superficie de la esfera es: "
                    << fixed << setprecision(2) << resultado << endl; //set precision y fixed para poder redondear a 2 lugares decimales
            }
            break;
        }

        //Caso C: Prisma rectangular
        
        case 'c': 
        case 'C':
        {
            
            cout << "\nPRISMA RECTANGULAR \n";

            //Declarar las varibales para alamcenar el largo, ancho y alto
            double largo, ancho, alto;

            //Ciclo do-while para validar que el input no sea un valor negativo
            //Mientras el input sea un valor negativo se volvera a pedir al ususario
            do 
            {
                cout << "Entre el largo (no puede ser negativo): ";
                cin >> largo;
                
                //Desplegar mensaje de error si el valor es negativo 
                if (largo < 0) 
                {
                    cout << "El valor no puede ser negativo. Intente de nuevo.\n";
                }
            }

            while (largo < 0);

            //Lo mismo pero para el input del ancho
            do 
            {
                cout << "Entre el ancho (no negativo): ";
                cin >> ancho;

                //Desplegar mensaje de error si el valor es negativo 
                if (ancho < 0) 
                {
                    cout << "El valor no puede ser negativo. Intente de nuevo.\n";
                }

            } 

            while (ancho < 0);

            //Lo mismo pero para el input de la altura
            do 
            {
                cout << "Entre la altura (no negativa): ";
                cin >> alto;

                //Desplegar mensaje de error si el valor es negativo 
                if (alto < 0) {
                    cout << "El valor no puede ser negativo. Intente de nuevo.\n";
                }
            } 
            
            while (alto < 0);

        
            //Llamar la funcion correspondiente segun la opcion que halla escogido el usuario
            //Si la opcion es 'a', se calcula el volumen; Si no, se calcula el área de la superficie
            if (opcion == 'a' || opcion == 'A') 
            {
                //Llamar la funcion para calcular el volumen 
                resultado = volumen(largo, ancho, alto);

                //Desplegar el resultado redondeado a 2 lugares decimales
                cout << "\nEl volumen del prisma rectangular es: "
                    << fixed << setprecision(2) << resultado << endl; //set precision y fixed para poder redondear a 2 lugares decimales
            }
            
            else 
            {
                //Llamar la funcion para calcular el area de la superficie
                resultado = areaSuperficie(largo, ancho, alto);

                //Desplegar resultado redondeado a 2 lugares decimales 
                cout << "\nEl area de la superficie del prisma rectangular es: "
                    << fixed << setprecision(2) << resultado << endl; //set precision y fixed para poder redondear a 2 lugares decimales
            }
            cout << endl;
            break;
        }
    
      
    }

    return 0;
}


// Definicion de las funciones "overload" para volumen


//Volumen de un CILINDRO = pi * (radio^2) * altura
double volumen(double radio, double altura) 
{
    
    //Inicializar una variable constante para PI
    const double PI = 3.14159;

    return PI * radio * radio * altura;
}

//Volumen de una ESFERA = (4/3) * PI * (radio^3)
double volumen(double radio) 
{
    //Inicializar una variable constante para PI
    const double PI = 3.14159;

    return (4.0 / 3.0) * PI * (radio * radio * radio);
}

//Volumen de un PRISMA RECTANGULAR = largo * ancho * alto
double volumen(double largo, double ancho, double alto) 
{
    return largo * ancho * alto;
}


//Definicion de las funciones "overload" para la area de la superficie


//Area de superficie de una ESFERA = 4 * pi * (radio^2)
double areaSuperficie(double radio) {

    //Inicializar una variable constante para PI
    const double PI = 3.14159;

    return 4.0 * PI * (radio * radio);
}


//Area de superficie de un CILINDRO = area lateral + area de las dos bases
//    area lateral = 2 * pi * radio * altura
//    area bases = 2 * (pi * radio^2)
//    total = 2 * pi * radio * altura + 2 * pi * radio^2
double areaSuperficie(double radio, double altura) 
{
   
    //Inicializar una variable constante para PI
    const double PI = 3.14159;

    //Iniciaizar variables para calcular y almacenar  el area lateral y la area de las bases
    double areaLateral = 2.0 * PI * radio * altura;
    double areaBases   = 2.0 * PI * (radio * radio);
    
    //total
    return areaLateral + areaBases;
}


//Area de superficie de un PRISMA RECTANGULAR = 2 * ( (largo * ancho) + (largo * alto) + (ancho * alto) )
double areaSuperficie(double largo, double ancho, double alto) 
{
    
    //Inicializar variable para calcular y almacenar largo * ancho 
    double l_w = largo * ancho;

    //Inicializar variable para calcular y almacenar largo * alto 
    double l_h = largo * alto;

    //Incializar variable para calcular y alamcenar ancho * alto
    double w_h = ancho * alto;

    //Calcular el area de la supeficie
    return 2.0 * (l_w + l_h + w_h);
}


