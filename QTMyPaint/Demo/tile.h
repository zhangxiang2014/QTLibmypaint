/* brushlib - The MyPaint Brush Library (demonstration project)
 * Copyright (C) 2013 POINTCARRE SARL / Sebastien Leon email: sleon at pointcarre.com
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 */

#ifndef TILE_H
#define TILE_H

#include <QGraphicsItem>
#include <QImage>

#include "MypaintView.h"

//-------------------------------------------------------------------------
// This basic class store a tile info & display it. the ushort table is the
// real info modified by libMyPaint. Before any screen refresh, we transfer
// it to a QImage acting as a cache. this QImage is only necessary to paint.
// NOTE that the uint16_t data (premul RGB 15 bits) is transfered in premul
// format. This is only useful if you plan to have several layers.
// if it is not the case, you could simply convert to RGBA (not premul)

#define CONV_16_8(x) ((x*255)/(1<<15))

class Tile : public QGraphicsItem
{
public:
  Tile (QGraphicsItem * parent = NULL):
    QGraphicsItem(parent),
    m_cache_img  (MypaintView::k_tile_dim, MypaintView::k_tile_dim, QImage::Format_ARGB32_Premultiplied)
  {
    setCacheMode(QGraphicsItem::NoCache);
    memset(t_pixels, 0, sizeof(t_pixels)); // Tile is transparent for now
    m_cache_img.fill( QColor(0,0,0,0) ); // image cache is transparent too, and aligned to the pixel table:
    m_cache_valid = true;
  }
  enum { k_red = 0, k_green = 1, k_blue = 2, k_alpha =3 }; // Index to access RGBA values in myPaint

  virtual QRectF       boundingRect () const { return m_cache_img.rect(); }
  virtual bool         contains  (const QPointF & point) const { return qAlpha(m_cache_img.pixel(point.toPoint())) > 0x10; } // opaque if alpha > 16
  virtual QPainterPath shape     () const { QPainterPath path; path.addRect(m_cache_img.rect()); return path; }
  virtual void         paint     (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
  {
    if (!m_cache_valid) UpdateCache(); // We need to transfer the uint16_t table to the QImage cache
    painter->drawImage( QPoint(), m_cache_img, m_cache_img.rect());
  }

  uint16_t* Bits (bool readOnly) { m_cache_valid = readOnly ? m_cache_valid : false; return (uint16_t*)t_pixels; } // Correct C++ way of doing things is using "const" but MyPaint API is not compatible here
  void DrawPoint ( uint x, uint y, uint16_t r, uint16_t g, uint16_t b, uint16_t a ) // debug function (simply replace previous value of pixel in t_pixels)
  { m_cache_valid = false; t_pixels[y][x][k_red  ] = r; t_pixels[y][x][k_green] = g; t_pixels[y][x][k_blue ] = b; t_pixels[y][x][k_alpha] = a; }
private:
  void UpdateCache() // Time to transfer the pixels from the uint16 to 32 bits cache before repaint...
  {
    QRgb* dst = (QRgb*)m_cache_img.bits();
    for (int y = 0 ; y < MypaintView::k_tile_dim ; y++)
    {
      for (int x = 0 ; x < MypaintView::k_tile_dim ; x++)
      {
        uint16_t alpha = t_pixels[y][x][k_alpha];
        *dst = alpha ? qRgba(
          CONV_16_8(t_pixels[y][x][k_red  ]),
          CONV_16_8(t_pixels[y][x][k_green]),
          CONV_16_8(t_pixels[y][x][k_blue ]),
          CONV_16_8(                  alpha)) :
          0; // aplha is 0 => all is zero (little optimization)
        dst++; // next image pixel...
      }
    }
    m_cache_valid = true;
  }
  uint16_t  t_pixels [MypaintView::k_tile_dim][MypaintView::k_tile_dim][4];
  QImage    m_cache_img;
  bool      m_cache_valid;
};

#endif // TILE_H
