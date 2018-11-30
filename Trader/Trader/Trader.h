#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Trader.h"
#include "CustomMdSpi.h"

class CustomMdSpi;

class Trader : public QMainWindow
{
	Q_OBJECT

public:
	Trader(QWidget *parent = Q_NULLPTR);
	void init();
	Ui::TraderClass& getUI() { return ui; }
	void insertLogText(std::string buff);
private slots:
	void on_pushButton_clicked();
private:
	Ui::TraderClass ui;
	int count;
	CustomMdSpi mdspi_;
};
