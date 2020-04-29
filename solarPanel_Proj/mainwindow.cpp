#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget_3->setWindowFlags(Qt::SubWindow);

    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*, int)), SLOT(mSelectedSlot(QTreeWidgetItem*, int)));
    items = ui->treeWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard | Qt::MatchRecursive); // get all the items

    c_state = new CStates();
    c_state->PassUi(ui);
    connect(c_state , SIGNAL(CState_SIGNAL()) , this , SLOT(c_state_SLOT()));

    ui->c_state_scroll->hide();
    ui->apply_reset_widget->hide();
    ui->undo_clear_widget->hide();
    ui->p_state_widget->hide();


}

void MainWindow::c_state_SLOT()
{
    qDebug() << "Main Class" << c_state->getBtnTxt();
    mText_VEC.push_back(c_state->getBtnTxt());
    setText();
}

void MainWindow::setText()
{
    QString result = "";
    for ( int i = 0 ; i < mText_VEC.count() ; i++){
        result += mText_VEC.at(i);
        result += ";";
    }
    ui->txt_c_states->setText(result);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mSelectedSlot(QTreeWidgetItem* item, int col)
{

    handleSelections(item->text(col));
//    qDebug() << " -------------------- ";
}


void MainWindow::handleSelections(QString val){

    QString result ;
    for (int i = 0 ; i < items.count() ; i++){


        if (items.at(i)->text(0) == "C-States"){
            if ( items.at(i)->checkState(0)){
                ui->c_state_scroll->show();
                ui->undo_clear_widget->show();
                ui->apply_reset_widget->show();
            }
            else {
                ui->c_state_scroll->hide();
                ui->undo_clear_widget->hide();
                ui->apply_reset_widget->hide();
            }
        }
        if( items.at(i)->text(0) == "P-States" )
        {
            if ( items.at(i)->checkState(0)){
                ui->p_state_widget->show();
            }
            else{
                ui->p_state_widget->hide();
            }
        }

    }


}

void MainWindow::on_pushButton_4_clicked()
{
    if (!mText_VEC.isEmpty()){
        mText_VEC.pop_back();
        setText();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if (!mText_VEC.isEmpty()){
        mText_VEC.clear();
        setText();
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    resetSpinBoxes();
    resetTextBoxes();
    if (!mText_VEC.isEmpty()){
        mText_VEC.clear();
        setText();
    }
}


void MainWindow::resetSpinBoxes()
{
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->spinBox_5->setValue(0);
    ui->spinBox_6->setValue(0);
    ui->spinBox_7->setValue(0);
    ui->spinBox_8->setValue(0);
    ui->spinBox_9->setValue(0);
    ui->spinBox_10->setValue(0);
    ui->spinBox_11->setValue(0);
    ui->spinBox_12->setValue(0);
    ui->spinBox_13->setValue(0);
    ui->spinBox_14->setValue(0);
}

void MainWindow::resetTextBoxes()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_6->setText("");
    ui->textEdit_7->setText("");
    ui->textEdit_8->setText("");
    ui->textEdit_9->setText("");
    ui->textEdit_10->setText("");
    ui->textEdit_11->setText("");
    ui->textEdit_12->setText("");
    ui->textEdit_13->setText("");
    ui->textEdit_14->setText("");
    ui->textEdit_15->setText("");

}
