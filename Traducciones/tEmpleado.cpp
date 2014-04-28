//
//  tEmpleado.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#include "tEmpleado.h"

tEmpleado::tEmpleado(){
    nombre = "";
    apellido = "";
    idiomas[0] = new tIdioma();
}

void tEmpleado::aniadeEmpleado(){
    //num no puede ser mayor que 5
    int num;
    
    
    cout << "Introduce el nombre y primer apellido: ";
    cin >> nombre;
    cin >> apellido;
    cout << endl;
    
    cout << "Introduce numero de idiomas que domina: ";
    cin >> num;
    cout << endl;
    
    cout << "Introduce los idiomas" << endl;
    
    for (int i = 0; i<num; i++) {
        string lengua;
        cin >> lengua;
        if (idiomas[i]==NULL) {
            idiomas[i] = new tIdioma();
        }
        idiomas[i]->ponLengua(lengua);
    }

}