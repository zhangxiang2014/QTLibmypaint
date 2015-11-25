#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PuMPBrushes.h"
#include <QSettings>
#include "spinslider.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Central widget:
    MypaintView* mpView = new MypaintView();
    setCentralWidget (mpView);
    mp_brushes= new PuMPBrushes("C:/msys64/usr/src/mypaint/brushes",this);
    QDockWidget* p_dockBrush = new QDockWidget("Style selection");
    p_dockBrush->setWidget(mp_brushes);
    addDockWidget( Qt::LeftDockWidgetArea, p_dockBrush);
    // Add a color selector:
    QDockWidget* p_dockColor = new QDockWidget("Color selection");
    m_colorBtn = new QPushButton("Click to select another brush color...");
    m_colorBtn->setMinimumHeight(60);
    m_colorBtn->setStyleSheet( "color: white; background-color: black;" );
    p_dockColor->setWidget(m_colorBtn);
    addDockWidget ( Qt::RightDockWidgetArea, p_dockColor );
    //Add change brush size
    //QSettings settings( "Pencil", "Pencil" );
    QDockWidget* p_dockBurshSize = new QDockWidget("Brush Size Select:");
    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(1);
    slider->setMaximum(200);
    slider->setValue(50);
    p_dockBurshSize->setWidget(slider);
//    sizeSlider = new SpinSlider(tr("size"),"log","real",0.2,200.0,p_dockBurshSize);
//    sizeSlider->setValue( settings.value( "pencilWidth" ).toDouble() );
//    sizeSlider->setToolTip( tr( "Set Pen Width <br><b>[SHIFT]+drag</b><br>for quick adjustment" ) );

    addDockWidget ( Qt::RightDockWidgetArea, p_dockBurshSize );
    //
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(setBrushSize(int)));
    connect(m_colorBtn, SIGNAL(pressed ()), mpView, SLOT(btnChgColorPressed()));
    connect(mp_brushes,  SIGNAL(BrushSelected(const QByteArray&)), mpView, SLOT(BrushSelected(const QByteArray&)));
    resize(800, 700);
    //mp_brushes->SelectDefaultBrush();
}

MainWindow::~MainWindow()
{
    delete ui;
}
