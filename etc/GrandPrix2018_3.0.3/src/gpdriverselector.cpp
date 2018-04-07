/**
 * @brief Gestionnaire de course de voitures. Projet 1A Ensicaen.
 *
 * @authors Julien Gosme (2012)
 *          Modifié par G. Lebrun (2015), S. Fourey (2016)
 */
#include "gpdriverselector.h"
#include "ui_gpdriverselector.h"
#include <QDir>

namespace {
bool caseInsensitiveLessThan(const QString &s1, const QString &s2) {
  return s1.toLower() < s2.toLower();
}
} // namespace

GPDriverSelector::GPDriverSelector(QWidget *parent)
    : QWidget(parent), ui(new Ui::GPDriverSelector) {
  ui->setupUi(this);
  _noCar = 0;
  QDir drivers = QDir("./drivers/");
  QStringList list = drivers.entryList(
      QDir::Files | QDir::Readable | QDir::Executable, QDir::Name);
  qSort(list.begin(), list.end(), caseInsensitiveLessThan);
  ui->comboBox->addItems(list);
}

void GPDriverSelector::setNoCar(int noCar) {
  _noCar = noCar;
  ui->label->setText(tr("Driver %1:").arg(noCar + 1));
  QString color;
  switch (noCar) {
  case 0:
    color = "red";
    break;
  case 1:
    color = "green";
    break;
  case 2:
    color = "blue";
    break;
  }
  ui->label->setStyleSheet("QLabel { color : " + color + "; }");
}

void GPDriverSelector::setEnabled(bool enabled) {
  ui->comboBox->setEnabled(enabled);
}

QString GPDriverSelector::getDriverPath() {
  return "./drivers/" + ui->comboBox->currentText();
}

QString GPDriverSelector::getDriverFileName() {
  return ui->comboBox->currentText();
}

void GPDriverSelector::setInfo(int nbMoves, int nbFailures, int carburant) {
  ui->info->setText(QString("%1 coups %3 carb (%2 fail) ")
                        .arg(nbMoves)
                        .arg(nbFailures)
                        .arg(carburant));
}

bool GPDriverSelector::debugIsChecked() { return ui->debug->isChecked(); }

void GPDriverSelector::on_debug_toggled(bool toggle) {
  emit debugToggle(_noCar, toggle);
}

GPDriverSelector::~GPDriverSelector() { delete ui; }
