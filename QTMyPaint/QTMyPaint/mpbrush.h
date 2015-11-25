#ifndef MPBRUSH_H
#define MPBRUSH_H

#include <QColor>

#include "mypaint-brush.h"


class MPBrush
{
public:
    MPBrush();
    ~MPBrush();

    MyPaintBrush * brush;

    QColor  getColor();
    void    setColor(QColor newColor);
    //MyPaintBrush* getBrush();
    void    initBrush();
    void    setSize(float value);

private:
    QColor m_color;
};

#endif // MPBRUSH_H
