#include <iostream>
#include <QString>
#include <QDir>

int main() {

    /**
     * Crea las carpetas que van a simular los discos del RAID5
     */

    QString path ="/home/racso/Odessey/RAID5/ClionTest";
    QString discosvirtuales[] = {"DiscoVirtual1","DiscoVirtual2","DiscoVirtual3"};

    for(int i = 0; i<3 ;i++){
        QDir dir("/home/racso/Odessey/RAID5/ClionTest/"+discosvirtuales[i]);
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
    file.close();

    /**
     * Realizamos los calculos de la particion de los bloques
     */

    ///Como tenemos 3 discos virtuales (3 carpetas), realiz


    std::cout<<array.size()<< "\n";
    std::cout<<array.length();

    ///Pruebas Varias
    QFile ArchivoDV1("/home/racso/Odessey/RAID5/ClionTest/DiscoVirtual1/Test.txt");
    ArchivoDV1.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV1.write(array.mid(0,array.size()/3));
    ArchivoDV1.seek(array.length()/3);
    ArchivoDV1.close();




    return 0;
}