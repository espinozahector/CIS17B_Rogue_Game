#include "replace.h"
#include "roomchild.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    //create the mdi area
    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),this, SLOT(updateActions()));
    //create actions
    crActns();
    //create menu
    crMenu();
    //create toolbars

    //create status bar

    //set the window properties
//    setWindowIcon(QPixmap(":/Other/icon.png"));
    setWindowTitle(tr("Operation Graduation"));

    //helps with loading
    QTimer::singleShot(0,this,SLOT(loadFiles()));
    newGame();
}

void MainWindow::crActns()
{
    //action for a new game
    newAct = new QAction(tr("&New")),this;
//    newAct->setIcon(QIcon(":/Other/new.png"));
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip(tr("Start a new game"));
    connect(newAct, SIGNAL(triggered()),this, SLOT(newGame()));

    //display for recent files
//    for(int i=0;i<MaxRec;i++){
//        recFiAc[i] = new QAction(this);
//        recFiAc[i]->setVisible(false);
//        connect(recFiAc[i],SIGNAL (triggered()),this, SLOT(close());
//    }

    //create exit action
    exitAct = new QAction(tr("&Exit"),this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close());


}

void MainWindow::crMenu()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(newAct);
//    fileMenu->addAction(openAct);
//    fileMenu->addAction(saveAct);
//    fileMenu->addAction(saveAsAct);
    //add separators
//    separatorAction = fileMenu->addSeparator();
//    for(int i=0;i<MaxRec;i++){
//        fileMenu->addAction(recFiAc(i));
//    }
    //above items are from QT book page 52

    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

}

void MainWindow::crRmChd(){
    RoomChild *roomChild = new RoomChild(ui->mdiArea);
    roomChild->setAttribute(Qt::WA_DeleteOnClose);
    roomChild->show();
}

void MainWindow::newGame()
{
    crRmChd();
}

void MainWindow::loadFiles()
{
    QStringList args = QApplication::arguments();
    args.removeFirst();
    if(!args.isEmpty()){
        foreach (QString arg, args)
            openFile(arg);
        mdiArea->cascadeSubWindows();
    }else{
        newGame();
    }
    mdiArea->activateNextSubWindow();
}
