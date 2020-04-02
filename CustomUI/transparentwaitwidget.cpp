#include "transparentwaitwidget.h"
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QToolButton>
#include <QGridLayout>

class TransparentWaitWidgetPrivate
{
    Q_DECLARE_PUBLIC(TransparentWaitWidget)
public:
    explicit TransparentWaitWidgetPrivate(TransparentWaitWidget *qptr) :
        q_ptr(qptr),
        m_pTimer(Q_NULLPTR),
        m_pCloseBt(Q_NULLPTR),
        m_ang(0)
    {}
    virtual ~TransparentWaitWidgetPrivate()
    {}
public:
    TransparentWaitWidget* const q_ptr;
    QString m_FilePath;
    QTimer  *m_pTimer;
    QToolButton *m_pCloseBt;
    quint32 m_ang;
};

TransparentWaitWidget::TransparentWaitWidget(QWidget *parent) :
    QWidget(parent),
    d_ptr(new TransparentWaitWidgetPrivate(this))
{
    Q_D(TransparentWaitWidget);

    // 设置窗口属性
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    // 在嵌入式设备可能会导致黑色背景
    //setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    //setWindowFlags(Qt::Dialog);
    // 设置窗口为模态
    setWindowModality(Qt::WindowModal);
    // 设置窗口的透明度
    //setWindowOpacity(1);
    // 设置背景色透明
    setAttribute(Qt::WA_TranslucentBackground);
    // 取消自动填充背景色
    setAutoFillBackground(false);
    // 初始化定时器
    d->m_pTimer = new QTimer(this);
    // 绘制25帧
    d->m_pTimer->setInterval(40);
    // 设置图片
    setFileName(":/image/loading.png");
    // 连接定时器的信号和界面刷新的槽函数
    connect(d->m_pTimer, &QTimer::timeout,
            [=](){
        d->m_ang += 30;
        update();
    });
    // 不显示
    setVisible(false);
}

TransparentWaitWidget::~TransparentWaitWidget()
{
    delete d_ptr;
}

void TransparentWaitWidget::setFileName(const QString &fileName)
{
    Q_D(TransparentWaitWidget);
    if (fileName.isEmpty()) {
        return;
    }
    QImage image;
    if (!image.load(fileName)) {
        return;
    }
    d->m_FilePath = fileName;
    // 界面适应图片的尺寸
    if (image.size() != this->size()) {
        setMinimumSize(image.size());
    }
    update();
}

void TransparentWaitWidget::paintEvent(QPaintEvent *event)
{
    Q_D(TransparentWaitWidget);
    // 文件为空或者加载失败
    QImage image;
    if (d->m_FilePath.isEmpty() || !image.load(d->m_FilePath)) {
        QWidget::paintEvent(event);
        return;
    }
    // 移动到父窗口的中心
    if (!(windowFlags() & Qt::Dialog)) {
        QWidget *pWidget = parentWidget();
        if (pWidget) {
            QPoint pos;
            pos.setX((pWidget->size().width()-this->size().width()) * 0.5);
            pos.setY((pWidget->size().height()-this->size().height()) * 0.5);
            if (pos != this->geometry().topLeft()) {
                this->move(pos);
            }
        }
    }
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int w = this->width();
    int h = this->height();
    // 当宽度和高度不为偶数的时候像素点减1
    if (w%2 != 0)
        w--;
    if (h%2 != 0)
        h--;
    int startX = (this->width()-image.width())*0.5;
    int startY = (this->height()-image.height())*0.5;
    painter.translate(w*0.5, h*0.5);
    painter.rotate(d->m_ang);
    painter.translate(-w*0.5, -h*0.5);
    painter.drawImage(startX, startY, image);

    QWidget::paintEvent(event);
}

void TransparentWaitWidget::setVisible(bool visible)
{
    Q_D(TransparentWaitWidget);
    if (visible) {
        d->m_pTimer->start();
    } else {
        d->m_pTimer->stop();
    }
    QWidget::setVisible(visible);
}
