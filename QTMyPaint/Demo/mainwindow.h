#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QPushButton>
#include <QColorDialog>
#include <QLabel>
#include <QTabWidget>
#include <QSlider>

#include <mypaintview.h>
#include <PuMPBrushes.h>
#include "spinslider.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MypaintView *mp_view;
    PuMPBrushes* mp_brushes;
    QPushButton *m_colorBtn;
    QSlider* slider;

};

#endif // MAINWINDOW_H
