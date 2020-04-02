#ifndef DRTOOLBUTTON_H
#define DRTOOLBUTTON_H

#include "customui_global.h"
#include <QToolButton>

class DRToolButtonPrivate;
class CUSTOMUISHARED_EXPORT DRToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit DRToolButton(QWidget *parent = 0);
    ~DRToolButton();
    void setDRImage(const QString &fileName);
    void setDRImage(const QImage &image);
public slots:
    // 设置旋转使能--调用start/stop
    void rotationEnable(bool enable);
    // 开始旋转
    void start(int mesc = 40);
    // 停止旋转
    void stop();
protected slots:
    // 绘制图像到ToolButton上
    virtual void drawIcon();
private:
    Q_DISABLE_COPY(DRToolButton)
    Q_DECLARE_PRIVATE(DRToolButton)
    DRToolButtonPrivate *const d_ptr;
};

#endif // DRTOOLBUTTON_H
