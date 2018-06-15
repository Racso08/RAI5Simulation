#include <iostream>
#include <QString>
#include <QDir>

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

    /**
     * Realizamos los calculos de la particion de los bloques
     */

    ///Como tenemos 3 discos virtuales (3 carpetas)
    std::cout<<array.size()<< "\n";
    std::cout<<array.length();

    ///Pruebas Varias
    QFile ArchivoDV1("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual1/Test.txt");
    ArchivoDV1.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV1.write(array.mid(0,array.size()/3));
    ArchivoDV1.seek(array.length()/3);
    ArchivoDV1.close();

    QFile ArchivoDV2("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual2/Test.txt");
    ArchivoDV2.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV2.write(array.mid(array.size()/3,2*(array.size()/3)));
    ArchivoDV2.seek(array.length()/3);
    ArchivoDV2.close();

    QFile ArchivoDV3("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual3/Test.txt");
    ArchivoDV3.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV3.write(array.mid(2*(array.size()/3),2*(array.size()/3))+ array.size()/3);
    ArchivoDV3.seek(array.length()/3);
    ArchivoDV3.close();




    return 0;
}