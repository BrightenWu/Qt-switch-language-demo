#pragma once

#include <QtWidgets/QWidget>
#include <QComboBox>
#include <QLabel>
#include "ui_QLanguageTest1.h"

class QLanguageTest1 : public QWidget
{
	Q_OBJECT

	enum LanguageType
	{
		LT_CHINESE,
		LT_ENGLISH,
		LT_JAPANESE
	};

public:
	QLanguageTest1(QWidget *parent = Q_NULLPTR);

protected:
	virtual void changeEvent(QEvent *e);

private:
	void reTranslateUi();
	void changeLanguage(int nIndex);

private:
	Ui::QLanguageTest1Class ui;
	QComboBox *m_pLanguageCombo = nullptr;
	QLabel *m_pLanguageLabel = nullptr;
	QTranslator *m_pTranslator = nullptr;
};
