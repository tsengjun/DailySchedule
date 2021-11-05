#include <QApplication>
#include <QFrame>
#include <QPainter>
#include <QMouseEvent>
#include <QDateTime>
#include <QTimer>

class QMyFrame : public QFrame
{
private:
    bool m_draging = false;
    std::vector<QPointF> m_pos;
    QSize m_size;

public:
    QMyFrame(QWidget*parent = 0) : QFrame(parent)
    {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, QOverload<>::of(&QMyFrame::update));
        timer->start(1000);
    }
private:
    QSize getCenter()
    {
        QSize ret;

        if (
                (!m_size.isEmpty()) &&
                (m_size.width() >= 0) &&
                (m_size.height() >= 0)
            )
        {
            ret.rwidth() = m_size.width() / 2;
            ret.rheight() = m_size.height() / 2;
        }

        return ret;
    }

    int getMaxDiameter()
    {
        int d = -1;

        if (
                (!m_size.isEmpty()) &&
                (m_size.width() >= 0) &&
                (m_size.height() >= 0)
            )
        {
            d = (m_size.width() <=  m_size.height()) ? m_size.width(): m_size.height();
        }

        return d;
    }

    int getMinDiameter()
    {
        int d = -1;

        if (
                (!m_size.isEmpty()) &&
                (m_size.width() >= 0) &&
                (m_size.height() >= 0)
            )
        {
            d = (m_size.width() <=  m_size.height()) ? m_size.width(): m_size.height();
            d = d / 5;
        }

        return d;
    }

    bool insideTrack(QPointF &p)
    {
        bool ret = false;
        int d = getMaxDiameter();
        int dm = getMaxDiameter();

        if (
                (d > 0) &&
                (dm > 0)
            )
        {


        }

        return ret;
    }

    void paintEvent(QPaintEvent* event)
    {
        QPainter p(this);
        p.translate(rect().width() / 2, rect().height() / 2);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.setPen(Qt::NoPen);

        if (getMaxDiameter() > 0)
        {
            p.save();
            QRadialGradient Radial(0, 0, getMaxDiameter() / 2, 0, 0);
            QRadialGradient RadialH(0, 0, getMaxDiameter() / 2, 0, 0);
            QRadialGradient RadialM(0, 0, getMaxDiameter() / 2, 0, 0);

            Radial.setColorAt(1, QColor::fromRgba(0xFF808080));
            Radial.setColorAt(0.98, QColor::fromRgba(0xFFE6E6E6));
            Radial.setColorAt(0.88, QColor::fromRgba(0xFFE6E6E6));
            Radial.setColorAt(0.75, QColor::fromRgba(0));
            Radial.setColorAt(0.00, QColor::fromRgba(0));
            p.setBrush(Radial);
            p.drawEllipse(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter());

            {
                Radial.setColorAt(1, QColor::fromRgba(0xFF7F00FF));
                Radial.setColorAt(0.98, QColor::fromRgba(0xFF3F00FF));
                Radial.setColorAt(0.94, QColor::fromRgba(0xFF3F00FF));
                Radial.setColorAt(0.90, QColor::fromRgba(0));
                Radial.setColorAt(0.00, QColor::fromRgba(0));
                p.setBrush(Radial);
                //for (int i = 0; i < 120; ++i)
                {
                    p.drawPie(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter(), 0, 1920);
                }

                Radial.setColorAt(1, QColor::fromRgba(0xFF005F00));
                Radial.setColorAt(0.98, QColor::fromRgba(0xFF004F00));
                Radial.setColorAt(0.94, QColor::fromRgba(0xFF004F00));
                Radial.setColorAt(0.90, QColor::fromRgba(0));
                Radial.setColorAt(0.00, QColor::fromRgba(0));
                p.setBrush(Radial);
                //for (int i = 0; i < 120; ++i)
                {
                    p.drawPie(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter(), 1920, 240 * 4);
                }

                Radial.setColorAt(1, QColor::fromRgba(0xFF00FF00));
                Radial.setColorAt(0.98, QColor::fromRgba(0xFF007F00));
                Radial.setColorAt(0.94, QColor::fromRgba(0xFF007F00));
                Radial.setColorAt(0.90, QColor::fromRgba(0));
                Radial.setColorAt(0.00, QColor::fromRgba(0));
                p.setBrush(Radial);
                //for (int i = 0; i < 120; ++i)
                {
                    p.drawPie(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter(), 2880, 240 * 9);
                }

                Radial.setColorAt(1, QColor::fromRgba(0xFF0000FF));
                Radial.setColorAt(0.98, QColor::fromRgba(0xFF00007F));
                Radial.setColorAt(0.94, QColor::fromRgba(0xFF00007F));
                Radial.setColorAt(0.90, QColor::fromRgba(0));
                Radial.setColorAt(0.00, QColor::fromRgba(0));
                p.setBrush(Radial);
                //for (int i = 0; i < 120; ++i)
                {
                    p.drawPie(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter(), 3840 + 240, 240);
                }

                Radial.setColorAt(1, QColor::fromRgba(0xFF00006F));
                Radial.setColorAt(0.98, QColor::fromRgba(0xFF00005F));
                Radial.setColorAt(0.94, QColor::fromRgba(0xFF00005F));
                Radial.setColorAt(0.90, QColor::fromRgba(0));
                Radial.setColorAt(0.00, QColor::fromRgba(0));
                p.setBrush(Radial);
                //for (int i = 0; i < 120; ++i)
                {
                    p.drawPie(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter(), 21 * 240, 720);
                }

                {
                    QPixmap img;
                    img.load("icons\\toothbrush.png");
                    p.drawPixmap(432, 16, 88, 88, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\english.png");
                    p.drawPixmap(400, 144, 88, 88, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\breakfast.png");
                    p.drawPixmap(336, 248, 96, 96, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\nap.png");
                    p.drawPixmap(-112, 416, 88, 88, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\piano.png");
                    p.drawPixmap(-472, -224, 88, 88, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\reading.png");
                    p.drawPixmap(-408, -328, 88, 88, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\programming.png");
                    p.drawPixmap(-328, -416, 88, 88, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\relationship.png");
                    p.drawPixmap(-508, -112, 88, 88, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\move_bricks.png");
                    p.drawPixmap(128, 366, 96, 96, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\move_bricks.png");
                    p.drawPixmap(-408, 208, 96, 96, img);
                }

                {
                    QPixmap img;
                    img.load("icons\\sleeping.png");
                    p.drawPixmap(128, -432, 128, 128, img);
                }
            }

            RadialM.setColorAt(1, QColor::fromRgba(0xFF808080));
            RadialM.setColorAt(0.98, QColor::fromRgba(0xFFA0A0A0));
            RadialM.setColorAt(0.96, QColor::fromRgba(0xFFA0A0A0));
            RadialM.setColorAt(0.95, QColor::fromRgba(0));
            RadialM.setColorAt(0.00, QColor::fromRgba(0));
            p.setBrush(RadialM);

            for (int i = 0; i < 120; ++i)
            {
                p.drawPie(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter(), -4 + i * 48, 8);
            }

            RadialH.setColorAt(1, QColor::fromRgba(0xFF808080));
            RadialH.setColorAt(0.98, QColor::fromRgba(0xFFA0A0A0));
            RadialH.setColorAt(0.88, QColor::fromRgba(0xFFA0A0A0));
            RadialH.setColorAt(0.84, QColor::fromRgba(0));
            RadialH.setColorAt(0.00, QColor::fromRgba(0));
            p.setBrush(RadialH);

            for (int i = 0; i < 24; ++i)
            {
                p.drawPie(-(getMaxDiameter() / 2), -(getMaxDiameter() / 2), getMaxDiameter(), getMaxDiameter(), -8 + i * 240, 16);
            }

            QDateTime UTC(QDateTime::currentDateTimeUtc());
            QDateTime local(UTC.toLocalTime());
            p.rotate((((float)local.time().hour() +  ((float)local.time().minute() / 60))  / (float)24) * (float)360 - 90);
            p.setPen( QColor(0xFFA0A0A0) );
            p.setBrush( QColor(0xFFA0A0A0) );
            p.drawEllipse(-16, -16, 32, 32);
            p.drawRect(0, -8, (getMaxDiameter() / 2) * 0.75, 16);
            p.drawEllipse((getMaxDiameter() / 2) * 0.75 - 8, -8, 16, 16);
            p.setPen( QColor(0xFF808080) );
            p.setBrush( QColor(0xFF808080) );
            p.drawEllipse(-8, -8, 16, 16);
            p.restore();

            p.save();
            p.setPen( QColor(0xFF808080) );
            p.setBrush( QColor(0xFF808080) );

            QFont font;
            font.setPointSize(22);
            font.setBold(true);
            p.setFont(font);


            p.drawText(-100, 64, 200, 64, Qt::AlignCenter, local.time().toString());
            p.drawText(-100, 128, 200, 64, Qt::AlignCenter, QString("Shanghai"));

            p.rotate(270);
            for (int i = 0; i < 24; ++i)
            {
                p.drawText((getMaxDiameter() / 2.0 ) * 0.85, 0, 32, 32, Qt::AlignCenter, QString::number(i));
                p.rotate(360.0/24.0);
            }
            p.restore();
        }
    }

    void mousePressEvent(QMouseEvent* event)
    {
        m_draging = true;
        QPointF p = event->position();
        m_pos.push_back(p);
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        if (m_draging)
        {
            //QPointF p = event->position();
            //m_pos.push_back(p);
        }
        else
        {
            Q_UNUSED(event);
        }
    }

    void mouseReleaseEvent(QMouseEvent* event)
    {
        if (m_draging)
        {
            QPointF p = event->position();
            m_pos.push_back(p);
        }
        else
        {
            Q_UNUSED(event);
        }

        m_draging = false;
    }

    void resizeEvent(QResizeEvent* event)
    {
        QSize size = event->size();

        if ((!size.isEmpty()) &&
                (size.width() > 0) &&
                (size.height() > 0)
           )
        {
            int x =event->size().width();
            x &= ~1;
            int y =event->size().height();
            y &= ~1;
            m_size.rwidth() = x;
            m_size.rheight() = y;
        }
        else
        {
            m_size = QSize();
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMyFrame w;

    w.show();
    return a.exec();
}
