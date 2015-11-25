#include <QGraphicsRectItem>
#include <QBrush>
#include <QPixmap>

#include "mpbrush.h"
#include "mypaintview.h"
#include "tile.h"
#include "mypaint-tiled-surface.h"


static MypaintView* s_view = NULL;

MypaintView::MypaintView()
{
    assert(s_view == NULL);
    s_view = this;
    // allocate an empty brush:
    mp_brush = mypaint_brush_new();

    using_tablet = false;

    MPHandler *mypaint = MPHandler::handler();

    connect(mypaint, SIGNAL(newTile(MPSurface*, MPTile*)), this, SLOT(onNewTile(MPSurface*, MPTile*)));
    connect(mypaint, SIGNAL(updateTile(MPSurface*, MPTile*)), this, SLOT(onUpdateTile(MPSurface*, MPTile*)));


    // Set scene
    m_scene.setSceneRect (  QRect(QPoint(), QSize(1920, 1080))  );
    setScene     (&m_scene);
    setAlignment (0);
    setVerticalScrollBarPolicy   (Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOn);
}

MypaintView::~MypaintView()
{

}


void
MypaintView::onNewTile(MPSurface *surface, MPTile *tile)
{
    m_scene.addItem(tile);
}


void
MypaintView::onUpdateTile(MPSurface *surface, MPTile *tile)
{
    tile->update();
}



void MypaintView::tabletEvent(QTabletEvent *e)
{
  switch (e->type())
  {
    case QEvent::TabletPress:
      if (e->pointerType() == QTabletEvent::Pen)
      {
        using_tablet = true;
        MPHandler::handler()->startStroke();
        e->accept();
      }
      break;
    case QEvent::TabletRelease:
      if (e->pointerType() == QTabletEvent::Pen)
      {
        // Finalize the stroke sequence.
        using_tablet = false;
        e->accept();
      }
      break;
    case QEvent::TabletMove:
      if (e->pointerType() == QTabletEvent::Pen)
      {
        QPointF pt(mapToScene(e->pos()));

        MPHandler::handler()->strokeTo(pt.x(), pt.y(), e->pressure(), e->xTilt(),  e->yTilt());
        //stroke_to(m_brush, (MyPaintSurface *)m_surface, pt.x(), pt.y(), e->pressure(), CTILT(e->xTilt()),  CTILT(e->yTilt()));

        e->accept();
      }
      break;
   }
}

void MypaintView::mousePressEvent(QMouseEvent * e)
{
    MPHandler::handler()->startStroke();
}



void MypaintView::mouseMoveEvent    ( QMouseEvent * e )
{
    if (!using_tablet) {
        QPointF pt = mapToScene(e->pos());
        MPHandler::handler()->strokeTo(pt.x(), pt.y());
    }
}


void MypaintView::mouseReleaseEvent ( QMouseEvent * e )
{
    // Finalize the stroke sequence.
}


void MypaintView::btnChgColorPressed()
{
    QPushButton* p_btn = dynamic_cast<QPushButton*>(sender());
    if (p_btn)
    {
        QColor newColor = QColorDialog::getColor ( m_color, window(), "Select the brush color", QColorDialog::ShowAlphaChannel );
        if (newColor.isValid())
        {
            p_btn->setStyleSheet( QString("color: %1; background-color: %2;").arg((newColor.lightnessF()>0.5)?"black":"white").arg(newColor.name()) );

            MPHandler *mypaint = MPHandler::handler();
            mypaint->setBrushColor(newColor);


        }
    }
}

void MypaintView::BrushSelected (const QByteArray& content)
{
  // I get a crash after several calls to mypaint_brush_from_string(p_brush, content.constData())
  // I do not see why... May be with some proper API doc I could fix that.
  // May be the desallocation code is a bit wrong and/or it is a MSVC compilation issue :
  // HEAP[test.exe]: HEAP: Free Heap block 31bfd28 modified at 31c2a34 after it was freed

  // user selected another brush. Time to reload it :
    MPHandler *mypaint = MPHandler::handler();
    mypaint->change_brush_style(content);
//    gboolean setting = mypaint_brush_from_string(mypaint->m_brush->getBrush(), content);
//  if (!setting)
//  {
//    // Not able to load the selected brush. Let's execute some backup code...
//    qDebug("Trouble when reading the selected brush !");
//  }
}

void MypaintView::setBrushSize(int value)
{
    MPHandler *mypaint = MPHandler::handler();
    mypaint->setBrushSize(value);
}
