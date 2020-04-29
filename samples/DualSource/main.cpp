// *****************************************************************************
//
//     Copyright (c) 2012, Pleora Technologies Inc., All rights reserved.
//
// *****************************************************************************

#include "dualsource.h"

#include <QtGui/QApplication>
#include <QtCore/QTime>
#include <QtCore/QTextCodec>

#include <signal.h>


void SignalHangler( int aSig )
{
	qApp->quit();
}


int main(int argc, char *argv[])
{
	// Forcing locale to English, US for consistency
	QLocale::setDefault( QLocale( QLocale::English, QLocale::UnitedStates ) );
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );

	QApplication a(argc, argv);

    QCoreApplication::setOrganizationName( "Pleora Technologies Inc" );
    QCoreApplication::setOrganizationDomain( "pleora.com" );
    QCoreApplication::setApplicationName( "DualSource" );
    
    DualSource w;

#ifdef _LINUX_
    // When catching the signal, we will simulate the File\Exit menu usage to ensure a proper cleanup
    QObject::connect( &a, SIGNAL( aboutToQuit() ), &w, SLOT( OnFileExitAction() ) );
    signal( SIGTERM, SignalHangler );
    signal( SIGINT, SignalHangler );
#endif // _LINUX_

    w.show();

    return a.exec();
}



