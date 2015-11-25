#ifndef MPHANDLER_H
#define MPHANDLER_H

#include <QColor>

#include "mypaint-brush.h"
#include "mypaint-surface.h"

#include "mpbrush.h"
#include "mpsurface.h"



class MPHandler : public QObject
{
    Q_OBJECT

public:
    ~MPHandler();

    static MPHandler *handler();

    typedef void (*MPOnUpdateFunction) (MPHandler *handler, MPSurface *surface, MPTile *tile);

    void startStroke();
    void strokeTo(float x, float y, float pressure, float xtilt, float ytilt);
    void strokeTo(float x, float y);
    void endStroke();

    void setBrushColor(QColor newColor);
    void requestUpdateTile(MPSurface *surface, MPTile *tile);
    void hasNewTile(MPSurface *surface, MPTile *tile);
    void change_brush_style(const char * content);
    void setBrushSize(float value);


private:
    MPHandler();
    static bool instanceFlag;
    static MPHandler *currentHandler;
    MPSurface * m_surface;
    MPBrush *   m_brush;



signals:
    void updateTile(MPSurface *surface, MPTile *tile);
    void newTile(MPSurface *surface, MPTile *tile);

};

#endif // MPHANDLER_H
