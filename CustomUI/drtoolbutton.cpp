#include "drtoolbutton.h"
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class DRToolButtonPrivate
{
    Q_DECLARE_PUBLIC(DRToolButton)
public:
    explicit DRToolButtonPrivate(DRToolButton *qptr) :
        q_ptr(qptr),
        m_pTimer(Q_NULLPTR)
    {}
public:
    DRToolButton *const q_ptr;
    QTimer *m_pTimer;
    QImage m_Image;
    QIcon m_BaseIcon;
};


DRToolButton::DRToolButton(QWidget *parent) :
    QToolButton(parent),
    d_ptr(new DRToolButtonPrivate(this))
{
    Q_D(DRToolButton);
    d->m_pTimer = new QTimer(this);
    d->m_pTimer->setSingleShot(false);
    d->m_Image = QImage(":/image/loading.png");
    connect(d->m_pTimer, &QTimer::timeout, this, &DRToolButton::drawIcon);
}

DRToolButton::~DRToolButton()
{
    delete d_ptr;
}

void DRToolButton::setDRImage(const QString &fileName)
{
    Q_D(DRToolButton);
    d->m_Image.load(fileName);
}

void DRToolButton::setDRImage(const QImage &image)
{
    Q_D(DRToolButton);
    d->m_Image = image;
}

// 设置旋转使能--调用start/stop
void DRToolButton::rotationEnable(bool enable)
{
    Q_D(DRToolButton);
    if (enable) {
        start();
    } else {
        stop();
    }
}

// 开始旋转
void DRToolButton::start(int mesc)
{
    Q_D(DRToolButton);
    d->m_BaseIcon = this->icon();
    d->m_pTimer->start(mesc);
}

// 停止旋转
void DRToolButton::stop()
{
    Q_D(DRToolButton);
    d->m_pTimer->stop();
    this->setIcon(d->m_BaseIcon);
}

void DRToolButton::drawIcon()
{
    static quint32 ang = 0;
    Q_D(DRToolButton);
    if (d->m_Image.isNull()) {
        return;
    }
    int w = d->m_Image.width();
    int h = d->m_Image.height();
    ang += 30;
    QPixmap pixmap(d->m_Image.size());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.translate(w*0.5, h*0.5);
    painter.rotate(ang);
    painter.translate(-w*0.5, -h*0.5);
    painter.drawImage(0, 0, d->m_Image);
    QIcon icon = QIcon(pixmap);
    icon.addPixmap(pixmap, QIcon::Disabled, QIcon::On);
    icon.addPixmap(pixmap, QIcon::Disabled, QIcon::Off);
    this->setIcon(icon);
    this->update();
}
