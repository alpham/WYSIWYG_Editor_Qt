#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QTextCursor>
class QTextDocument;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
    QTextCursor myCursor;
    QTextDocument *myDocument;
    QString filePath;
    QString currentFileName;
    void setCurrentFile(const QString &currentFile);
    void setupConnections();


private slots:
    void makeBold();
    void makeCenter();
    void makeLeft();
    void makeRight();
    void makeJustifyed();
    void updateHTML();

signals:
    void modified(bool modificationState);
};

#endif // WIDGET_H
