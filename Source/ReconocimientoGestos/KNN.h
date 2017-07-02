// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include "CoreMinimal.h"

/**
 * 
 */
using namespace std;
class RECONOCIMIENTOGESTOS_API KNN
{
public:
    private:
        vector<double> d1;
        vector<double> d2;
        vector<double> d3;
        vector<double> d4;
        vector<double> d5;
        int k;
        double DistanciaUmbral;
        std::vector<std::vector<double> > GestosVectores;
        std::vector<int> GestosClases;// el numer 0 es desconocido
        //estos son los gestores almacenados con su respectiva clase a la que pertenence
        //ninguno es 0
        int nclases;//este contador inicia en 0, aumenta segun cada clase que aparezca al ller la base, luego se
    public:
        //bool CompararGestos(std::pair<int, double> a, std::pair<int, double> b);
        int Clasificar(std::vector<double> & GestoNuevo);
        int ClasificarUmbralDistancia(std::vector<double> & GestoNuevo);
        void AgregarGesto(std::vector<double> GestoNuevo, int GestoClase);
        std::vector<std::pair<int, double> > ObtenerKVecinos(std::vector<double> & GestoNuevo);//funcona para obtener a los vecinos, y luego procesar a que calses pertenecen
        void LeerBaseDatos();//estas deberian usar xml o bases de datos, quiza el de unreal, probar despues quiza pueda usar esas mismas librerias
        void EscribirBaseDatos();
        double Distancia(std::vector<double> & Gesto1, std::vector<double> Gesto2);
        KNN();
        ~KNN();
        double super_dividir(double a, int p);
        string convertir_a_letras(int numero);
        int convertir_a_numero(string numero);
        string super_lectura_de_archivos(string nombre, int p);
        void super_llenado_de_archivos(string nombre, string texto);
        void funcion_main(vector<vector<double>>& V, vector<int>& I);
};
