#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString AUTOMATICO = "Automatico";
const QString MANUAL = "Manual";
const QString ATIVADA    = "ATIVADA";
const QString DESATIVADA = "DESATIVADA";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for(auto& item : QSerialPortInfo::availablePorts())
    {
        ui->box_serial->addItem(item.portName());
    }

    for(auto& item : QSerialPortInfo::standardBaudRates())
    {
        ui->box_velocidade->addItem(QString::number(item));
    }

    connect(&serial,
            SIGNAL(readyRead()),
            this,
            SLOT(dadosRecebidos()));
   }

MainWindow::~MainWindow()
{
    serial.close();
    delete ui;
}

void MainWindow::dadosRecebidos() //json que esta reccebendo sdo arduino
{
    auto data = serial.readAll();
    auto dados = QJsonDocument::fromJson(data).object().toVariantMap();

    if(dados.contains("LUMINOSIDADE")){
        luminosidade = dados["LUMINOSIDADE"].toString();
        ui->lbl_LDR->setText(luminosidade);
    }

    if(dados.contains("UMIDADE_SOLO"))
    {
        umidade_Solo = dados["UMIDADE_SOLO"].toString();
        ui->lbl_umidade_solo->setText(umidade_Solo);
    }

    if(dados.contains("STATUS_VALVULA"))
    {
        status_valvula = dados["STATUS_VALVULA"].toString();
    }
}

void MainWindow::on_btnPlug_clicked()
{
    plugStatus = !plugStatus;

    if(plugStatus)
    {
        serial.setPortName(ui->box_serial->currentText());
        serial.setBaudRate(ui->box_velocidade->currentText().toInt());

        if(serial.open(QIODevice::ReadWrite)){
            ui->status_conexao->setText("Status: Conectado");
            ui->btnPlug ->setText("Desconectar");
        }
    }
    else
    {
        ui->status_conexao->setText("Status: Desconectado");
        ui->btnPlug->setText("Conectar");
        serial.close();
    }
}


void MainWindow::on_btnModo_Activated(const QString &arg1) //manda  o json para a esp32
{
       if (arg1 == AUTOMATICO){
           serial.write("{\"MODO\": 1}");

       }

       if (arg1 == MANUAL){
           serial.write("{\"MODO\": 2}");
       }
}

void MainWindow::on_btnLigaDesliga_clicked()
{
    if(ui->combo_Sistema->currentText() == MANUAL){
        if(status_valvula == ATIVADA)
            status_valvula = DESATIVADA;

        if(status_valvula == DESATIVADA)
            status_valvula = ATIVADA;
    }
    else{
        QMessageBox::warning(this,"AVISO!","O Modulo Manual não está ativado, você não pode ligar/desligar.");
    }

}

//LEMBRAR DE COLOCAR UM BOTAO BOOL DE DESLIGA E LIGA VALVULA, SERIA BOM UM BOTÃO DE VALVULA, EM VEZ DAQUELE QUE TEM DESLIGAR
