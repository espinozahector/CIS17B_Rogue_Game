/* To do:
 *
 * Create Enemy detection box for attacking player
 * Create enemy bullet
 *

*/


#include <QApplication>
#include "game.h"
#include "ctime"

Game *GAME;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(0));
    GAME = new Game();
    GAME->show();


    return a.exec();
}
