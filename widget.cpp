#include "widget.h"
#include "ui_widget.h"
#include <QtGui>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTextDocument *document=new QTextDocument;
    ui->textEdit->setDocument(document);
    setCurrentFile("");
    ui->htmlEditor->setPlainText(ui->textEdit->toHtml());
    setupConnections();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setCurrentFile(const QString &currentFile)
{
    if(currentFile.isEmpty())
        currentFileName=tr("NEW_FILE");
    else
        currentFileName=QFileInfo(currentFile).fileName();

}

void Widget::setupConnections()
{
    /*font decoration connections*/
    connect(ui->boldButton,SIGNAL(clicked()),this,SLOT(makeBold()));
    connect(ui->italicButton,SIGNAL(clicked(bool)),ui->textEdit,SLOT(setFontItalic(bool)));
    connect(ui->underlineButton,SIGNAL(clicked(bool)),ui->textEdit,SLOT(setFontUnderline(bool)));

    /*Alignment connections*/
    connect(ui->centerButton,SIGNAL(clicked()),this,SLOT(makeCenter()));
    connect(ui->leftButton,SIGNAL(clicked()),this,SLOT(makeLeft()));
    connect(ui->rightButton,SIGNAL(clicked()),this,SLOT(makeRight()));
    connect(ui->justifyButton,SIGNAL(clicked()),this,SLOT(makeJustifyed()));

    /*HTML Editor connections*/
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(updateHTML()));

}


void Widget::makeBold()
{
    ui->textEdit->setFontWeight(ui->boldButton->isChecked() ? QFont::Bold : QFont::Normal);
}

void Widget::makeCenter()
{
    ui->textEdit->setAlignment(ui->centerButton->isChecked()? Qt::AlignHCenter : Qt::AlignAbsolute);
}

void Widget::makeLeft()
{
    ui->textEdit->setAlignment(ui->leftButton->isChecked()? Qt::AlignLeft : Qt::AlignAbsolute);
}

void Widget::makeRight()
{
    ui->textEdit->setAlignment(ui->rightButton->isChecked()? Qt::AlignRight : Qt::AlignAbsolute);
}

void Widget::makeJustifyed()
{
    ui->textEdit->setAlignment(ui->justifyButton->isChecked()? Qt::AlignJustify : Qt::AlignAbsolute);
}

void Widget::updateHTML()
{
    ui->htmlEditor->setPlainText(ui->textEdit->toHtml());
}

