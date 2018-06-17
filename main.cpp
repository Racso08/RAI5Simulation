#include <iostream>
#include <QString>
#include <QDir>
#include <QtCore/QBitArray>

using namespace std;
static int seek;
//static QString discosvirtuales[] = {"DiscoVirtual1","DiscoVirtual2","DiscoVirtual3"};

int main() {

    /**
     * Crea las carpetas que van a simular los discos del RAID5 en el sistema de archivos
     */

    QString path ="/home/racso/Odessey/RAID5/ClionTest";        ///Cambiar el path
    QString discosvirtuales[] = {"DiscoVirtual1","DiscoVirtual2","DiscoVirtual3"};

    for(int i = 0; i<3 ;i++){
        QDir dir(path+"/"+discosvirtuales[i]);
        if (!dir.exists()) {
            dir.mkpath(".");
        }
    }

    /**
     * Simulamos el guardado de un archivo
     */

    QFile file("/home/racso/Odessey/RAID5/ClionTest/Dimelo.mp4");
    QByteArray array;
    file.open((QIODevice::ReadOnly));
    array = file.readAll();
    QString information = array.toBase64().constData();
    file.close();
    std::cout<<"Aquibdskjfbsd";

    /**
     * Pasamos la informacion a biniario con el fin de calcular el bloque de paridad (AUN NO FUNCIONA )
     */

    QByteArray bytes = array;

// Create a bit array of the appropriate size
    QBitArray bits(bytes.count()*8);

// Convert from QByteArray to QBitArray
    for(int i=0; i<bytes.count(); ++i) {
        for(int b=0; b<8;b++) {
            bits.setBit( i*8+b, bytes.at(i)&(1<<b) );
        }
    }

    QByteArray byteArr;
    for(int i=0; i<bits.count(); ++i)
        byteArr[i/8] = (byteArr.at(i/8) | ((bits[i]?1:0)<<(i%8)));

    QString este = QString(byteArr);
    std::cout<<este.toStdString();



    ///Como tenemos 3 discos virtuales (3 carpetas), aun falta implementar el calculo del bloque de paridad
    int size_block = array.size()/3;

    ///Escritura de archivos
    QFile ArchivoDV1("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual1/A.txt");
    ArchivoDV1.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV1.write(array.mid(seek,size_block));
    ArchivoDV1.close();
    seek += size_block;

    QFile ArchivoDV2("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual2/B.txt");
    ArchivoDV2.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV2.write(array.mid(seek,size_block));
    ArchivoDV2.close();
    seek += size_block;

    QFile ArchivoDV3("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual3/C.txt");
    ArchivoDV3.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV3.write(array.mid(seek,size_block));
    ArchivoDV3.close();

    ///Pruebas en la carga de archivos en caso de que un disco no funcione

    /**
     * Simulamos la perdidad de uno de los discos virtuales
     */
    QDir test("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual1/A.txt");
    test.removeRecursively();

    /**
     * Carga de archivos
     */

    QString pathtemp = "/home/racso/Odessey/RAID5/ClionTest/";
    for(int i = 0; i<discosvirtuales->size()-1; i++){
        QDir temp(pathtemp+discosvirtuales[i]);
        if(temp.exists()){
            std::cout<<"El disco virtual: " + discosvirtuales[i].toStdString()+" esta en funcionamiento...";
        }else{
            std::cout<<"El disco virtual: " + discosvirtuales[i].toStdString()+" no esta en funcionamiento...";
        }
    }





    return 0;
}