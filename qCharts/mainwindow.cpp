#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //        MainWindow::makePlot();
    MainWindow::barGraph();
    //    ui->customPlot->addGraph();
    //    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    //    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);

    //    q_vx.append(1.0);
    //    q_vy.append(1.0);
    //    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    //    c_textLabel= new QCPItemText(ui->customPlot);
//    c_textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
//    c_textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
//    c_textLabel->position->setCoords(0.5, 14); // place position at center/top of axis rect
//    c_textLabel->setText("C-State");
//    c_textLabel->setFont(QFont(font().family(), 11)); // make font a bit larger
//    c_textLabel->setPen(QPen(Qt::black)); // show black border around text

//    t_textLabel = new QCPItemText(ui->customPlot);
//    c_textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
//    c_textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
//    c_textLabel->position->setCoords(0.5, 2); // place position at center/top of axis rect
//    c_textLabel->setText("T-State");
//    c_textLabel->setFont(QFont(font().family(), 11)); // make font a bit larger
//    c_textLabel->setPen(QPen(Qt::black)); // show black border around text

//    hwp_textLabel= new QCPItemText(ui->customPlot);
//    c_textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
//    c_textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
//    c_textLabel->position->setCoords(0.5, 4); // place position at center/top of axis rect
//    c_textLabel->setText("HWP-State");
//    c_textLabel->setFont(QFont(font().family(), 11)); // make font a bit larger
//    c_textLabel->setPen(QPen(Qt::black)); // show black border around text

//    sdc_textLabel  = new QCPItemText(ui->customPlot);
//    c_textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
//    c_textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
//    c_textLabel->position->setCoords(0.5, 6); // place position at center/top of axis rect
//    c_textLabel->setText("SDC-State");
//    c_textLabel->setFont(QFont(font().family(), 11)); // make font a bit larger
//    c_textLabel->setPen(QPen(Qt::black)); // show black border around text



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double x, double y)
{
    q_vx.append(x);
    q_vy.append(y);
}

void MainWindow::clearData()
{

}

void MainWindow::plot()
{
    QVector<double> ticks;
    QVector<QString> labels;
    //    ticks << 1 << 2 << 3 << 4 ;
    ticks << 10 << 8 << 5 << 6 ;

    regenData.clear();
    regenData << c_val << hwp_val << t_state << sdc_state ;
    regen->setData(ticks, regenData);

    ui->customPlot->replot();
    ui->customPlot->update();
}

void MainWindow::makePlot(){

    // irralevent
    // prepare data:
    QVector<double> x1(20), y1(20);
    QVector<double> x2(100), y2(100);
    QVector<double> x3(20), y3(20);
    QVector<double> x4(20), y4(20);
    for (int i=0; i<x1.size(); ++i)
    {
      x1[i] = i/(double)(x1.size()-1)*10;
      y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    for (int i=0; i<x2.size(); ++i)
    {
      x2[i] = i/(double)(x2.size()-1)*10;
      y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
    }
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i/(double)(x3.size()-1)*10;
      y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
    }
    for (int i=0; i<x4.size(); ++i)
    {
      x4[i] = x3[i];
      y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
    }

    // create and configure plottables:
    QCPGraph *graph1 = ui->customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));

    QCPGraph *graph2 = ui->customPlot->addGraph();
    graph2->setData(x2, y2);
    graph2->setPen(Qt::NoPen);
    graph2->setBrush(QColor(200, 200, 200, 20));
    graph2->setChannelFillGraph(graph1);

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(9/(double)x3.size());
    bars1->setData(x3, y3);
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(10, 140, 70, 160));

    QCPBars *bars2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars2->setWidth(9/(double)x4.size());
    bars2->setData(x4, y4);
    bars2->setPen(Qt::NoPen);
    bars2->setBrush(QColor(10, 100, 50, 70));
    bars2->moveAbove(bars1);

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->yAxis->setRange(0, 2);
}


void MainWindow::barGraph(){
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //    QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    regen->setStackingGap(1);

//    regen->setName("Graph label");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    //    ticks << 10 << 8 << 5 << 6 ; // axis
    // labels << "USA" << "Japan" << "Germany" << "France" << "UK" << "Italy" << "Canada";
    //    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    //    textTicker->addTicks(ticks, labels);

    ui->customPlot->xAxis->setSubTicks(false);
    ////    ui->customPlot->xAxis->setTickLength(0, 4);
    //    ui->customPlot->xAxis->setRange(0, 1);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();

    ui->customPlot->yAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();

    // prepare y axis:
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("y Axis");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:

    //    ticks << 10 << 8 << 5 << 6 ; // x axis

    //    regenData   << 14 << 10  << 10 << 0.2 ; // y axis

    //    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0 , 30);
    ui->customPlot->yAxis->setRange(0, 30);

}
bool cOn = false;
void MainWindow::on_pushButton_5_clicked()
{
    // set cstate
    if (cOn){
        c_val =  0;
        cOn = false;
    }
    else {
        c_val =  14;//
        cOn = true;
    }
    plot();
}
bool hOn = false;
void MainWindow::on_pushButton_4_clicked()
{
    // set hwp
    if (hOn){
        hwp_val = 0 ; //
        hOn = false;
    }
    else{
        hwp_val = 10 ; //
        hOn = true;
    }
    plot();

}
bool tOn;
void MainWindow::on_pushButton_3_clicked()
{
    // set t state
    if (tOn){
        t_state = 0;//
        tOn = false;
    }
    else{

        t_state =   10;//
        tOn = true;
    }
    plot();
}
bool sOn;
void MainWindow::on_pushButton_2_clicked()
{
    //    set sdc state
    if ( sOn){
        sdc_state = 0;
        sOn= false;
    }else {
        sdc_state = 0.2;
        sOn = true;
    }
    plot();

}
