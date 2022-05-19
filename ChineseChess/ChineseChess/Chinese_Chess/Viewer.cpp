#include "Viewer.h"

Viewer::Viewer()
{
	
}
void Viewer::SetUi(Ui::Chinese_ChessClass* inpUi)
{
	ui = *inpUi;
}
void Viewer::paintout()
{
	ui.page_1->update();
	ui.textBrowser->setText("abcdef");
}