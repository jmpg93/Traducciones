//
//  tEmpleado.cpp
//  Traducciones
//
//  Created by Jose Maria Puerta on 26/04/14.
//  Copyright (c) 2014 Jose Maria Puerta. All rights reserved.
//

#include "tEmpleado.h"

tEmpleado::tEmpleado():tTraductor(){
    
    enServicio = false;
    nombre = "";
    apellido = "";
    idiomas[0] = new tIdioma();
}

tEmpleado::~tEmpleado(){
    for (int i = 0; i < idiomasHablados; i++) {
        delete idiomas[i];
        idiomas[i] = NULL;
    }
}

void tEmpleado::aniadeEmpleado(){
    //num no puede ser mayor que 5
    
    
    cout << "Introduce el nombre y primer apellido: ";
    cin >> nombre;
    cin >> apellido;
    cout << endl;
    
    cout << "Introduce numero de idiomas que domina: ";
    cin >> idiomasHablados;
    cout << endl;
    
    cout << "Introduce los idiomas" << endl;
    
    for (int i = 0; i < idiomasHablados; i++) {
        string lengua;
        cin >> lengua;
        if (idiomas[i]==NULL) {
            idiomas[i] = new tIdioma();
        }
        idiomas[i]->ponLengua(lengua);
    }

}

void tEmpleado::cargaEmpleado(string datos){
    int lengt = (int) datos.length();
    
    unsigned long pos = datos.find_first_of(" ");
    nombre = datos.substr(0,pos);
    datos = datos.substr(pos + 1, lengt);
    
    pos = datos.find_first_of(" ");
    apellido = datos.substr(0,pos);
    datos = datos.substr(pos + 1, lengt);
    
    pos = datos.find_first_of(" ");
    string aux =  datos.substr(0, pos);
    idiomasHablados = (int)aux[0] - 48;
    datos = datos.substr(pos + 1, lengt);
    
    
    for (int i = 0; i < idiomasHablados; i++){
        pos = datos.find_first_of(" ");
        string aux =  datos.substr(0, pos);
        datos = datos.substr(pos + 1, lengt);
        if(idiomas[i]==NULL){
            idiomas[i] = new tIdioma();
        }
        idiomas[i]->ponLengua(aux);
    }
    
}

void tEmpleado::mostrarEmpleado(){
    int aux = 20;
    string aux2 = dameNombre();
    
   
    cout << dameNombre() << ".";
    for (aux -= (int)aux2.length(); aux>0; aux--) {
        cout << " ";
    }
    cout << "Idiomas: ";
    
    for (int i = 0; i<idiomasHablados; i++) {
        cout << idiomas[i]->dameLengua();
        if (i<idiomasHablados-1) cout << ", ";
    }
    cout << endl;
    
}


int tEmpleado::dameIdiomasHablados(){
    return idiomasHablados;
}
tIdioma * tEmpleado::dameIdioma(int i){
    return idiomas[i];
}

void tEmpleado::ponNombre(string nom){
    nombre = nom;
}
string tEmpleado::dameNombre(){
    return nombre + " " + apellido;
}

bool tEmpleado::tieneIdioma(tIdioma idiom){
    bool enc = false;
    int i = 0;
    while (!enc && i < idiomasHablados) {
        if (idiomas[i]->comparaIdioma(idiom)) enc = true;
        i++;
    }
    
    return enc;
}

bool tEmpleado::comparaIdiomasDeEmpleados(tEmpleado * empleado){
    bool enc = false;
    int i = 0, j = 0;
    
    tEmpleado * empleadoMasIdiomas;
    tEmpleado * empleadoMenosIdiomas;
    
    if (empleado->dameIdiomasHablados()>this->dameIdiomasHablados()) {
        empleadoMasIdiomas = empleado;
        empleadoMenosIdiomas = this;
    } else {
        empleadoMasIdiomas = this;
        empleadoMenosIdiomas = empleado;
    }
    
    while (!enc && i < empleadoMasIdiomas->dameIdiomasHablados()){
        
        j=0;
        while (!enc && j < empleadoMenosIdiomas->dameIdiomasHablados()){
            if(empleadoMenosIdiomas->dameIdioma(j)->dameLengua() == empleadoMasIdiomas->dameIdioma(i)->dameLengua()) enc = true;
            j++;
        }
        i++;
    }
    return enc;
}

int tEmpleado::numeroTraductores(){
    return 1;
}

void tEmpleado::muestraTraductores(){
    mostrarEmpleado();
}
bool tEmpleado::dameServicio(){
    return tTraductor::enServicio;
}

void tEmpleado::ocupaTraductor(){
    enServicio = true;
}
void tEmpleado::liberaTraductor(){
    enServicio = false;
}

