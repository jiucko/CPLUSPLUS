#include "Trader.h"
#include <sstream>

Trader::Trader(QWidget *parent)
	: QMainWindow(parent), mdspi_(*this)
{
	ui.setupUi(this);

	init();
}
void Trader::init()
{
	//connect(ui.textLog, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	count = 0;
}

void Trader::on_pushButton_clicked()
{
	count++;
	std::stringstream ss;
	ss << count;
	std::string s = (std::string)"helloworld" + ss.str();
	insertLogText(s);
}

void Trader::insertLogText(std::string buff)
{
	ui.textLog->moveCursor(QTextCursor::Start);
	ui.textLog->insertPlainText(QString::fromStdString(buff));
}