#include "CustomMdSpi.h"

CustomMdSpi::CustomMdSpi(Trader& t):m_treader(t)
{
}

void CustomMdSpi::OnFrontConnected()
{
	m_treader.insertLogText("=====建立网络连接成功=====");
}