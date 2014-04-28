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
    idiomas[0] = new tIdioma();
}

void tEmpleado::aniadeEmpleado(){

    int num;
    
    nombre = "jose";
    
    cout << "Introduce el nombre: ";
    cin >> nombre;
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