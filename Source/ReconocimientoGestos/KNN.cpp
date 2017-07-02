// Fill out your copyright notice in the Description page of Project Settings.

#include "KNN.h"


bool CompararGestos(std::pair<int, double> & a, std::pair<int, double> & b) {
    return a.second < b.second;
}

int KNN::Clasificar(std::vector<double> & GestoNuevo){
    std::vector<std::pair<int, double> > vecinos = ObtenerKVecinos(GestoNuevo);
    std::vector<int> ContadorClases(nclases+1, 0);//el indice 0 represnetnra la clase desconocido
    for(int i = 0; i < k && i < vecinos.size(); i++){
        ContadorClases[GestosClases[vecinos[i].first]] += 1;
        //std::cout << "base: " << vecinos[i].first << " " << vecinos[i].second << std::endl;
    }
    int max = 0;
    int imax = 0;
    for(int i = 0; i < ContadorClases.size(); i++){
        if(ContadorClases[i] > max){
            max = ContadorClases[i];
            imax = i;
        }
    }
    return imax;//este es la clase a la que pertenede este nuevo gesto
}

int KNN::ClasificarUmbralDistancia(std::vector<double> & GestoNuevo){
    std::vector<std::pair<int, double> > vecinos = ObtenerKVecinos(GestoNuevo);
    std::vector<int> ContadorClases(nclases, 0);//el indice 0 represnetnra la clase desconocido
    for(int i = 0; i < k && i < vecinos.size() && vecinos[i].second <= DistanciaUmbral; i++){
        ContadorClases[vecinos[i].first]++;
    }
    int max = 0;
    int imax = 0;
    for(int i = 0; i < ContadorClases.size(); i++){
        if(ContadorClases[i] > max){
            max = ContadorClases[i];
            imax = i;
        }
    }
    return imax;//este es la clase a la que pertenede este nuevo gesto
}

void KNN::AgregarGesto(std::vector<double> GestoNuevo, int GestoClase){
    GestosVectores.push_back(GestoNuevo);
    GestosClases.push_back(GestoClase);
    //debo pregnar para confirmar que se desea gaurdar
    //y extender para que use todo la informacion(posicion, rotacion, si fue con perfil, HMD o no, y el gesto supuestamente asociado, )
}

std::vector<std::pair<int, double> > KNN::ObtenerKVecinos(std::vector<double> & GestoNuevo){//obitne los indices, no exactamente los vectores
    //tal vez los deba regresar ordenados, esta cosa compara la distancia con todos y los ordena segun eso, por lo tanto debe haber una copia
    //o podria regresar los indices en forma ordenad, ya que no se necesta mas, solo acceder en el arreglo de acuerdo a los ideas
    std::vector<std::pair<int, double> > resultado (GestosVectores.size());
    for(int i = 0; i < GestosVectores.size(); i++){
        resultado[i].first = i;
        resultado[i].second = Distancia(GestoNuevo, GestosVectores[i]);
        //std::cout << "base: " << resultado[i].first << " " << resultado[i].second << std::endl;
    }
    //ordenar, pero crear la funcon para el oredanmiento
    std::sort(resultado.begin(), resultado.end(), CompararGestos);
    return resultado;//del resultado solo me debo quedar con los primeros k
}

double KNN::Distancia(std::vector<double> & Gesto1, std::vector<double> Gesto2){
    double acum = 0;
    for(int i = 0; i < Gesto1.size(); i++){
        acum += (Gesto1[i] - Gesto2[i])*(Gesto1[i] - Gesto2[i]);
    }
    //hasta aqui el calculo esta al cuadraado, evitar el sqrt ayuda a que sea mas aficiente
    return sqrt(acum);
}

void KNN::LeerBaseDatos(){
    funcion_main(GestosVectores, GestosClases);
}

void KNN::EscribirBaseDatos(){
    string archivo = "D:\\UnrealProjects\\ReconocimientoGestos\\Resources\\basedatos.txt";
    ofstream salida (archivo.c_str());
    for (int i = 0; i < GestosVectores.size(); i++) {
        for (int j = 0; j < GestosVectores[i].size(); j++) {
            salida << GestosVectores[i][j] << ",";
        }
        salida << GestosClases[i] << endl;
    }
    salida.close();
}


KNN::KNN(){
    nclases = 10;
    k = 3;
    //std::cout << "KNN construido" << std::endl;//falla por que se esta llamando antes de que se contruyya el objeto que contiene a esta clase, que es la que manipula el buffer del cout
}

