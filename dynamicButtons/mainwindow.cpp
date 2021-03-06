#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QElapsedTimer>
#include <QScrollArea>
#include <QScroller>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QElapsedTimer *qTim = new QElapsedTimer();
//    ui->centralWidget->setMaximumSize(QSize(220,220));
     ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QScroller::grabGesture(ui->scrollArea->viewport(),QScroller::LeftMouseButtonGesture);

    qTim->start();
<<<<<<< HEAD
      for (int i = 0; i < 2; ++i){
=======
      for (int i = 0; i < 100; ++i){
>>>>>>> 0e944406adf0a181ad153713c0e7654782132ba5
          button = new QDynamicButton(this);  // Create a dynamic button object
//           button2 = new QDynamicButton(this);  // Create a dynamic button object
          /* Set the text with number of button
           * */
           button->setText("Song" + QString::number(button->getID()));
//           button2->setText("Time" + QString::number(button->getID()));
          /* Adding a button to the bed with a vertical layout
           * */
           ui->verticalLayout_2->addWidget(button);
//           ui->verticalLayout_4->addWidget(button2);

//           ui->verticalLayout_6->addWidget(button);
//           ui->verticalLayout_7->addWidget(button2);

          /* Connect the signal to the slot pressing buttons produce numbers
           * */
          connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
          mLastChild = button;
//          connect(button2, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
          QTimer::singleShot( 5, this, SLOT(ScrollToEnd()) );
    }
      qDebug() << "_ _ " << qTim->elapsed();

//      QWidget* scrollAreaContent = new QWidget;
//      scrollAreaContent->setLayout( ui->verticalLayout );
//      QScrollArea* scrollArea = new QScrollArea;
////      scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
////      scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded );
//      scrollArea->setWidgetResizable( true );
//      scrollArea->setWidget( scrollAreaContent );



}
void MainWindow::ScrollToEnd()
{
    qDebug() << " called ";
    //mScrollArea->verticalScrollBar()->setValue( mScrollArea->verticalScrollBar()->maximum() );
    ui->scrollArea->ensureWidgetVisible( mLastChild , 0, 0 );
}
MainWindow::~MainWindow()
{
    delete ui;
    delete button;
}
void MainWindow::slotGetNumber()
{
    /* To determine the object that caused the signal
     * */
    QDynamicButton *button = (QDynamicButton*) sender();
    /* Then set the number of buttons in lineEdit,
     * which is contained in the dynamic button
     * */
    QTimer::singleShot( 5, this, SLOT(ScrollToEnd()) );

    qDebug() << button->getID();
    /* That is the key number is set to lineEdit field only
     * when we press one of the dynamic keys,
     * and this number corresponds to the button you pressed
     * */
}

//void MainWindow::mouseReleaseEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)  //najdeme najblizsi obrazok
//        ;
//    if (event->button() == Qt::RightButton)
//    {
//        QPointF m_rightEnd = event->pos();
//        m_offset += m_rightEnd - m_rightStart;
//    }
//}

//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::RightButton)
//    {
//        m_rightStart = event->pos();
//    }
//}

//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    m_mousePoint = event->pos();
//    repaint(); //this is the problem for me
//}
