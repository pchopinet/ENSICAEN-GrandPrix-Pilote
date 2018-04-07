/**
 * @brief Gestionnaire de course de voitures. Projet 1A Ensicaen.
 *
 * @authors Julien Gosme (2012)
 *          Modifié par G. Lebrun (2015), S. Fourey (2016)
 */
#include "grandprix.h"
#include "headless.h"
#include <QApplication>
#include <QDebug>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    QApplication a(argc, argv);
    GrandPrix w;
    w.show();
    return a.exec();
  } else if (argc == 5) {
    bool ok;
    Headless a(argc, argv, &ok);
    if (ok)
      return a.exec();
    else
      return 1;
  } else {
    qCritical("./GrandPrix tracks/<map> drivers/<driver1> drivers/<driver2> "
              "drivers/<driver3>");
  }
  return 0;
}
