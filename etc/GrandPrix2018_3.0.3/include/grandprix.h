/**
 * @brief Gestionnaire de course de voitures. Projet 1A Ensicaen.
 *
 * @authors Julien Gosme (2012)
 *          Modifi� par G. Lebrun (2015), S. Fourey (2016)
 */
#ifndef GRANDPRIX_H
#define GRANDPRIX_H

#include "gpcontrolview.h"
#include "gpmapview.h"
#include <QMainWindow>

namespace Ui {
class GrandPrix;
}

class GrandPrix : public QMainWindow {
  Q_OBJECT

public:
  explicit GrandPrix(QWidget *parent = 0);
  ~GrandPrix();

private:
  Ui::GrandPrix *ui;
};

#endif // GRANDPRIX_H