KNN::~KNN(){}


double KNN::super_dividir(double a,int p)
{
	double m1=136.412000;
	double m2=111.113000;
	double m3=113.370000;
	double m4=105.467000;
	double m5=107.302000;
	double m6=106.100000;
	double m7=97.824300;
	double m8=106.167000;
	double m9=113.378000;
	double m10=111.497000;
	double m11=94.00500;
	double m12=113.304000;
	double m13=103.798000;
	double m14=109.307000;
    if(p==1) return a/m1;
    if(p==2) return a/m2;
    if(p==3) return a/m3;
    if(p==4) return a/m4;
    if(p==5) return a/m5;
    if(p==6) return a/m6;
    if(p==7) return a/m7;
    if(p==8) return a/m8;
    if(p==9) return a/m9;
    if(p==10) return a/m10;
    if(p==11) return a/m11;
    if(p==12) return a/m12;
    if(p==13) return a/m13;
    if(p==14) return a/m14;
    return 0;
}

string KNN::convertir_a_letras(int numero)
{
    stringstream asd;
    asd.str("");
    asd << numero;
    string qwe = asd.str();
    return qwe;
}
int KNN::convertir_a_numero(string numero)
{
    int num = 0;
    int temp;
    long j = numero.length() - 1;
    for(int i = 0; i < numero.length(); i++)
    {
        temp = numero[i] - 48;
        num += temp * pow(10, j - i);
    }
    return num;
}

string KNN::super_lectura_de_archivos(string nombre,int p) {
    string texto;
    nombre = nombre + ".csv";
    ifstream stream(nombre.c_str());
    string line;
    //std::cout << stream.good() << std::endl;
    if (stream.good()) {
        getline(stream, line);
        string aline = "";
        for (int k = 0; k < 6; k++) {
            getline(stream, line, ',');
            //cout<<line<<'#';
            if (k == 1) d1.push_back(super_dividir(atof(line.c_str()), p));
            if (k == 2) d2.push_back(super_dividir(atof(line.c_str()), p));
            if (k == 3) d3.push_back(super_dividir(atof(line.c_str()), p));
            if (k == 4) d4.push_back(super_dividir(atof(line.c_str()), p));
            if (k == 5) {
                for (int j = 0; j < line.size() && line[j] != '\n'; j++) {
                    aline = aline + line[j];
                }
                d5.push_back(super_dividir(atof(line.c_str()), p));;
            }
        }
    }
    stream.close();
    return line;
}

void KNN::super_llenado_de_archivos(string nombre, string texto)
{
    string tipo=".csv";
    nombre+=tipo;
    ofstream Salida("b.txt");
    Salida<<texto;
    Salida.close();
}

void KNN::funcion_main( vector<vector<double> > &V, vector<int> &I)
{
	for(int p=1;p<15;p++){
        for(int g=1;g<11;g++){
            for(int i=1;i<11;i++){

                //super_lectura_de_archivos("D:/IA/kinect_leap_dataset/acquisitions/P"+convertir_a_letras(p)+"/G"+convertir_a_letras(g)+"/"+convertir_a_letras(i)+"_leap_motion",p);
                //super_lectura_de_archivos("D:\IA\kinect_leap_dataset\acquisitions\P"+convertir_a_letras(p)+"\G"+convertir_a_letras(g)+"\"+convertir_a_letras(i)+"_leap_motion",p);
                super_lectura_de_archivos("D:\\IA\\kinect_leap_dataset\\acquisitions\\P"+convertir_a_letras(p)+"\\G"+convertir_a_letras(g)+"\\"+convertir_a_letras(i)+"_leap_motion",p);
                //super_lectura_de_archivos("acquisitions\\P"+convertir_a_letras(p)+"\\G"+convertir_a_letras(g)+"\\"+convertir_a_letras(i)+"_leap_motion",p);
                //std::cout << "D:\\IA\\kinect_leap_dataset\\acquisitions\\P" + convertir_a_letras(p) + "\\G" + convertir_a_letras(g) + "\\" + convertir_a_letras(i) + "_leap_motion" << std::endl;
                I.push_back(g);
            }
        }
    }
    for(int i=0;i<d1.size();i++)
    {
        vector<double> v;
    	v.push_back(d1[i]);
    	v.push_back(d2[i]);
    	v.push_back(d3[i]);
    	v.push_back(d4[i]);
    	v.push_back(d5[i]);
        V.push_back(v);
    }
    std::cout << "paso lectura archivos" << std::endl;
}