#pragma once
#include "ui_Chinese_Chess.h"

class Viewer
{
public:
	Viewer();
	void SetUi(Ui::Chinese_ChessClass*);
	void paintout();
private:
	Ui::Chinese_ChessClass ui;
};
