#ifndef TRANSPARENTWAITWIDGET_H
#define TRANSPARENTWAITWIDGET_H

#include "customui_global.h"
#include <QWidget>
#include <QToolButton>

class TransparentWaitWidgetPrivate;
class CUSTOMUISHARED_EXPORT TransparentWaitWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TransparentWaitWidget(QWidget *parent = 0);
    ~TransparentWaitWidget();
    // 设置窗口需要显示的等待图片
    void setFileName(const QString &fileName);
    QToolButton *getColseButton();
protected:
    void paintEvent(QPaintEvent *event);
    void setVisible(bool visible);
private:
    Q_DISABLE_COPY(TransparentWaitWidget)
    Q_DECLARE_PRIVATE(TransparentWaitWidget)
    TransparentWaitWidgetPrivate* const d_ptr;
};

#endif // TRANSPARENTWAITWIDGET_H
