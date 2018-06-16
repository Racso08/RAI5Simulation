#include <iostream>
#include <QString>
#include <QDir>

static int seek;

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
     * Pasamos la informacion a biniario con el fin de calcular el bloque de paridad (AUN NO FUNCIONA )
     */

    QByteArray transformation = array;
    QString infohexadecimal = QString(transformation.toHex());
    bool ok;
    QString infobinary =QString("%1").arg(infohexadecimal.toULongLong(&ok, 16), 5, 2, QChar('0'));
    //std::cout<<infohexadecimal.toStdString();
    std::cout<<infobinary.toStdString();

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

    return 0;
}